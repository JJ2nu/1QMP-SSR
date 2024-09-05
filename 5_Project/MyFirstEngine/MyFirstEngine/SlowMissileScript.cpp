#include "SlowMissileScript.h"
#include "ResourceManager.h"

int SlowMissileScript::s_eSoundChannel = 11;

SlowMissileScript::SlowMissileScript(GameObject* pOwner, std::string ObjName)
    : ProjectileWeaponScript(pOwner, std::move(ObjName))
{
    Start();
}

void SlowMissileScript::Start()
{
    m_TexComp = m_pOwner->CreateComponent<TextureComponent>("SlowMissileTextureComponent");
    //m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"SlowMissileWarning", L"\\Animation\\Missile\\SlowMissile\\Warning_Horiziontal.bmp");
    m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"SlowMissile1", L"\\Animation\\Missile\\SlowMissile\\slow_missile_001.bmp");
    m_TexComp->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"SlowMissile2", L"\\Animation\\Missile\\SlowMissile\\slow_missile_002.bmp");
    m_TexComp->m_tTexture[2] = ResourceManager::GetInstance()->LoadTexture(L"SlowMissile3", L"\\Animation\\Missile\\SlowMissile\\slow_missile_003.bmp");
    m_TexComp->m_uRenderIndex = 0;
    m_TexComp->m_uExcep = RGB(255, 0, 255);
    m_TexComp->m_iRenderFlag = 0;
    m_TexComp->SetStatus(game::Status::Active);

    m_ColComp = m_pOwner->CreateComponent<ColliderComponent>("SlowMissileColliderComponent");
    m_ColComp->SetStatus(game::Status::Active);
    m_ColComp->m_Transform.SetScale(128, 64, 0);
    m_fMoveSpeed = 160.0f;

}

void SlowMissileScript::MoveMissile(float fixedDeltaTime, Vector3 moveDirection)
{
    m_Transform.Position += moveDirection * m_fMoveSpeed * fixedDeltaTime;
    if (m_Transform.Position.x + missileWidth < 0 || m_Transform.Position.y + missileHeight > ScreenHeight)
    {
        m_pOwner->SetStatus(game::Status::InActive);
    }
    AnimationUpdate(fixedDeltaTime);
}

void SlowMissileScript::FixedUpdate(float fixedDeltaTime)
{
   
    MoveMissile(fixedDeltaTime, Vector3(-1, 0, 0));

}

void SlowMissileScript::Activate()
{
    m_pOwner->SetStatus(game::Status::Active);
    MissileMode();
}
void SlowMissileScript::MissileMode()
{
    m_TexComp->m_iRenderFlag = 0;
    Vector3 temp = m_Transform.GetPosition();
    temp.x = 1800;
    m_Transform.SetPosition(temp);

    //저속 미사일 발사
    s_eSoundChannel = (s_eSoundChannel + 1) % 2 + 11;
    ResourceManager::GetInstance()->PlayMusic(game::eSoundList::Battle, 6, static_cast<game::eSoundChannel>(s_eSoundChannel));
}

void SlowMissileScript::AnimationUpdate(float fixedDeltaTime)
{
    animationTimer += fixedDeltaTime;
    if (animationTimer >= 0.2f)
    {
        m_TexComp->m_uRenderIndex = (m_TexComp->m_uRenderIndex + 1) % 3;
        animationTimer -= 0.2f;
    }
}
