#include "FontScript.h"
#include "ScriptComponent.h"
#include "ResourceManager.h"
#include "InputSystem.h"
#include "GameRender.h"
#include <cstring>

FontScript::FontScript(GameObject* pOwner, std::string ObjName)
	:ScriptComponent(pOwner, ObjName), m_TextComp(nullptr), m_TexComp(nullptr)
	, m_iDialogArrSize(0)
{
}

FontScript::~FontScript()
{}

void FontScript::SetRectSizeAndTransform(int _Width, int _Height, float _TransformX, float _TransformY)
{
	m_TextComp->SetTransform(_TransformX, _TransformY, 0);
	m_TextComp->SetRectSize(_TransformX, _TransformY,_Width, _Height);
}

void FontScript::SetMyDialog(std::wstring* ObjectDialog, int strArrSize)
{
	m_iDialogArrSize = strArrSize;
	for (int i = 0; i < strArrSize; i++)
	{
		m_sDialog = new std::wstring(ObjectDialog[i]);
		m_tString.push_back(m_sDialog);
	}
	m_sDialog = nullptr;
}

void FontScript::SetMyColor(int R, int G, int B)
{
	m_TextComp->m_uColor = RGB(R, G, B);
}

void FontScript::SetFontSize(int _FontSize)
{
	m_TextComp->m_iFontSize =_FontSize;
}

void FontScript::SetMyTextureTransform(float _PositionX, float _PositionY)
{
	m_pOwner->m_Transform.SetPosition(_PositionX, _PositionY, 0);
}



