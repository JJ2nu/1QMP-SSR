#pragma once
#include "Component.h"
class RenderComponent :
    public Component
{
public:
	virtual void FixedUpdate(float fixedDeltaTime) = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render() = 0;

public:
	RenderComponent(GameObject* pOwner, const std::string& ObjName);
	virtual ~RenderComponent();
};

