#include "PlayerBuffAreaScript.h"
#include "SceneBase.h"
#include "ResourceManager.h"

PlayerBuffAreaScript::PlayerBuffAreaScript(GameObject* pOwner, std::string ObjName)
	: AreaWeaponScript(pOwner, ObjName)
{
	Start();
}

void PlayerBuffAreaScript::Start()
{
	// 이미지 
	m_TexComp = m_pOwner->CreateComponent<TextureComponent>("PlayerBuffAreaTextureComponent");
	m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"BuffAreaWepon", L"\\TestResource\\Icon_Sample_0.bmp");
	// 키값 조심하기 

	// m_TexComp->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"Monster", L"\\Texture\\Cat_King.bmp");  혹시 몰라서 대기
	m_TexComp->m_uExcep = RGB(255, 0, 255);
	m_TexComp->m_uRenderIndex = 0;

	// 콜라이더 추후 최종 빌드 시 콜라이더 표시 삭제 해야됨 했을 경우 주석 삭제
	m_ColComp = m_pOwner->CreateComponent<ColliderComponent>("PlayerBuffAreaColliderComponent");
	m_ColComp->SetStatus(game::Status::Active);
	m_ColComp->m_Transform.SetScale(72.0f, 72.0f, 0);
}

void PlayerBuffAreaScript::FixedUpdate(float fixedDeltaTime)
{

}

void PlayerBuffAreaScript::Reset()
{
	m_fImageChangeTime = 0;
	m_TexComp->m_uRenderIndex = 0;
	m_ColComp->SetStatus(game::Status::InActive);
}


