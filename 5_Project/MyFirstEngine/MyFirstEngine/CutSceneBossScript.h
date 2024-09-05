#pragma once
#include "ScriptComponent.h"
class CutSceneBossScript :
    public ScriptComponent
{
public:

    void AnimationInitialize();

    void AnimationUpdate(float fixedDeltaTime);
public:
    virtual void Start();
    virtual void Update(float deltaTime) {};
    virtual void FixedUpdate(float fixedDeltaTime);
    virtual void Render() {};

private:
    AnimationComponent* m_cRender;
    float floatingVector = 1.0f;
public:
    CutSceneBossScript(GameObject* pOwner, const std::string& ObjName);
    ~CutSceneBossScript();
};

