#include "TextTureUIDelayScript.h"
#include "ResourceManager.h"

TextTureUIDelayScript::TextTureUIDelayScript(GameObject* pOwner, std::string ObjName)
	: TextureUIScript(pOwner, ObjName)
{
	Start();
}

void TextTureUIDelayScript::Start()
{
	ResourceManager::GetInstance()->PlayMusic(game::eSoundList::STORY_Story03_Takeoff, 0, game::eSoundChannel::Voice);
}

void TextTureUIDelayScript::FixedUpdate(float fixedDeltaTime)
{
	m_fDelayTime += fixedDeltaTime;

	
		if (m_fDelayTime > 6)
		{
			if (m_TexComp->m_uRenderIndex < m_iDelayCount)
			{
				if (m_fDelayTime > m_fOtherMAXDelayTime && m_TexComp->m_uRenderIndex < m_iTextureSize - 1)
				{
					ResourceManager::GetInstance()->PlayMusic(game::eSoundList::STORY_Story03_Takeoff, m_TexComp->m_uRenderIndex+1, game::eSoundChannel::Voice);
					m_TexComp->m_uRenderIndex++;
					m_fDelayTime = 0;
				}
			}
		}


	if(m_TexComp->m_uRenderIndex > m_iDelayCount -1 && m_TexComp->m_uRenderIndex >= 5)
	{
		if (m_fDelayTime > m_fMovieMAXDelayTime && m_TexComp->m_uRenderIndex < m_iTextureSize - 1)
		{
			m_TexComp->m_uRenderIndex++;
			m_fDelayTime = 0;
		}
	}
	

	if (m_TexComp->m_uRenderIndex == m_iTextureSize - 1)
	{
		if (m_fDelayTime > m_fSceneDelayTime)
		{
			m_fDelayTime = 0.f;
			SetMySceneChange();
		}
	}
}
