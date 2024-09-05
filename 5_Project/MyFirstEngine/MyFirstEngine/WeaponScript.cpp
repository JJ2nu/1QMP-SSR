#include "WeaponScript.h"
#include "ScriptComponent.h"
#include "ResourceManager.h"
#include "InputSystem.h"

#include "GameManager.h"


WeaponScript::WeaponScript(GameObject* pOwner, std::string ObjName)
	:ScriptComponent(pOwner, ObjName), m_ColComp(nullptr), m_TexComp(nullptr)
{
	Start();
}


void WeaponScript::Start()
{
}

void WeaponScript::FixedUpdate(float fixedDeltaTime)
{
}

void WeaponScript::Update(float deltaTime)
{
}

void WeaponScript::Activate(Vector3 pos)
{
}

void WeaponScript::OnCollision(ColliderComponent* src)
{
	m_pOwner->SetStatus(game::Status::InActive);
}
