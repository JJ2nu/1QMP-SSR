#pragma once
#include "GameObject.h"
#include "TextureUIScript.h"

class ShipDirectingBoss_02_Object : public GameObject
{
	TextureUIScript* myScript;

public:
	ShipDirectingBoss_02_Object(SceneBase* Scene) : GameObject("ShipDirectingBoss_01_Object", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<TextureUIScript>("ShipDirectingBoss_02_Object");
		myScript->m_Transform.SetPosition(ScreenWidth / 2, ScreenHeight / 2, 0);

		myScript->m_sObjName = L"ShipDirectingBoss_02_Object";
		myScript->m_sRoute = L"\\TestResource\\meeting_boss2\\meeting_boss2 (";
		myScript->SetMyPoldeo(myScript->m_sObjName, myScript->m_sRoute, 45);

		myScript->m_eScene_Type = game::SCENE_TYPE::STAGE_NORMAL_02;

		myScript->m_bObjectType = true; // 애니메이션
		myScript->m_iTextureSize = 45; // 이미지 갯수
		myScript->m_fMovieMAXDelayTime = 0.08f; // MAX 델타
	

		myScript->m_TexComp->m_iRenderFlag = 1; // 배경이면 꼭 이거 해주어야 한다
	}
};