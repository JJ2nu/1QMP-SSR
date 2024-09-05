#pragma once
#include "GameObject.h"
#include "MeteorScript.h"
#include "AnimationComponent.h"

class MeteorObject : public GameObject
{
public:
    MeteorScript* m_Script;

public:
    MeteorObject(SceneBase* Scene) : GameObject("MeteorObject", Scene)
    {
        SetObjType(game::OBJECT_TYPE::ENEMY_WEAPON);
        m_Script = CreateComponent<MeteorScript>("MeteorObject");
    }
    virtual ~MeteorObject() {}

    virtual void OnCollisionEnter(ColliderComponent* src)
    {
        m_Script->OnCollisionEnter(src);
    }
};