#pragma once
#include "ProjectileWeaponScript.h"
#include "AnimationComponent.h"
class SupportingMissileScript :
    public ProjectileWeaponScript
{
    static int s_eExplosionSoundChannel;
public:
    float animationTimer = 0.0f;
    bool m_bExplosionFlag = false;
    float m_fSinValue= rand()%360;
    AnimationComponent* m_cRender;
    Vector3 m_vPrevVector;
    Vector3 m_vPrevPos = m_Transform.GetPosition();
    Vector3 m_vLookVec = m_Transform.GetPosition()-m_vPrevPos;
    SupportingMissileScript(GameObject* pOwner, std::string ObjName);
    void Start() override;
    void FixedUpdate(float fixedDeltaTime) override;
    void Update(float DeltaTime);
    void MoveMissile(float fixedDeltaTime, Vector3 moveDirection) override;
    void Activate();
    void MissileMode();
    void ExplodeMode();
    void OnCollisionEnter(ColliderComponent* src) 
    {
        ExplodeMode();
        //m_pOwner->SetStatus(game::Status::InActive); 
    };
    void AnimationUpdate(float fixedDeltaTime);
};

