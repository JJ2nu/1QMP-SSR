#pragma once
#include "Define.h"

class PlayerGameObject;
class BossObject;
class Boss_1_Object;
class FadeInFadeOutObject;
class PrototypeBackgroundObject;

class Observer
{
private:
	static Observer* instance;

public:
	void SetPlayer(PlayerGameObject* Player) { m_Player = Player; }
	const PlayerGameObject* GetPlayer() { return m_Player; }
	void SetBoss(BossObject* boss) { m_Boss = boss; }
	BossObject* GetBoss() { return m_Boss; }
	void SetBoss1(Boss_1_Object* boss) { m_Boss_1 = boss; }
	Boss_1_Object* GetBoss1() { return m_Boss_1; }
	void SetBackground(PrototypeBackgroundObject* bg) { m_BG = bg; }
	PrototypeBackgroundObject* GetBackground() { return m_BG; }

	void SettingPlayerEnhance();

public:
	static Observer* GetInstance();
	static void DestroyInstance();

public:
	PlayerGameObject* m_Player;
	BossObject* m_Boss;
	Boss_1_Object* m_Boss_1;


	PrototypeBackgroundObject* m_BG;

	//FadeInFadeOut
	FadeInFadeOutObject* m_FadeInFadeOut;
	game::SCENE_TYPE m_GameFlag = game::SCENE_TYPE::END;
	game::SCENE_TYPE m_CurSceneFlag = game::SCENE_TYPE::END;


	//PlayerInfo
	struct PlayerInfo
	{
		//실드
		bool m_bShield = false;
		int  m_iMaxShield = 0;
		
		//무적
		bool m_bInvincibility = false;
		
		//강화 공격력비율 1.5배
		int m_fEnhanceDamageRatio = 0;
		
		//강화 공격 차지 속도 x 1.5
		int m_iEnhanceBulletRate = 0;

		//포탈 true/80;
		bool m_bPortal = false;
	} m_sPlayerInfo;

	int m_iStageNum = 0;
	bool m_bHardFlag;

	int m_iStoryIndex = 0;

private:
	Observer();
	~Observer();
};

