#pragma once
#include "GameObject.h"
#include "AreaWeaponScript.h"

// 게임 오브젝트를 상속 받는다
class AreaWeaponObject : public GameObject
{

private:
	AreaWeaponScript* m_Script;

public:
	AreaWeaponObject(SceneBase* Scene) : GameObject("WeaponObject", Scene)
	{
		SetObjType(game::OBJECT_TYPE::WEAPON);
		m_Script = CreateComponent<AreaWeaponScript>("AreaWeaponObject");
	}

	virtual void OnCollisionEnter(ColliderComponent* src)
	{
		m_Script->OnCollisionEnter(src);
	}
};

