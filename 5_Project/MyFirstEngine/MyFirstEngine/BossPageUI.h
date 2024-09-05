#pragma once
#include "GameObject.h"
#include "BossPageUIScript.h"

class BossPageUI : public GameObject
{
	BossPageUIScript* myScript;

public:
	BossPageUI(SceneBase* Scene) :GameObject("Player", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<BossPageUIScript>("BossPageUIScript");
	}

	virtual	~BossPageUI(){};

private:

};

