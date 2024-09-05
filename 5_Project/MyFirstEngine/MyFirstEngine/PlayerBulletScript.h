#pragma once
#include "WeaponScript.h"
class PlayerBulletScript :
	public WeaponScript
{

public:
	PlayerBulletScript(GameObject* pOwner, std::string ObjName);

	virtual void Start();
	void MoveMissileLeft(float fixedDeltaTime);
	void ChangEnhanceBullet(int i);
	virtual void FixedUpdate(float fixedDeltaTime);

	virtual void OnCollision(ColliderComponent* src) {};
	virtual void OnCollisionEnter(ColliderComponent* src)
	{
		m_pOwner->SetStatus(game::Status::InActive);
	};
	virtual void OnCollisionExit(ColliderComponent* src) {};
private:
	float missileWidth = 50.0f;		// 미사일의 가로
	float missileHeight = 10.0f;	// 미사일의 세로
};
