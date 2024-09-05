#include "ColliderComponent.h"
#include "SceneBase.h"
#include "GameObject.h"
#include "GameRender.h"

UINT ColliderComponent::s_uStaticID = 0;

void ColliderComponent::OnCollision(ColliderComponent* src)
{
	m_RenderColor = RGB(0, 0, 255);
	m_pOwner->OnCollision(src);
}

void ColliderComponent::OnCollisionEnter(ColliderComponent* src)
{
	m_uCollisionCount++;
	m_RenderColor = RGB(0, 255, 0);
	m_pOwner->OnCollisionEnter(src);
}

void ColliderComponent::OnCollisionExit(ColliderComponent* src)
{
	m_uCollisionCount--;
	m_RenderColor = RGB(255, 0, 0);
	m_pOwner->OnCollisionExit(src);
}



ColliderComponent::ColliderComponent(GameObject* pOwner, std::string ObjName)
	:Component(pOwner, ObjName),
	m_uCollisionID(s_uStaticID++),
	m_uCollisionCount(0),
	m_RenderColor(RGB(255, 0, 0))
{
	pOwner->GetSceneBase()->AddCollider(this, pOwner->GetObjType());
}

ColliderComponent::~ColliderComponent()
{
}

//20ms 기준 위치 이동
void ColliderComponent::FixedUpdate(float fixedDeltaTime)
{
	m_Transform.Position = m_pOwner->m_Transform.Position;
}

void ColliderComponent::Update(float deltaTime)
{
}

void ColliderComponent::Render()
{
	GameRender::GetInstance()->DrawRectLine(
		(int)(m_Transform.Position.x - m_Transform.Scale.x / 2.f)
		, (int)(m_Transform.Position.y - m_Transform.Scale.y / 2.f)
		, m_Transform.Scale.x, m_Transform.Scale.y, m_RenderColor);
}

GameObject* ColliderComponent::GetOwner() const
{
	return m_pOwner;
}
