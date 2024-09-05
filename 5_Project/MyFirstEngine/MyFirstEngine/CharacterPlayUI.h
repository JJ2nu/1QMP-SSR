#pragma once
#include "GameObject.h"
#include "CharacterPlayUIScript.h"

class CharacterPlayUI : public GameObject
{
	CharacterPlayUIScript* myScript;

public:
	CharacterPlayUI(SceneBase* Scene) :GameObject("Player", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<CharacterPlayUIScript>("CharacterPlayUIScript");
	}
	virtual ~CharacterPlayUI() {};

private:

};

