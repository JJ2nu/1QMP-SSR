#pragma once
#include "GameObject.h"
#include "CrossHairScript.h"

class CrossHairObject :public GameObject
{
	CrossHairScript* myScript;
public:
	CrossHairObject(SceneBase* Scene) :GameObject("CrossHair", Scene)
	{
		SetObjType(game::OBJECT_TYPE::MOUSE_CROSSHAIR);
		myScript = CreateComponent<CrossHairScript>("CrossHairScript");
	}
	virtual ~CrossHairObject() {};

	virtual void OnCollision(ColliderComponent* src)
	{
		myScript->OnCollision(src);
	}
};