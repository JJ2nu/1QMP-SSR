#include "FaidInFadeOutRenderComponent.h"
#include "GameObject.h"
#include "GameRender.h"
#include "ResourceManager.h"

void FaidInFadeOutRenderComponent::FixedUpdate(float fixedDeltaTime)
{}

void FaidInFadeOutRenderComponent::Update(float deltaTime)
{}

void FaidInFadeOutRenderComponent::Render()
{
	Transform pos = m_pOwner->GetTransform();
	GameRender::GetInstance()->DrawFadeInFadeOut(m_Bitmap, pos.Scale.x, pos.Scale.y, pos.Position.x - pos.Scale.x/2, pos.Position.y - pos.Scale.y / 2, false, m_fAlpha /255.f);
}

FaidInFadeOutRenderComponent::FaidInFadeOutRenderComponent(GameObject* pOwner, const std::string& ObjName)
	:RenderComponent(pOwner, ObjName)
{
	std::wstring tmp = L"\\TestResource\\FadeInFadeOut.bmp";
	tmp = ResourceManager::GetInstance()->GetPath() + tmp;
	m_Bitmap = Gdiplus::Image::FromFile(tmp.c_str());
}

FaidInFadeOutRenderComponent::~FaidInFadeOutRenderComponent()
{
	if (m_Bitmap)
		delete m_Bitmap;
}
