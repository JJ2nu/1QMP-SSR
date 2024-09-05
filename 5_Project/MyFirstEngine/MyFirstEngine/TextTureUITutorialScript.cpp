#include "TextTureUITutorialScript.h"
#include "InputSystem.h"
#include "Observer.h"

TextTureUITutorialScript::TextTureUITutorialScript(GameObject* pOwner, std::string ObjName)
	: TextureUIScript(pOwner, ObjName)
{
	Start();
}

void TextTureUITutorialScript::Start()
{

}

void TextTureUITutorialScript::FixedUpdate(float fixedDeltaTime)
{

}

void TextTureUITutorialScript::Update(float deltaTime)
{
	if (input::KEYTAP(input::KEY::RIGHT) && m_iTextureSize - 1 > m_TexComp->m_uRenderIndex)
	{
		m_TexComp->m_uRenderIndex++;
	}
	else if (input::KEYTAP(input::KEY::LEFT) && m_TexComp->m_uRenderIndex > 0)
	{
		m_TexComp->m_uRenderIndex--;
	}

	if (input::KEYTAP(input::KEY::ESCAPE))
	{
		Observer::GetInstance()->m_GameFlag = game::SCENE_TYPE::MAIN_MENU;
	}

}

