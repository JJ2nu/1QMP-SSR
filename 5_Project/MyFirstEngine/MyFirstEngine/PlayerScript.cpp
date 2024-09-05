#include "PlayerScript.h"
#include "WeaponScript.h"
#include "HomingWeaponScript.h"
#include "GameObject.h"
#include "PlayerBulletObject.h"
#include "SceneManager.h"
#include "FadeInFadeOutObject.h"
#include "Observer.h"
#include "PrototypeBackgroundObject.h"


PlayerScript::PlayerScript(GameObject* pOwner, std::string ObjName)
    :ScriptComponent(pOwner, ObjName), m_cCollider(nullptr), m_cRender(nullptr)
    , m_fDamage(1.0f)
    , m_PBullet{}
{
    Start();
	if (m_bHardFlag)
        m_fHP = 300.0f;
	else 
        m_fHP = 1000.0f;
	m_fMaxHP = m_fHP;
}

PlayerScript::~PlayerScript() {}

void PlayerScript::Start()
{
    //Collider
    m_cCollider = m_pOwner->CreateComponent<ColliderComponent>("PlayerColliderComponent");
    m_cCollider->m_Transform.SetScale(56, 56, 0);

    //Potal
    m_cPortalTexture = m_pOwner->CreateComponent<TextureComponent>("PortalTextureComponent");
    m_cPortalTexture->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"Portal", L"\\Image\\00. BATTLE\\PlayerSkill\\skill_portal.bmp");
    m_cPortalTexture->m_uExcep = RGB(255, 0, 255);
    m_cPortalTexture->SetStatus(game::Status::InActive);

    //Render
    m_cRender = m_pOwner->CreateComponent<AnimationComponent>("PlayerAnimationComponent");
    m_cRender->m_tAnim = ResourceManager::GetInstance()->LoadAnimationImage(L"Player", L"\\Animation\\Player\\player_anime_up_down_stop_go_back.bmp");
    ResourceManager::GetInstance()->LoadAnimationMotion(m_cRender->m_tAnim, L"\\Animation\\Player\\PlayerIdle.txt");			
    ResourceManager::GetInstance()->LoadAnimationMotion(m_cRender->m_tAnim, L"\\Animation\\Player\\PlayerUp.txt");				 
    ResourceManager::GetInstance()->LoadAnimationMotion(m_cRender->m_tAnim, L"\\Animation\\Player\\PlayerDown.txt");			
    ResourceManager::GetInstance()->LoadAnimationMotion(m_cRender->m_tAnim, L"\\Animation\\Player\\PlayerLeft.txt");			
    ResourceManager::GetInstance()->LoadAnimationMotion(m_cRender->m_tAnim, L"\\Animation\\Player\\PlayerRight.txt");			
    m_cRender->m_fAnimationDelayTime = 0.2f;
    SetMotion(0);

    //Property
    m_Transform.SetPosition(170, 400, 0);
    m_vNextPos = m_Transform.Position;


    //Invincibility
    m_cInvincibilityTexture = m_pOwner->CreateComponent<TextureComponent>("PortalTextureComponent");
    m_cInvincibilityTexture->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"Invincibility1", L"\\Image\\00. BATTLE\\PlayerSkill\\effect_invincibility_001.bmp");
    m_cInvincibilityTexture->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"Invincibility2", L"\\Image\\00. BATTLE\\PlayerSkill\\effect_invincibility_002.bmp");
    m_cInvincibilityTexture->m_uExcep = RGB(255, 0, 255);
    m_cInvincibilityTexture->SetStatus(game::Status::InActive);

    //Shield
    m_cShieldTexture = m_pOwner->CreateComponent<TextureComponent>("PortalTextureComponent");
    m_cShieldTexture->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"Shield1", L"\\Image\\00. BATTLE\\PlayerSkill\\effect_shield001.bmp");
    m_cShieldTexture->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"Shield2", L"\\Image\\00. BATTLE\\PlayerSkill\\effect_shield002.bmp");
    m_cShieldTexture->m_uExcep = RGB(255, 0, 255);
    m_cShieldTexture->SetStatus(game::Status::InActive);


    //Bullet
    SceneBase* tempSceneBase = m_pOwner->GetSceneBase();
    for (int i = 0; i < 20; i++)
    {
        PlayerBulletObject* tmpObj =  new PlayerBulletObject(tempSceneBase);
        tmpObj->SetStatus(game::Status::InActive);
        tmpObj->SetObjType(game::OBJECT_TYPE::PLAYER_WEAPON);
        tmpObj->m_Script->SetFireRate(0.2f);
        m_pOwner->AddChildGameObject(tmpObj);
        m_PBullet.push_back(tmpObj);
    }
}

