#pragma once
#include "GameObject.h"
#include "TextTureUI_Input_Script.h"

class NewsBackGroundUI : public GameObject
{
	TextTureUI_Input_Script* myScript;

public:
	NewsBackGroundUI(SceneBase* Scene) :GameObject("NewBackGroundUI", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<TextTureUI_Input_Script>("TextureUIScript");
		myScript->m_iTextureSize = 2;
		//myScript->m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"NewBackGroundUI1", L"\\04. INTRODUCTION_STORY_NEWS\\image\\STORY_Story01_News_01.bmp");
		myScript->m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"NewBackGroundUI1", L"\\image\\04. INTRODUCTION_STORY_NEWS\\STORY_Story01_News_01.bmp");
		myScript->m_TexComp->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"NewBackGroundUI2", L"\\image\\04. INTRODUCTION_STORY_NEWS\\STORY_Story01_News_01~07.bmp");
		myScript->m_TexComp->m_iRenderFlag = 1;
		myScript->m_Transform.SetPosition(ScreenWidth / 2, ScreenHeight / 2, 0);
		//myScript->m_iInputStop = -1;
	}

	virtual ~NewsBackGroundUI(){};

private:

};

