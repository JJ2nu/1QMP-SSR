#include "Ship_Directing_Boss_03_Scene.h"
#include "ShipDirectingBoss_03_Object.h"

void Ship_Directing_Boss_03_Scene::Initialize()
{

}

void Ship_Directing_Boss_03_Scene::Finalize()
{

}

void Ship_Directing_Boss_03_Scene::Enter()
{
	//BGM
	ResourceManager::GetInstance()->PlayMusic(game::eSoundList::BGM, 2, game::eSoundChannel::BGM);

	ShipDirectingBoss_03_Object* storyBriefingBackGroundUI = new ShipDirectingBoss_03_Object(this);
	AddObject(storyBriefingBackGroundUI, game::OBJECT_TYPE::UI);
}

void Ship_Directing_Boss_03_Scene::Exit()
{
	//BGM
	ResourceManager::GetInstance()->StopMusic(game::eSoundChannel::BGM);
}
