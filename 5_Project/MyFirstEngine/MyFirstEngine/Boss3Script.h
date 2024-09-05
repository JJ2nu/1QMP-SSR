#pragma once
#include "ScriptComponent.h"
#include "ResourceManager.h"
#include "InputSystem.h"
#include "WeaponObject.h"
#include "HomingWeaponObject.h"
#include "CrossAreaWeaponObject.h"
#include "LaserWeaponObject.h"
#include "ProjectileWeaponObject.h"
#include "SlowMissileObject.h"
#include "FastMissileObject.h" 
#include "MeteorObject.h"
#include "SupportingMissileObject.h"
#include "Observer.h"
#include "PrototypeBackgroundObject.h"
#include <cstdlib> 
#include <ctime>  
#include <vector>

class Boss3Script :
	public ScriptComponent
{
public:
	virtual void Start();
	virtual void Update(float deltaTime) {};
	virtual void FixedUpdate(float fixedDeltaTime);
	virtual void Render() {};
	virtual void OnCollisionEnter(ColliderComponent* src);
	virtual void OnCollisionExit(ColliderComponent* src) {};

	//Status
public:
	float m_fHP = 1200.0f;
	float m_fMaxHP = m_fHP;
	bool m_bHardFlag = Observer::GetInstance()->m_bHardFlag;

private:
	//Damage
	void GetDamage(float Damage);

private:
	TextureComponent* m_cTexture;
	float   m_fTextureRenderTime = 0;

	float hitTimer = 0.0f;

	float elapsedTime = 0.0f;
	float elapsedTime2 = 0.0f; // 패턴ID : 401
	float elapsedTime3 = 0.0f; // 패턴ID : 402
	float elapsedTime4 = 0.0f; // 패턴ID : 403
	float elapsedTime5 = 0.0f;
	float elapsedTime6 = 0.0f;
	float elapsedTime7 = 0.0f; // 발악 딜레이용
	float elapsedTimer407 = 0.0f;
	int pattern401Index = 0;
	int pattern402Index = 0;
	int pattern403Index = 0;
	int pattern404Index = 0;
	int pattern404PlusIndex = 0;
	int pattern404Count = 50;
	int pattern405Index = 0;
	int pattern407Index = 0;
	int pattern500Index = -1;


	enum WEAPON_TYPE {
		HOMING,
		PROJECTILE,
		WEAPON_TYPE_END
	};

	ColliderComponent* m_cCollider;
	AnimationComponent* m_cRender;


public:
	CrossAreaWeaponObject* area[7][7];
	std::vector<HomingWeaponObject*>m_vHomingWeaponPool;
	std::vector<SlowMissileObject*>m_vSlowMissilePool;
	std::vector<FastMissileObject*>m_vFastMissilePool;
	std::vector<MeteorObject*>m_vMeteorPool;
	std::vector<SupportingMissileObject*>m_vSupportingMissilePool;
	LaserWeaponObject* m_laserWeapon;


public:
	int m_iHomingMissileIndex = 0;
	int m_iSlowMissileIndex = 0;
	int m_iFastMissileIndex = 0; //건드림
	int m_iMeteorIndex = 0;      //건드림
	static float floatingVector;// = 1.0f;


	Boss3Script(GameObject* pOwner, std::string ObjName);
	void PatternHP15();

	float m_fPatternTimer[30] = { 0.0f, };
	void PatternFixedUpdate(void (Boss3Script::* funcToExecute)(), float fixedDeltaTime, float fixedInterval, float& patternTimer);
	void PatternFixedUpdate(void (Boss3Script::* funcToExecute)(int), int param1, float fixedDeltaTime, float fixedInterval, float& patternTimer);
	void PatternFixedUpdate(void (Boss3Script::* funcToExecute)(int, int), int param1, int param2, float fixedDeltaTime, float fixedInterval, float& patternTimer);
	void PatternFixedUpdate(void (Boss3Script::* funcToExecute)(float), float param1, float fixedDeltaTime, float fixedInterval, float& patternTimer);

	void ComponentInitialize();
	void WeaponInitialize();
	void HomingWeaponSpawn(int index);
	void SlowMissileSpawn(int index);
	void FastMissileSpawn(int index);
	void LaserWeaponSpawn();
	void MeteorSpawn(int index);
	void AnimationUpdate(float fixedDeltaTime);

	void Pattern101(int x, int y); // 십자
	void Pattern102(int x, int y); // 엑스
	void Pattern103(int x, int y); // 3x3


	//float 
	void Pattern401(float fixedDeltaTime, float interval); // 피자패턴 401
	void Pattern402(float fixedDeltaTime, float interval); // 피자패턴 402
	void Pattern403(float fixedDeltaTime, float interval); // 구석패턴 403
	void Pattern404(float fixedDeltaTime, float interval); // 미로패턴 404
	void Pattern405(float fixedDeltaTime);// 랜덤 패턴 405
	void Pattern407(float fixedDeltaTime, float interval); // 발악패턴
	void Pattern500();

	bool b_PizzaPattern401[9][7][7] = {
	   {   // 1번
		  {0, 0, 0, 0, 0, 0, 0},
		  {0, 0, 0, 0, 0, 0, 0},
		  {0, 0, 0, 0, 0, 0, 0},
		  {1, 1, 1, 1, 1, 1, 1},
		  {0, 0, 0, 0, 0, 0, 0},
		  {0, 0, 0, 0, 0, 0, 0},
		  {0, 0, 0, 0, 0, 0, 0}
	   },

	   {   // 2번
		  {0, 0, 0, 0, 0, 0, 0},
		  {1, 0, 0, 0, 0, 0, 0},
		  {1, 1, 0, 0, 0, 0, 0},
		  {0, 0, 1, 1, 1, 0, 0},
		  {0, 0, 0, 0, 0, 1, 1},
		  {0, 0, 0, 0, 0, 0, 1},
		  {0, 0, 0, 0, 0, 0, 0}
	   },

	   {   // 3번
		  {1, 0, 0, 0, 0, 0, 0},
		  {0, 1, 0, 0, 0, 0, 0},
		  {0, 0, 1, 0, 0, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 0, 0, 1, 0, 0},
		  {0, 0, 0, 0, 0, 1, 0},
		  {0, 0, 0, 0, 0, 0, 1}
	   },

	   {   // 4번
		  {0, 1, 1, 0, 0, 0, 0},
		  {0, 0, 1, 0, 0, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 0, 0, 1, 0, 0},
		  {0, 0, 0, 0, 1, 1, 0}
	   },

	   {   // 5번
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0}
	   },

	   {   // 6번
		  {0, 0, 0, 0, 1, 1, 0},
		  {0, 0, 0, 0, 1, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 1, 0, 0, 0, 0},
		  {0, 1, 1, 0, 0, 0, 0}
	   },

	   {   // 7번
		  {0, 0, 0, 0, 0, 0, 1},
		  {0, 0, 0, 0, 0, 1, 0},
		  {0, 0, 0, 0, 1, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 1, 0, 0, 0, 0},
		  {0, 1, 0, 0, 0, 0, 0},
		  {1, 0, 0, 0, 0, 0, 0}
	   },

	   {   // 8번
		  {0, 0, 0, 0, 0, 0, 0},
		  {0, 0, 0, 0, 0, 0, 1},
		  {0, 0, 0, 0, 0, 1, 1},
		  {0, 0, 1, 1, 1, 0, 0},
		  {1, 1, 0, 0, 0, 0, 0},
		  {1, 0, 0, 0, 0, 0, 0},
		  {0, 0, 0, 0, 0, 0, 0}
	   },

	   {   // 9번
		  {0, 0, 0, 0, 0, 0, 0},
		  {0, 0, 0, 0, 0, 0, 0},
		  {0, 0, 0, 0, 0, 0, 0},
		  {1, 1, 1, 1, 1, 1, 1},
		  {0, 0, 0, 0, 0, 0, 0},
		  {0, 0, 0, 0, 0, 0, 0},
		  {0, 0, 0, 0, 0, 0, 0}
	   },
	};
	bool b_PizzaPattern402[9][7][7] = {

	   {
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0},
		  {1, 1, 1, 1, 1, 1, 1},
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0}
	   },

	   {
		  {0, 0, 0, 0, 1, 1, 0},
		  {1, 0, 0, 0, 1, 0, 0},
		  {1, 1, 0, 1, 0, 0, 0},
		  {0, 0, 1, 1, 1, 0, 0},
		  {0, 0, 0, 1, 0, 1, 1},
		  {0, 0, 1, 0, 0, 0, 1},
		  {0, 1, 1, 0, 0, 0, 0}
	   },

	   {
		  {1, 0, 0, 0, 0, 0, 1},
		  {0, 1, 0, 0, 0, 1, 0},
		  {0, 0, 1, 0, 1, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 1, 0, 1, 0, 0},
		  {0, 1, 0, 0, 0, 1, 0},
		  {1, 0, 0, 0, 0, 0, 1}
	   },

	   {
		  {0, 1, 1, 0, 0, 0, 0},
		  {0, 0, 1, 0, 0, 0, 1},
		  {0, 0, 0, 1, 0, 1, 1},
		  {0, 0, 1, 1, 1, 0, 0},
		  {1, 1, 0, 1, 0, 0, 0},
		  {1, 0, 0, 0, 1, 0, 0},
		  {0, 0, 0, 0, 1, 1, 0}
	   },
		{
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0},
		  {1, 1, 1, 1, 1, 1, 1},
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0}
	   },

	   {
		  {0, 0, 0, 0, 1, 1, 0},
		  {1, 0, 0, 0, 1, 0, 0},
		  {1, 1, 0, 1, 0, 0, 0},
		  {0, 0, 1, 1, 1, 0, 0},
		  {0, 0, 0, 1, 0, 1, 1},
		  {0, 0, 1, 0, 0, 0, 1},
		  {0, 1, 1, 0, 0, 0, 0}
	   },

	   {
		  {1, 0, 0, 0, 0, 0, 1},
		  {0, 1, 0, 0, 0, 1, 0},
		  {0, 0, 1, 0, 1, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 1, 0, 1, 0, 0},
		  {0, 1, 0, 0, 0, 1, 0},
		  {1, 0, 0, 0, 0, 0, 1}
	   },

	   {
		  {0, 1, 1, 0, 0, 0, 0},
		  {0, 0, 1, 0, 0, 0, 1},
		  {0, 0, 0, 1, 0, 1, 1},
		  {0, 0, 1, 1, 1, 0, 0},
		  {1, 1, 0, 1, 0, 0, 0},
		  {1, 0, 0, 0, 1, 0, 0},
		  {0, 0, 0, 0, 1, 1, 0}
	   },
		{
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0},
		  {1, 1, 1, 1, 1, 1, 1},
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0},
		  {0, 0, 0, 1, 0, 0, 0}
	   }


	};
	bool b_CornerPattern403[5][7][7] = {

	  {
		 {1, 1, 1, 1, 0, 0, 0},
		 {1, 1, 1, 1, 0, 0, 0},
		 {1, 1, 1, 1, 0, 0, 0},
		 {1, 1, 1, 1, 0, 0, 0},
		 {1, 1, 1, 1, 0, 0, 0},
		 {1, 1, 1, 1, 0, 0, 0},
		 {1, 1, 1, 1, 0, 0, 0}
	  },

	  {
		 {0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 0},
		 {1, 1, 1, 1, 1, 1, 1},
		 {1, 1, 1, 1, 1, 1, 1},
		 {1, 1, 1, 1, 1, 1, 1},
		 {1, 1, 1, 1, 1, 1, 1},
	  },

	  {
		 {0, 0, 0, 1, 1, 1, 1},
		 {0, 0, 0, 1, 1, 1, 1},
		 {0, 0, 0, 1, 1, 1, 1},
		 {0, 0, 0, 1, 1, 1, 1},
		 {0, 0, 0, 1, 1, 1, 1},
		 {0, 0, 0, 1, 1, 1, 1},
		 {0, 0, 0, 1, 1, 1, 1},
	  },

	  {
		 {0, 0, 0, 0, 0, 0, 0},
		 {1, 1, 1, 1, 1, 1, 1},
		 {1, 1, 1, 1, 1, 1, 1},
		 {1, 1, 1, 1, 1, 1, 1},
		 {1, 1, 1, 1, 1, 1, 1},
		 {1, 1, 1, 1, 1, 1, 1},
		 {1, 1, 1, 1, 1, 1, 1},
	  },

	  {
		 {0, 1, 1, 1, 1, 1, 1},
		 {1, 1, 1, 1, 1, 1, 1},
		 {1, 1, 1, 1, 1, 1, 1},
		 {1, 1, 1, 1, 1, 1, 1},
		 {1, 1, 1, 1, 1, 1, 1},
		 {1, 1, 1, 1, 1, 1, 1},
		 {1, 1, 1, 1, 1, 1, 1},
	  }
	};
	bool b_Mazepattern404[27][7] = {
		{0,1,1,1,0,1,1},
		{0,0,0,0,0,0,0},
		{0,0,0,1,0,0,1},
		{1,1,0,0,1,0,0},
		{0,0,0,0,0,0,1},
		{1,1,1,0,0,0,0},
		{0,0,0,0,1,1,1},
		{1,0,0,0,0,0,0},
		{0,0,1,1,0,0,0},
		{0,0,0,0,1,1,0},
		{0,1,0,0,0,0,0},
		{0,0,0,0,0,1,0},
		{0,0,0,1,0,0,0},
		{1,1,1,0,0,0,0},
		{0,0,0,1,0,1,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,1,0,0,0,0,1},
		{0,0,1,1,1,0,0},
		{0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0},
		{0,1,0,0,1,1,1},
		{0,0,1,0,0,0,0},
		{0,0,0,0,0,1,0},
		{1,0,1,1,0,0,0},
		{0,0,0,0,0,0,0},
		{0,1,1,0,0,1,1}
	};




};
