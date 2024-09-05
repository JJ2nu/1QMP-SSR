#pragma once

#include "ScriptComponent.h"
#include "ResourceManager.h"
#include "InputSystem.h"
#include "Observer.h"
class PlayerBulletObject;

class PlayerScript :
    public ScriptComponent
{
public:
    virtual void Start();
    virtual void Update(float deltaTime);
    virtual void FixedUpdate(float fixedDeltaTime);
    virtual void Render();
    virtual void OnCollisionEnter(ColliderComponent* src);

private:
    //anim
    enum ObjectStatus {
        OBJECT_STATUS_IDLE,
        OBJECT_STATUS_MOVE,
        OBJECT_STATUS_ATTACK
    };
    ObjectStatus m_status = OBJECT_STATUS_IDLE;

private:
    //Anim
    void UpdateAnimation(float delta);
    void SetMotion(int index);
    void ChangeStatus(ObjectStatus status);
    void PlayerInput(float deltaTime);


public:
    //Damage
    void GetDamage(float Damage);

private:
    ColliderComponent* m_cCollider;
    AnimationComponent* m_cRender;
    TextureComponent* m_cPortalTexture;
    TextureComponent* m_cInvincibilityTexture;
    TextureComponent* m_cShieldTexture;

    float m_fMoveLimitTime;
    Vector3 m_vNextPos;

 //Bullet
    void Attack(float fixedDeltaTime);
    std::vector<PlayerBulletObject*> m_PBullet;
public:
    bool m_bEnhanceBulletFlag = false;
    int m_iCurIndex = 0;
    float m_fEnhanceDamage = 20.f;
    float m_fFireRateTime = 0;
    int m_iCurEnhanceBulletRate = 0;
    int m_iEnhanceBulletRate = 10;

//피격시 무적
    bool m_bHitInvincibility = false;
    float m_fHitInvincibility = 0.0f;

//Skill
    //Invincibility(무적)
    bool m_bInvincibility = false;
    bool m_bOnInvincibility = false;
    float m_fInvincibilityTime = 30.0f;
    float m_fInvincibilityCurTime = 30.0f;
    float m_fInvincibilityContinuousTime = 2.5f;
    
    //Shield(실드)
    bool m_bShield = false;
    int  m_iMaxShield = 1;
    int  m_iCurShield = 0;
    float m_fShieldTime = 10.0f;
    float m_fShieldCurTime = 10.0f;

    //Portal
    //두개의 값 둘다 바꾸어 주어야 한다.
    bool m_bPortal = false;
    float m_fPortalRange = 0.f;//80.f;
    

//Status
public:
    float m_fHP;
    float m_fMaxHP;
    float m_fDamage;
    float m_bHardFlag = Observer::GetInstance()->m_bHardFlag;
    float m_bIsDead = false;
    float m_fIsDead = 0.f;
public:
    PlayerScript(GameObject* pOwner, std::string ObjName);
    ~PlayerScript();
};