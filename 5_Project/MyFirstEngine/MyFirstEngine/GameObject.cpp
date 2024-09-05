#include "GameObject.h"
#include "SceneBase.h"
#include "RenderComponent.h"
#include "ColliderComponent.h"
#include "ScriptComponent.h"
#include "Define.h"

void GameObject::FixedUpdate(float fixedDeltaTime)
{
	for (auto& pComponent : m_vComponentList)
	{
		if(pComponent->GetStatus() == game::Status::Active)
			pComponent->FixedUpdate(fixedDeltaTime);
	}
	for (auto& pGameObject : m_vChildGameObject)
	{
		if (pGameObject->GetStatus() == game::Status::Active)
			pGameObject->FixedUpdate(fixedDeltaTime);
	}
}

void GameObject::Update(float deltaTime)
{
	for (auto& pComponent : m_vComponentList)
	{
		if (pComponent->GetStatus() == game::Status::Active)
			pComponent->Update(deltaTime);
	}
	for (auto& pGameObject : m_vChildGameObject)
	{
		if (pGameObject->GetStatus() == game::Status::Active)
			pGameObject->Update(deltaTime);
	}
}

void GameObject::Render()
{
	for (auto& pComponent : m_vComponentList)
	{
		//있으면 바뀌고 없으면 null반환
		//캐스팅을 먼저인가 아니면 ACtive판정이 먼저인가 뭐가 더 오버헤드가 적을까?
		if (pComponent->GetStatus() == game::Status::Active)
		{
			RenderComponent* pRenderComponent = dynamic_cast<RenderComponent*>(pComponent);
			if (pRenderComponent)
			{
				pRenderComponent->Render();
			}
			if (DebugMode)
			{
				ColliderComponent* pColliderComponent = dynamic_cast<ColliderComponent*>(pComponent);
				if(pColliderComponent)
				{
					pColliderComponent->Render();
				}
			}
		}
	}
	for (auto& pGameObject : m_vChildGameObject)
	{
		//있으면 바뀌고 없으면 null반환
		//캐스팅을 먼저인가 아니면 ACtive판정이 먼저인가 뭐가 더 오버헤드가 적을까?
		if (pGameObject->GetStatus() == game::Status::Active)
		{
			pGameObject->Render();
		}
	}
}


GameObject::GameObject(std::string ObjName, SceneBase* Scene)
:Object(ObjName)
, m_pScene(Scene)
{}

GameObject::~GameObject()
{
	for (auto& pGameObject : m_vChildGameObject)
	{
		delete pGameObject;
	}
	for (auto& p_Component : m_vComponentList)
	{
		delete p_Component;
	}
	m_vComponentList.clear();
	m_vChildGameObject.clear();
}

void GameObject::OnCollision(ColliderComponent* src)
{}

void GameObject::OnCollisionEnter(ColliderComponent* src)
{}

void GameObject::OnCollisionExit(ColliderComponent* src)
{}

Component* GameObject::GetComponent(const std::string& ComponentType)
{
	for (auto& p_Component : m_vComponentList)
	{
		if (p_Component->GetObjClassName() == ComponentType)
		{
			return p_Component;
		}
	}
	return nullptr;
}

void GameObject::AddChildGameObject(GameObject* _GameObject)
{
	m_vChildGameObject.push_back(_GameObject);
}
