#pragma once
#include "GameObject.h"
#include "TextureUIScript.h"

class UpgradeBackGroundUI : public GameObject
{
	TextureUIScript* myScript;

public:
	UpgradeBackGroundUI(SceneBase* Scene) :GameObject("UpgradeBackGroundUI", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<TextureUIScript>("TextureUIScript");
		myScript->m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"UpgradeBackGroundUI", L"\\image\\02. START_MENU\\bg_to_cockpit (1).bmp");
		myScript->m_TexComp->m_iRenderFlag = 1;
		myScript->m_Transform.SetPosition(ScreenWidth / 2, ScreenHeight / 2, 0);

	}

	virtual ~UpgradeBackGroundUI() {};
};