#pragma once
#include "RenderComponent.h"

class BossHPRenderComponent :
    public RenderComponent
{
public:
	void FixedUpdate(float fixedDeltaTime) override;
	void Update(float deltaTime) override;
	void Render() override;

public:
	float m_fMaxWidth;
	float m_fMaxHeight;
	float m_fCurWidth;
	float m_fCurHeight;
	//Color Index Max Value -> m_uMaxColorIndex
	UINT m_uColor[5];
	UINT m_uCurColorIndex;
	UINT m_uMaxColorIndex = 5;
	int m_iOffset = 23;

public:
	BossHPRenderComponent(GameObject* pOwner, const std::string& ObjName);
	virtual ~BossHPRenderComponent();
};

