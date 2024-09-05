#pragma once
#include "GameObject.h"
#include "TextureUIScript.h"

class PlayerShipUI : public GameObject
{
	TextureUIScript* myScript;

public:
	PlayerShipUI(SceneBase* Scene) :GameObject("PlayerShipUI", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<TextureUIScript>("PlayerShipUIScript");
		myScript->m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"PlayerShipUI", L"\\TestResource\\Ship_Player_0.bmp");
		myScript->m_TexComp->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"PlayerShipUI", L"\\TestResource\\Ship_Player_0.bmp");
		myScript->m_TexComp->m_tTexture[2] = ResourceManager::GetInstance()->LoadTexture(L"PlayerShipUI", L"\\TestResource\\Ship_Player_0.bmp");
	}

	virtual ~PlayerShipUI() {};

};

