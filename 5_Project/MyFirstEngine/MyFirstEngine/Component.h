#pragma once
#include "Object.h"

class GameObject;

class Component :
    public Object
{
public:
	virtual void FixedUpdate(float fixedDeltaTime) = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render() = 0;

protected:
	GameObject* m_pOwner;

public:
	Component(GameObject* pOwner, std::string ObjName);
	virtual ~Component();
};
