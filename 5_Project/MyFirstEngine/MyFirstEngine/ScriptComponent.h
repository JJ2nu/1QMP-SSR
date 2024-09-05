#pragma once
#include "Component.h"
#include "ColliderComponent.h"
#include "TextureComponent.h"
#include "AnimationComponent.h"
#include "RenderComponent.h"
#include "TextComponent.h"
#include "GameObject.h"
#include  "Define.h"

class ScriptComponent :
    public Component, ICollider
{
public:
	virtual void Start() = 0;
	//Script
	virtual void FixedUpdate(float fixedDeltaTime);
	virtual void Update(float deltaTime);
	virtual void Render();

	//ICollider
	virtual void OnCollision(ColliderComponent* src);
	virtual void OnCollisionEnter(ColliderComponent* src);
	virtual void OnCollisionExit(ColliderComponent* src);

public:
	Transform& m_Transform;

public:
	ScriptComponent(GameObject* pOwner, std::string ObjName);
	virtual ~ScriptComponent();
};

