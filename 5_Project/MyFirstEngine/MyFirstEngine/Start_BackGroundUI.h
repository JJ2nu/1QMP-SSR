#pragma once
#include "GameObject.h"
#include "TextTureUIIoopScript.h"


class Start_BackGroundUI : public GameObject
{
	TextTureUIIoopScript* myScript;

public:

	Start_BackGroundUI(SceneBase* Scene) :GameObject("Start_BackGroundUI", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<TextTureUIIoopScript>("Start_BackGroundUI");
		myScript->m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"Start_BackGroundUI1", L"\\Image\\01. START\\bg_waiting001.bmp");
		myScript->m_TexComp->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"Start_BackGroundUI2", L"\\Image\\01. START\\bg_waiting002.bmp");

		myScript->m_bObjectType = true;		// 애니메이션 적용
		myScript->m_iTextureSize = 2;		// 사이즈
		myScript->m_fMovieMAXDelayTime = 0.6f;	// 딜레이 타임


		myScript->m_TexComp->m_iRenderFlag = 1;
		myScript->m_Transform.SetPosition(ScreenWidth / 2, ScreenHeight / 2, 0);
	}

	virtual ~Start_BackGroundUI() {};

private:

};


