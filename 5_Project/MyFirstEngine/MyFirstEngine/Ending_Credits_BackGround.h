#pragma once
#include "GameObject.h"
#include "TextTureUITutorialScript.h"

class Ending_Credits_BackGround : public GameObject
{
	TextTureUITutorialScript* myScript;

public:
	Ending_Credits_BackGround(SceneBase* Scene) :GameObject("Ending_Credits_BackGround", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<TextTureUITutorialScript>("Ending_Credits_BackGround");
		myScript->m_Transform.SetPosition(ScreenWidth / 2, ScreenHeight / 2, 0);

		myScript->m_iTextureSize = 4;

		myScript->m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"Tutorial_BackGroundUI1", L"\\Image\\99. CREDIT\\01.bmp");
		myScript->m_TexComp->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"Tutorial_BackGroundUI2", L"\\Image\\99. CREDIT\\02.bmp");
		myScript->m_TexComp->m_tTexture[2] = ResourceManager::GetInstance()->LoadTexture(L"Tutorial_BackGroundUI3", L"\\Image\\99. CREDIT\\03.bmp");
		myScript->m_TexComp->m_tTexture[3] = ResourceManager::GetInstance()->LoadTexture(L"Tutorial_BackGroundUI4", L"\\Image\\99. CREDIT\\04.bmp");
	}

};