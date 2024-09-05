#include "PlayerHPUIScript.h"
#include "ResourceManager.h"
#include "PlayerGameObject.h"
#include "GameObject.h"
#include "Texture.h"
#include "Observer.h"



PlayerHPUIScript::PlayerHPUIScript(GameObject* pOwner, std::string ObjName)
    :ScriptComponent(pOwner, ObjName)
    , m_cRender(nullptr)

{
    Start();
}

PlayerHPUIScript::~PlayerHPUIScript() {}

void PlayerHPUIScript::Start()
{
    m_cRender = m_pOwner->CreateComponent<TextureComponent>("PlayerHPUITextureComponent");
    m_cRender->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"PlayerHP", L"\\TestResource\\UI_Player_Slider_HP_0.bmp");
    m_cRender->m_vOffset.x = 20.f;
    m_cRender->m_vOffset.y = -30.f;

    m_cRender2 = m_pOwner->CreateComponent<TextureComponent>("PlayerHPUITextureComponent");
    m_cRender2->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"PlayerEnhanceBack", L"\\TestResource\\UI_Player_Slider_EnhanceBack.bmp");
    m_cRender2->m_vOffset.x = -175.f;
    m_cRender2->m_vOffset.y = 22.f;

    m_cRender3 = m_pOwner->CreateComponent<TextureComponent>("PlayerHPUITextureComponent");
    m_cRender3->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"PlayerEnhance", L"\\TestResource\\UI_Player_Slider_Enhance.bmp");
    m_cRender3->m_vOffset.x = -175.f;
    m_cRender3->m_vOffset.y = 22.f;

    m_cRender4 = m_pOwner->CreateComponent<TextureComponent>("PlayerHPUITextureComponent");
    m_cRender4->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"PlayerHPUI", L"\\Image\\00. BATTLE\\UpperUI\\PlayerUI\\HpBar\\UI_Player_Slider_HP.bmp");
    m_cRender4->m_uExcep = RGB(255, 0, 255);

    m_fMaxHP = Observer::GetInstance()->GetPlayer()->myScript->m_fMaxHP;
    m_fHP = m_fMaxHP;
    m_iMaxEnhanceBulletRate = Observer::GetInstance()->GetPlayer()->myScript->m_iEnhanceBulletRate;
}

void PlayerHPUIScript::Update(float deltaTime)
{}

void PlayerHPUIScript::FixedUpdate(float fixedDeltaTime)
{
    m_fHP = Observer::GetInstance()->GetPlayer()->myScript->m_fHP;
    float cutwid;
    cutwid = (m_fMaxHP - m_fHP) / m_fMaxHP * m_cRender->m_tTexture[0]->Width();
    m_cRender->m_tTexture[0]->SetCutOffset(cutwid, 0, 0);

    m_iEnhanceBulletRate = Observer::GetInstance()->GetPlayer()->myScript->m_iCurEnhanceBulletRate;
    cutwid = ((float)(m_iMaxEnhanceBulletRate - m_iEnhanceBulletRate) / m_iMaxEnhanceBulletRate) * m_cRender3->m_tTexture[0]->Width();
    m_cRender3->m_tTexture[0]->SetCutOffset(cutwid, 0, 0);
}

void PlayerHPUIScript::Render()
{
}