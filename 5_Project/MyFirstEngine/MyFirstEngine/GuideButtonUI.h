#pragma once
#include "ButtonGameObject.h"
#include "ResourceManager.h"

class GuideButtonUI : public ButtonGameObject
{
public:
	GuideButtonUI(SceneBase* Scene)
		:ButtonGameObject("GuideButtonUI", Scene)
	{
		//이미지 설정
		m_cTexture = CreateComponent<TextureComponent>("GuideButtonUI");
		m_cTexture->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"GuideButton", L"\\TestResource\\GuideButton.bmp");
		m_cTexture->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"GuideButton2", L"\\TestResource\\GuideButton2.bmp");
		m_cTexture->m_uExcep = RGB(0, 0, 0);

		//컬라이더 크기 설정
		m_vButtonScale = Vector3(300, 150, 0);
	}
	virtual ~GuideButtonUI()
	{}
	void OnClick() override
	{

	}
};