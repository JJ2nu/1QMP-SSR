#include "PlayerBulletScript.h"
#include "SceneBase.h"
#include "ResourceManager.h"



PlayerBulletScript::PlayerBulletScript(GameObject* pOwner, std::string ObjName)
	:WeaponScript(pOwner, ObjName)
{
	Start();
}

void PlayerBulletScript::Start()
{

	m_ColComp = m_pOwner->CreateComponent<ColliderComponent>("PlayerBulletComponent");
	m_TexComp = m_pOwner->CreateComponent<TextureComponent>("PlayerBulletTextureComponent");

	m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"PlayerBullet", L"\\Animation\\Player\\player_missile.bmp");
	m_TexComp->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"PlayerBullet1", L"\\Animation\\Player\\player_missile2.bmp");
	m_TexComp->m_uExcep = RGB(255, 0, 255);
	m_Transform.Position.x = 0;
	m_Transform.Position.y = 0;

	m_fMoveSpeed = 1000.0f;
}



void PlayerBulletScript::MoveMissileLeft(float fixedDeltaTime)
{
	m_Transform.Position.x += m_fMoveSpeed * fixedDeltaTime;
	if (m_Transform.Position.x + missileWidth > 1980) // 화면 왼쪽 끝에 도달하면 미사일을 리셋
	{
		m_pOwner->SetStatus(game::Status::InActive);
	}

}

void PlayerBulletScript::ChangEnhanceBullet(int i)
{
	m_TexComp->m_uRenderIndex = i;
}

void PlayerBulletScript::FixedUpdate(float fixedDeltaTime)
{
	MoveMissileLeft(fixedDeltaTime);
}

