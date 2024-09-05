#include "Tutorial_Scene.h"
#include "Tutorial_BackGroundUI.h"
#include "Text_Tutorial_ESC.h"
#include "CrossHairObject.h"

void Tutorial_Scene::Initialize()
{
}

void Tutorial_Scene::Finalize()
{
}

void Tutorial_Scene::Enter()
{
	//BGM
	ResourceManager::GetInstance()->PlayMusic(game::eSoundList::BGM, 3, game::eSoundChannel::BGM);

	Tutorial_BackGroundUI* tutorial_BackGroundUI = new Tutorial_BackGroundUI(this);
	AddObject(tutorial_BackGroundUI, game::OBJECT_TYPE::UI);

	CrossHairObject* CrossHair = new CrossHairObject(this);
	AddObject(CrossHair, game::OBJECT_TYPE::UI);

	Text_Tutorial_ESC* text_Tutorial_ESC = new Text_Tutorial_ESC(this);
	AddObject(text_Tutorial_ESC, game::OBJECT_TYPE::UI);
}

void Tutorial_Scene::Exit()
{
	//m_ColliderManager.ResetGroup();
	
	//BGM
	ResourceManager::GetInstance()->StopMusic(game::eSoundChannel::BGM);
}
