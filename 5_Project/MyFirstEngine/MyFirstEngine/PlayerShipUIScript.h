#pragma once
#include "ScriptComponent.h"

class PlayerShipUIScript : public ScriptComponent
{
public :
    PlayerShipUIScript(GameObject* pOwner, std::string ObjName);

    virtual void Start(); // 시작 업데이트
    virtual void FixedUpdate(float fixedDeltaTime);
    virtual void Update(float deltaTime) {};

    TextureComponent* m_TexComp;
};

