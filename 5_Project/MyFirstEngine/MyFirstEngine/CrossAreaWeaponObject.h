#pragma once
#include "GameObject.h"
#include "CrossAreaWeaponScript.h"

class CrossAreaWeaponObject : public GameObject
{
public:
	CrossAreaWeaponScript* m_Script;

public:
	CrossAreaWeaponObject(SceneBase* Scene) : GameObject("WeaponObject", Scene)
	{
		SetObjType(game::OBJECT_TYPE::ENEMY_WEAPON);
		m_Script = CreateComponent<CrossAreaWeaponScript>("CrossAreaWeaponScript");
	}
	virtual void OnCollisionEnter(ColliderComponent* src)
	{
		m_Script->OnCollisionEnter(src);
	}
	

};

