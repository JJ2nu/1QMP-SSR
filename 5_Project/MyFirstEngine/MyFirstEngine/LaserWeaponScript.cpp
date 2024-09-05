#include "LaserWeaponScript.h"
#include "SceneBase.h"
#include "ResourceManager.h"
#include "BossScript.h"
#include "BossObject.h"
#include "PlayerGameObject.h"
#include "Observer.h"
LaserWeaponScript::LaserWeaponScript(GameObject* pOwner, std::string ObjName)
	:AreaWeaponScript(pOwner, ObjName)
{
	Start();
}

void LaserWeaponScript::Start()
{
	// 이미지
	m_TexComp = m_pOwner->CreateComponent<TextureComponent>("LaserWeaponTextureComponent");
	m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"charge1", L"\\Animation\\Missile\\laser\\charge_001.bmp");
	m_TexComp->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"charge2", L"\\Animation\\Missile\\laser\\charge_002.bmp");
	m_TexComp->m_tTexture[2] = ResourceManager::GetInstance()->LoadTexture(L"charge3", L"\\Animation\\Missile\\laser\\charge_003.bmp");
	
	m_TexComp->m_tTexture[3] = ResourceManager::GetInstance()->LoadTexture(L"charge4", L"\\Animation\\Missile\\laser\\charge_004.bmp");
	m_TexComp->m_tTexture[4] = ResourceManager::GetInstance()->LoadTexture(L"charge5", L"\\Animation\\Missile\\laser\\charge_005.bmp");
	m_TexComp->m_tTexture[5] = ResourceManager::GetInstance()->LoadTexture(L"charge6", L"\\Animation\\Missile\\laser\\charge_006.bmp");
	//m_TexComp->m_tTexture[6] = ResourceManager::GetInstance()->LoadTexture(L"charge6", L"\\Animation\\Missile\\laser\\charge_007.bmp");
	m_TexComp->m_uExcep = RGB(0, 0, 0);
	m_TexComp->m_iRenderFlag = 2;
	m_TexComp->m_uAlpha = 230;
	m_TexComp->SetStatus(game::Status::InActive);	
	
	
	m_cWarningTexture = m_pOwner->CreateComponent<TextureComponent>("LaserWeaponWarningTextureComponent");
	m_cWarningTexture->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"Boss_Warning", L"\\Animation\\Missile\\laser\\boss_warning.bmp");
	m_cWarningTexture->m_uExcep = RGB(255, 0, 255);
	m_cWarningTexture->m_iRenderFlag = 2;
	m_cWarningTexture->m_uAlpha = 140;
	m_cWarningTexture->SetStatus(game::Status::Active);

	
	
	
	
	m_CRender = m_pOwner->CreateComponent<AnimationComponent>("LaserWeaponAnimationComponent");
	m_CRender->m_tAnim = ResourceManager::GetInstance()->LoadAnimationImage(L"BossLaser", L"\\Animation\\Missile\\laser\\boss_laser_charge.png");
	ResourceManager::GetInstance()->LoadAnimationMotion(m_CRender->m_tAnim, L"\\Animation\\Missile\\laser\\7.txt");

	m_CRender->m_iAnimationFrameIndex = 0;
	m_CRender->m_iAnimationMotionIndex = 0;
	m_CRender->SetStatus(game::Status::InActive);

	//// 콜라이더 추후 최종 빌드 시 콜라이더 표시 삭제 해야됨 했을 경우 주석 삭제
	//m_ColComp = m_pOwner->CreateComponent<ColliderComponent>("LaserWeaponColliderComponent");
	//m_ColComp->SetStatus(game::Status::InActive);
	//m_ColComp->m_Transform.SetScale(80.0f, 80.0f, 0);
	chargeFlag = true;



	//Text Component
	//m_cTextRender = m_pOwner->CreateComponent<TextComponent>("BossHPUITextComponent");
	//curstr = new std::wstring();
	//m_cTextRender->m_uColor = RGB(255, 0, 0);
	//m_cTextRender->m_iFontSize = 50;
	//m_cTextRender->m_tString.push_back(curstr);
	//m_cTextRender->SetTransform(Vector3(1800, 560,0));
	//m_cTextRender->SetRectSize(200, 100);

}

