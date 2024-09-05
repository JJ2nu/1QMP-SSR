#pragma once
#include "ButtonGameObject.h"
#include "ResourceManager.h"
#include "SceneManager.h"

class StartButtonUI : public ButtonGameObject
{
public:
	StartButtonUI(SceneBase* Scene)
		:ButtonGameObject("StartButtonUI", Scene)
	{
		//이미지 설정
		m_cTexture = CreateComponent<TextureComponent>("StartButtonUI");
		m_cTexture->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"StartButton", L"\\TestResource\\StartButton.bmp");
		m_cTexture->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"StartButton2", L"\\TestResource\\StartButton2.bmp");
		m_cTexture->m_uExcep = RGB(0, 0, 0);
		m_cTexture->m_iRenderFlag = 0;

		//컬라이더 크기 설정
		m_vButtonScale = Vector3(300, 150, 0);
	}

	virtual ~StartButtonUI()
	{}

	void OnClick() override
	{
		SceneManager::GetInstance()->ChangeScene(game::SCENE_TYPE::PALY);
	}
};