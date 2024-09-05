#include "Start_Menu.h"

#include "CrossHairObject.h"
#include "Start_BackGroundUI.h"


void Start_Menu::Initialize()
{
}

void Start_Menu::Finalize()
{
}

void Start_Menu::Enter()
{
	//BGM
	ResourceManager::GetInstance()->PlayMusic(game::eSoundList::BGM, 0, game::eSoundChannel::BGM);

	Start_BackGroundUI* start_BackGroundUI = new Start_BackGroundUI(this);
	AddObject(start_BackGroundUI, game::OBJECT_TYPE::UI);

	CrossHairObject* CrossHair = new CrossHairObject(this);
	AddObject(CrossHair, game::OBJECT_TYPE::MOUSE_CROSSHAIR);



}

void Start_Menu::Exit()
{
	m_ColliderManager.ResetGroup();
}
