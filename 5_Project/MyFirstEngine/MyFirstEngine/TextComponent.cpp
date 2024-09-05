#include "TextComponent.h"
#include "GameRender.h"
#include "GameObject.h"
#include <atlconv.h>



void TextComponent::FixedUpdate(float fixedDeltaTime)
{}

void TextComponent::Update(float deltaTime)
{}

void TextComponent::Render()
{
	if (m_tString.size())
	{
		std::string tempPath;
		USES_CONVERSION;
		tempPath = std::string(W2A(m_tString[m_uTextIndex]->c_str()));
		GameRender::GetInstance()->DrawText(m_Transform.Position.x, m_Transform.Position.y
			, tempPath.c_str()
			, m_uColor, m_pFontName
			, m_iFontSize, m_Rect);
	}

}

void TextComponent::SetRectSize(float x, float y, float Width, float Height)
{
	m_Rect.left = x;
	m_Rect.top = y;
	m_Rect.right = m_Rect.left + Width; // 텍스트 출력 영역의 폭 (필요에 따라 조정)
	m_Rect.bottom = m_Rect.top + Height; // 텍스트 출력 영역의 높이 (필요에 따라 조정)
}

void TextComponent::SetTransform(Vector3 pos)
{
	m_Transform.Position = pos;
	m_Rect.left = pos.x;
	m_Rect.top = pos.y;
}

void TextComponent::SetTransform(float x, float y, float z)
{
	m_Transform.Position.x = x;
	m_Transform.Position.y = y;
	m_Transform.Position.z = z;
	m_Rect.left = x;
	m_Rect.top = y;
}

TextComponent::TextComponent(GameObject* pOwner, const std::string& ObjName)
	:RenderComponent(pOwner, ObjName)
	, m_tString()
	, m_uTextIndex(0)
	, m_uColor(RGB(0, 0, 0))
	, m_iFontSize(30)
	, m_pFontName(TEXT("April16thTTF-Promise.ttf"))
	, m_Transform(pOwner->m_Transform)
{
	m_Rect.left = 0;
	m_Rect.top = 0;
	m_Rect.right = 1500; // 텍스트 출력 영역의 폭 (필요에 따라 조정)
	m_Rect.bottom = 500; // 텍스트 출력 영역의 높이 (필요에 따라 조정)
}

TextComponent::~TextComponent()
{}
