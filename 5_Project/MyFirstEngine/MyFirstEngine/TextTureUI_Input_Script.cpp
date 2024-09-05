#include "TextTureUI_Input_Script.h"
#include "InputSystem.h"
#include "Observer.h"

TextTureUI_Input_Script::TextTureUI_Input_Script(GameObject* pOwner, std::string ObjName)
	: TextureUIScript(pOwner, ObjName)
{
	Start();
}

void TextTureUI_Input_Script::Start()
{
	m_TexComp->m_uRenderIndex = 0;
	Observer::GetInstance()->m_iStoryIndex = 0;
}

void TextTureUI_Input_Script::FixedUpdate(float fixedDeltaTime)
{

}

void TextTureUI_Input_Script::Update(float deltaTime)
{

	m_TexComp->m_uRenderIndex = Observer::GetInstance()->m_iStoryIndex;
	//if (m_TexComp->m_uRenderIndex == m_iInputStop )
	//{
	//	m_fDelayTime += deltaTime;

	//	if (m_fDelayTime > 1.f)
	//	{
	//		m_TexComp->m_uRenderIndex++;
	//		m_fDelayTime = 0.f;
	//	}
	//}

	if (m_iTextureSize <= m_TexComp->m_uRenderIndex)
	{
		m_TexComp->m_uRenderIndex = m_iTextureSize - 1;
	}
}

void TextTureUI_Input_Script::NextIndex()
{
	m_TexComp->m_uRenderIndex++;
}
