#pragma once
#include "GameObject.h"
#include "BackGroundScript.h"

class PrototypeBackgroundObject :public GameObject
{
public:
	BackGroundScript* m_Script;


public:
	PrototypeBackgroundObject(SceneBase * Scene) :GameObject("Player", Scene)
	{
		SetObjType(game::OBJECT_TYPE::BACKGROUND);
		m_Script = CreateComponent<BackGroundScript>("BackGroundSCript");
	}
	virtual ~PrototypeBackgroundObject() {};
};


