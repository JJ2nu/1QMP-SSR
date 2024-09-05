#include "TextTureUIIoopScript.h"
#include "SceneManager.h"
#include "InputSystem.h"
#include "Observer.h"

TextTureUIIoopScript::TextTureUIIoopScript(GameObject* pOwner, std::string ObjName)
	: TextureUIScript(pOwner, ObjName)
{
	Start();
}

void TextTureUIIoopScript::Start()
{

}

void TextTureUIIoopScript::FixedUpdate(float fixedDeltaTime)
{
	m_fDelayTime += fixedDeltaTime;

	if (m_fDelayTime > m_fMovieMAXDelayTime && m_bSwitch == true)
	{
		m_TexComp->m_uRenderIndex++;
		m_bSwitch = false;
		m_fDelayTime = 0;
	}
	else if(m_fDelayTime > m_fMovieMAXDelayTime && m_bSwitch == false)
	{
		m_TexComp->m_uRenderIndex--;
		m_bSwitch = true;
		m_fDelayTime = 0;
	}

	for (int i = input::KEY::LEFT; i < input::KEY::LAST; ++i)
	{
		if (input::KEYHOLD(static_cast<input::KEY>(i)))
		{
			//GameStart
			ResourceManager::GetInstance()->PlayMusic(game::eSoundList::UI, 1, game::eSoundChannel::UI);

			Observer::GetInstance()->m_GameFlag = game::SCENE_TYPE::MAIN_MENU;
			//SceneManager::GetInstance()->ChangeScene(game::SCENE_TYPE::MAIN_MENU);
		}
	}

}


