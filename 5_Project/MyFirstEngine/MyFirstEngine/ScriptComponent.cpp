#include "ScriptComponent.h"

void ScriptComponent::FixedUpdate(float fixedDeltaTime)
{}

void ScriptComponent::Update(float deltaTime)
{}

void ScriptComponent::Render()
{}

void ScriptComponent::OnCollision(ColliderComponent* src)
{}

void ScriptComponent::OnCollisionEnter(ColliderComponent* src)
{}

void ScriptComponent::OnCollisionExit(ColliderComponent* src)
{}

ScriptComponent::ScriptComponent(GameObject* pOwner, std::string ObjName)
	:Component(pOwner, ObjName)
	, m_Transform(pOwner->m_Transform)
{}

ScriptComponent::~ScriptComponent()
{}
