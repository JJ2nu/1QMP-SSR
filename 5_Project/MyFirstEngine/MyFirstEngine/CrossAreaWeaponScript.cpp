#include "CrossAreaWeaponScript.h"
#include "SceneBase.h"
#include "ResourceManager.h"

int CrossAreaWeaponScript::s_eAreaSoundChannel = 19;
int CrossAreaWeaponScript::s_eExplosionSoundChannel = 23;

CrossAreaWeaponScript::CrossAreaWeaponScript(GameObject* pOwner, std::string ObjName)
	: AreaWeaponScript(pOwner, ObjName)
{
	Start();
}



void CrossAreaWeaponScript::Start()
{
	// 이미지
	m_TexComp = m_pOwner->CreateComponent<TextureComponent>("AreaWeaponTextureComponent");
	m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"AreaWarning", L"\\Animation\\AreaWeapon\\Effect_Explosion_00.bmp");
	m_TexComp->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"ExplosionEffect0", L"\\Animation\\AreaWeapon\\Effect_Explosion_01.bmp");
	m_TexComp->m_tTexture[2] = ResourceManager::GetInstance()->LoadTexture(L"ExplosionEffect1", L"\\Animation\\AreaWeapon\\Effect_Explosion_02.bmp");
	m_TexComp->m_tTexture[3] = ResourceManager::GetInstance()->LoadTexture(L"ExplosionEffect2", L"\\Animation\\AreaWeapon\\Effect_Explosion_03.bmp");
	m_TexComp->m_tTexture[4] = ResourceManager::GetInstance()->LoadTexture(L"ExplosionEffect3", L"\\Animation\\AreaWeapon\\Effect_Explosion_04.bmp");
	m_TexComp->m_tTexture[5] = ResourceManager::GetInstance()->LoadTexture(L"ExplosionEffect4", L"\\Animation\\AreaWeapon\\Effect_Explosion_05.bmp");
	m_TexComp->m_tTexture[6] = ResourceManager::GetInstance()->LoadTexture(L"ExplosionEffect5", L"\\Animation\\AreaWeapon\\Effect_Explosion_06.bmp");
	m_TexComp->m_tTexture[7] = ResourceManager::GetInstance()->LoadTexture(L"ExplosionEffect6", L"\\Animation\\AreaWeapon\\Effect_Explosion_07.bmp");
	m_TexComp->m_tTexture[8] = ResourceManager::GetInstance()->LoadTexture(L"ExplosionEffect7", L"\\Animation\\AreaWeapon\\Effect_Explosion_08.bmp");
	m_TexComp->m_tTexture[9] = ResourceManager::GetInstance()->LoadTexture(L"ExplosionEffect8", L"\\Animation\\AreaWeapon\\Effect_Explosion_09.bmp");
	m_TexComp->m_uExcep = RGB(255, 0, 255);
	m_TexComp->m_uRenderIndex = 0;
	m_TexComp->m_iRenderFlag = 2;
	m_TexComp->m_uAlpha = 255;
	m_TexComp->SetStatus(game::Status::Active);

	//m_cRender = m_pOwner->CreateComponent<AnimationComponent>("CrossAreaWeaponAnimationComponent");
	//m_cRender->m_tAnim = ResourceManager::GetInstance()->LoadAnimationImage(L"Areaweapon", L"\\Animation\\Player\\Effect_Explosion_02.bmp");
	//ResourceManager::GetInstance()->LoadAnimationMotion(m_cRender->m_tAnim, L"\\Animation\\Player\\warning.txt");	
	//ResourceManager::GetInstance()->LoadAnimationMotion(m_cRender->m_tAnim, L"\\Animation\\Player\\Explosion.txt");

	//m_cRender->m_fAnimationDelayTime = 0.05f;
	//m_cRender->m_iAnimationMotionIndex = 0;
	//m_cRender->m_iAnimationFrameIndex = 0;
	//m_cRender->m_fAnimationAccTime = 0.0f;



	// 콜라이더 추후 최종 빌드 시 콜라이더 표시 삭제 해야됨 했을 경우 주석 삭제
	m_ColComp = m_pOwner->CreateComponent<ColliderComponent>("AreaWeaponColliderComponent");
	m_ColComp->SetStatus(game::Status::InActive);
	m_ColComp->m_Transform.SetScale(72.0f, 72.0f, 0);
}

