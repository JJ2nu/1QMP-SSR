#include "StartStageUIScript.h"
#include "SceneBase.h"
#include "ResourceManager.h"
#include "FontScript.h"


StartStageUIScript::StartStageUIScript(GameObject* pOwner, std::string ObjName)
	:FontScript(pOwner, ObjName)
{
	Start();
}

void StartStageUIScript::Start()
{
	m_TextComp = m_pOwner->CreateComponent<TextComponent>("StartStageUITextComponent");
	m_TextComp->m_pFontName = L"\\Resource\\TestResource\\qwe.ttf";  //폰트 경로를 찾아서 로드
}

void StartStageUIScript::FixedUpdate(float fixedDeltaTime)
{
	delayTime += fixedDeltaTime;

	if (delayTime > MaxdelayTime)
	{
		if (m_TextComp->m_uTextIndex < m_TextComp->m_tString.size()-1)
		{
			m_TextComp->m_uTextIndex++;
		}
		delayTime = 0.f;
	}

}

void StartStageUIScript::SetAllText()
{
	for (int i = 0; i < m_iDialogArrSize; i++)
		m_TextComp->m_tString.push_back(m_tString[i]);
}


