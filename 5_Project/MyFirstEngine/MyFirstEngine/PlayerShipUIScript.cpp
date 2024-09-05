#include "PlayerShipUIScript.h"
#include "SceneBase.h"
#include "ResourceManager.h"

PlayerShipUIScript::PlayerShipUIScript(GameObject* pOwner, std::string ObjName)
	:ScriptComponent(pOwner, ObjName), m_TexComp(nullptr)
{
	Start();
}

void PlayerShipUIScript::Start()
{
	m_TexComp = m_pOwner->CreateComponent<TextureComponent>("PlayerShipUITextureComponent");
	m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"PlayerShipUI", L"\\TestResource\\Ship_Player_0.bmp");
	m_TexComp->m_uExcep = RGB(255, 0, 255);
}

void PlayerShipUIScript::FixedUpdate(float fixedDeltaTime)
{
	// 추후 플레이어 체력이 감소할때 이미지 변경 필요
}
