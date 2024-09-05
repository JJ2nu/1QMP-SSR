#pragma once
#include "ScriptComponent.h"
#include "BossHPRenderComponent.h"

class BossHPUIScript :
    public ScriptComponent
{
public:
    virtual void Start();
    virtual void Update(float deltaTime);
    virtual void FixedUpdate(float fixedDeltaTime);
    virtual void Render();

private:
    TextureComponent* m_cRender;
    BossHPRenderComponent* m_cBossHPRender;
    TextComponent* m_cTextRender;

    std::wstring* curstr = nullptr;

private:
    float m_fMaxHP;
    float m_fCurMaxHP;
    float m_fHP;
    float m_fRatio;
    int m_fPhase = 0;

public:
    BossHPUIScript(GameObject* pOwner, std::string ObjName);
    ~BossHPUIScript();
};

