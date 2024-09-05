#pragma once
#include "ScriptComponent.h"

class PlayerHPUIScript :
    public ScriptComponent
{
public:
    virtual void Start();
    virtual void Update(float deltaTime);
    virtual void FixedUpdate(float fixedDeltaTime);
    virtual void Render();
 
private:
    TextureComponent* m_cRender;
    TextureComponent* m_cRender2;
    TextureComponent* m_cRender3;
    TextureComponent* m_cRender4;

private:
    float m_fMaxHP;
    float m_fHP;
    int m_iMaxEnhanceBulletRate;
    int m_iEnhanceBulletRate;

public:
    PlayerHPUIScript(GameObject* pOwner, std::string ObjName);
    ~PlayerHPUIScript();
};

