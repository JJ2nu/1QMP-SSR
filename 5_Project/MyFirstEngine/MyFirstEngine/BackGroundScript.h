#pragma once
#include "ScriptComponent.h"
#include "GameObject.h"


class BackGroundScript :
    public ScriptComponent
{
public:
    BackGroundScript(GameObject* pOwner, std::string ObjName);
    virtual void Start();
    virtual void Update(float deltaTime) {};
    virtual void FixedUpdate(float fixedDeltaTime);
    void CameraShake(float fixedDeltaTime);
     void ShakeOn();

    void CameraReset();
    TextureComponent* m_cTexture;
private:
    float m_fShakeVector = 1.0f;
    float m_fElapsedTime = 0.0f;
    float m_fElapsedTime2 = 0.0f;
public:
    bool m_bShakeFlag = false;


};