//한칸의 40
void PlayerScript::Update(float deltaTime)
{
    if (m_bIsDead)
        return;

    SetMotion(0);
    HomingWeaponScript::s_vPlayerPos = m_Transform.GetPosition();
    
    PlayerInput(deltaTime);

    //애니메이션
    if ((m_cRender->m_tAnim) && m_cRender->m_iAnimationMotionIndex != -1)
        UpdateAnimation(deltaTime);
}

void PlayerScript::FixedUpdate(float fixedDeltaTime)
{
    if (m_bIsDead)
    {
        if (m_fIsDead < 0)
            Observer::GetInstance()->m_GameFlag = Observer::GetInstance()->m_CurSceneFlag;
        m_fIsDead -= fixedDeltaTime;
        return;
    }

    float Range = 10.0f;
    int moveSpeed = 10;
    
    //피격시 무적
    if (m_bHitInvincibility)
    {
        m_fHitInvincibility += fixedDeltaTime;
        if (m_fHitInvincibility > 0)
        {
            m_bHitInvincibility = false;
        }
    }

    m_Transform.Position = m_Transform.Position + (m_vNextPos - m_Transform.Position) * (fixedDeltaTime) *moveSpeed;
    if ((m_vNextPos - m_Transform.Position).Magnitude() < Range)
    {
        m_Transform.Position = m_vNextPos;
    }
    if (m_bPortal)
    {
        if (m_Transform.Position.y <= 400 - m_fPortalRange)
        {
            m_Transform.Position.y = 880;
            m_vNextPos.y = 880;
            m_cPortalTexture->SetStatus(game::Status::InActive);
            //포탈 사운드
            ResourceManager::GetInstance()->PlayMusic(game::eSoundList::Battle, 14, game::eSoundChannel::SFX_Player_Skill_Portal);
        }
        if (m_Transform.Position.y >= 880 + m_fPortalRange)
        {
            m_Transform.Position.y = 400;
            m_vNextPos.y = 400;
            m_cPortalTexture->SetStatus(game::Status::InActive);
            //포탈 사운드
            ResourceManager::GetInstance()->PlayMusic(game::eSoundList::Battle, 14, game::eSoundChannel::SFX_Player_Skill_Portal);
        }
        if (m_Transform.Position.x <= 170 - m_fPortalRange)
        {
            m_Transform.Position.x = 650;
            m_vNextPos.x = 650;
            m_cPortalTexture->SetStatus(game::Status::InActive);
            //포탈 사운드
            ResourceManager::GetInstance()->PlayMusic(game::eSoundList::Battle, 14, game::eSoundChannel::SFX_Player_Skill_Portal);
        }
        if (m_Transform.Position.x >= 650 + m_fPortalRange)
        {
            m_Transform.Position.x = 170;
            m_vNextPos.x = 170;
            m_cPortalTexture->SetStatus(game::Status::InActive);
            //포탈 사운드
            ResourceManager::GetInstance()->PlayMusic(game::eSoundList::Battle, 14, game::eSoundChannel::SFX_Player_Skill_Portal);
        }
    }

    //Attack
    if(!m_bOnInvincibility)
        Attack(fixedDeltaTime);
    
}

