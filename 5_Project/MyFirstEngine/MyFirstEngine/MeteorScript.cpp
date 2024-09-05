#include "MeteorScript.h"
#include "ResourceManager.h"

MeteorScript::MeteorScript(GameObject* pOwner, std::string ObjName)
    : ProjectileWeaponScript(pOwner, std::move(ObjName))
{
    Start();
}

void MeteorScript::Start()
{
    m_TexComp = m_pOwner->CreateComponent<TextureComponent>("MeteorTextureComponent");
    m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"MeteorWarning", L"\\Animation\\Missile\\Meteor\\Warning_Vertical.bmp");
    m_TexComp->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"Meteor1", L"\\Animation\\Missile\\Meteor\\meteor_001.bmp");
    m_TexComp->m_tTexture[2] = ResourceManager::GetInstance()->LoadTexture(L"Meteor2", L"\\Animation\\Missile\\Meteor\\meteor_002.bmp");
    m_TexComp->m_tTexture[3] = ResourceManager::GetInstance()->LoadTexture(L"Meteor3", L"\\Animation\\Missile\\Meteor\\meteor_003.bmp");
    m_TexComp->m_uRenderIndex = 0;
    m_TexComp->m_uExcep = RGB(255, 0, 255);
    m_TexComp->m_iRenderFlag = 0;
    m_TexComp->SetStatus(game::Status::Active);

    m_ColComp = m_pOwner->CreateComponent<ColliderComponent>("MeteorColliderComponent");

    m_ColComp->m_Transform.SetScale(80, 80, 0);
    m_ColComp->SetStatus(game::Status::InActive);
    m_IsWarningActive = true;
    m_ActivationTime = 2.0f;
    m_fMoveSpeed = 800.0f;

}

void MeteorScript::MoveMissile(float fixedDeltaTime, Vector3 moveDirection)
{
    m_Transform.Position += moveDirection * m_fMoveSpeed * fixedDeltaTime;
    if (m_Transform.Position.x + missileWidth < 0 || m_Transform.Position.y + missileHeight > ScreenHeight)
    {
        m_pOwner->SetStatus(game::Status::InActive);
        m_IsWarningActive = false;
    }
    AnimationUpdate(fixedDeltaTime);
}

void MeteorScript::FixedUpdate(float fixedDeltaTime)
{
    if (m_IsWarningActive)
    {
        m_ActivationTime -= fixedDeltaTime;
        if (m_ActivationTime <= 0)
        {
            MissileMode();
            m_IsWarningActive = false;
        }
        return;
    }

    MoveMissile(fixedDeltaTime, Vector3(0, 1, 0));

}

void MeteorScript::Activate()
{
    m_pOwner->SetStatus(game::Status::Active);
    WarningMode();
    m_ActivationTime = 2.0f;
    m_IsWarningActive = true;
}
void MeteorScript::WarningMode()
{
    m_TexComp->m_iRenderFlag = 2;
    m_TexComp->m_uAlpha = 128;
    m_TexComp->m_uRenderIndex = 0;
    Vector3 temp = m_Transform.GetPosition();
    temp.y = 640;
    m_Transform.SetPosition(temp);
    m_ColComp->SetStatus(game::Status::InActive);

    //메테오 공격 경고 소리
    ResourceManager::GetInstance()->PlayMusic(game::eSoundList::Battle, 19, game::eSoundChannel::SFX_Warning_Meteo);
}
void MeteorScript::MissileMode()
{
    if (m_TexComp->m_uRenderIndex == 0) m_TexComp->m_uRenderIndex = 1;
    m_TexComp->m_iRenderFlag = 0;
    Vector3 temp = m_Transform.GetPosition();
    temp.y = 0;
    m_Transform.SetPosition(temp);
    m_ColComp->SetStatus(game::Status::Active);
}

void MeteorScript::AnimationUpdate(float fixedDeltaTime)
{
    animationTimer += fixedDeltaTime;
    if (animationTimer >= 0.2f)
    {
        m_TexComp->m_uRenderIndex = (m_TexComp->m_uRenderIndex + 1) % 3 + 1;
        animationTimer -= 0.2f;

    }
}
