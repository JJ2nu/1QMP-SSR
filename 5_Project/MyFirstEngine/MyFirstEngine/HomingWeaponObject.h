#pragma once
#include "GameObject.h"
#include "HomingWeaponScript.h"

class HomingWeaponObject : public GameObject
{
public:
	HomingWeaponScript* m_Script;
public:
	HomingWeaponObject(SceneBase* Scene) :GameObject("WeaponObject", Scene)
	{
		SetObjType(game::OBJECT_TYPE::HOMING_WEAPON);
		m_Script = CreateComponent<HomingWeaponScript>("HomingWeaponObject");
	}
	virtual void OnCollisionEnter(ColliderComponent* src)
	{
		m_Script->OnCollisionEnter(src);
	}
};