void PlayerScript::Attack(float fixedDeltaTime)
{
    m_fFireRateTime += fixedDeltaTime;
    if (m_fFireRateTime > m_PBullet[m_iCurIndex]->m_Script->GetFireRate())
    {
        m_fFireRateTime -= m_PBullet[m_iCurIndex]->m_Script->GetFireRate();
        m_PBullet[m_iCurIndex]->m_Script->SetDamage(m_fDamage);
        m_PBullet[m_iCurIndex]->m_Script->m_Transform.SetPosition(m_Transform.Position);
        m_PBullet[m_iCurIndex]->SetStatus(game::Status::Active);
        m_PBullet[m_iCurIndex]->m_Script->SetMoveSpeed(1000.f);
        if (m_iCurEnhanceBulletRate != m_iEnhanceBulletRate)
        {
            m_iCurEnhanceBulletRate++;
            //강화공격 차지 소리
            if(m_iCurEnhanceBulletRate == m_iEnhanceBulletRate)
                ResourceManager::GetInstance()->PlayMusic(game::eSoundList::Battle, 8, game::eSoundChannel::SFX_Player_Attack_Charge);
        }
        if (m_bEnhanceBulletFlag)
        {
            //강화공격
            m_PBullet[m_iCurIndex]->m_Script->ChangEnhanceBullet(1);
            m_PBullet[m_iCurIndex]->m_Script->SetDamage(m_fEnhanceDamage);
            m_PBullet[m_iCurIndex]->m_Script->SetMoveSpeed(1500.f);
            m_bEnhanceBulletFlag = false;
            m_iCurEnhanceBulletRate = 0;
            //강화공격소리
            ResourceManager::GetInstance()->PlayMusic(game::eSoundList::Battle, 9, game::eSoundChannel::SFX_Player_Attack_Charge);
        }
        else
        {
            //일반공격
            m_PBullet[m_iCurIndex]->m_Script->ChangEnhanceBullet(0);
            //일반공격 소리
            ResourceManager::GetInstance()->PlayMusic(game::eSoundList::Battle, 10, game::eSoundChannel::SFX_Player_Attack);
        }
        m_iCurIndex = (m_iCurIndex + 1) % 20;
    }
}


void PlayerScript::Render()
{
}

void PlayerScript::OnCollisionEnter(ColliderComponent* src)
{
    if (m_bIsDead)
        return;
    GameObject* HitObject = src->GetOwner();
    if (HitObject->GetObjType() == game::OBJECT_TYPE::ENEMY_WEAPON || HitObject->GetObjType() == game::OBJECT_TYPE::HOMING_WEAPON)
    {
        if (!m_bHitInvincibility)
        {
            m_fHitInvincibility = -0.5f;
            m_bHitInvincibility = true;
        }
        else
            return;
        if (m_iCurShield)
        {
            //실드 피격 사운드
            ResourceManager::GetInstance()->PlayMusic(game::eSoundList::Battle, 15, game::eSoundChannel::SFX_Player_Skill_Shield);
            m_iCurShield--;
            return;
        }
        WeaponScript* hitWeapon = HitObject->GetComponent<WeaponScript>();
        GetDamage(100.0f);
        Observer::GetInstance()->GetBackground()->m_Script->ShakeOn();
    }
}

void PlayerScript::UpdateAnimation(float delta)
{

    if (input::KEYTAP(input::KEY::W)||input::KEYHOLD(input::KEY::W))
    {
        SetMotion(1);
    }
    else if (input::KEYTAP(input::KEY::S) || input::KEYHOLD(input::KEY::S))
    {
        SetMotion(2);

    }
    else if (input::KEYTAP(input::KEY::A) || input::KEYHOLD(input::KEY::A))
    {
        SetMotion(4);

    }
    else if (input::KEYTAP(input::KEY::D) || input::KEYHOLD(input::KEY::D))
    {
        SetMotion(3);

    }



    int frameCount = m_cRender->m_tAnim->m_motions[m_cRender->m_iAnimationMotionIndex].FrameCount;
    bool isLoop = m_cRender->m_tAnim->m_motions[m_cRender->m_iAnimationMotionIndex].IsLoop;

    // 누적된 시간으로 보여줄 프레임 찾기
    m_cRender->m_fAnimationAccTime += delta;
    while (m_cRender->m_fAnimationAccTime > m_cRender->m_fAnimationDelayTime)
    {
        m_cRender->m_fAnimationAccTime -= m_cRender->m_fAnimationDelayTime;

        if (m_cRender->m_iAnimationFrameIndex < frameCount)
            m_cRender->m_iAnimationFrameIndex++;
    }

    // 끝 프레임 넘어갔을때 처리
    if (m_cRender->m_iAnimationFrameIndex >= frameCount)
    {
        if (isLoop)
        {
            m_cRender->m_iAnimationFrameIndex = 0;
        }
        else
        {
            if (m_status == ObjectStatus::OBJECT_STATUS_ATTACK)
                ChangeStatus(ObjectStatus::OBJECT_STATUS_IDLE);
        }
    }
}

