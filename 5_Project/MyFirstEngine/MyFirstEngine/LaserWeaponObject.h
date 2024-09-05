#pragma once
#include "ButtonGameObject.h"
#include "LaserWeaponScript.h"


class LaserWeaponObject : public ButtonGameObject
{
public:
	LaserWeaponScript* m_Script;

public:
	LaserWeaponObject(SceneBase* Scene) : ButtonGameObject("WeaponObject", Scene)
	{
		SetObjType(game::OBJECT_TYPE::ENEMY_WEAPON);
		m_Script = CreateComponent<LaserWeaponScript>("LaserWeaponScript");

		//컬라이더 크기 설정
		m_vButtonScale = Vector3(400, 500, 0);
	}

	void OnClick() override
	{
		m_Script->OnHit();
	}
	//virtual void OnCollision(ColliderComponent* src)
	//{
	//	m_Script->OnCollision(src);
	//}
	
};