void CrossAreaWeaponScript::ExplosionAnimation(float fixedDeltaTime)
{
	if (m_TexComp->m_uRenderIndex == 10)
	{
		if (m_TexComp->m_uRenderIndex == 0)m_TexComp->m_uRenderIndex = 1;
		m_frameDelay = 0.0f;
		//flag = false;
		return;
	}
	m_frameDelay += fixedDeltaTime;
	if (m_frameDelay >= 0.1f)
	{
		m_TexComp->m_uRenderIndex++;
		m_frameDelay -= 0.1f;

	}


}

void CrossAreaWeaponScript::FixedUpdate(float fixedDeltaTime)
{
	m_fImageChangeTime += fixedDeltaTime; // 타임 누적
	m_fStandardTime += fixedDeltaTime;

	if (m_bQueueFlag)
	{
		m_fQueue.push(m_fStandardTime);
		m_bQueueFlag = false;
	}
	if (m_fImageChangeTime > 2.f)
	{
		ExplosionAnimation(fixedDeltaTime);
		if (flag)
		{
			m_ColComp->SetStatus(game::Status::Active); // 콜라이더 출력
			//장판공격 폭팔
			s_eAreaSoundChannel = (s_eAreaSoundChannel + 1) % 4 + 23;
			ResourceManager::GetInstance()->PlayMusic(game::eSoundList::Battle, 22, static_cast<game::eSoundChannel>(s_eAreaSoundChannel));
		}
		if (m_fImageChangeTime > m_fInActiveTime) // 해당 초를 지나면 사라지게 처리
		{
			if (m_fQueue.size() != 0)
			{
				m_fImageChangeTime = m_fImageChangeTime - m_fQueue.front() + m_fLastQueueTime;
				m_fLastQueueTime = m_fQueue.front();
				m_fQueue.pop();
				m_TexComp->m_uRenderIndex = 1;

				if (m_fImageChangeTime < 2.f)
				{
					m_ColComp->SetStatus(game::Status::InActive);
					m_TexComp->m_uRenderIndex = 0;
				}
				return;
			}
			m_pOwner->SetStatus(game::Status::InActive);
			m_TexComp->m_uRenderIndex = 0;
			m_TexComp->SetStatus(game::Status::InActive);
			m_ColComp->SetStatus(game::Status::InActive);
		}
	}
}

void CrossAreaWeaponScript::Update(float deltaTime)
{

}

void CrossAreaWeaponScript::OnCollisionEnter(ColliderComponent* src)
{
	//if (m_fQueue.size() < 1)
	//{
	//	m_pOwner->SetStatus(game::Status::InActive);
	//	m_TexComp->SetStatus(game::Status::InActive);
	//	m_ColComp->SetStatus(game::Status::InActive);
	//}
}

void CrossAreaWeaponScript::Reset()
{
	//장판공격 경고
	s_eAreaSoundChannel = (s_eAreaSoundChannel + 1) % 4 + 19;
	ResourceManager::GetInstance()->PlayMusic(game::eSoundList::Battle, 17, static_cast<game::eSoundChannel>(s_eAreaSoundChannel));

	if (m_pOwner->GetStatus() == game::Status::Active)
	{
		m_bQueueFlag = true;
	}
	else
	{
		m_fStandardTime = 0.f;
		m_bQueueFlag = false;
		m_fImageChangeTime = 0;
		//m_frameDelay = 0;
		m_TexComp->m_uRenderIndex = 0;
		m_pOwner->SetStatus(game::Status::Active);
		m_TexComp->SetStatus(game::Status::Active);
		m_fLastQueueTime = 0;
		m_fInActiveTime = 2.5f;
		//m_cRender->SetStatus(game::Status::InActive);
	}
}


