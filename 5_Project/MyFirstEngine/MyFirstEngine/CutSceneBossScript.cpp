#include "CutSceneBossScript.h"
#include "ResourceManager.h"

CutSceneBossScript::CutSceneBossScript(GameObject* pOwner, const std::string& ObjName)
	:ScriptComponent(pOwner, ObjName), m_cRender(nullptr)
{
	Start();
}

CutSceneBossScript::~CutSceneBossScript()
{}

void CutSceneBossScript::AnimationInitialize()
{
	//애니메이션
	m_cRender = m_pOwner->CreateComponent<AnimationComponent>("PlayerAnimationComponent");
	//m_cRender->m_tAnim = ResourceManager::GetInstance()->LoadAnimationImage(L"Boss1", L"\\Animation\\Player\\boss001_anime.bmp");
	//m_cRender->m_tAnim = ResourceManager::GetInstance()->LoadAnimationImage(L"Boss2", L"\\Animation\\Player\\boss002_anime.bmp");
	m_cRender->m_tAnim = ResourceManager::GetInstance()->LoadAnimationImage(L"Boss3", L"\\Animation\\Player\\boss003_anime.bmp");

	ResourceManager::GetInstance()->LoadAnimationMotion(m_cRender->m_tAnim, L"\\Animation\\Player\\BossIdle.txt");				 //	OBJECT_STATUS_IDLE,
	m_cRender->m_fAnimationDelayTime = 0.2f;
	m_cRender->m_iAnimationMotionIndex = 0;
	m_cRender->m_iAnimationFrameIndex = 0;
	m_cRender->m_fAnimationAccTime = 0.0f;
}

void CutSceneBossScript::AnimationUpdate(float fixedDeltaTime)
{
	m_cRender->m_fAnimationAccTime += fixedDeltaTime;
	if (m_cRender->m_fAnimationAccTime > m_cRender->m_fAnimationDelayTime)
	{
		m_cRender->m_iAnimationFrameIndex = (m_cRender->m_iAnimationFrameIndex + 1) % m_cRender->m_tAnim->m_motions[m_cRender->m_iAnimationMotionIndex].FrameCount;
		m_cRender->m_fAnimationAccTime -= m_cRender->m_fAnimationDelayTime;
	}
	m_Transform.Position.y += floatingVector * fixedDeltaTime * 10;
}

void CutSceneBossScript::Start()
{
	AnimationInitialize();
	m_Transform.SetPosition(1920/2, 1080/2,0);
}

void CutSceneBossScript::FixedUpdate(float fixedDeltaTime)
{
	AnimationUpdate(fixedDeltaTime);
	m_cRender->m_fRotate = m_Transform.Rotation.x++;
}

