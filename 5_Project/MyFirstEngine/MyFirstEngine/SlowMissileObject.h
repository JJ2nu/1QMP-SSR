#pragma once
#include "GameObject.h"
#include "SlowMissileScript.h"
#include "AnimationComponent.h"

class SlowMissileObject :
    public GameObject
{
public:
    SlowMissileScript* m_Script;

public:
    SlowMissileObject(SceneBase* Scene) : GameObject("SlowMissileObject", Scene)
    {
        SetObjType(game::OBJECT_TYPE::ENEMY_WEAPON);
        m_Script = CreateComponent<SlowMissileScript>("SlowMissileObject");
        
    }
    virtual ~SlowMissileObject() {}

    virtual void OnCollisionEnter(ColliderComponent* src)
    {
        m_Script->OnCollisionEnter(src);
    }
};

