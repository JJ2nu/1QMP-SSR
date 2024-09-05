#pragma once
#include "GameObject.h"
#include "Define.h"
#include "TextureComponent.h"
class Weapon :  public GameObject
{
protected:
	float m_fSpeed;
	float m_fSpawnInterval;
	float m_fDamage;

public:
	Weapon(SceneBase* Scene) : GameObject("Weapon", Scene)
	{
		SetObjType( game::OBJECT_TYPE::WEAPON );
		CreateComponent<ColliderComponent>("WeaponColliderComponent");
		CreateComponent<TextureComponent>("WeaponTextureComponent");
	}
	virtual ~Weapon() {};

	//float getSpeed()
	//{
	//	return m_fSpeed;
	//}
	//float getSpawnInterval()
	//{
	//	return m_fSpawnInterval;
	//}
	//float getDamage()
	//{
	//	return m_fDamage;
	//}
	//void setSpeed(float speed)
	//{
	//	m_fSpeed = speed;
	//}
	//void setSpawnInterval(float spawninterval)
	//{
	//	m_fSpawnInterval = spawninterval;
	//}
	//void setDamage(float damage)
	//{
	//	m_fDamage = damage;
	//}
};

