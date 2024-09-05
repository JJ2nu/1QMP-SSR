#pragma once
#include "GameObject.h"

#include "FadeInFadeOutScript.h"

class FadeInFadeOutObject :public GameObject
{
public:
	FadeInFadeOutScript* m_Script;


public:
	FadeInFadeOutObject() :GameObject("FadeInFadeOutObject", nullptr)
	{
		SetObjType(game::OBJECT_TYPE::MOUSE_CROSSHAIR);
		m_Script = CreateComponent<FadeInFadeOutScript>("FadeInFadeOutScript");
	}
	virtual ~FadeInFadeOutObject() {};
};


