#include "AnimationComponent.h"
#include "GameRender.h"
#include "GameObject.h"

void AnimationComponent::FixedUpdate(float fixedDeltaTime)
{}

void AnimationComponent::Update(float deltaTime)
{
	
}

void AnimationComponent::Render()
{
	if (m_tAnim)
		GameRender::GetInstance()->DrawAnimationResource(m_tAnim
			, m_iAnimationMotionIndex
			, m_iAnimationFrameIndex
			, m_fAnimationAccTime
			, m_bAnimationFlip
			, m_pOwner->m_Transform.Position.x, m_pOwner->m_Transform.Position.y
			, m_uExcept, m_fRotate);
}

AnimationComponent::AnimationComponent(GameObject* pOwner, const std::string& ObjName)
	:RenderComponent(pOwner, ObjName), m_tAnim(nullptr)
{
}

AnimationComponent::~AnimationComponent()
{
}