void PlayerScript::SetMotion(int index)
{
    if (m_cRender->m_tAnim == nullptr)
        return;

    assert(m_cRender->m_tAnim->m_motionCount > index);
    m_cRender->m_iAnimationMotionIndex = index;
    m_cRender->m_iAnimationFrameIndex = 0;
    m_cRender->m_fAnimationAccTime = 0.0f;
}

void PlayerScript::ChangeStatus(ObjectStatus status)
{
    if (m_status == status)
        return;

    // End 이전 상태를 끝내면서 처리할 내용을 작성
    switch (m_status)
    {
    case OBJECT_STATUS_IDLE:
        break;
    case OBJECT_STATUS_MOVE:
        break;
    case OBJECT_STATUS_ATTACK:
        break;
    default:
        break;
    }


    m_status = status;

    // Begin 새로운 상태가 시작될때 처리할 내용을 작성
    switch (m_status)
    {
    case ObjectStatus::OBJECT_STATUS_IDLE:
        SetMotion(ObjectStatus::OBJECT_STATUS_IDLE);
        break;
    case ObjectStatus::OBJECT_STATUS_MOVE:
        SetMotion(ObjectStatus::OBJECT_STATUS_MOVE);
        break;
    case ObjectStatus::OBJECT_STATUS_ATTACK:
        SetMotion(ObjectStatus::OBJECT_STATUS_ATTACK);
        break;
    }
}

void PlayerScript::GetDamage(float Damage)
{
    m_fHP -= Damage;
    m_fHP -= 34;
    // 플레이어 피격 사운드
    ResourceManager::GetInstance()->PlayMusic(game::eSoundList::Battle, 12, game::eSoundChannel::SFX_Player_Hitted);

    if (m_fHP <= 0)
    {
        m_fHP = 0;
        // 플레이어 사망 사운드
        ResourceManager::GetInstance()->PlayMusic(game::eSoundList::Battle, 11, game::eSoundChannel::SFX_Player_Dead);
        m_bIsDead = true;
        m_fIsDead = 8.0f;
    }
}

