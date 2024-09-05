#include "RenderComponent.h"

RenderComponent::RenderComponent(GameObject* pOwner, const std::string& ObjName)
	:Component(pOwner, ObjName)
{}

RenderComponent::~RenderComponent()
{}