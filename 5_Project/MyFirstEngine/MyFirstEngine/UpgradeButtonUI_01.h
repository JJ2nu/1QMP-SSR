#pragma once
#include "ButtonGameObject.h"
#include "ResourceManager.h"
#include "Upgrade_Scene.h"


class UpgradeButtonUI_01 : public ButtonGameObject
{
public:
	TextureComponent* m_cClickTexture;
	Upgrade_Scene::UpgradeInfo _uinfo;
	UpgradeButtonUI_01(SceneBase* Scene, Upgrade_Scene::UpgradeInfo info) : ButtonGameObject("UpgradeButtonUI_01", Scene),_uinfo(info)
	{
		_uinfo = info;
		// 컬라이더 크기 설정  추후 이미지 크기에 따른 조정이 필요
		m_vButtonScale = Vector3(300, 150, 0);
		//m_Transform.SetPosition(320, 500, 0);
		m_cTexture = CreateComponent<TextureComponent>("UpgradeSkillTexture");
		m_cTexture->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(info.strKey, info.relPath);
		m_cTexture->m_iRenderFlag = 0;
		m_cTexture->m_uExcep = RGB(255,0,255);
		m_cTexture->m_vOffset.y = -300.0f;



		//이미지 설정 스킬 아이콘 추가 필요
		m_cClickTexture = CreateComponent<TextureComponent>("UpgradeButtonUI_01");
		m_cClickTexture->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"UpgradeButtonUI_01_1", L"\\image\\02. START_MENU\\button_normal_big.bmp");
		m_cClickTexture->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"UpgradeButtonUI_01_2", L"\\image\\02. START_MENU\\button_click_big.bmp");
		m_cClickTexture->m_uRenderIndex = 0;
		m_cClickTexture->m_uExcep = RGB(255, 0, 255);
		m_cClickTexture->m_iRenderFlag = 0;

		std::wstring m_wStringArr[100];

		std::wstring* text = new std::wstring(info.options);
		m_cText = CreateComponent<TextComponent>("UpgradeButtonUI_01TextComponent");
		m_cText->m_pFontName = L"\\Resource\\TestResource\\qwe.ttf";  //폰트 경로를 찾아서 로드
		m_cText->m_uColor = RGB(0, 0, 0); // 폰트 색
		m_cText->m_tString.push_back(text);
		m_cText->SetRectSize(m_Transform.Position.x, m_Transform.Position.y, 250, 150);
		m_cText->m_iFontSize = 25;
	}

	virtual ~UpgradeButtonUI_01() {};

	void OnClick() override
	{
		m_cClickTexture->m_uRenderIndex = 1;

		switch(_uinfo.type)
		{
		case 0:
			Observer::GetInstance()->m_sPlayerInfo.m_fEnhanceDamageRatio++;
			break;
		case 1:
			Observer::GetInstance()->m_sPlayerInfo.m_iEnhanceBulletRate++;
			break;
		case 2:
			Observer::GetInstance()->m_sPlayerInfo.m_iMaxShield++;
			Observer::GetInstance()->m_sPlayerInfo.m_bShield = true;
			break;
		case 3:
			Observer::GetInstance()->m_sPlayerInfo.m_bInvincibility = true;
			break;
		case 4:
			Observer::GetInstance()->m_sPlayerInfo.m_bPortal = true;
			break;
		}
		if (Observer::GetInstance()->m_iStageNum == 1)
			Observer::GetInstance()->m_GameFlag = game::SCENE_TYPE::MIDDLE_STORY_01;
		if (Observer::GetInstance()->m_iStageNum == 2)
			Observer::GetInstance()->m_GameFlag = game::SCENE_TYPE::MIDDLE_STORY_02;
	}

private:

};