void LaserWeaponScript::FixedUpdate(float fixedDeltaTime)
{
	if (m_iHitCount <= 0)
	{
		//보스 레이저 공격 사운드
		ResourceManager::GetInstance()->PlayMusic(game::eSoundList::Battle, 0, game::eSoundChannel::SFX_Boss_Laser);

		m_pOwner->SetStatus(game::Status::InActive);
	}

	m_fImageChangeTime += fixedDeltaTime; // 타임 누적

	if (m_fImageChangeTime > 4 && m_fImageChangeTime < 12)
	{
		//Observer::GetInstance()->GetBoss()->m_Script->floatingVector = 0.0f;
		m_bWarningFlag = false;
		chargeFlag = true;
	}
	else
	{
		m_cWarningTexture->m_iRenderFlag = 2;
		m_bWarningTime += fixedDeltaTime;
		if (m_bWarningTime > 0.5f)
		{
			m_bWarningAlphaFlag *= -1;
			m_bWarningTime -= 0.5f;
		}
	}
	if (m_fImageChangeTime > 12 && chargeFlag == true)
	{

		chargeFlag = false;
		//보스 레이저 공격 사운드
		ResourceManager::GetInstance()->PlayMusic(game::eSoundList::Battle, 3, game::eSoundChannel::SFX_Boss_Laser);

		Observer::GetInstance()->GetPlayer()->myScript->GetDamage(10000.f);
		//m_ColComp->SetStatus(game::Status::Active);	
	}
	//*curstr = std::to_wstring(static_cast<int>(m_iHitCount));
	AnimationUpdate(fixedDeltaTime);
}

void LaserWeaponScript::OnHit()
{
	m_iHitCount--;
	//보스 레이저 공격 사운드
	ResourceManager::GetInstance()->PlayMusic(game::eSoundList::Battle, 1, game::eSoundChannel::SFX_Boss_Laser_Click);
}

void LaserWeaponScript::Reset()
{
	m_pOwner->SetStatus(game::Status::Active);
	m_fImageChangeTime = 0.f;
	m_iHitCount = 20;
	chargeFlag = false;
	m_bWarningFlag = true;
	m_bWarningAlphaFlag = -1;
	//보스 레지저 공격 준비 사운드
	ResourceManager::GetInstance()->PlayMusic(game::eSoundList::Battle, 2, game::eSoundChannel::SFX_Boss_Laser);
}

void LaserWeaponScript::AnimationUpdate(float fixedDeltaTime)
{
	m_fTextureRenderTime += fixedDeltaTime;
	if (m_bWarningFlag)
	{
		m_cWarningTexture->SetStatus(game::Status::Active);
		m_Transform.SetPosition(1000, 640, 0);
		if (m_bWarningAlphaFlag > 0)
		{

			m_cWarningTexture->m_iRenderFlag = 2;
		}
		else
		{

			m_cWarningTexture->m_iRenderFlag = 0;
		}
	}
	else if (chargeFlag)
	{
		m_CRender->SetStatus(game::Status::InActive);
		m_cWarningTexture->SetStatus(game::Status::InActive);
		m_TexComp->SetStatus(game::Status::Active);
		m_Transform.SetPosition(1150, 560, 0);

		//m_ColComp->SetStatus(game::Status::Active);

		while (m_fTextureRenderTime >=0.08f)
		{
			m_TexComp->m_uRenderIndex = (m_TexComp->m_uRenderIndex + 1) % 6;
			m_fTextureRenderTime -= 0.08f;
		}

	}
	else
	{
		m_CRender->SetStatus(game::Status::Active);
		m_TexComp->SetStatus(game::Status::InActive);

		m_Transform.SetPosition(350, 640, 0);
		m_CRender->m_iAnimationMotionIndex = 0;
		//m_ColComp->SetStatus(game::Status::InActive);
		while (m_fTextureRenderTime > 0.08f)
		{
			m_CRender->m_iAnimationFrameIndex = (m_CRender->m_iAnimationFrameIndex + 1) % 3;
			m_fTextureRenderTime -= 0.08f;
		}
		Observer::GetInstance()->m_Player->myScript->m_fHP = 0.0f;
	}

}


