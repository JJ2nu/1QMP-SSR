#pragma once
#include "RenderComponent.h"
#include "AnimationResource.h"

class AnimationComponent : public RenderComponent
{
public:
	void FixedUpdate(float fixedDeltaTime) override;
	void Update(float deltaTime) override;
	void Render() override;

public:
	AnimationResource* m_tAnim;
	int m_iAnimationMotionIndex = -1;
	int m_iAnimationFrameIndex = 0;
	float m_fAnimationDelayTime = 0.5f;
	float m_fAnimationAccTime = 0.0f;
	bool m_bAnimationFlip = false;
	float m_fRotate = 0;
	UINT m_uExcept = RGB(255,0,255);

public:
	AnimationComponent(GameObject* pOwner, const std::string& ObjName);
	virtual ~AnimationComponent();
};

