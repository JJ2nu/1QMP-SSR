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
#include "FastMissileObject.h" // FastMissile 때문에 건드렸습니다.
#include "MeteorObject.h"      // MeteorObject 때문에 건드렸습니다.

#include<cstdlib> // 건드림
#include<ctime>   // 건드림

#include <vector>
class Boss_1_Script :
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
    float m_fHP = 100.0f;
    float m_fMaxHP = m_fHP;

private:
    //Damage
    void GetDamage(float Damage);

private:
    TextureComponent* m_cTexture;
    float   m_fTextureRenderTime = 0;

    float elapsedTime = 0.0f;
    float elapsedTime2 = 0.0f; // 패턴ID : 401
    float elapsedTime3 = 0.0f; // 패턴ID : 402
    float elapsedTime4 = 0.0f; // 패턴ID : 403
    float elapsedTime5 = 0.0f;
    float elapsedTime6 = 0.0f;
    int pattern401Index = 0;
    int pattern402Index = 0;
    int pattern403Index = 0;
    int pattern404Index = 0;
    int pattern404PlusIndex = 0;
    int pattern404Count = 30;
    int pattern405Index = 0;


    CrossAreaWeaponObject* area[7][7];
    enum WEAPON_TYPE {
        HOMING,
        PROJECTILE,
        WEAPON_TYPE_END
    };

    ColliderComponent* m_cCollider;
    AnimationComponent* m_cRender;


public:
    std::vector<HomingWeaponObject*>m_vHomingWeaponPool;
    std::vector<SlowMissileObject*>m_vSlowMissilePool;
    std::vector<FastMissileObject*>m_vFastMissilePool;  //여기도 pool 때문에 건드렸습니다.
    std::vector<MeteorObject*>m_vMeteorPool;          //여기도 pool 때문에 건드렸습니다.


public:
    int m_iSlowMissileIndex = 0;
    int m_iFastMissileIndex = 0; //건드림
    int m_iMeteorIndex = 0;      //건드림
    static float floatingVector;// = 1.0f;


    Boss_1_Script(GameObject* pOwner, std::string ObjName);

    void Delay(float time);

    void AnimationInitialize();

    void AnimationUpdate(float fixedDeltaTime);

    void Pattern101(int x, int y); // 십자
    void Pattern102(int x, int y); // 엑스
    void Pattern103(int x, int y); // 3x3


    //float 
    void Pattern401(float fixedDeltaTime); // 피자패턴 401
    void Pattern402(float fixedDeltaTime); // 피자패턴 402
    void Pattern403(float fixedDeltaTime); // 구석패턴 403
    void Pattern404(float fixedDeltaTime, float interval); // 미로패턴 404
    void Pattern405(float fixedDeltaTime);// 랜덤 패턴 405
    

    //void Pattern104(Vector3); // 보스 레이저
    //void Pattern104(Vector3); // 보스 레이저

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
    bool b_Mazepattern404[27][7] = 
    {
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
