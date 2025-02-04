#include "Boss3Script.h"

float Boss3Script::floatingVector = 1.0f;
Boss3Script::Boss3Script(GameObject* pOwner, std::string ObjName)
	:ScriptComponent(pOwner, ObjName), m_cCollider(nullptr), m_cRender(nullptr)
{
	Start();
	Observer::GetInstance()->GetBackground()->m_Script->m_cTexture->m_uRenderIndex = 2;
	std::srand(std::time(0)); // 랜덤 시드 초기화
}
void Boss3Script::ComponentInitialize()
{
	m_cTexture = m_pOwner->CreateComponent<TextureComponent>("BossTexture");
	m_cTexture->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"BossTexture3", L"\\Animation\\Player\\boss_003_001.bmp");
	m_cTexture->m_uRenderIndex = 0;
	m_cTexture->m_iRenderFlag = 2;
	m_cTexture->m_uExcep = RGB(255, 0, 255);

	m_cCollider = m_pOwner->CreateComponent<ColliderComponent>("BossColliderComponent");
	m_cCollider->m_Transform.SetScale(300.0f, 800.0f, 0);

}
void Boss3Script::WeaponInitialize()
{
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

	//HomingWeapon Initialize
	for (int i = 0; i < 23; i++)
	{
		HomingWeaponObject* hw = new HomingWeaponObject(m_pOwner->GetSceneBase());
		m_pOwner->AddChildGameObject(hw);
		hw->SetStatus(game::Status::InActive);
		m_vHomingWeaponPool.push_back(hw);
	}

	//SlowMissile Initialize
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 7; i++)
		{
			SlowMissileObject* sm = new SlowMissileObject(m_pOwner->GetSceneBase());
			sm->m_Transform.SetPosition(410, 400 + 80 * i, 0);
			sm->SetStatus(game::Status::InActive);
			m_pOwner->AddChildGameObject(sm);
			m_vSlowMissilePool.push_back(sm);
		}
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

	//SupportingMissile Initialize
	for (int i = 0; i < 210; i++)
	{
		SupportingMissileObject* smo = new SupportingMissileObject(m_pOwner->GetSceneBase());
		smo->m_Transform.SetPosition(10, 400 + 80 * (i%7), 0);
		smo->SetStatus(game::Status::InActive);
		m_pOwner->AddChildGameObject(smo);
		m_vSupportingMissilePool.push_back(smo);
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

	//BossLaser Initialize
	m_laserWeapon = new LaserWeaponObject(m_pOwner->GetSceneBase());
	m_laserWeapon->m_Transform.SetPosition(350, 640, 0);
	m_laserWeapon->SetStatus(game::Status::InActive);
	m_pOwner->AddChildGameObject(m_laserWeapon);


}
void Boss3Script::HomingWeaponSpawn(int index)
{
	if (m_vHomingWeaponPool[index]->GetStatus() == game::Status::InActive)
		m_vHomingWeaponPool[index]->m_Script->Reset();
}
void Boss3Script::SlowMissileSpawn(int index)
{
	if (m_vSlowMissilePool[index]->GetStatus() == game::Status::InActive)
		m_vSlowMissilePool[index]->m_Script->Activate();
}
void Boss3Script::FastMissileSpawn(int index)
{
	if (m_vFastMissilePool[index]->GetStatus() == game::Status::InActive)
		m_vFastMissilePool[index]->m_Script->Activate();
}
void Boss3Script::LaserWeaponSpawn()
{
	m_laserWeapon->SetStatus(game::Status::Active);
}
void Boss3Script::MeteorSpawn(int index)
{
	if (m_vMeteorPool[index]->GetStatus() == game::Status::InActive)
		m_vMeteorPool[index]->m_Script->Activate();

}
void Boss3Script::AnimationUpdate(float fixedDeltaTime)
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
void Boss3Script::Start()
{
	ComponentInitialize();
	WeaponInitialize();
}
void Boss3Script::FixedUpdate(float fixedDeltaTime)
{
	AnimationUpdate(fixedDeltaTime);
	if (m_fHP <= 0.0f)
	{
		Observer::GetInstance()->m_iStageNum = 0;
		Observer::GetInstance()->m_GameFlag = game::SCENE_TYPE::ENDING_STORY;
	}
	if (m_fHP > 350.0f)
	{
		PatternFixedUpdate(&Boss3Script::PatternHP15, fixedDeltaTime, 2.5f, m_fPatternTimer[0]);
		PatternFixedUpdate(&Boss3Script::PatternHP15, fixedDeltaTime, 2.5f, m_fPatternTimer[1]);

		int idx = rand() % 7;
		PatternFixedUpdate(&Boss3Script::FastMissileSpawn, idx, fixedDeltaTime, 4.5f, m_fPatternTimer[2]);
		int idx2 = rand() % 7;
		while (idx == idx2) { idx2 = rand() % 7; }
		PatternFixedUpdate(&Boss3Script::FastMissileSpawn, idx2, fixedDeltaTime, 4.5f, m_fPatternTimer[3]);
		int idx3 = rand() % 7;
		while (idx == idx3 || idx2 == idx3) { idx3 = rand() % 7; }
		PatternFixedUpdate(&Boss3Script::FastMissileSpawn, idx3, fixedDeltaTime, 4.5f, m_fPatternTimer[4]);

		idx = rand() % 7;
		PatternFixedUpdate(&Boss3Script::SlowMissileSpawn, idx, fixedDeltaTime, 10.0f, m_fPatternTimer[5]);
		idx2 = rand() % 7;
		while (idx == idx2) { idx2 = rand() % 7; }
		PatternFixedUpdate(&Boss3Script::SlowMissileSpawn, idx2, fixedDeltaTime, 10.0f, m_fPatternTimer[6]);
		idx3 = rand() % 7;
		while (idx == idx3 || idx2 == idx3) { idx3 = rand() % 7; }
		PatternFixedUpdate(&Boss3Script::SlowMissileSpawn, idx3, fixedDeltaTime, 10.0f, m_fPatternTimer[7]);

		PatternFixedUpdate(&Boss3Script::HomingWeaponSpawn, (m_iHomingMissileIndex++) % 3, fixedDeltaTime, 5.5f, m_fPatternTimer[8]);
		idx = rand() % 7;
		PatternFixedUpdate(&Boss3Script::MeteorSpawn, idx, fixedDeltaTime, 5.5f, m_fPatternTimer[9]);
	}
	else if (m_fHP > 50.0f)
	{
		Pattern402(fixedDeltaTime, 0.5f);
		if(pattern402Index == 14)
			ResourceManager::GetInstance()->PlayMusic(game::eSoundList::Battle, 18, game::eSoundChannel::SFX_Warning_Danger);
		if (pattern402Index >= 15)
			Pattern405(fixedDeltaTime);

		if (pattern402Index == 40)
		{
			ResourceManager::GetInstance()->PlayMusic(game::eSoundList::Battle, 18, game::eSoundChannel::SFX_Warning_Danger);
			for (int i = 0; i < 7; i++)
			{
				m_vSlowMissilePool[i]->m_Script->Activate();
			}
		}
		if (pattern402Index == 44)
		{
			for (int i = 0; i < 7; i++)
			{
				m_vSlowMissilePool[i + 7]->m_Script->Activate();
			}
		}
		if (pattern402Index == 48)
		{
			for (int i = 0; i < 7; i++)
			{
				m_vSlowMissilePool[i + 14]->m_Script->Activate();
			}
		}
	}
	if (m_fHP <= 50.0f)
	{
		if (pattern402Index > 20)
		{
			for (int i = 0; i < 23; i++)
			{
				m_vHomingWeaponPool[i]->m_Script->Reset();
			}
			pattern402Index = 0;
		}
		//m_cCollider->SetStatus(game::Status::InActive);
		if (m_fHP <= 50.0f && pattern500Index < 260)m_fHP = 50.0f;
		PatternFixedUpdate(&Boss3Script::Pattern500, fixedDeltaTime, 0.02f, m_fPatternTimer[0]);
		if (pattern500Index == 50)
		{
			for (int i = 0; i < 21; i++)
			{
				m_vSlowMissilePool[i]->SetStatus(game::Status::InActive);
			}
		}
		if (pattern500Index == 100)
		{
			for (int i = 0; i < 21; i++)
			{
				m_vHomingWeaponPool[i]->SetStatus(game::Status::InActive);
			}
		}
	
	}

}
void Boss3Script::OnCollisionEnter(ColliderComponent* src)
{
	m_cTexture->m_uAlpha = 200;
	GameObject* HitObject = src->GetOwner();
	if (HitObject->GetObjType() == game::OBJECT_TYPE::PLAYER_WEAPON)
	{
		WeaponScript* hitWeapon = HitObject->GetComponent<WeaponScript>();
		GetDamage(hitWeapon->GetDamage());
	}
}
void Boss3Script::GetDamage(float Damage)
{
	m_fHP -= Damage;
	if (m_fHP < 0)
	{
		m_fHP = 0;
		//GameOver
	}
}
void Boss3Script::PatternHP15()
{
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
void Boss3Script::Pattern101(int x, int y)
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
void Boss3Script::Pattern102(int x, int y)
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
void Boss3Script::Pattern103(int x, int y)
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
void Boss3Script::Pattern401(float fixedDeltaTime, float interval)
{
	if (pattern401Index >= 9)return;
	elapsedTime2 += fixedDeltaTime;
	if (elapsedTime2 >= interval)
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
		elapsedTime2 -= interval;
	}

}
void Boss3Script::Pattern402(float fixedDeltaTime, float interval)
{
	elapsedTime3 += fixedDeltaTime;
	if (elapsedTime3 >= interval)
	{
		if (pattern402Index >= 9)
		{
			elapsedTime3 -= interval;
			pattern402Index++;
			return;
		}
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (b_PizzaPattern402[pattern402Index][i][j])
					area[i][j]->m_Script->Reset();
			}
		}
		pattern402Index = pattern402Index + 1;
		elapsedTime3 -= interval;
	}
}
void Boss3Script::Pattern403(float fixedDeltaTime, float interval)
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
void Boss3Script::Pattern404(float fixedDeltaTime, float interval)
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
void Boss3Script::Pattern405(float fixedDeltaTime)
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
void Boss3Script::Pattern407(float fixedDeltaTime, float interval)
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
void Boss3Script::Pattern500()
{
	pattern500Index++;
	if (pattern500Index == 1)
	{
		//플레이어 지원 미사일 사운드
		ResourceManager::GetInstance()->PlayMusic(game::eSoundList::Battle, 21, game::eSoundChannel::SFX_Support_Missile);
	}
	if (pattern500Index < 210)	m_vSupportingMissilePool[pattern500Index]->m_Script->Activate();
	else return;
}
void Boss3Script::PatternFixedUpdate(void (Boss3Script::* funcToExecute)(), float fixedDeltaTime, float fixedInterval, float& patternTimer)
{
	patternTimer += fixedDeltaTime;
	if (patternTimer >= fixedInterval)
	{
		(this->*funcToExecute)();
		patternTimer -= fixedInterval;
	}
}
void Boss3Script::PatternFixedUpdate(void(Boss3Script::* funcToExecute)(int), int param1, float fixedDeltaTime, float fixedInterval, float& patternTimer)
{
	patternTimer += fixedDeltaTime;
	if (patternTimer >= fixedInterval)
	{
		(this->*funcToExecute)(param1);
		patternTimer -= fixedInterval;
	}
}
void Boss3Script::PatternFixedUpdate(void (Boss3Script::* funcToExecute)(int, int), int param1, int param2, float fixedDeltaTime, float fixedInterval, float& patternTimer)
{
	patternTimer += fixedDeltaTime;
	if (patternTimer >= fixedInterval)
	{
		(this->*funcToExecute)(param1, param2);
		patternTimer -= fixedInterval;
	}

}
void Boss3Script::PatternFixedUpdate(void (Boss3Script::* funcToExecute)(float), float param1, float fixedDeltaTime, float fixedInterval, float& patternTimer)
{
	patternTimer += fixedDeltaTime;
	if (patternTimer >= fixedInterval)
	{
		(this->*funcToExecute)(param1);
		patternTimer -= fixedInterval;
	}

}