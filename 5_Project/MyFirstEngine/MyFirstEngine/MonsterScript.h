#pragma once

#include "ScriptComponent.h"
#include "ResourceManager.h"
#include <random>

class MonsterScript :
	public ScriptComponent
{
    ColliderComponent* myCollider;
    TextureComponent* myTexRender;
public:
    MonsterScript(GameObject* pOwner, std::string ObjName)
        :ScriptComponent(pOwner, ObjName)
    {
        Start();
    }

    ~MonsterScript()
    {}


    virtual void Start()
    {
        Component* component;
        component = m_pOwner->GetComponent("ColliderComponent");
        myCollider = dynamic_cast<ColliderComponent*>(component);

        component = m_pOwner->GetComponent("TextureComponent");
        myTexRender = dynamic_cast<TextureComponent*>(component);

        myTexRender->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"Monster", L"\\Texture\\Cat_King.bmp");
        m_Transform.SetPosition(rand()% 1920, rand()%1080, 0);
    }

};