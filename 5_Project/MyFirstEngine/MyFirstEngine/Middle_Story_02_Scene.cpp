#include "Middle_Story_02_Scene.h"
#include "Middle_Story_02_ButtonUI.h"
#include "Middle_Story_02_BackGroundUI.h"
#include "Middle_Story_02_Dialog.h"
#include "CrossHairObject.h"

void Middle_Story_02_Scene::Initialize()
{

}

void Middle_Story_02_Scene::Finalize()
{

}

void Middle_Story_02_Scene::Enter()
{
	//BGM
	ResourceManager::GetInstance()->PlayMusic(game::eSoundList::BGM, 2, game::eSoundChannel::BGM);

	Middle_Story_02_BackGroundUI* middle_Story_02_BackGroundUI = new Middle_Story_02_BackGroundUI(this);
	AddObject(middle_Story_02_BackGroundUI, game::OBJECT_TYPE::UI);

	Middle_Story_02_Dialog* middle_Story_02_Dialog = new Middle_Story_02_Dialog(this);
	AddObject(middle_Story_02_Dialog, game::OBJECT_TYPE::UI);

	Middle_Story_02_ButtonUI* middle_Story_02_ButtonUI = new Middle_Story_02_ButtonUI(this);
	AddObject(middle_Story_02_ButtonUI, game::OBJECT_TYPE::UI);

	CrossHairObject* crossHairObject = new CrossHairObject(this);
	AddObject(crossHairObject, game::OBJECT_TYPE::UI);
}

void Middle_Story_02_Scene::Exit()
{
	m_ColliderManager.ResetGroup();
}
