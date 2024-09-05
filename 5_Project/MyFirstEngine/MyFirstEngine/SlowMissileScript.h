#pragma once
#include "ProjectileWeaponScript.h"


class SlowMissileScript : public ProjectileWeaponScript
{
    static int s_eSoundChannel;
public:
    float animationTimer = 0.0f;
    SlowMissileScript(GameObject* pOwner, std::string ObjName);
    void Start() override;
    void FixedUpdate(float fixedDeltaTime) override;

    void MoveMissile(float fixedDeltaTime, Vector3 moveDirection) override;
    void Activate();
	void OnCollisionEnter(ColliderComponent* src) {	m_pOwner->SetStatus(game::Status::InActive); }
    void MissileMode();
    void AnimationUpdate(float fixedDeltaTime);
};

