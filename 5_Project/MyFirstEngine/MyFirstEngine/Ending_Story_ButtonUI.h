#pragma once
#include "ButtonGameObject.h"
#include "ResourceManager.h"
#include "SceneManager.h"

class Ending_Story_ButtonUI : public ButtonGameObject
{
public:
	Ending_Story_ButtonUI(SceneBase* Scene) : ButtonGameObject("Ending_Story_ButtonUI", Scene)
	{
		//이미지 설정
		m_cTexture = CreateComponent<TextureComponent>("Ending_Story_ButtonUI");
		m_cTexture->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"Ending_Story_ButtonUI1", L"\\TestResource\\GuideButton.bmp");
		m_cTexture->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"Ending_Story_ButtonUI2", L"\\TestResource\\GuideButton2.bmp");
		m_cTexture->m_uExcep = RGB(0, 0, 0);

		//컬라이더 크기 설정
		m_vButtonScale = Vector3(300, 150, 0);

		// 위치 추후 수정 필요
		m_Transform.SetPosition(100.f, 200.f, 0);
	}

	virtual ~Ending_Story_ButtonUI() {};

	void OnClick() override
	{
		// 추후 다음 씬 넘어가기 만들어야 함
	}
};