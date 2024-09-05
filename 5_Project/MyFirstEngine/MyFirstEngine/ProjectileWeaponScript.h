#pragma once
#include "WeaponScript.h"
class ProjectileWeaponScript : public WeaponScript
{
	

public:

	ProjectileWeaponScript(GameObject* pOwner, std::string ObjName);

	virtual void Start();
	virtual void MoveMissile(float fixedDeltaTime, Vector3 moveDirection);
	virtual void FixedUpdate(float fixedDeltaTime);
	virtual void Activate(Vector3 pos);

	virtual void OnCollision(ColliderComponent* src) {};
	virtual void OnCollisionEnter(ColliderComponent* src) { m_pOwner->SetStatus(game::Status::InActive); }
	virtual void OnCollisionExit(ColliderComponent* src) {};

protected:

	AnimationComponent* m_cRender;

	float missileX = 2000.0f;	
	float missileY = 300.0f;	
	float missileWidth = 50.0f;	
	float missileHeight = 10.0f;

protected:
	float m_ActivationTime;
	bool m_IsWarningActive;

};
