#pragma once
#include "GameObject.h"
#include "SupportingMissileScript.h"

class SupportingMissileObject :
    public GameObject
{
public:
    SupportingMissileScript* m_Script;

public:
    SupportingMissileObject(SceneBase* Scene) : GameObject("SupportingMissileObject", Scene)
    {
        SetObjType(game::OBJECT_TYPE::PLAYER_WEAPON);
        m_Script = CreateComponent<SupportingMissileScript>("SupportingMissileObject");

    }
    virtual ~SupportingMissileObject() {}

    virtual void OnCollisionEnter(ColliderComponent* src)
    {
        m_Script->OnCollisionEnter(src);
    }
};