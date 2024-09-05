#include "Ship_Directing_Boss_01_Scene.h"
#include "ShipDirectingBoss_01_Object.h"

void Ship_Directing_Boss_01_Scene::Initialize()
{

}

void Ship_Directing_Boss_01_Scene::Finalize()
{

}

void Ship_Directing_Boss_01_Scene::Enter()
{
	//BGM SpaceShip
	ResourceManager::GetInstance()->PlayMusic(game::eSoundList::BGM, 4, game::eSoundChannel::BGM);

	ShipDirectingBoss_01_Object* shipDirectingBoss_01_Object = new ShipDirectingBoss_01_Object(this);
	AddObject(shipDirectingBoss_01_Object, game::OBJECT_TYPE::UI);
}

void Ship_Directing_Boss_01_Scene::Exit()
{
	//BGM
	ResourceManager::GetInstance()->StopMusic(game::eSoundChannel::BGM);
}
