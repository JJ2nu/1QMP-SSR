#pragma once
#include "GameObject.h"
#include "ProjectileWeaponScript.h"

class ProjectileWeaponObject : public GameObject
{
private:
	ProjectileWeaponScript* m_Script;
public:
	ProjectileWeaponObject(SceneBase* Scene) :GameObject("WeaponObject", Scene)
	{
		SetObjType(game::OBJECT_TYPE::WEAPON);
		m_Script = CreateComponent<ProjectileWeaponScript>("ProjectileWeaponObject");
	}
	virtual void OnCollisionEnter(ColliderComponent* src)
	{
		m_Script->OnCollisionEnter(src);
	}
};

