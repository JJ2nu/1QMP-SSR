#include "ButtonGameObject.h"
#include "InputSystem.h"
#include "Define.h"

void ButtonGameObject::FixedUpdate(float fixedDeltaTime)
{
	for (auto& pComponent : m_vComponentList)
	{
		if (pComponent->GetStatus() == game::Status::Active)
			pComponent->FixedUpdate(fixedDeltaTime);
	}
	for (auto& pGameObject : m_vChildGameObject)
	{
		if (pGameObject->GetStatus() == game::Status::Active)
			pGameObject->FixedUpdate(fixedDeltaTime);
	} 
	CurButtonStatus();
}

void ButtonGameObject::Update(float DeltaTime)
{
	for (auto& pComponent : m_vComponentList)
	{
		if (pComponent->GetStatus() == game::Status::Active)
			pComponent->Update(DeltaTime);
	}
	for (auto& pGameObject : m_vChildGameObject)
	{
		if (pGameObject->GetStatus() == game::Status::Active)
			pGameObject->Update(DeltaTime);
	}

	if (curStatus == ButtonStatus::EnterMouse)
	{
		m_iflag = 1;
		if (nullptr != m_cTexture && nullptr != m_cTexture->m_tTexture[1])
			m_cTexture->m_uRenderIndex = 1;
	}
	else if (curStatus == ButtonStatus::ExitMouse)
	{
		m_iflag = 0;
		if (nullptr != m_cTexture && nullptr != m_cTexture->m_tTexture[0])
			m_cTexture->m_uRenderIndex = 0;
	}
	if (m_iflag == 1 && input::KEYTAP(input::KEY::L_MOUSE_BUTTON))
	{
		OnClick();
	}
}

bool ButtonGameObject::IsButtonOnMouse(Vector3 mousePos)
{
	Transform LTranform = this->m_Transform;
	bool A1 = (LTranform.Position.y - m_vButtonScale.y / 2.f) > (mousePos.y);
	bool A2 = (LTranform.Position.y + m_vButtonScale.y / 2.f) < (mousePos.y);
	bool B1 = (LTranform.Position.x + m_vButtonScale.x / 2.f) < (mousePos.x);
	bool B2 = (LTranform.Position.x - m_vButtonScale.x / 2.f) > (mousePos.x);
	if (A1 || A2 || B1 || B2)
		return false;
	return true;
}

void ButtonGameObject::CurButtonStatus()
{
	const input::MouseState& MousePos = input::InputSystem::GetInstance()->GetMouseState();
	Vector3 dirVector(MousePos.x, MousePos.y, 0);
	bool curOnMouse = IsButtonOnMouse(dirVector);
	if (curOnMouse)
	{
		//이전에도 충돌중이고 지금도 충돌중
		if (PrevOnMouse)
		{
			curStatus = ButtonStatus::OnMouse;
		}
		else //이전에는 충돌하지 않았지만 지금은 충돌중 -> 방금 만남
		{
			PrevOnMouse = true;
			curStatus = ButtonStatus::EnterMouse;
		}
	}
	else
	{
		//이전에도 충돌중이지만 지금 충돌X
		if (PrevOnMouse)
		{
			PrevOnMouse = false;
			curStatus = ButtonStatus::ExitMouse;
		}
		else
			curStatus = ButtonStatus::Default;
	}
}


ButtonGameObject::ButtonGameObject(std::string ObjName, SceneBase* Scene)
	:GameObject(ObjName, Scene)
	, curStatus(ButtonStatus::Default)
	, PrevOnMouse(false)
	, m_iflag(0)
{}

ButtonGameObject::~ButtonGameObject()
{}
