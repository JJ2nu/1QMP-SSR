#include "Middle_Story_01_Scene.h"
#include "Middle_Story_01_ButtonUI.h"
#include "Middle_Story_01_BackGroundUI.h"

#include "Middle_Story_01_Dialog.h"
#include "CrossHairObject.h"

void Middle_Story_01_Scene::Initialize()
{

}

void Middle_Story_01_Scene::Finalize()
{

}

void Middle_Story_01_Scene::Enter()
{
	//BGM
	ResourceManager::GetInstance()->PlayMusic(game::eSoundList::BGM, 2, game::eSoundChannel::BGM);

	Middle_Story_01_BackGroundUI* middle_Story_01_BackGroundUI = new Middle_Story_01_BackGroundUI(this);
	AddObject(middle_Story_01_BackGroundUI, game::OBJECT_TYPE::UI);

	Middle_Story_01_ButtonUI* middle_Story_01_ButtonUI = new Middle_Story_01_ButtonUI(this);
	AddObject(middle_Story_01_ButtonUI, game::OBJECT_TYPE::UI);

	Middle_Story_01_Dialog* middle_Story_01_Dialog = new Middle_Story_01_Dialog(this);
	AddObject(middle_Story_01_Dialog, game::OBJECT_TYPE::UI);

	CrossHairObject* crossHairObject = new CrossHairObject(this);
	AddObject(crossHairObject, game::OBJECT_TYPE::UI);
}

void Middle_Story_01_Scene::Exit()
{
	m_ColliderManager.ResetGroup();
}
