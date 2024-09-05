#include "Ship_Directing_Boss_02_Scene.h"
#include "ShipDirectingBoss_02_Object.h"

void Ship_Directing_Boss_02_Scene::Initialize()
{

}

void Ship_Directing_Boss_02_Scene::Finalize()
{

}

void Ship_Directing_Boss_02_Scene::Enter()
{
	//BGM
	ResourceManager::GetInstance()->PlayMusic(game::eSoundList::BGM, 4, game::eSoundChannel::BGM);

	ShipDirectingBoss_02_Object* shipDirectingBoss_02_Object = new ShipDirectingBoss_02_Object(this);
	AddObject(shipDirectingBoss_02_Object, game::OBJECT_TYPE::UI);
}

void Ship_Directing_Boss_02_Scene::Exit()
{
	//BGM
	ResourceManager::GetInstance()->StopMusic(game::eSoundChannel::BGM);
}
