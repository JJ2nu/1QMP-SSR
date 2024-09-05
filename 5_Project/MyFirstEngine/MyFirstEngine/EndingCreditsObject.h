#pragma once
#include "GameObject.h"
#include "TextureUIScript.h"

class EndingCreditsObject : public GameObject
{
	TextureUIScript* myScript;

public:
	EndingCreditsObject(SceneBase* Scene) :GameObject("EndingCreditsObject", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<TextureUIScript>("TextureUIScript");
		// 추후 이미지 변경 필요 변경시 주석 삭제
		myScript->m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"EndingCreditsObject", L"\\TestResource\\background_stage001.bmp");
		myScript->m_TexComp->m_iRenderFlag = 1;
		myScript->m_Transform.SetPosition(ScreenWidth / 2, ScreenHeight / 2, 0);
	}

	virtual ~EndingCreditsObject() {};

private:

};
