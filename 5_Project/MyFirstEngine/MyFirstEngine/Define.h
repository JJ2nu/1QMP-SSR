#pragma once

#define DebugModeFlag 0

namespace game
{
#define DebugMode 0
#define DevelopKey 1
#define FixedUpdateTime 0.02 //0.02초
#define ScreenWidth 1920 
#define ScreenHeight 1080

	enum class COMPONENT_LAYER
	{
		Script,
		Collider,
		Render,
		ENd
	};
	
	enum class OBJECT_TYPE
	{
		DEFAULT,
		BACKGROUND,
		FACTORY,
		BOSS,
		ITEM,
		WEAPON,
		ENEMY_WEAPON,
		HOMING_WEAPON,
		PLAYER_WEAPON,
		PLAYER,
		UI,
		MOUSE_CROSSHAIR,

		END//최대 32
	};

	enum class SCENE_TYPE
	{
		START,								// 시작 화면
		MAIN_MENU,							// 메인 메뉴 (난이도 버튼 클릭하여 씬이동)
		STAGE_TUTORIAL,						// 튜토리얼
		SALLY,								// 출격씬
		STAGE_NORMAL_01,					// 노말 모드 보스1
		STAGE_NORMAL_02,					// 노말 모드 보스2
		STAGE_NORMAL_03,					// 노말 모드 보스3
		STAGE_HARD_01,						// 하드 모드 보스1
		STAGE_HARD_02,						// 하드 모드 보스2
		STAGE_HARD_03,						// 하드 모드 보스3
		INTRODUCTION_STORY_NEWS,			// 도입 스토리(뉴스)
		INTRODUCTION_STORY_BRIEFING,		// 도입 스토리(요약 보고)
		PLAY,								// 일단 테스트씬 사용중  추후 삭제할예정
		UPGRADE,							// 업그레이드 씬
		MIDDLE_STORY_01,					// 1스테이지 클리어 중간 스토리
		MIDDLE_STORY_02,					// 2스테이지 클리어 중간 스토리
		ENDING_STORY,						// 엔딩 스토리				
		SHIP_DIRECTING_BOSS_01,				// 함선 보스1 애니메이션 연출
		SHIP_DIRECTING_BOSS_02,				// 함선 보스2 애니메이션 연출
		SHIP_DIRECTING_BOSS_03,				// 함선 보스3 애니메이션 연출
		SPARE,								// 예비씬
		COKPIT,								// 비행기 타는 씬
		ENDING,								// 엔딩크레딧
		CHANGE_EFFECT,						// 씬 전환 효과
		END
	};

	//
	//수정	//이거 컴포넌트와 게임 오브젝트 다 가지도록 만들고 각각 조절 가능하게
	//		//메인 오브젝트만에서 끄면 다 꺼지고 키면 다 켜지게
	//
	enum class Status
	{
		InActive,
		Active,
		Destroy
	};

	enum class eSoundChannel
	{
		BGM,
		UI,
		Voice,
		//플레이어 일반 공격
		SFX_Player_Attack,
		//플레이어 차지 공격
		SFX_Player_Attack_Charge,
		//플레이어 적 미사일 요격
		SFX_Player_Intercept,
		//플레이어 피격
		SFX_Player_Hitted,
		//플레이어 사망
		SFX_Player_Dead,
		//플레이어 쉴드
		SFX_Player_Skill_Shield,
		//플레이어 무적 사용
		SFX_Player_Skill_Invincible,
		//플레이어 포탈 사용
		SFX_Player_Skill_Portal,
		//보스 일반 저속 미사일 발사
		SFX_Boss_Missile_Slow_1,
		SFX_Boss_Missile_Slow_2,
		//보스 일반 고속 미사일 발사
		SFX_Boss_Missile_Fast_1,
		SFX_Boss_Missile_Fast_2,
		//보스 유도 미사일 발사
		SFX_Boss_Missile_Guided_1,
		SFX_Boss_Missile_Guided_2,
		//보스 레이저 공격(준비, 발사, 캔슬)
		SFX_Boss_Laser,
		SFX_Boss_Laser_Click,
		//장판 공격 경고
		SFX_Warning_Area_1,
		SFX_Warning_Area_2,
		SFX_Warning_Area_3,
		SFX_Warning_Area_4,
		//폭발음
		SFX_Explosion_1,
		SFX_Explosion_2,
		SFX_Explosion_3,
		SFX_Explosion_4,
		//메테오 공격 경고
		SFX_Warning_Meteo,
		//강력한 공격 경고
		SFX_Warning_Danger,
		//플레이어 지원 미사일
		SFX_Support_Missile,
	
		End
	};

	enum class eSoundList
	{
		BGM,
		Battle,
		UI,

		STORY_Story01_News,
		STORY_Story02_Briefing,
		STORY_Story03_Takeoff,
		STORY_Story04_Encounters,
		STORY_Story05_Briefing,
		STORY_Story06_Encounters,
		STORY_Story07_Briefing,
		STORY_Story08_Encounters,
		STORY_Story09_News,
		STORY_Story10_Briefing,
		STORY_Story11_Bombing,
	


		STORY_Stage01_Battle,
		STORY_Stage02_Battle,
		STORY_Stage03_Battle,

		End
	};

	enum class EVENT_TYPE
	{
		//임시로 이름 이렇게 지어놓고 필요하면 추가해서 보충하자
		event1,
		event2,
		event3,

		End
	};

}
