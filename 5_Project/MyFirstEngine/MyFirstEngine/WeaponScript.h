#pragma once
#include "ScriptComponent.h"
class WeaponScript : public ScriptComponent
{

public:
	//Get & Set
	float GetMoveSpeed() { return m_fMoveSpeed; }
	void SetMoveSpeed(float MoveSpeed) { m_fMoveSpeed = MoveSpeed; }
	float GetFireRate() { return m_fFireRate; }
	void SetFireRate(float FireRate) { m_fFireRate = FireRate; }
	float GetDamage() { return m_fDamage; }
	void SetDamage(float Damage) { m_fDamage = Damage; }


	//IScript
	virtual void Start();
	virtual void FixedUpdate(float fixedDeltaTime);
	virtual void Update(float deltaTime);
	virtual void Renders() {};
	virtual void Activate(Vector3 pos);


	//ICollider
	virtual void OnCollision(ColliderComponent* src);
	void OnCollisionEnter(ColliderComponent* src) {};
	virtual void OnCollisionExit(ColliderComponent* src) {};

protected:
	float m_fMoveSpeed = 0.0f;
	float m_fFireRate = 0.0f;
	float m_fDamage = 100.0f;
	ColliderComponent* m_ColComp;
	TextureComponent* m_TexComp;


public:
	WeaponScript(GameObject* pOwner, std::string ObjName);

};

