#include "Ending_Credits_Scene.h"
#include "CrossHairObject.h"
#include "Text_Tutorial_ESC.h"
#include "ResourceManager.h"
#include "Ending_Credits_BackGround.h"

void Ending_Credits_Scene::Initialize()
{

}

void Ending_Credits_Scene::Finalize()
{

}

void Ending_Credits_Scene::Enter()
{
	ResourceManager::GetInstance()->PlayMusic(game::eSoundList::BGM, 0, game::eSoundChannel::BGM);

	Ending_Credits_BackGround* ending_Credits_BackGround = new Ending_Credits_BackGround(this);
	AddObject(ending_Credits_BackGround, game::OBJECT_TYPE::UI);

	CrossHairObject* CrossHair = new CrossHairObject(this);
	AddObject(CrossHair, game::OBJECT_TYPE::UI);

	Text_Tutorial_ESC* text_Tutorial_ESC = new Text_Tutorial_ESC(this);
	AddObject(text_Tutorial_ESC, game::OBJECT_TYPE::UI);
}

void Ending_Credits_Scene::Exit()
{

	//BGM
	ResourceManager::GetInstance()->StopMusic(game::eSoundChannel::BGM);
}
