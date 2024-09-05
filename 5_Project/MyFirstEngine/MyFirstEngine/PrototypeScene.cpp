#include "PrototypeScene.h"
#include "CutSceneBossObject.h"
#include "PrototypeBackgroundObject.h"

void PrototypeScene::Initialize()
{
}

void PrototypeScene::Finalize()
{
}

void PrototypeScene::Enter()
{
	GameObject* Player = new CutSceneBossObject(this);
	AddObject(Player, game::OBJECT_TYPE::UI);

	// 백그라운 배경
	GameObject* PrototypeBackground = new PrototypeBackgroundObject(this);
	AddObject(PrototypeBackground, game::OBJECT_TYPE::BACKGROUND);
}

void PrototypeScene::Exit()
{
}

PrototypeScene::PrototypeScene()
: SceneBase("PrototypeScene")
{}

PrototypeScene::~PrototypeScene()
{}
