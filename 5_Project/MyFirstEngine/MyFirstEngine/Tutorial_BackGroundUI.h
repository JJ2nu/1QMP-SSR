#pragma once
#include "GameObject.h"
#include "TextTureUITutorialScript.h"


class Tutorial_BackGroundUI : public GameObject
{
	TextTureUITutorialScript* myScript;

public:
	Tutorial_BackGroundUI(SceneBase* Scene) :GameObject("Tutorial_BackGroundUI", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<TextTureUITutorialScript>("Tutorial_BackGroundUI");
		myScript->m_Transform.SetPosition(ScreenWidth / 2, ScreenHeight / 2, 0);

		myScript->m_iTextureSize = 4;

		myScript->m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"Tutorial_BackGroundUI1", L"\\Image\\03. START_TUTORIAL\\BG_t_1.bmp");
		myScript->m_TexComp->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"Tutorial_BackGroundUI2", L"\\Image\\03. START_TUTORIAL\\BG_t_2.bmp");
		myScript->m_TexComp->m_tTexture[2] = ResourceManager::GetInstance()->LoadTexture(L"Tutorial_BackGroundUI3", L"\\Image\\03. START_TUTORIAL\\BG_t_3.bmp");
		myScript->m_TexComp->m_tTexture[3] = ResourceManager::GetInstance()->LoadTexture(L"Tutorial_BackGroundUI4", L"\\Image\\03. START_TUTORIAL\\BG_t_4.bmp");
	}

};
