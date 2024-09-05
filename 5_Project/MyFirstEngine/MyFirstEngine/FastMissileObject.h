#pragma once

#include "GameObject.h"
#include "FastMissileScript.h"
#include "AnimationComponent.h"

class FastMissileObject :
    public GameObject
{
public:
    FastMissileScript* m_Script;

public:
    FastMissileObject(SceneBase* Scene) : GameObject("FastMissileObject", Scene)
    {
        SetObjType(game::OBJECT_TYPE::ENEMY_WEAPON);
        m_Script = CreateComponent<FastMissileScript>("FastMissileObject");

    }
    virtual ~FastMissileObject() {}

    virtual void OnCollisionEnter(ColliderComponent* src)
    {
        m_Script->OnCollisionEnter(src);
    }
};

