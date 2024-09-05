#include "FadeInFadeOutScript.h"
#include "FaidInFadeOutRenderComponent.h"
#include "ResourceManager.h"
#include "GameObject.h"

FadeInFadeOutScript::FadeInFadeOutScript(GameObject* pOwner, std::string ObjName)
	:ScriptComponent(pOwner, ObjName)
{
	Start();
}

void FadeInFadeOutScript::Start()
{
	m_Transform.SetPosition(ScreenWidth / 2, ScreenHeight / 2, 0);
	m_Transform.SetScale(ScreenWidth, ScreenHeight, 0);
	
	
	m_cDoor = m_pOwner->CreateComponent<TextureComponent>("DoorRenderComponentComponent");
	std::wstring m_sObjName = L"door_open";
	std::wstring m_sRoute = L"\\Image\\21. DOOR_OPEN\\Big_Door\\door_open (";
	for (int i = 0; i < DoorIndexSize; i++)
	{
		std::wstring temp = m_sObjName + L"_" + std::to_wstring(static_cast<int>(i));
		std::wstring temp2 = m_sRoute + std::to_wstring(static_cast<int>(i + 1)) + L").bmp";
		m_cDoor->m_tTexture[i] = ResourceManager::GetInstance()->LoadTexture(temp, temp2);
	}
	m_cDoor->SetStatus(game::Status::InActive);
	m_cDoor->m_iRenderFlag = 2;
	m_cDoor->m_uExcep = RGB(0, 0, 0);
	m_cDoor->m_uAlpha = 255;
	m_cDoor->m_uRenderIndex = 30;


	m_cTexture = m_pOwner->CreateComponent<FaidInFadeOutRenderComponent>("FaidInFadeOutRenderComponentComponent");


}

void FadeInFadeOutScript::FixedUpdate(float fixedDeltaTime)
{
	//1 정방향, 2 꺼꾸로
	if (m_iFlag == 2)
		DoorFlag = 0;
	if (DoorFlag == 1)
	{
		m_cDoor->SetStatus(game::Status::Active);
		m_cDoor->m_uRenderIndex--;
		if (m_cDoor->m_uRenderIndex == 0)
		{
			DoorFlag = 0;
			return;
		}
		return;
	}
	else if (DoorFlag == 2)
	{
		m_cDoor->SetStatus(game::Status::Active);
		m_cDoor->m_uRenderIndex++;
		if (m_cDoor->m_uRenderIndex == DoorIndexSize - 1)
		{
			DoorFlag = 1;
			m_pOwner->SetStatus(game::Status::InActive);
			m_OnEffect = false;
			return;
		}
		return;
	}
	m_fElapsedTime += fixedDeltaTime;

	while (m_fElapsedTime >= m_fDelayTime)
	{
		if (m_iSign > 0)
		{
			if (m_iFlag == 1)
			{
				m_OnEffect = false;
			}
			else
			{
				if (m_cTexture->m_fAlpha < 255)
				{
					m_iSign *= 2;
					m_cTexture->m_fAlpha += m_iSign;
				}
				else
				{
					m_OnEffect = false;
				}
			}
		}
		if (m_iSign < 0)
		{
			if (m_iFlag == 1)
			{
				DoorFlag = 2;
			}
			else
			{
				if (m_cTexture->m_fAlpha > 0)
				{
					m_iSign *= 2;
					m_cTexture->m_fAlpha += m_iSign;
				}
				else
				{
					DoorFlag = 2;
					if (m_iFlag == 2)
					{
						m_pOwner->SetStatus(game::Status::InActive);
						m_OnEffect = false;
					}
				}
			}
		}
		m_fElapsedTime -= m_fDelayTime;
	}
}

void FadeInFadeOutScript::SetSign(bool ture)
{
	m_OnEffect = true;
	//Start
	if (ture)
	{
		m_iSign = -1;
		m_fElapsedTime = 0;
		if(m_iFlag != 1)
			m_cTexture->m_fAlpha = 255.0f;
	}
	else//End
	{
		m_iSign = 1;
		m_fElapsedTime = 0;
		m_cTexture->m_fAlpha = 0.0f;
	}
}

void FadeInFadeOutScript::SetDoor(bool ture)
{
	if (ture)
	{
		DoorFlag = true;
	}
	else//End
	{
		DoorFlag = false;
	}
}
