#include "SampleScene.h"
#include "PlayerGameObject.h"
#include "CrossHairObject.h"

#include "BossGameObject.h"
#include "PrototypeBackgroundObject.h"
#include "SampleSceneUI.h"
#include "Observer.h"


void SampleScene::Initialize()
{
}

void SampleScene::Finalize()
{
}


void SampleScene::Enter()
{
		// 플레이어
		PlayerGameObject* Player = new PlayerGameObject(this);
		Observer::GetInstance()->SetPlayer(Player);
		AddObject(Player, game::OBJECT_TYPE::PLAYER);


		// 마운스 포인트
		CrossHairObject* CrossHair = new CrossHairObject(this);
		AddObject(CrossHair, game::OBJECT_TYPE::UI);

		// 보스 

		// 백그라운 배경
		PrototypeBackgroundObject* PrototypeBackground = new PrototypeBackgroundObject(this);
		AddObject(PrototypeBackground, game::OBJECT_TYPE::BACKGROUND);	
		Observer::GetInstance()->SetBackground(PrototypeBackground);
	
		BossObject* Boss = new BossObject(this,3);
		Observer::GetInstance()->SetBoss(Boss);		
		AddObject(Boss, game::OBJECT_TYPE::BOSS);
		Boss->m_Transform.SetPosition(1550.f, 560.f, 0);

		BossHPUI* bossHPUI = new BossHPUI(this);
		AddObject(bossHPUI, game::OBJECT_TYPE::UI);
		bossHPUI->m_Transform.SetPosition(1500, 80, 0);

		PlayerHPUI* playerHPUI = new PlayerHPUI(this);
		AddObject(playerHPUI, game::OBJECT_TYPE::UI);
		playerHPUI->m_Transform.SetPosition(460, 80, 0);

		CharacterPlayUI* characterPlayUI = new CharacterPlayUI(this);
		AddObject(characterPlayUI, game::OBJECT_TYPE::UI);
		characterPlayUI->m_Transform.SetPosition(80.f, 80.f, 0);
	
	
		m_ColliderManager.CheckGroup(game::OBJECT_TYPE::PLAYER, game::OBJECT_TYPE::ENEMY_WEAPON);
		m_ColliderManager.CheckGroup(game::OBJECT_TYPE::PLAYER, game::OBJECT_TYPE::HOMING_WEAPON);
		m_ColliderManager.CheckGroup(game::OBJECT_TYPE::BOSS, game::OBJECT_TYPE::PLAYER_WEAPON);
		m_ColliderManager.CheckGroup(game::OBJECT_TYPE::MOUSE_CROSSHAIR, game::OBJECT_TYPE::HOMING_WEAPON);

}


void SampleScene::Exit()
{
	m_ColliderManager.ResetGroup();
}

SampleScene::SampleScene()
	:SceneBase("SampleScene")
{}

SampleScene::~SampleScene()
{}
