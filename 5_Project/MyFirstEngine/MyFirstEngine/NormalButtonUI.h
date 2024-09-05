#pragma once
#include "ButtonGameObject.h"
#include "ResourceManager.h"
#include "SceneManager.h"

class NormalButtonUI : public ButtonGameObject
{
public:
	NormalButtonUI(SceneBase* Scene) : ButtonGameObject("NormalButtonUI", Scene)
	{
		// 컬라이더 크기 설정  추후 이미지 크기에 따른 조정이 필요
		m_vButtonScale = Vector3(300, 150, 0);
		// 추후 위치 조정 필요 했을 경우 주석 삭제좀
		m_Transform.SetPosition(960, 500, 0);

		//이미지 설정
		m_cTexture = CreateComponent<TextureComponent>("NormalButtonUI");
		m_cTexture->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"NormalButtonUI", L"\\image\\02. START_MENU\\button_normal_big.bmp");
		m_cTexture->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"StartButton2", L"\\image\\02. START_MENU\\button_click_big.bmp");


		m_cTexture->m_uExcep = RGB(255, 0, 255);
		m_cTexture->m_iRenderFlag = 0;


		std::wstring* text = new std::wstring(L"NORMAL");
		m_cText = CreateComponent<TextComponent>("NumberPrintUITextComponent");
		m_cText->m_pFontName = L"\\Resource\\TestResource\\qwe.ttf";  //폰트 경로를 찾아서 로드
		m_cText->m_uColor = RGB(0, 0, 255); // 폰트 색
		m_cText->m_tString.push_back(text);
		m_cText->SetRectSize(885, 480, 300, 150);
		m_cText->m_iFontSize = 50;
	}

	virtual ~NormalButtonUI() {};

	void OnClick() override
	{
		Observer::GetInstance()->m_bHardFlag = false;
		Observer::GetInstance()->m_GameFlag = game::SCENE_TYPE::COKPIT;
		ResourceManager::GetInstance()->PlayMusic(game::eSoundList::UI, 0, game::eSoundChannel::UI);
	}
};