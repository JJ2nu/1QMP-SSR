#pragma once
#include "ButtonGameObject.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "Observer.h"


class TutorialButtonUI : public ButtonGameObject
{
public:
	TutorialButtonUI(SceneBase* Scene) : ButtonGameObject("TutorialButtonUI", Scene)
	{
		// 컬라이더 크기 설정  추후 이미지 크기에 따른 조정이 필요
		m_vButtonScale = Vector3(300, 150, 0);

		// 추후 위치 조정 필요 했을 경우 주석 삭제좀
		m_Transform.SetPosition(320, 500, 0);

		//이미지 설정
		m_cTexture = CreateComponent<TextureComponent>("TutorialButtonUI");
		m_cTexture->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"NormalButtonUI", L"\\image\\02. START_MENU\\button_normal_big.bmp");
		m_cTexture->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"StartButton2", L"\\image\\02. START_MENU\\button_click_big.bmp");

		m_cTexture->m_uExcep = RGB(255, 0, 255);
		m_cTexture->m_iRenderFlag = 0;

		//폰트 출력
		std::wstring* text = new std::wstring(L"TUTORIAL");
		m_cText = CreateComponent<TextComponent>("NumberPrintUITextComponent");
		m_cText->m_pFontName = L"\\Resource\\TestResource\\qwe.ttf";  //폰트 경로를 찾아서 로드
		m_cText->m_uColor = RGB(0, 0, 0); // 폰트 색
		m_cText->m_tString.push_back(text);
		m_cText->SetRectSize(228, 480, 250, 150);
		m_cText->m_iFontSize = 50;
	}

	virtual ~TutorialButtonUI() {};

	void OnClick() override
	{
		// 테스트를 위해 일단 남겨놓음
		Observer::GetInstance()->m_GameFlag = game::SCENE_TYPE::STAGE_TUTORIAL;
		ResourceManager::GetInstance()->PlayMusic(game::eSoundList::UI, 0, game::eSoundChannel::UI);
	}
};