#pragma once
#include "GameObject.h"
#include "BossHPUIScript.h"

class BossHPUI : public GameObject
{
	BossHPUIScript* myScript;
public:
	BossHPUI(SceneBase* Scene) :GameObject("Boss", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<BossHPUIScript>("BossScript");
	}
	virtual ~BossHPUI() {};

};
