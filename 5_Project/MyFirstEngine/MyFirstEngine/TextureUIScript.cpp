#include "TextureUIScript.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "Observer.h"


TextureUIScript::TextureUIScript(GameObject* pOwner, std::string ObjName)
	:ScriptComponent(pOwner, ObjName), m_TexComp(nullptr)
{
	Start();
}

void TextureUIScript::Start()
{
	m_TexComp = m_pOwner->CreateComponent<TextureComponent>("TextureUITextureComponent");
	m_TexComp->m_uRenderIndex = 0;

	m_TexComp->m_uExcep = RGB(255, 0, 255);
}

void TextureUIScript::FixedUpdate(float fixedDeltaTime)
{
	m_fDelayTime += fixedDeltaTime; // 타임 누적
	if (m_bObjectType == true && m_TexComp->m_uRenderIndex < m_iTextureSize - 1)
	{
		if (m_fDelayTime > m_fMovieMAXDelayTime)
		{
			m_TexComp->m_uRenderIndex++;
			m_fDelayTime = 0.f;
		}

	}

	if (m_TexComp->m_uRenderIndex == m_iTextureSize - 1)
	{
		if (m_fDelayTime > m_fSceneDelayTime)
		{
			m_fDelayTime = 0.f;
			SetMySceneChange();
		}
	}

}

void TextureUIScript::SetMyLoadScene(game::SCENE_TYPE name)
{
	Observer::GetInstance()->m_GameFlag = name;
}

void TextureUIScript::SetMySceneChange()
{
	Observer::GetInstance()->m_GameFlag = m_eScene_Type;
}

void TextureUIScript::SetMyTextureTransform(float _PositionX, float _PositionY)
{
	m_pOwner->m_Transform.SetPosition(_PositionX, _PositionY, 0);
}


void TextureUIScript::SetMyPoldeo(std::wstring _m_sObjName, std::wstring _m_sRoute, int _m_iTextureSize)
{

	for (int i = 0; i < _m_iTextureSize; i++)
	{
		std::wstring temp = _m_sObjName +L"_" + std::to_wstring(static_cast<int>(i));
		std::wstring temp2 = _m_sRoute + std::to_wstring(static_cast<int>(i+1)) + L").bmp";

		m_TexComp->m_tTexture[i] = ResourceManager::GetInstance()->LoadTexture(temp, temp2);
	}
}

void TextureUIScript::PlayMusic()
{
	//if()
}

