#include "BossHPUIScript.h"
#include "ResourceManager.h"
#include "BossObject.h"
#include "GameObject.h"
#include "Texture.h"
#include "GameRender.h"
#include "Observer.h"
#include<string>



BossHPUIScript::BossHPUIScript(GameObject* pOwner, std::string ObjName)
    :ScriptComponent(pOwner, ObjName)
    , m_cRender(nullptr)

{
    Start();
}

BossHPUIScript::~BossHPUIScript() {}

void BossHPUIScript::Start()
{
    //내부 색깔
    m_cBossHPRender = m_pOwner->CreateComponent<BossHPRenderComponent>("BossHPUIRectComponent");

    //UI이미지
    m_cRender = m_pOwner->CreateComponent<TextureComponent>("BossHPUITextureComponent");
    m_cRender->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"BossHPUI", L"\\Image\\00. BATTLE\\UpperUI\\BossUI\\UI_Boss_Slider_HP.bmp");
    m_cRender->m_uExcep = RGB(255, 0, 255);
    
    m_fMaxHP = Observer::GetInstance()->GetBoss()->m_Script->m_fMaxHP;
    m_fCurMaxHP = m_fMaxHP;
    m_fHP = m_fMaxHP;
    m_fRatio = 0.3f;

    //내부 색깔 위치 조정
    m_cBossHPRender->m_fMaxWidth = m_cRender->m_tTexture[0]->Width() - 58;
    m_cBossHPRender->m_fMaxHeight = m_cRender->m_tTexture[0]->Height() - 15;
    m_cBossHPRender->m_fCurWidth = m_cBossHPRender->m_fMaxWidth;
    m_cBossHPRender->m_fCurHeight = m_cBossHPRender->m_fMaxHeight;

    /*Text Component*/
   /* m_cTextRender = m_pOwner->CreateComponent<TextComponent>("BossHPUITextComponent");
    curstr = new std::wstring();
    m_cTextRender->m_tString.push_back(curstr);
    m_cTextRender->SetRectSize(m_Transform.Position.x, m_Transform.Position.y,200, 100);
    m_cTextRender->m_uColor = RGB(255, 0, 0);*/
}

void BossHPUIScript::Update(float deltaTime)
{}

void BossHPUIScript::FixedUpdate(float fixedDeltaTime)
{
    m_fHP = Observer::GetInstance()->GetBoss()->m_Script->m_fHP;
    //*curstr = std::to_wstring(static_cast<float>((m_fCurMaxHP - m_fHP) / (m_fMaxHP * m_fRatio)));
    float cutwid;
    if (m_fMaxHP * 0.3f > m_fHP && m_fPhase == 1)
    {
        m_cBossHPRender->m_uCurColorIndex = (m_cBossHPRender->m_uCurColorIndex + 1) % m_cBossHPRender->m_uMaxColorIndex;
        m_fPhase++;
        m_fCurMaxHP = m_fMaxHP * 0.3f;
        m_fRatio = 0.3f;
    }
    else if (m_fMaxHP * 0.7f > m_fHP && m_fPhase == 0)
    {
        m_cBossHPRender->m_uCurColorIndex = (m_cBossHPRender->m_uCurColorIndex + 1) % m_cBossHPRender->m_uMaxColorIndex;
        m_fPhase++;
        m_fCurMaxHP = m_fMaxHP * 0.7f;
        m_fRatio = 0.4f;
    }
    cutwid = ((m_fCurMaxHP - m_fHP) / (m_fMaxHP * m_fRatio)) * m_cBossHPRender->m_fMaxWidth;
    m_cBossHPRender->m_fCurWidth = cutwid;
}

void BossHPUIScript::Render()
{
}