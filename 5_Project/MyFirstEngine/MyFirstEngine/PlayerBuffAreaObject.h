#pragma once
#include "GameObject.h"
#include "PlayerBuffAreaScript.h"

class PlayerBuffAreaObject : public GameObject
{

private:
	PlayerBuffAreaScript* m_Script;

public:
	PlayerBuffAreaObject(SceneBase* Scene) : GameObject("WeaponObject", Scene)
	{
		SetObjType(game::OBJECT_TYPE::ITEM);
		m_Script = CreateComponent<PlayerBuffAreaScript>("PlayerBuffAreaWeaponScript");
	}

	virtual void OnCollisionEnter(ColliderComponent* src)
	{
		m_Script->OnCollisionEnter(src);
	}
};

