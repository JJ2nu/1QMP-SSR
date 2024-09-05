#include "BossPhaseUIScript.h"
#include "SceneBase.h"
#include "ResourceManager.h"

BossPhaseUIScript::BossPhaseUIScript(GameObject* pOwner, std::string ObjName)
	:ScriptComponent(pOwner, ObjName), m_TexComp(nullptr)
{
	Start();
}

void BossPhaseUIScript::Start()
{
	m_TexComp = m_pOwner->CreateComponent<TextureComponent>("BossPhaseUITextureComponent");
	m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"BossPhaseUI", L"\\TestResource\\Icon_Sample_0.bmp");
	m_TexComp->m_uExcep = RGB(255, 0, 255);
}

void BossPhaseUIScript::FixedUpdate(float fixedDeltaTime)
{
	// 추후 보스 체력에 따른 출력 변경 생각하여 일단 추가 함.
}
