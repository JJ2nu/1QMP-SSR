#include "SupportingMissileScript.h"
#include "ResourceManager.h"

int SupportingMissileScript::s_eExplosionSoundChannel = 23;

SupportingMissileScript::SupportingMissileScript(GameObject* pOwner, std::string ObjName)
    : ProjectileWeaponScript(pOwner, std::move(ObjName))
    ,m_vPrevVector(-1, 0, 0)
{
    Start();
}

void SupportingMissileScript::Start()
{
    m_TexComp = m_pOwner->CreateComponent<TextureComponent>("SupportingMissileTextureComponent");
    m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"Explosion1", L"\\Animation\\Missile\\SupportWeapon\\Effect_Explosion_Normal_01.bmp"); 
    m_TexComp->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"Explosion2", L"\\Animation\\Missile\\SupportWeapon\\Effect_Explosion_Normal_02.bmp"); 
    m_TexComp->m_tTexture[2] = ResourceManager::GetInstance()->LoadTexture(L"Explosion3", L"\\Animation\\Missile\\SupportWeapon\\Effect_Explosion_Normal_03.bmp"); 
    m_TexComp->m_tTexture[3] = ResourceManager::GetInstance()->LoadTexture(L"Explosion4", L"\\Animation\\Missile\\SupportWeapon\\Effect_Explosion_Normal_04.bmp");
    m_TexComp->m_tTexture[4] = ResourceManager::GetInstance()->LoadTexture(L"Explosion5", L"\\Animation\\Missile\\SupportWeapon\\Effect_Explosion_Normal_05.bmp");
    m_TexComp->m_tTexture[5] = ResourceManager::GetInstance()->LoadTexture(L"Explosion6", L"\\Animation\\Missile\\SupportWeapon\\Effect_Explosion_Normal_06.bmp");
    m_TexComp->m_tTexture[6] = ResourceManager::GetInstance()->LoadTexture(L"Explosion7", L"\\Animation\\Missile\\SupportWeapon\\Effect_Explosion_Normal_07.bmp");
    m_TexComp->m_tTexture[7] = ResourceManager::GetInstance()->LoadTexture(L"Explosion8", L"\\Animation\\Missile\\SupportWeapon\\Effect_Explosion_Normal_08.bmp");
    m_TexComp->m_tTexture[8] = ResourceManager::GetInstance()->LoadTexture(L"Explosion9", L"\\Animation\\Missile\\SupportWeapon\\Effect_Explosion_Normal_09.bmp");
    m_TexComp->m_uRenderIndex = 0;
    m_TexComp->m_uExcep = RGB(255, 0, 255);
    m_TexComp->m_iRenderFlag = 0;
    m_TexComp->SetStatus(game::Status::InActive);
    
    m_cRender = m_pOwner->CreateComponent<AnimationComponent>("SupportingMissileAnimationComponent");
    m_cRender->m_tAnim = ResourceManager::GetInstance()->LoadAnimationImage(L"SupportingMissileAnim", L"\\Animation\\Missile\\SupportWeapon\\SupportingWeapon.bmp");
    ResourceManager::GetInstance()->LoadAnimationMotion(m_cRender->m_tAnim, L"\\Animation\\Missile\\SupportWeapon\\supportingweapon.txt");
    m_cRender->m_fAnimationDelayTime = 0.1f;
    m_cRender->m_iAnimationMotionIndex = 0;
    m_cRender->m_iAnimationFrameIndex = 0;
    m_cRender->m_fAnimationAccTime = 0.0f;
    m_cRender->m_uExcept = RGB(255, 0, 255);
    m_cRender->SetStatus(game::Status::Active);

    m_ColComp = m_pOwner->CreateComponent<ColliderComponent>("SupportingMissileColliderComponent");
    m_ColComp->m_Transform.SetScale(128.f, 64.f, 0);
    m_ColComp->SetStatus(game::Status::Active);
    m_fMoveSpeed = 1400.0f;

    m_fDamage = 1.0f;


}

