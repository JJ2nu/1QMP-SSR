#include "TextureComponent.h"
#include "GameRender.h"
#include "GameObject.h"

void TextureComponent::FixedUpdate(float fixedDeltaTime)
{}

void TextureComponent::Update(float deltaTime)
{}

void TextureComponent::Render()
{
	Transform temp = m_pOwner->GetTransform();
	temp.Position += m_vOffset;
	if(m_tTexture[m_uRenderIndex])
		GameRender::GetInstance()->DrawTexture(m_tTexture[m_uRenderIndex], temp, m_uExcep, m_iRenderFlag, m_uAlpha);
}

TextureComponent::TextureComponent(GameObject* pOwner, const std::string& ObjName)
	:RenderComponent(pOwner, ObjName)
	, m_uRenderIndex(0)
	, m_tTexture{}
	, m_uExcep(RGB(255, 255, 255)), m_uAlpha((UINT)0)
	, m_iRenderFlag(0)
{}

TextureComponent::~TextureComponent()
{}

