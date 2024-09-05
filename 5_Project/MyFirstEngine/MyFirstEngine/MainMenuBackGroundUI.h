#pragma once
#include "GameObject.h"
#include "TextureUIScript.h"

class MainMenuBackGroundUI : public GameObject
{
	TextureUIScript* myScript;

public:
	MainMenuBackGroundUI(SceneBase* Scene) :GameObject("MainMenuBackGroundUI", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<TextureUIScript>("TextureUIScript");
		myScript->m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"MainMenuBackGroundUI", L"\\image\\02. START_MENU\\bg_to_cockpit (1).bmp");
		myScript->m_TexComp->m_iRenderFlag = 1;
		myScript->m_Transform.SetPosition(ScreenWidth / 2, ScreenHeight / 2, 0);
		
	}

	virtual ~MainMenuBackGroundUI() {};
};