void SupportingMissileScript::MoveMissile(float fixedDeltaTime, Vector3 moveDirection)
{
    m_vPrevPos = m_Transform.GetPosition();
    m_fSinValue += fixedDeltaTime;
    Vector3 dirVector = Vector3(1650.f, 560.f, 0);
    Vector3 tmp = (dirVector - m_Transform.Position).Nomalization() * fixedDeltaTime * m_fMoveSpeed;
    if ((dirVector - m_Transform.Position).Magnitude() > 600.f)
    {
        m_pOwner->m_Transform.Position.x += tmp.x;
        m_pOwner->m_Transform.Position.y = sin(m_fSinValue/3) * 600.f + 600.f;
    }
    else
    {
        m_pOwner->m_Transform.Position.x += tmp.x;
        m_pOwner->m_Transform.Position.y += tmp.y;
    }
    m_vLookVec = m_Transform.GetPosition() - m_vPrevPos;
}

void SupportingMissileScript::FixedUpdate(float fixedDeltaTime)
{
    
   
    Vector3 dirVector1 = Vector3(1550.f, 560.f, 0);
    if ((dirVector1 - m_Transform.Position).Magnitude() > 600.f)
    {
        dirVector1 = m_vLookVec;
    }
    else
    {
        if (m_Transform.Position.y > 560.0f)
        {
            dirVector1 = dirVector1 - m_Transform.Position;
            m_cRender->m_fRotate = Vector3::Angle2D(m_vPrevVector, dirVector1);
            if (m_Transform.Position.y > 560.0f)
                m_cRender->m_fRotate += 180.f;

        }
        else
        {
            dirVector1 = m_Transform.Position- dirVector1;
            m_cRender->m_fRotate = Vector3::Angle2D(m_vPrevVector, dirVector1);

        }
    }

   

}

void SupportingMissileScript::Update(float DeltaTime)
{
    AnimationUpdate(DeltaTime);
    MoveMissile(DeltaTime, Vector3(1, 0, 0));
}



void SupportingMissileScript::Activate()
{
    m_pOwner->SetStatus(game::Status::Active);
    MissileMode();
}

void SupportingMissileScript::MissileMode()
{
    m_ColComp->SetStatus(game::Status::Active);
    m_cRender->SetStatus(game::Status::Active);
    m_TexComp->SetStatus(game::Status::InActive);
    m_cRender->m_iAnimationFrameIndex = 0;
    m_bExplosionFlag = false;
    m_fMoveSpeed = 1000.0f;
}

void SupportingMissileScript::ExplodeMode()
{
    m_ColComp->SetStatus(game::Status::InActive);
    m_cRender->SetStatus(game::Status::InActive);
    m_TexComp->SetStatus(game::Status::Active);
    m_TexComp->m_uRenderIndex = 0;
    m_bExplosionFlag = true;
    m_fMoveSpeed = 0.0f;

    //플레이어 지원 미사일 폭발 사운드
    ResourceManager::GetInstance()->PlayMusic(game::eSoundList::Battle, 22, game::eSoundChannel::SFX_Support_Missile);
}

void SupportingMissileScript::AnimationUpdate(float fixedDeltaTime)
{
    animationTimer += fixedDeltaTime;
    if (animationTimer >= 0.15f)
    {
        if (m_bExplosionFlag)
        {
            m_TexComp->m_uRenderIndex = (m_TexComp->m_uRenderIndex + 1) % 9;
            if (m_TexComp->m_uRenderIndex >= 8)
            {
                m_pOwner->SetStatus(game::Status::InActive);
                return;
            }
        }
        else
        {
            m_cRender->m_iAnimationFrameIndex = (m_cRender->m_iAnimationFrameIndex + 1) % 3;
        }
        animationTimer -= 0.15f;
    }
    


}