void PlayerScript::PlayerInput(float deltaTime)
{
    float interval = 80.0f;
    float KeyDelay = 0.08f;
    static float temp = 0;

    temp += deltaTime;

    if (m_bInvincibility)
    {
        m_fInvincibilityCurTime += deltaTime;
        if (input::KEYTAP(input::KEY::SPACE) && m_fInvincibilityCurTime > m_fInvincibilityTime)
        {
            m_bOnInvincibility = true;
            m_fInvincibilityCurTime = 0.f;
            //무적 이미지 변경
            m_cRender->SetStatus(game::Status::InActive);
            m_cInvincibilityTexture->SetStatus(game::Status::Active);
            //무적 사운드 재생
            ResourceManager::GetInstance()->PlayMusic(game::eSoundList::Battle, 20, game::eSoundChannel::SFX_Player_Skill_Invincible);
        }
        else if(m_bOnInvincibility)
        {
            m_fInvincibilityCurTime += deltaTime;
            m_cInvincibilityTexture->m_uRenderIndex = (m_cInvincibilityTexture->m_uRenderIndex + 1) % 2;
            if (m_fInvincibilityCurTime > m_fInvincibilityContinuousTime)
            {
                m_bOnInvincibility = false;
                m_fInvincibilityCurTime = 0.f;
                //무적 이미지 해제
                m_cRender->SetStatus(game::Status::Active);
                m_cInvincibilityTexture->SetStatus(game::Status::InActive);
            }
            return;
        }
    }
    if (m_bShield)
    {
        m_fShieldCurTime += deltaTime;
        if (m_iMaxShield == m_iCurShield)
        {
             m_fShieldCurTime = 0.f;
        }
        else if (m_fShieldCurTime > m_fShieldTime)
        {
            //실드 재생 사운드
            ResourceManager::GetInstance()->PlayMusic(game::eSoundList::Battle, 16, game::eSoundChannel::SFX_Player_Skill_Shield);
            m_iCurShield++;
            m_fShieldCurTime -= m_fShieldTime;
        }

        if (m_iCurShield > 0)
        {
            //실드 이미지
            m_cShieldTexture->SetStatus(game::Status::Active);
            m_cShieldTexture->m_uRenderIndex = (m_cShieldTexture->m_uRenderIndex + 1) % 2;
        }
        else
        {
            //그냥
            m_cShieldTexture->SetStatus(game::Status::InActive);
        }
    }

    while (temp > KeyDelay)
    {
        temp -= KeyDelay;
        if (input::KEYHOLD(input::KEY::W))
        {
            if (m_vNextPos.y > 400 - m_fPortalRange)
                m_vNextPos.y -= interval;
            if (m_bPortal && m_vNextPos.y < 400)
            {
                m_cPortalTexture->SetStatus(game::Status::Active);
                m_cPortalTexture->m_vOffset = Vector3(0, m_vNextPos.y - m_Transform.Position.y, 0);
            }
            else
                m_cPortalTexture->SetStatus(game::Status::InActive);
        }
        else if (input::KEYHOLD(input::KEY::S))
        {
            if (m_vNextPos.y < 880 + m_fPortalRange)
                m_vNextPos.y += interval;
            if (m_bPortal && m_vNextPos.y > 880)
            {
                m_cPortalTexture->SetStatus(game::Status::Active);
                m_cPortalTexture->m_vOffset = Vector3(0, m_vNextPos.y - m_Transform.Position.y, 0);
            }
            else
                m_cPortalTexture->SetStatus(game::Status::InActive);
        }
        else if (input::KEYHOLD(input::KEY::A))
        {
            if (m_vNextPos.x > 170 - m_fPortalRange)
                m_vNextPos.x -= interval;
            if (m_bPortal && m_vNextPos.x < 170)
            {
                m_cPortalTexture->SetStatus(game::Status::Active);
                m_cPortalTexture->m_vOffset = Vector3(m_vNextPos.x - m_Transform.Position.x, 0, 0);
            }
            else
                m_cPortalTexture->SetStatus(game::Status::InActive);
        }
        else if (input::KEYHOLD(input::KEY::D))
        {
            if (m_vNextPos.x < 650 + m_fPortalRange)
                m_vNextPos.x += interval;
            if (m_bPortal && m_vNextPos.x > 650)
            {
                m_cPortalTexture->SetStatus(game::Status::Active);
                m_cPortalTexture->m_vOffset = Vector3(m_vNextPos.x - m_Transform.Position.x, 0, 0);
            }
            else
                m_cPortalTexture->SetStatus(game::Status::InActive);
        }
    }

    //Portal
    if (m_bPortal && m_cPortalTexture->GetStatus() == game::Status::Active)
    {
        if (m_vNextPos.y < 400)
        {
            m_cPortalTexture->m_vOffset = Vector3(0, m_vNextPos.y - m_Transform.Position.y, 0);
        }
        if (m_vNextPos.y > 880)
        {
            m_cPortalTexture->m_vOffset = Vector3(0, m_vNextPos.y - m_Transform.Position.y, 0);
        }
        if (m_vNextPos.x < 170)
        {
            m_cPortalTexture->m_vOffset = Vector3(m_vNextPos.x - m_Transform.Position.x, 0, 0);
        }
        if (m_vNextPos.x > 650)
        {
            m_cPortalTexture->m_vOffset = Vector3(m_vNextPos.x - m_Transform.Position.x, 0, 0);
        }
    }

    if (input::KEYTAP(input::KEY::R_MOUSE_BUTTON))
    {
        if (m_iEnhanceBulletRate == m_iCurEnhanceBulletRate)
        {
            m_bEnhanceBulletFlag = true;
        }
    }


    if (DevelopKey)
    {
        //Player 무적 -> 실드량 1000개
        if (input::KEYTAP(input::KEY::L))
        {
            m_bShield = true;
            m_iCurShield = 1000;
        }

        //Player 데미지 50배
        if (input::KEYTAP(input::KEY::K))
        {
            m_iEnhanceBulletRate = 2;
            m_iCurEnhanceBulletRate = 0;
            m_fEnhanceDamage = 40.f;
        }
        if (input::KEYTAP(input::KEY::J))
        {
            m_iEnhanceBulletRate = 10;
            m_iCurEnhanceBulletRate = 0;
            m_fEnhanceDamage = 20.f;
        }
    }
}
