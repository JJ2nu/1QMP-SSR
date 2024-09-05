#include "Story_Briefing_Scene.h"
#include "Story02_Dialog_Briefing.h"
#include "StoryBriefingBackGroundUI.h"
#include "Story_Briefing_ButtonUI.h"

#include "CrossHairObject.h"

void Story_Briefing_Scene::Initialize()
{

}

void Story_Briefing_Scene::Finalize()
{

}

void Story_Briefing_Scene::Enter()
{
	//BGM
	ResourceManager::GetInstance()->PlayMusic(game::eSoundList::BGM, 2, game::eSoundChannel::BGM);

	StoryBriefingBackGroundUI* storyBriefingBackGroundUI = new StoryBriefingBackGroundUI(this);
	AddObject(storyBriefingBackGroundUI, game::OBJECT_TYPE::UI);

	Story02_Dialog_Briefing* story02_Dialog_Briefing = new Story02_Dialog_Briefing(this);
	AddObject(story02_Dialog_Briefing, game::OBJECT_TYPE::UI);

	Story_Briefing_ButtonUI* story_Briefing_ButtonUI = new Story_Briefing_ButtonUI(this);
	AddObject(story_Briefing_ButtonUI, game::OBJECT_TYPE::UI);

	CrossHairObject* CrossHair = new CrossHairObject(this);
	AddObject(CrossHair, game::OBJECT_TYPE::UI);
}

void Story_Briefing_Scene::Exit()
{
	ResourceManager::GetInstance()->StopMusic(game::eSoundChannel::BGM);
	m_ColliderManager.ResetGroup();
}
