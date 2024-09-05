#include "CharacterPlayUIScript.h"
#include "SceneBase.h"
#include "ResourceManager.h"
#include "Observer.h"
#include "PlayerGameObject.h"
CharacterPlayUIScript::CharacterPlayUIScript(GameObject* pOwner, std::string ObjName)
	:ScriptComponent(pOwner, ObjName)
{
	Start();
}

void CharacterPlayUIScript::Start()
{
	//초상화
	m_cPortraitTexture = m_pOwner->CreateComponent<TextureComponent>("CharacterPlayUITextureComponent");
	m_cPortraitTexture->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"CharacterPlayUI1", L"\\Image\\00. BATTLE\\UpperUI\\PlayerUI\\Portrait\\UI_Player_Sprite_Character_01.bmp");
	m_cPortraitTexture->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"CharacterPlayUI2", L"\\Image\\00. BATTLE\\UpperUI\\PlayerUI\\Portrait\\UI_Player_Sprite_Character_02.bmp");
	m_cPortraitTexture->m_tTexture[2] = ResourceManager::GetInstance()->LoadTexture(L"CharacterPlayUI3", L"\\Image\\00. BATTLE\\UpperUI\\PlayerUI\\Portrait\\UI_Player_Sprite_Character_03.bmp");
	m_cPortraitTexture->m_uExcep = RGB(255, 0, 255);
	m_cPortraitTexture->m_uRenderIndex = 0;

	//함선
	m_cShipTexture = m_pOwner->CreateComponent<TextureComponent>("ShipUITextureComponent");
	m_cShipTexture->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"CharacterShipUI1", L"\\Image\\00. BATTLE\\UpperUI\\PlayerUI\\ShipState\\UI_Player_Sprite_State_01.bmp");
	m_cShipTexture->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"CharacterShipUI2", L"\\Image\\00. BATTLE\\UpperUI\\PlayerUI\\ShipState\\UI_Player_Sprite_State_02.bmp");
	m_cShipTexture->m_tTexture[2] = ResourceManager::GetInstance()->LoadTexture(L"CharacterShipUI3", L"\\Image\\00. BATTLE\\UpperUI\\PlayerUI\\ShipState\\UI_Player_Sprite_State_03.bmp");
	m_cShipTexture->m_uExcep = RGB(255, 0, 255);
	m_cShipTexture->m_uRenderIndex = 0;
	m_cShipTexture->m_vOffset = Vector3(416, 30, 0);

}

void CharacterPlayUIScript::FixedUpdate(float fixedDeltaTime)
{
	m_cPortraitTexture->m_uRenderIndex = index;
	m_cShipTexture->m_uRenderIndex = index;

	if (Observer::GetInstance()->m_bHardFlag)
	{
		if (Observer::GetInstance()->GetPlayer()->myScript->m_fHP <= 200.0f) index = 1;
		if (Observer::GetInstance()->GetPlayer()->myScript->m_fHP <= 100.0f) index = 2;
	}
	else
	{
		if (Observer::GetInstance()->GetPlayer()->myScript->m_fHP <= 600.0f) index = 1;
		if (Observer::GetInstance()->GetPlayer()->myScript->m_fHP <= 300.0f) index = 2;
	}

}
