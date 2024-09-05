#pragma once
#include "GameObject.h"
#include "BossPhaseUIScript.h"

class BossPhaseUI : public GameObject
{
	BossPhaseUIScript* myScript;

public:
	BossPhaseUI(SceneBase* Scene) :GameObject("Player", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<BossPhaseUIScript>("BossPhaseUIScript");
	}

	virtual	~BossPhaseUI(){};

private:

};

