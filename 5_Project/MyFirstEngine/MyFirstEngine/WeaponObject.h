#pragma once
#include "GameObject.h"
#include "WeaponScript.h"

class WeaponObject : public GameObject
{
public:
	WeaponScript* m_Script;
public:
	WeaponObject(SceneBase* Scene) :GameObject("WeaponObject", Scene)
	{
		SetObjType(game::OBJECT_TYPE::WEAPON);
		m_Script = CreateComponent<WeaponScript>("WeaponObject");
	}
	virtual void OnCollisionEnter(ColliderComponent* src)
	{
		m_Script->OnCollisionEnter(src);
	}
};


