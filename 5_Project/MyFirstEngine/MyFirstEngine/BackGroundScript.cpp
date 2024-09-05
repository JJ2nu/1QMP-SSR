#include "BackGroundScript.h"
#include "TextureComponent.h"
#include "ResourceManager.h"
#include "GameObject.h"
BackGroundScript::BackGroundScript(GameObject* pOwner, std::string ObjName)
    :ScriptComponent(pOwner, ObjName)
{
    Start();
}
void BackGroundScript::Start()
{

	m_cTexture = m_pOwner->CreateComponent<TextureComponent>("PrototypeBackgroundObjectTextureComponent");
	m_cTexture->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"PrototypeBackground1", L"\\Animation\\Player\\background_stage001.bmp");
	m_cTexture->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"PrototypeBackground2", L"\\Animation\\Player\\background_stage002.bmp");
	m_cTexture->m_tTexture[2] = ResourceManager::GetInstance()->LoadTexture(L"PrototypeBackground3", L"\\Animation\\Player\\background_stage003.bmp");
	m_cTexture->m_uRenderIndex = 2;
	m_cTexture->m_iRenderFlag = 1;
	m_bShakeFlag = false;
	m_Transform.SetPosition(ScreenWidth / 2, ScreenHeight / 2, 0);
}

void BackGroundScript::FixedUpdate(float fixedDeltaTime)
{
	if (m_bShakeFlag)
	{
		m_fElapsedTime += fixedDeltaTime;
		if (m_fElapsedTime <= 0.3f)
		{
			CameraShake(fixedDeltaTime);
		}
		else
		{
			CameraReset();
		}
	}

}

void BackGroundScript::CameraShake(float fixedDeltaTime)
{
	m_Transform.SetPosition(ScreenWidth / 2 + (fixedDeltaTime * m_fShakeVector * 200), ScreenHeight / 2 + (fixedDeltaTime * m_fShakeVector * 200), 0);
	m_fShakeVector *= -1;

}

void BackGroundScript::ShakeOn()
{
	m_bShakeFlag = true;

}

void BackGroundScript::CameraReset()
{
	m_bShakeFlag = false;
	m_fElapsedTime = 0.0f;
	m_Transform.SetPosition(ScreenWidth / 2, ScreenHeight / 2, 0);
}
