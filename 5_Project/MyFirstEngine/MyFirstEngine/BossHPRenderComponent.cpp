#include "BossHPRenderComponent.h"
#include "GameObject.h"
#include "GameRender.h"

void BossHPRenderComponent::FixedUpdate(float fixedDeltaTime)
{}

void BossHPRenderComponent::Update(float deltaTime)
{}

void BossHPRenderComponent::Render()
{
	Vector3 pos = m_pOwner->GetTransform().GetPosition();
	GameRender::GetInstance()->DrawRect(
		pos.x + m_iOffset - m_fMaxWidth / 2,
		pos.y - m_fMaxHeight /2,
		m_fMaxWidth,
		m_fMaxHeight,
		m_uColor[m_uCurColorIndex]);
	GameRender::GetInstance()->DrawRect(
		pos.x + m_iOffset - m_fMaxWidth / 2, 
		pos.y - m_fMaxHeight / 2, 
		m_fCurWidth, 
		m_fCurHeight, 
		m_uColor[(m_uCurColorIndex + 1)% m_uMaxColorIndex]);
}

BossHPRenderComponent::BossHPRenderComponent(GameObject* pOwner, const std::string& ObjName)
	:RenderComponent(pOwner, ObjName)
	,m_fMaxWidth(0), m_fMaxHeight(0)
	, m_fCurWidth(0), m_fCurHeight(0)
	,m_uColor{}
	, m_uCurColorIndex(0)
{
	m_uColor[0] = RGB(255, 69, 58);
	m_uColor[1] = RGB(255, 159, 10);
	m_uColor[2] = RGB(255, 205, 0);
	m_uColor[3] = RGB(169, 169, 169);
	m_uColor[4] = RGB(0, 0, 0);
}

BossHPRenderComponent::~BossHPRenderComponent()
{}
