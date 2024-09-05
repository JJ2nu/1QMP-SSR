#include "CrossHairScript.h"
#include "ResourceManager.h"
#include "InputSystem.h"
#include "GameObject.h"

CrossHairScript::CrossHairScript(GameObject* pOwner, std::string ObjName)
	:ScriptComponent(pOwner, ObjName), m_cCollider(nullptr), m_cRender(nullptr)
{
	Start();
}

CrossHairScript::~CrossHairScript()
{
}

void CrossHairScript::Start()
{
	//TextureRender
	m_cRender = m_pOwner->CreateComponent<TextureComponent>("CrossHairTextureComponent");
	m_cRender->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"CrossHair", L"\\Animation\\UI\\UI_Aim.bmp");
	m_cRender->SetExcep(RGB(255, 0, 255));


	//Collider
	m_cCollider = m_pOwner->CreateComponent<ColliderComponent>("CrossHairColliderComponent");
	m_cCollider->m_Transform.SetScale(80, 80, 0);
	m_cCollider->SetStatus(game::Status::InActive);
}

void CrossHairScript::Update(float deltaTime)
{
	if (input::KEYTAP(input::KEY::L_MOUSE_BUTTON))
	{
		m_bColliderFlag = true;
		m_fCurContinueTime = 0.f;
		m_cCollider->SetStatus(game::Status::Active);
	}

	if (m_bColliderFlag && m_fCurContinueTime < m_fContinueTime)
	{
		m_fCurContinueTime += deltaTime;
	}
	else
	{
		m_bColliderFlag = false;
		m_cCollider->SetStatus(game::Status::InActive);
	}
}

void CrossHairScript::FixedUpdate(float fixedDeltaTime)
{
	const input::MouseState& MousePos = input::InputSystem::GetInstance()->GetMouseState();
	m_Transform.SetPosition(MousePos.x, MousePos.y, 0);
}

void CrossHairScript::Render()
{}

void CrossHairScript::OnCollision(ColliderComponent* src)
{
	GameObject* HitObject = src->GetOwner();
	if (HitObject->GetObjType() == game::OBJECT_TYPE::HOMING_WEAPON)
	{
		//적 미사일 요격 성공 음성
		ResourceManager::GetInstance()->PlayMusic(game::eSoundList::Battle, 13, game::eSoundChannel::SFX_Player_Intercept);
		HitObject->SetStatus(game::Status::InActive);
	}
}



