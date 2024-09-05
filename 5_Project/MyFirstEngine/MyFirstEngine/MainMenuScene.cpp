#include "MainMenuScene.h"

// 배경
#include "MainMenuBackGroundUI.h"

// 버튼
#include "TutorialButtonUI.h"
#include "NormalButtonUI.h"
#include "HardButtonUI.h"
#include "Ending_Button.h"

#include "CrossHairObject.h"

void MainMenuScene::Initialize()
{

}

void MainMenuScene::Finalize()
{

}

void MainMenuScene::Enter()
{
	//BGM
	//ResourceManager::GetInstance()->PlayMusic(game::eSoundList::BGM, 0, game::eSoundChannel::BGM);

	// 배경
	MainMenuBackGroundUI* mainMenuBackGroundUI = new MainMenuBackGroundUI(this);
	AddObject(mainMenuBackGroundUI, game::OBJECT_TYPE::UI);

	// 튜토리얼 버튼
	TutorialButtonUI* tutorialButtonUI = new TutorialButtonUI(this);
	AddObject(tutorialButtonUI, game::OBJECT_TYPE::UI);

	// 노말 난이도 버튼
	NormalButtonUI* normalButtonUI = new NormalButtonUI(this);
	AddObject(normalButtonUI, game::OBJECT_TYPE::UI);

	// 하드 난이도 버튼
	HardButtonUI* hardButtonUI = new HardButtonUI(this);
	AddObject(hardButtonUI, game::OBJECT_TYPE::UI);

	Ending_Button* ending_Button = new Ending_Button(this);
	AddObject(ending_Button, game::OBJECT_TYPE::UI);

	CrossHairObject* CrossHair = new CrossHairObject(this);
	AddObject(CrossHair, game::OBJECT_TYPE::UI);

}

void MainMenuScene::Exit()
{
	//ResourceManager::GetInstance()->StopMusic(game::eSoundChannel::BGM);
	m_ColliderManager.ResetGroup();
}
