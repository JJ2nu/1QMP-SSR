#include "Boss1Script.h"
#include "BossObject.h"
float Boss1Script::floatingVector = 1.0f;
Boss1Script::Boss1Script(GameObject* pOwner, std::string ObjName)
	:ScriptComponent(pOwner, ObjName), m_cCollider(nullptr), m_cRender(nullptr)
{
	Start();
	Observer::GetInstance()->GetBackground()->m_Script->m_cTexture->m_uRenderIndex = 0;
	std::srand(std::time(0)); // 랜덤 시드 초기화
}
Boss1Script::~Boss1Script()
{

}
void Boss1Script::ComponentInitialize()
{
	m_cTexture = m_pOwner->CreateComponent<TextureComponent>("BossTexture");
	m_cTexture->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"BossTexture1", L"\\Animation\\Player\\boss_001_001.bmp");
	m_cTexture->m_uRenderIndex = 0;
	m_cTexture->m_iRenderFlag = 2;
	m_cTexture->m_uExcep = RGB(255, 0, 255);

	m_cCollider = m_pOwner->CreateComponent<ColliderComponent>("BossColliderComponent");
	m_cCollider->m_Transform.SetScale(300.0f, 800.0f, 0);

}
void Boss1Script::WeaponInitialize()
{
	//HomingWeapon Initialize
	for (int i = 0; i < 3; i++)
	{
		HomingWeaponObject* hw = new HomingWeaponObject(m_pOwner->GetSceneBase());
		m_pOwner->AddChildGameObject(hw);
		hw->SetStatus(game::Status::InActive);
		m_vHomingWeaponPool.push_back(hw);
	}

	//SlowMissile Initialize
	for (int i = 0; i < 7; i++)
	{
		SlowMissileObject* sm = new SlowMissileObject(m_pOwner->GetSceneBase());
		sm->m_Transform.SetPosition(410, 400 + 80 * i, 0);
		sm->SetStatus(game::Status::InActive);
		m_pOwner->AddChildGameObject(sm);
		m_vSlowMissilePool.push_back(sm);
	}

	for (int i = 0; i < 7; i++)
	{
		FastMissileObject* fm = new FastMissileObject(m_pOwner->GetSceneBase());
		fm->m_Transform.SetPosition(410, 400 + 80 * i, 0);
		fm->SetStatus(game::Status::InActive);
		m_pOwner->AddChildGameObject(fm);
		m_vFastMissilePool.push_back(fm);
	}


	//Meteor Initialize
	for (int i = 0; i < 7; i++)
	{
		MeteorObject* mo = new MeteorObject(m_pOwner->GetSceneBase());
		mo->m_Transform.SetPosition(170 + (80 * i), 400, 0);
		mo->SetStatus(game::Status::InActive);
		m_pOwner->AddChildGameObject(mo);
		m_vMeteorPool.push_back(mo);
	}

	//MAZE pattern
	for (int j = 0; j < pattern404Count; j++)
	{
		for (int i = 0; i < 7; i++)
		{
			SlowMissileObject* fm = new SlowMissileObject(m_pOwner->GetSceneBase());
			fm->m_Transform.SetPosition(410, 400 + 80 * i, 0);
			fm->SetStatus(game::Status::InActive);
			m_pOwner->AddChildGameObject(fm);
			m_vSlowMissilePool.push_back(fm);
		}
	}

	//areaWeapon Initialize
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			area[i][j] = new CrossAreaWeaponObject(m_pOwner->GetSceneBase());
			area[i][j]->SetStatus(game::Status::InActive);
			area[i][j]->SetObjType(game::OBJECT_TYPE::ENEMY_WEAPON);
			area[i][j]->m_Transform.SetPosition(170 + (80 * j), 400 + (80 * i), 0);
			m_pOwner->AddChildGameObject(area[i][j]);
		}
	}

	//BossLaser Initialize
	m_laserWeapon = new LaserWeaponObject(m_pOwner->GetSceneBase());
	m_laserWeapon->m_Transform.SetPosition(350, 640, 0);
	m_laserWeapon->SetStatus(game::Status::InActive);
	m_pOwner->AddChildGameObject(m_laserWeapon);


}
void Boss1Script::HomingWeaponSpawn(int index)
{
	if (m_vHomingWeaponPool[index]->GetStatus() == game::Status::InActive)
		m_vHomingWeaponPool[index]->m_Script->Reset();
}
void Boss1Script::SlowMissileSpawn(int index)
{
	if (m_vSlowMissilePool[index]->GetStatus() == game::Status::InActive)
		m_vSlowMissilePool[index]->m_Script->Activate();
}
void Boss1Script::FastMissileSpawn(int index)
{
	if (m_vFastMissilePool[index]->GetStatus() == game::Status::InActive)
		m_vFastMissilePool[index]->m_Script->Activate();
}
void Boss1Script::LaserWeaponSpawn()
{
	if (m_laserWeapon->GetStatus() == game::Status::InActive)
	{
		m_bLaserFlag = true;
		m_laserWeapon->m_Script->Reset();
	}
}
void Boss1Script::MeteorSpawn(int index)
{
	if (m_vMeteorPool[index]->GetStatus() == game::Status::InActive)
		m_vMeteorPool[index]->m_Script->Activate();

}
void Boss1Script::AnimationUpdate(float fixedDeltaTime)
{
	m_Transform.Position.y += floatingVector * fixedDeltaTime * 10;
	elapsedTime += fixedDeltaTime;
	if (elapsedTime >= 3.0f)
	{

		floatingVector *= -1; // 보스 부유 움직임		
		elapsedTime -= 3.0f;
	}
	hitTimer += fixedDeltaTime;
	if (hitTimer >= 0.2f)
	{
		m_cTexture->m_uAlpha = 255;

		hitTimer -= 0.2f;
	}


}
void Boss1Script::Start()
{
	ComponentInitialize();
	WeaponInitialize();
}
void Boss1Script::FixedUpdate(float fixedDeltaTime)
{
	AnimationUpdate(fixedDeltaTime);
	if (m_fHP <= 0.0f)
	{
		Observer::GetInstance()->m_iStageNum = 1;
		Observer::GetInstance()->m_GameFlag = game::SCENE_TYPE::UPGRADE;
	}
	if (m_fHP > 500.0f)
	{
		if (m_fHP <= m_fMaxHP - 15.0f)
		{
			PatternFixedUpdate(&Boss1Script::PatternHP15, fixedDeltaTime, 2.5f, m_fPatternTimer[0]);
		}
		if (m_fHP <= m_fMaxHP - 75.0f)
		{
			PatternFixedUpdate(&Boss1Script::HomingWeaponSpawn, (m_iHomingMissileIndex++) % 3, fixedDeltaTime, 5.0f, m_fPatternTimer[2]);
			PatternFixedUpdate(&Boss1Script::HomingWeaponSpawn, (m_iHomingMissileIndex++) % 3, fixedDeltaTime, 5.0f, m_fPatternTimer[3]);
			PatternFixedUpdate(&Boss1Script::HomingWeaponSpawn, (m_iHomingMissileIndex++) % 3, fixedDeltaTime, 5.0f, m_fPatternTimer[4]);

			int idx = rand() % 7;
			PatternFixedUpdate(&Boss1Script::FastMissileSpawn, idx, fixedDeltaTime, 4.0f, m_fPatternTimer[5]);
			int idx2 = rand() % 7;
			while (idx == idx2) { idx2 = rand() % 7; }
			PatternFixedUpdate(&Boss1Script::FastMissileSpawn, idx2, fixedDeltaTime, 4.0f, m_fPatternTimer[6]);
			int idx3 = rand() % 7;
			while (idx == idx3 || idx2 == idx3) { idx3 = rand() % 7; }
			PatternFixedUpdate(&Boss1Script::FastMissileSpawn, idx3, fixedDeltaTime, 4.0f, m_fPatternTimer[7]);

		}
		if (m_fHP <= m_fMaxHP - 120.0f)
		{
			int idx = rand() % 7;
			PatternFixedUpdate(&Boss1Script::MeteorSpawn, idx, fixedDeltaTime, 5.0f, m_fPatternTimer[8]);
		}
	}
	else if (m_fHP <= 500.0f && !m_bLaserFlag)
	{
		PatternFixedUpdate(&Boss1Script::LaserWeaponSpawn, fixedDeltaTime, 5.0f, m_fPatternTimer[8]);
	}
	if (m_laserWeapon->GetStatus() == game::Status::InActive)
	{
		m_cCollider->SetStatus(game::Status::Active);
		if (m_fHP <= 400.0f && m_fHP > 10.0f)
		{
			PatternFixedUpdate(&Boss1Script::PatternHP15, fixedDeltaTime, 2.5f, m_fPatternTimer[0]);
			PatternFixedUpdate(&Boss1Script::HomingWeaponSpawn, (m_iHomingMissileIndex++) % 3, fixedDeltaTime, 5.0f, m_fPatternTimer[2]);
			PatternFixedUpdate(&Boss1Script::HomingWeaponSpawn, (m_iHomingMissileIndex++) % 3, fixedDeltaTime, 5.0f, m_fPatternTimer[3]);
			PatternFixedUpdate(&Boss1Script::HomingWeaponSpawn, (m_iHomingMissileIndex++) % 3, fixedDeltaTime, 5.0f, m_fPatternTimer[4]);
			int idx = rand() % 7;
			PatternFixedUpdate(&Boss1Script::FastMissileSpawn, idx, fixedDeltaTime, 4.0f, m_fPatternTimer[5]);
			int idx2 = rand() % 7;
			while (idx == idx2) { idx2 = rand() % 7; }
			PatternFixedUpdate(&Boss1Script::FastMissileSpawn, idx2, fixedDeltaTime, 4.0f, m_fPatternTimer[6]);
			int idx3 = rand() % 7;
			while (idx == idx3 || idx2 == idx3) { idx3 = rand() % 7; }
			PatternFixedUpdate(&Boss1Script::FastMissileSpawn, idx3, fixedDeltaTime, 4.0f, m_fPatternTimer[7]);

			idx = rand() % 7;
			PatternFixedUpdate(&Boss1Script::MeteorSpawn, idx, fixedDeltaTime, 5.0f, m_fPatternTimer[8]);

		}
		if (m_fHP <= 10.0f)
		{
			if (pattern403Index < 5)m_fHP = 10;
			m_cCollider->SetStatus(game::Status::Active);
			if (pattern407Index < 6)
				Pattern407(fixedDeltaTime, 0.6f);
			else
				Pattern403(fixedDeltaTime, 2.0f);

		}
	}


}
void Boss1Script::OnCollisionEnter(ColliderComponent* src)
{
	m_cTexture->m_uAlpha = 200;
	GameObject* HitObject = src->GetOwner();
	if (HitObject->GetObjType() == game::OBJECT_TYPE::PLAYER_WEAPON)
	{
		WeaponScript* hitWeapon = HitObject->GetComponent<WeaponScript>();
		GetDamage(hitWeapon->GetDamage());
		//HitObject->SetStatus(game::Status::InActive);
	}
}
void Boss1Script::GetDamage(float Damage)
{
	m_fHP -= Damage;
	if (m_fHP < 0)
	{
		m_fHP = 0;
		//GameOver
	}
}
void Boss1Script::PatternHP15()
{
	//0 1 2 3 4 5 6
	int patternNum = rand() % 3;
	int x = rand() % 5 + 1;
	int y = rand() % 5 + 1;
	switch (patternNum)
	{
	case 0:
		Pattern101(x, y);
		break;
	case 1:
		Pattern102(x, y);
		break;
	case 2:
		Pattern103(x, y);
		break;
	}
}
void Boss1Script::Pattern101(int x, int y)
{

	for (int i = -2; i <= 2; i++)
	{
		for (int j = -2; j <= 2; j++)
		{
			if (i == 0 || j == 0)
			{
				if (i + y >= 0 && i + y < 7 && j + x >= 0 && j + x < 7)
				{

					area[i + y][j + x]->m_Script->Reset();
				}
			}
		}
	}

}
void Boss1Script::Pattern102(int x, int y)
{
	for (int i = -2; i <= 2; i++)
	{
		for (int j = -2; j <= 2; j++)
		{
			if (i == j || i + j == 0)
			{
				if (i + y >= 0 && i + y < 7 && j + x >= 0 && j + x < 7)
				{

					area[i + y][j + x]->m_Script->Reset();
				}
			}
		}
	}
}
void Boss1Script::Pattern103(int x, int y)
{
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (i >= 0 && i < 7 && j >= 0 && j < 7)
			{
				area[i][j]->m_Script->Reset();
			}

		}
	}

}
void Boss1Script::Pattern401(float fixedDeltaTime)
{
	if (pattern401Index >= 9)return;
	elapsedTime2 += fixedDeltaTime;
	if (elapsedTime2 >= 2.6f)
	{
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (b_PizzaPattern401[pattern401Index][i][j])
					area[i][j]->m_Script->Reset();
			}
		}
		pattern401Index = pattern401Index + 1;
		elapsedTime2 -= 2.6f;
	}

}
void Boss1Script::Pattern402(float fixedDeltaTime)
{
	if (pattern402Index >= 9)return;
	elapsedTime3 += fixedDeltaTime;
	if (elapsedTime3 >= 2.6f)
	{
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (b_PizzaPattern402[pattern402Index][i][j])
					area[i][j]->m_Script->Reset();
			}
		}
		pattern402Index = pattern402Index + 1;
		elapsedTime3 -= 2.6f;
	}
}
void Boss1Script::Pattern403(float fixedDeltaTime, float interval)
{
	if (pattern403Index >= 5)return;
	elapsedTime4 += fixedDeltaTime;
	if (elapsedTime4 >= interval)
	{
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (b_CornerPattern403[pattern403Index][i][j])
					area[i][j]->m_Script->Reset();
			}
		}
		pattern403Index = pattern403Index + 1;
		elapsedTime4 -= interval;
	}
}
void Boss1Script::Pattern404(float fixedDeltaTime, float interval)
{

	elapsedTime6 += fixedDeltaTime;
	while (elapsedTime6 >= interval)
	{
		if (pattern404Index < 27)
		{
			for (int j = 0; j < 7; ++j)
			{
				if (b_Mazepattern404[pattern404Index][j])
				{
					m_vSlowMissilePool[(7 * pattern404PlusIndex) + j]->m_Script->Activate();
					m_vSlowMissilePool[(7 * pattern404PlusIndex) + j]->m_Script->MissileMode();

				}
			}
			pattern404PlusIndex = (pattern404PlusIndex + 1) % pattern404Count;
		}
		else if (pattern404Index < 33)
		{
			m_vMeteorPool[pattern404Index - 27]->m_Script->Activate();
		}
		else
			return;
		pattern404Index++;
		elapsedTime6 -= interval;
	}
}
void Boss1Script::Pattern405(float fixedDeltaTime)
{
	if (pattern405Index >= 4) return;
	elapsedTime5 += fixedDeltaTime;

	if (elapsedTime5 >= 2.6f)
	{
		int safeX = rand() % 7;
		int safeY = rand() % 7;

		for (int i = 0; i < 7; ++i)
		{
			for (int j = 0; j < 7; ++j)
			{
				if (i == safeX && j == safeY)
				{
					continue;
				}
				else
				{
					area[i][j]->m_Script->Reset();
				}
			}
		}
		pattern405Index++;
		elapsedTime5 -= 2.6f;
	}
}
void Boss1Script::Pattern407(float fixedDeltaTime, float interval)
{
	elapsedTimer407 += fixedDeltaTime;
	if (elapsedTimer407 >= interval)
	{
		if (pattern407Index < 6)
		{
			FastMissileSpawn(6 - pattern407Index);
			MeteorSpawn(pattern407Index);
			pattern407Index++;
		}
		elapsedTimer407 -= interval;
	}
}
void Boss1Script::PatternFixedUpdate(void (Boss1Script::* funcToExecute)(), float fixedDeltaTime, float fixedInterval, float& patternTimer)
{
	patternTimer += fixedDeltaTime;
	if (patternTimer >= fixedInterval)
	{
		(this->*funcToExecute)();
		patternTimer -= fixedInterval;
	}
}
void Boss1Script::PatternFixedUpdate(void(Boss1Script::* funcToExecute)(int), int param1, float fixedDeltaTime, float fixedInterval, float& patternTimer)
{
	patternTimer += fixedDeltaTime;
	if (patternTimer >= fixedInterval)
	{
		(this->*funcToExecute)(param1);
		patternTimer -= fixedInterval;
	}
}
void Boss1Script::PatternFixedUpdate(void (Boss1Script::* funcToExecute)(int, int), int param1, int param2, float fixedDeltaTime, float fixedInterval, float& patternTimer)
{
	patternTimer += fixedDeltaTime;
	if (patternTimer >= fixedInterval)
	{
		(this->*funcToExecute)(param1, param2);
		patternTimer -= fixedInterval;
	}

}
void Boss1Script::PatternFixedUpdate(void (Boss1Script::* funcToExecute)(float), float param1, float fixedDeltaTime, float fixedInterval, float& patternTimer)
{
	patternTimer += fixedDeltaTime;
	if (patternTimer >= fixedInterval)
	{
		(this->*funcToExecute)(param1);
		patternTimer -= fixedInterval;
	}

}