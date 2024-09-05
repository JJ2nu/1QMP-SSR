#include "EndingStory_TextureScript.h"
#include "ResourceManager.h"
#include "Observer.h"

#include "FadeInFadeOutObject.h"

EndingStory_TextureScript::EndingStory_TextureScript(GameObject* pOwner, std::string ObjName)
	: TextureUIScript(pOwner, ObjName)
{
	Start();
}

void EndingStory_TextureScript::Start()
{
	fadeInFadeOutObject = new FadeInFadeOutObject;
	m_pOwner->AddChildGameObject(fadeInFadeOutObject);
	fadeInFadeOutObject->m_Script->m_iFlag = 2;

	ResourceManager::GetInstance()->PlayMusic(game::eSoundList::STORY_Story09_News, 0, game::eSoundChannel::Voice);
}

void EndingStory_TextureScript::FixedUpdate(float fixedDeltaTime)
{
	m_fDelayTime += fixedDeltaTime;

	fadeInFadeOutObject->SetStatus(game::Status::Active);
	if (m_fDelayTime > 8.f && m_TexComp->m_uRenderIndex == 0)  // 3
	{
		ResourceManager::GetInstance()->PlayMusic(game::eSoundList::STORY_Story09_News, 1, game::eSoundChannel::Voice);
		m_TexComp->m_uRenderIndex++;
		m_fDelayTime = 0;
		fadeInFadeOutObject->m_Script->SetSign(true);
		fadeInFadeOutObject->SetStatus(game::Status::Active);
	}

	if (m_fDelayTime > 7.f && m_TexComp->m_uRenderIndex == 1) // 5
	{
		ResourceManager::GetInstance()->PlayMusic(game::eSoundList::STORY_Story09_News, 2, game::eSoundChannel::Voice);
		m_TexComp->m_uRenderIndex++;
		m_fDelayTime = 0;
		fadeInFadeOutObject->m_Script->SetSign(true);
		fadeInFadeOutObject->SetStatus(game::Status::Active);
	}

	if (m_fDelayTime > 9.f && m_TexComp->m_uRenderIndex == 2)  // 12
	{
		ResourceManager::GetInstance()->PlayMusic(game::eSoundList::STORY_Story10_Briefing, 0, game::eSoundChannel::Voice);
		m_TexComp->m_uRenderIndex++;
		m_fDelayTime = 0;
		fadeInFadeOutObject->m_Script->SetSign(true);
		fadeInFadeOutObject->SetStatus(game::Status::Active);
	}

	
	if (m_fDelayTime > 4.f && m_TexComp->m_uRenderIndex == 3) // 14
	{
		ResourceManager::GetInstance()->PlayMusic(game::eSoundList::STORY_Story10_Briefing, 1, game::eSoundChannel::Voice);
		m_TexComp->m_uRenderIndex++;
		m_fDelayTime = 0;
		fadeInFadeOutObject->m_Script->SetSign(true);
		fadeInFadeOutObject->SetStatus(game::Status::Active);
		m_bBriefing = true;
	}

	if (m_bBriefing == true)
	{
		ResourceManager::GetInstance()->PlayMusic(game::eSoundList::STORY_Story10_Briefing, 2, game::eSoundChannel::Voice);
		m_bBriefing = false;
	}
	
	if (m_fDelayTime > 3.f && m_TexComp->m_uRenderIndex >= 4 && m_TexComp->m_uRenderIndex < 10) // 17 ~ 21
	{
		m_TexComp->m_uRenderIndex++;
		m_fDelayTime = 0;

		if (m_TexComp->m_uRenderIndex == 9)
		{
			ResourceManager::GetInstance()->PlayMusic(game::eSoundList::STORY_Story11_Bombing, 0, game::eSoundChannel::Voice);
			m_bFadeinFadeoutCooltime = true;
			fadeInFadeOutObject->m_Script->m_fDelayTime = 1.2f;
			fadeInFadeOutObject->m_Script->SetSign(true);
			fadeInFadeOutObject->SetStatus(game::Status::Active);
		}
	}

	if (m_fDelayTime > 5.5f && m_bFadeinFadeoutCooltime == true)
	{
		ResourceManager::GetInstance()->PlayMusic(game::eSoundList::STORY_Story11_Bombing, 1, game::eSoundChannel::Voice);
		fadeInFadeOutObject->SetStatus(game::Status::Active);
		m_bExplosion = true;
		m_fDelayTime = 0;
	}

	if (m_bExplosion == true)
	{
		if (m_fDelayTime > .9f && m_TexComp->m_uRenderIndex < 14)
		{
			m_fDelayTime = 0;
			m_TexComp->m_uRenderIndex++;
		}
	}

	if (m_TexComp->m_uRenderIndex == 14)
	{
		if (m_fDelayTime > 4.f)
		{
			Observer::GetInstance()->m_GameFlag = game::SCENE_TYPE::START;
		}
	}

}

void EndingStory_TextureScript::Update(float deltaTime)
{

}

EndingStory_TextureScript::~EndingStory_TextureScript()
{

}
