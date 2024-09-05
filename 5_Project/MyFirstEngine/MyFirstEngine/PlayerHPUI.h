#pragma once
#include "GameObject.h"
#include "PlayerHPUIScript.h"

class PlayerHPUI : public GameObject
{
	PlayerHPUIScript* myScript;
public:
	PlayerHPUI(SceneBase* Scene) :GameObject("Player", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<PlayerHPUIScript>("PlayerScript");
	}
	virtual ~PlayerHPUI() {};

};
