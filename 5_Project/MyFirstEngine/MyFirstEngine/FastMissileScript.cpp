#include "FastMissileScript.h"
#include "ResourceManager.h"

int FastMissileScript::s_eSoundChannel = 13;

FastMissileScript::FastMissileScript(GameObject* pOwner, std::string ObjName)
    : ProjectileWeaponScript(pOwner, std::move(ObjName))
{
    Start();
}

void FastMissileScript::Start()
{
    m_TexComp = m_pOwner->CreateComponent<TextureComponent>("FastMissileTextureComponent");
    m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"FastMissile1", L"\\Animation\\Missile\\FastMissile\\fast_missile_001.bmp");
    m_TexComp->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"FastMissile2", L"\\Animation\\Missile\\FastMissile\\fast_missile_002.bmp");
    m_TexComp->m_tTexture[2] = ResourceManager::GetInstance()->LoadTexture(L"FastMissile3", L"\\Animation\\Missile\\FastMissile\\fast_missile_003.bmp");
    m_TexComp->m_uRenderIndex = 0;
    m_TexComp->m_uExcep = RGB(255, 0, 255);
    m_TexComp->m_iRenderFlag = 0;
    m_TexComp->SetStatus(game::Status::Active);

    m_ColComp = m_pOwner->CreateComponent<ColliderComponent>("FastMissileColliderComponent");
    m_ColComp->m_Transform.SetScale(128.f, 64.f, 0);
    m_ColComp->SetStatus(game::Status::InActive);
    m_IsWarningActive = true;
    m_ActivationTime = 2.0f;
    m_fMoveSpeed = 800.0f;

}

void FastMissileScript::MoveMissile(float fixedDeltaTime, Vector3 moveDirection)
{
    m_Transform.Position += moveDirection * m_fMoveSpeed * fixedDeltaTime;
    if (m_Transform.Position.x + missileWidth < 0 || m_Transform.Position.y + missileHeight > ScreenHeight)
    {
        m_pOwner->SetStatus(game::Status::InActive);
        m_IsWarningActive = false;
    }
    AnimationUpdate(fixedDeltaTime);
}

void FastMissileScript::FixedUpdate(float fixedDeltaTime)
{
     MoveMissile(fixedDeltaTime, Vector3(-1, 0, 0));
}

void FastMissileScript::Activate()
{
    m_pOwner->SetStatus(game::Status::Active);
    MissileMode();
}
void FastMissileScript::MissileMode()
{
    if (m_TexComp->m_uRenderIndex == 0) m_TexComp->m_uRenderIndex = 1;
    m_TexComp->m_iRenderFlag = 0;

    Vector3 temp = m_Transform.GetPosition();
    temp.x = 1600;
    m_Transform.SetPosition(temp);
    m_ColComp->SetStatus(game::Status::Active);
    m_IsWarningActive = false;

    //고속 미사일 발사
    s_eSoundChannel = (s_eSoundChannel + 1) % 2 + 13;
    ResourceManager::GetInstance()->PlayMusic(game::eSoundList::Battle, 4, static_cast<game::eSoundChannel>(s_eSoundChannel));
}

void FastMissileScript::AnimationUpdate(float fixedDeltaTime)
{
    animationTimer += fixedDeltaTime;
    if (animationTimer >= 0.2f)
    {
        m_TexComp->m_uRenderIndex = (m_TexComp->m_uRenderIndex + 1) % 3;
        animationTimer -= 0.2f;

    }
}
