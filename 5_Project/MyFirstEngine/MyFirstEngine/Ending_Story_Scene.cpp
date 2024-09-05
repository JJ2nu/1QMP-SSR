#include "Ending_Story_Scene.h"
#include "EndingStoryBackGroundUI.h"
#include "EndingStory_Dialog.h"
#include "Ending_Story_ButtonUI.h"

void Ending_Story_Scene::Initialize()
{

}

void Ending_Story_Scene::Finalize()
{

}

void Ending_Story_Scene::Enter()
{
	ResourceManager::GetInstance()->PlayMusic(game::eSoundList::BGM, 8, game::eSoundChannel::BGM);

	EndingStoryBackGroundUI* endingStoryBackGroundUI = new EndingStoryBackGroundUI(this);
	AddObject(endingStoryBackGroundUI, game::OBJECT_TYPE::UI);

	//EndingStory_Dialog* endingStory_Dialog = new EndingStory_Dialog(this);
	//AddObject(endingStory_Dialog, game::OBJECT_TYPE::UI);

	//Ending_Story_ButtonUI* ending_Story_ButtonUI = new Ending_Story_ButtonUI(this);
	//AddObject(ending_Story_ButtonUI, game::OBJECT_TYPE::UI);
}

void Ending_Story_Scene::Exit()
{
	m_ColliderManager.ResetGroup();

	//BGM
	//ResourceManager::GetInstance()->StopMusic(game::eSoundChannel::BGM);
}
