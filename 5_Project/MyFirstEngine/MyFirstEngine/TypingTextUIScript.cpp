#include "TypingTextUIScript.h"
#include "ResourceManager.h"
#include "InputSystem.h"
#include "SceneManager.h"
#include "Observer.h"


TypingTextUIScript::TypingTextUIScript(GameObject* pOwner, std::string ObjName) :FontScript(pOwner, ObjName)
{
	Start();
}

void TypingTextUIScript::Start()
{
	/*m_TexComp = m_pOwner->CreateComponent<TextureComponent>("TypingTextUITextureComponent");
	m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"TypingTextUI", L"\\TestResource\\Ship_Player_0.bmp");*/

	m_TextComp = m_pOwner->CreateComponent<TextComponent>("TypingTextUITextComponent");
	m_TextComp->m_pFontName = L"\\Resource\\TestResource\\qwe.ttf";  //폰트 경로를 찾아서 로드
	m_TextComp->m_uTextIndex = -1; // 0부터 시작할려고 만듬


}

void TypingTextUIScript::FixedUpdate(float fixedDeltaTime)
{
	if (m_iDialogArrSize == m_TextComp->m_uTextIndex)
	{
		SetMyLoadScene();
		return;
	}

	if (m_bTextFlag)
	{
		m_sDialog = new std::wstring();
		m_TextComp->m_tString.push_back(m_sDialog);
		m_bTextFlag = false;
		m_TextComp->m_uTextIndex++;
		Observer::GetInstance()->m_iStoryIndex = m_TextComp->m_uTextIndex;
		delayTime = 0.f;
		i_fontCount = 0;

		if (game::eSoundList::End != m_eSoundList)
		{
			ResourceManager::GetInstance()->PlayMusic(m_eSoundList, m_TextComp->m_uTextIndex, m_eSoundChannel);
		}
		
		if (m_iDialogArrSize == m_TextComp->m_uTextIndex)
		{
			SetMyLoadScene();
			return;
		}
	}
	delayTime += fixedDeltaTime;
	while (delayTime > m_fDelayTime && !((*m_tString[m_TextComp->m_uTextIndex]).size() == i_fontCount)) // && !m_sDialog->length()
	{
		*m_sDialog += (*m_tString[m_TextComp->m_uTextIndex])[i_fontCount];
		//m_sDialog->push_back((*m_tString[m_TextComp->m_uTextIndex])[i_fontCount]);
		  
		i_fontCount++;
		delayTime -= m_fDelayTime;
	}
	m_fDelayTime = m_fMaxDelayTime;

	if ((*m_tString[m_TextComp->m_uTextIndex]).size() == i_fontCount)
	{
		m_bFullFlag = true;
	}
}

void TypingTextUIScript::Update(float deltaTime)
{
	if ((input::KEYTAP(input::KEY::SPACE) || input::KEYTAP(input::KEY::L_MOUSE_BUTTON))) // 키와 마우스로 넘어가기
	{
		if (m_bFullFlag)
		{
			m_bTextFlag = true;
			m_bFullFlag = false;
		}
		else
		{
			m_fDelayTime = 0.f;
			m_bFullFlag = true;
		}
	}
}

void TypingTextUIScript::SetMyLoadScene()
{
	Observer::GetInstance()->m_GameFlag = m_eScene_Type;
}
