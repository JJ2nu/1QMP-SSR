#include "Boss_1_Script.h"

float Boss_1_Script::floatingVector = 1.0f;
Boss_1_Script::Boss_1_Script(GameObject* pOwner, std::string ObjName)
	:ScriptComponent(pOwner, ObjName), m_cCollider(nullptr), m_cRender(nullptr)
{
	Start();
	std::srand(std::time(0)); // 랜덤 시드 초기화
}

void Boss_1_Script::AnimationInitialize()
{
	//애니메이션
	//m_cRender = m_pOwner->CreateComponent<AnimationComponent>("PlayerAnimationComponent");
	////m_cRender->m_tAnim = ResourceManager::GetInstance()->LoadAnimationImage(L"Boss1", L"\\Animation\\Player\\boss001_anime.bmp");
	////m_cRender->m_tAnim = ResourceManager::GetInstance()->LoadAnimationImage(L"Boss2", L"\\Animation\\Player\\boss002_anime.bmp");
	//m_cRender->m_tAnim = ResourceManager::GetInstance()->LoadAnimationImage(L"Boss3", L"\\Animation\\Player\\boss003_anime.bmp");

	//ResourceManager::GetInstance()->LoadAnimationMotion(m_cRender->m_tAnim, L"\\Animation\\Player\\BossIdle.txt");				 //	OBJECT_STATUS_IDLE,
	//m_cRender->m_fAnimationDelayTime = 0.2f;
	//m_cRender->m_iAnimationMotionIndex = 0;
	//m_cRender->m_iAnimationFrameIndex = 0;
	//m_cRender->m_fAnimationAccTime = 0.0f;
	m_cTexture = m_pOwner->CreateComponent<TextureComponent>("BossTexture");
	m_cTexture->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"BossTexture1", L"\\Animation\\Player\\boss_001_001.bmp");
	m_cTexture->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"BossTexture2", L"\\Animation\\Player\\boss_001_002.bmp");
	m_cTexture->m_tTexture[2] = ResourceManager::GetInstance()->LoadTexture(L"BossTexture3", L"\\Animation\\Player\\boss_001_003.bmp");
	/*m_cTexture->m_tTexture[3] = ResourceManager::GetInstance()->LoadTexture(L"BossTexture4", L"\\Animation\\Player\\boss_003_004.bmp");
	m_cTexture->m_tTexture[4] = ResourceManager::GetInstance()->LoadTexture(L"BossTexture5", L"\\Animation\\Player\\boss_003_005.bmp");*/
	m_cTexture->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"BossTexture1", L"\\Animation\\Player\\boss_003_001.bmp");
	m_cTexture->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"BossTexture2", L"\\Animation\\Player\\boss_003_002.bmp");
	m_cTexture->m_tTexture[2] = ResourceManager::GetInstance()->LoadTexture(L"BossTexture3", L"\\Animation\\Player\\boss_003_003.bmp");
	m_cTexture->m_tTexture[3] = ResourceManager::GetInstance()->LoadTexture(L"BossTexture4", L"\\Animation\\Player\\boss_003_004.bmp");
	m_cTexture->m_tTexture[4] = ResourceManager::GetInstance()->LoadTexture(L"BossTexture5", L"\\Animation\\Player\\boss_003_005.bmp");
	m_cTexture->m_uExcep = RGB(255, 0, 255);

}
void Boss_1_Script::AnimationUpdate(float fixedDeltaTime)
{
	//m_cRender->m_fAnimationAccTime += fixedDeltaTime;
	//if (m_cRender->m_fAnimationAccTime > m_cRender->m_fAnimationDelayTime)
	//{
	//	m_cRender->m_iAnimationFrameIndex = 
	//		(m_cRender->m_iAnimationFrameIndex + 1) % m_cRender->m_tAnim->
	//		m_motions[m_cRender->m_iAnimationMotionIndex].FrameCount;
	//	m_cRender->m_fAnimationAccTime -= m_cRender->m_fAnimationDelayTime;
	//}
	//m_Transform.Position.y += floatingVector*fixedDeltaTime*10;
	m_fTextureRenderTime += fixedDeltaTime;
	while (m_fTextureRenderTime > 0.2f)
	{
		m_cTexture->m_uRenderIndex = (m_cTexture->m_uRenderIndex + 1) % 3;
		m_fTextureRenderTime -= 0.2f;
	}
	m_Transform.Position.y += floatingVector * fixedDeltaTime * 10;
}

