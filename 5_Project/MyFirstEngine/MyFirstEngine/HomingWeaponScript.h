#pragma once
#include "WeaponScript.h"
class HomingWeaponScript :
	public WeaponScript
{
public:
	static Vector3 s_vPlayerPos;
	static int s_eSoundChannel;
private:
	Transform m_TtargetPos;
	AnimationComponent* m_cRender;
	Vector3 m_vPrevVector;
	float m_fSinValue = 0.0f;

public:
	HomingWeaponScript(GameObject* pOwner, std::string ObjName);
	void Start();
	void FixedUpdate(float fixedDeltaTime) ;
	void Update(float deltaTime);
	void Render() {};
	void Reset();
	
	virtual void OnCollision(ColliderComponent* src) {}
	virtual void OnCollisionEnter(ColliderComponent* src) {	m_pOwner->SetStatus(game::Status::InActive); }
	virtual void OnCollisionExit(ColliderComponent* src) {}

};

