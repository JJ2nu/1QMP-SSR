#pragma once
#include "RenderComponent.h"
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")
#include <ole2.h>

class FaidInFadeOutRenderComponent :
	public RenderComponent
{
public:
	void FixedUpdate(float fixedDeltaTime) override;
	void Update(float deltaTime) override;
	void Render() override;

public:
	float m_fAlpha = 255.0f;
	Gdiplus::Image* m_Bitmap = nullptr;

public:
	FaidInFadeOutRenderComponent(GameObject* pOwner, const std::string& ObjName);
	virtual ~FaidInFadeOutRenderComponent();
};

