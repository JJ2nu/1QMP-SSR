#pragma once
#include "ScriptComponent.h"
class CrossHairScript :
    public ScriptComponent
{
public:
    virtual void Start();
    virtual void Update(float deltaTime);
    virtual void FixedUpdate(float fixedDeltaTime);
    virtual void Render();
    virtual void OnCollision(ColliderComponent* src);


private:
    ColliderComponent* m_cCollider;
    TextureComponent* m_cRender;
    bool m_bColliderFlag = false;
    float m_fCurContinueTime = 0.f;
    float m_fContinueTime = .2f;


public:
    CrossHairScript(GameObject* pOwner, std::string ObjName);
    ~CrossHairScript();
};