void Boss_1_Script::Start()
{

	AnimationInitialize();
	//콜라이더
	m_cCollider = m_pOwner->CreateComponent<ColliderComponent>("BossColliderComponent");
	m_cCollider->m_Transform.SetScale(80.0f, 80.0f, 0);

	//areaWeapon initialize
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
	for (int i = 0; i < 7; i++)
	{
		HomingWeaponObject* hw = new HomingWeaponObject(m_pOwner->GetSceneBase());
		m_pOwner->AddChildGameObject(hw);
		m_vHomingWeaponPool.push_back(hw);

		SlowMissileObject* sm = new SlowMissileObject(m_pOwner->GetSceneBase());
		sm->m_Transform.SetPosition(410, 400 + 80 * i, 0);
		sm->SetStatus(game::Status::InActive);
		m_pOwner->AddChildGameObject(sm);
		m_vSlowMissilePool.push_back(sm);

		MeteorObject* mo = new MeteorObject(m_pOwner->GetSceneBase());
		mo->m_Transform.SetPosition(170 + (80 * i), 400, 0);
		mo->SetStatus(game::Status::InActive);
		m_pOwner->AddChildGameObject(mo);
		m_vMeteorPool.push_back(mo);
	}

	//FastMissileObject
	for (int j = 0; j < pattern404Count; j++)
	{
		for (int i = 0; i < 7; i++)
		{
			FastMissileObject* fm = new FastMissileObject(m_pOwner->GetSceneBase());
			fm->m_Transform.SetPosition(410, 400 + 80 * i, 0);
			fm->SetStatus(game::Status::InActive);
			m_pOwner->AddChildGameObject(fm);
			m_vFastMissilePool.push_back(fm);
		}
	}

	//BossLaser Initialize
	//LaserWeaponObject* lw = new LaserWeaponObject(m_pOwner->GetSceneBase());
	//lw->m_Transform.SetPosition(350, 640, 0);
	//m_pOwner->AddChildGameObject(lw);
}

void Boss_1_Script::FixedUpdate(float fixedDeltaTime)
{
	AnimationUpdate(fixedDeltaTime);

	elapsedTime += fixedDeltaTime;
	if (elapsedTime >= 3.0f)
	{
		floatingVector *= -1; // 보스 부유 움직임

		//if (m_vSlowMissilePool[m_iSlowMissileIndex % 7]->GetStatus() == game::Status::InActive)
		//{
		//	m_vSlowMissilePool[(m_iSlowMissileIndex++) % 7]->m_Script->Activate();
		//	m_iSlowMissileIndex %= 7;
		//}
		//if (m_vFastMissilePool[m_iFastMissileIndex & 7]->GetStatus() == game::Status::InActive)
		//{
		//	m_vFastMissilePool[(m_iFastMissileIndex++) % 7]->m_Script->Activate();
		//	m_iFastMissileIndex %= 7;
		//}
		//if (m_vMeteorPool[m_iMeteorIndex & 7]->GetStatus() == game::Status::InActive)
		//{
		//	m_vMeteorPool[(m_iMeteorIndex++) % 7]->m_Script->Activate();
		//	m_iMeteorIndex %= 7;
		//}
		// 


		elapsedTime -= 3.0f;
	}
	//Pattern404(fixedDeltaTime, .6f);
	/*if (pattern401Index <= 8) {
		Pattern401(fixedDeltaTime);
	}
	else {
		Pattern402(fixedDeltaTime);
	}*/
	//Pattern405(fixedDeltaTime);
	
}

void Boss_1_Script::OnCollisionEnter(ColliderComponent* src)
{
	GameObject* HitObject = src->GetOwner();
	if (HitObject->GetObjType() == game::OBJECT_TYPE::PLAYER_WEAPON)
	{
		WeaponScript* hitWeapon = HitObject->GetComponent<WeaponScript>();
		GetDamage(hitWeapon->GetDamage());
		HitObject->SetStatus(game::Status::InActive);
	}
}

void Boss_1_Script::GetDamage(float Damage)
{
	m_fHP -= Damage;
	if (m_fHP < 0)
	{
		m_fHP = 0;
		//GameOver
	}
}

void Boss_1_Script::Pattern101(int x, int y)
{

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (i == 5 / 2 || j == 5 / 2)
			{
				if (i + y >= 0 && i + y < 7 && j + x >= 0 && j + x < 7)
				{

					area[i + y][j + x]->m_Script->Reset();
				}
			}
		}
	}

}

void Boss_1_Script::Pattern102(int x, int y)
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (i == j || i + j == 5 - 1)
			{
				if (i + y >= 0 && i + y < 7 && j + x >= 0 && j + x < 7)
				{

					area[i + y][j + x]->m_Script->Reset();
				}
			}
		}
	}
}

void Boss_1_Script::Pattern103(int x, int y)
{
	for (int i = x - 3; i <= x + 3; i++)
	{
		for (int j = y - 3; j <= y + 3; j++)
		{
			if (i >= 0 && i < 7 && j >= 0 && j < 7)
			{
				area[i][j]->m_Script->Reset();
			}

		}
	}

}
void Boss_1_Script::Pattern401(float fixedDeltaTime)
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
void Boss_1_Script::Pattern402(float fixedDeltaTime)
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

void Boss_1_Script::Pattern403(float fixedDeltaTime)
{
	if (pattern403Index >= 5)return;
	elapsedTime4 += fixedDeltaTime;
	if (elapsedTime4 >= 2.6f)
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
		elapsedTime4 -= 2.6f;
	}
}

void Boss_1_Script::Pattern404(float fixedDeltaTime, float interval)
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
					m_vFastMissilePool[(7 * pattern404PlusIndex) + j]->m_Script->Activate();
					m_vFastMissilePool[(7 * pattern404PlusIndex) + j]->m_Script->MissileMode();

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

void Boss_1_Script::Pattern405(float fixedDeltaTime)
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


