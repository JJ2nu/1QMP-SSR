#include "HomingWeaponScript.h"
#include "SceneBase.h"
#include "ResourceManager.h"
#include <cmath>


Vector3 HomingWeaponScript::s_vPlayerPos = 0;
int HomingWeaponScript::s_eSoundChannel = 15;

HomingWeaponScript::HomingWeaponScript(GameObject* pOwner, std::string ObjName)
	:WeaponScript(pOwner, ObjName)
	,m_vPrevVector(1,0,0)
{
	Start();
}


void HomingWeaponScript::Start()
{
	// 이미지
	/*m_TexComp = m_pOwner->CreateComponent<TextureComponent>("HomingWeaponTextureComponent");
	m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"Monster", L"\\Texture\\Cat_King.bmp");
	*/
	
	m_cRender = m_pOwner->CreateComponent<AnimationComponent>("HomingAnimationComponent");
	m_cRender->m_tAnim = ResourceManager::GetInstance()->LoadAnimationImage(L"Homing", L"\\Animation\\Missile\\SupportWeapon\\Homing.bmp");
	ResourceManager::GetInstance()->LoadAnimationMotion(m_cRender->m_tAnim, L"\\Animation\\Missile\\SupportWeapon\\HomingIdle.txt");				 //	OBJECT_STATUS_IDLE,
	m_cRender->m_fAnimationDelayTime = 0.1f;
	m_cRender->m_iAnimationMotionIndex = 0;
	m_cRender->m_iAnimationFrameIndex = 0;
	m_cRender->m_fAnimationAccTime = 0.0f;
	m_cRender->m_bAnimationFlip = true;


	// 콜라이더 추후 최종 빌드 시 콜라이더 표시 삭제 해야됨 했을 경우 주석 삭제
	m_ColComp = m_pOwner->CreateComponent<ColliderComponent>("HomingWeaponColliderComponent");
	m_ColComp->SetStatus(game::Status::Active);
	m_ColComp->m_Transform.SetScale(80.0f, 80.0f, 0);

	m_Transform.SetPosition(rand() % 960+960, rand() % 1080, 0);
	m_fMoveSpeed = 300.f;
}

void HomingWeaponScript::FixedUpdate(float fixedDeltaTime)
{/*
	if (s_vPlayerPos.x >= m_pOwner->m_Transform.Position.x) m_pOwner->m_Transform.Position.x+= fixedDeltaTime * 300;
	if (s_vPlayerPos.x < m_pOwner->m_Transform.Position.x) m_pOwner->m_Transform.Position.x-= fixedDeltaTime * 300;
	if (s_vPlayerPos.y >= m_pOwner->m_Transform.Position.y) m_pOwner->m_Transform.Position.y+= fixedDeltaTime * 300;
	if (s_vPlayerPos.y < m_pOwner->m_Transform.Position.y) m_pOwner->m_Transform.Position.y-= fixedDeltaTime * 300;*/

	m_cRender->m_fAnimationAccTime += fixedDeltaTime;
	if (m_cRender->m_fAnimationAccTime > m_cRender->m_fAnimationDelayTime)
	{
		m_cRender->m_iAnimationFrameIndex = (m_cRender->m_iAnimationFrameIndex + 1) % m_cRender->m_tAnim->m_motions[m_cRender->m_iAnimationMotionIndex].FrameCount;
		m_cRender->m_fAnimationAccTime -= m_cRender->m_fAnimationDelayTime;
	}
	//회전
	Vector3 dirVector = s_vPlayerPos;
	if (s_vPlayerPos.y < m_Transform.Position.y)
		dirVector = m_Transform.Position - dirVector;
	else
		dirVector = dirVector - m_Transform.Position;


	m_cRender->m_fRotate = Vector3::Angle2D(m_vPrevVector, dirVector);
	if (s_vPlayerPos.y > m_Transform.Position.y)
		m_cRender->m_fRotate += 180.f;
}

void HomingWeaponScript::Update(float DeltaTime)
{
	m_fSinValue += DeltaTime;
	Vector3 dirVector = s_vPlayerPos;
	Vector3 tmp = (dirVector - m_Transform.Position).Nomalization() * DeltaTime * m_fMoveSpeed;
	if ((dirVector - m_Transform.Position).Magnitude() > 600.f)
	{
		m_pOwner->m_Transform.Position.x += tmp.x;
		m_pOwner->m_Transform.Position.y = sin(m_fSinValue) * m_fMoveSpeed + 600.f;
	}
	else
	{
		m_pOwner->m_Transform.Position.x += tmp.x;
		m_pOwner->m_Transform.Position.y += tmp.y;
	}
}

void HomingWeaponScript::Reset()
{
	//position setting
	m_Transform.SetPosition(rand() % 920 + 1000, rand() % 1080, 0);
	m_pOwner->SetStatus(game::Status::Active);
	m_fSinValue = rand() % 360;

	//호밍 미사일 발사
	s_eSoundChannel = (s_eSoundChannel + 1) % 2 + 15;
	ResourceManager::GetInstance()->PlayMusic(game::eSoundList::Battle, 4, static_cast<game::eSoundChannel>(s_eSoundChannel));
}
