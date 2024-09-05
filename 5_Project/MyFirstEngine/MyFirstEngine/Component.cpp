#include "Component.h"

//void Component::FixedUpdate(float fixedDeltaTime)
//{}
//
//void Component::Update(float deltaTime)
//{}
//
//void Component::Render(HDC& _dc)
//{}

Component::Component(GameObject* pOwner, std::string ObjName)
	: Object(ObjName), 
	m_pOwner(pOwner)
{}

Component::~Component()
{}
