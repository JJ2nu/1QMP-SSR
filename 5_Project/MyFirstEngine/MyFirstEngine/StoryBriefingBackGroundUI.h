#pragma once
#include "GameObject.h"
#include "TextTureUI_Input_Script.h"

class StoryBriefingBackGroundUI : public GameObject
{
	TextTureUI_Input_Script* myScript;

public:
	StoryBriefingBackGroundUI(SceneBase* Scene) :GameObject("StoryBriefingBackGroundUI", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<TextTureUI_Input_Script>("TextTureUI_Input_Script");
		// 추후 이미지 변경 필요 변경시 주석 
		myScript->m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"StoryBriefingBackGroundUI0", L"\\Image\\04. INTRODUCTION_STORY_NEWS\\STORY_Story02_Briefing_00.bmp");
		myScript->m_TexComp->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"StoryBriefingBackGroundUI2", L"\\Image\\04. INTRODUCTION_STORY_NEWS\\STORY_Story02_Briefing_01.bmp");
		myScript->m_TexComp->m_tTexture[2] = ResourceManager::GetInstance()->LoadTexture(L"StoryBriefingBackGroundUI3", L"\\Image\\04. INTRODUCTION_STORY_NEWS\\STORY_Story02_Briefing_02~03.bmp");
		myScript->m_TexComp->m_tTexture[3] = ResourceManager::GetInstance()->LoadTexture(L"StoryBriefingBackGroundUI4", L"\\Image\\04. INTRODUCTION_STORY_NEWS\\STORY_Story02_Briefing_02~03.bmp");
		myScript->m_TexComp->m_tTexture[4] = ResourceManager::GetInstance()->LoadTexture(L"StoryBriefingBackGroundUI5", L"\\Image\\04. INTRODUCTION_STORY_NEWS\\STORY_Story02_Briefing_04.bmp");
		myScript->m_TexComp->m_tTexture[5] = ResourceManager::GetInstance()->LoadTexture(L"StoryBriefingBackGroundUI6", L"\\Image\\04. INTRODUCTION_STORY_NEWS\\STORY_Story02_Briefing_05-1.bmp");
		myScript->m_TexComp->m_tTexture[6] = ResourceManager::GetInstance()->LoadTexture(L"StoryBriefingBackGroundUI7", L"\\Image\\04. INTRODUCTION_STORY_NEWS\\STORY_Story02_Briefing_05-2.bmp");
		myScript->m_TexComp->m_tTexture[7] = ResourceManager::GetInstance()->LoadTexture(L"StoryBriefingBackGroundUI8", L"\\Image\\04. INTRODUCTION_STORY_NEWS\\STORY_Story02_Briefing_06~08.bmp");
		myScript->m_TexComp->m_tTexture[8] = ResourceManager::GetInstance()->LoadTexture(L"StoryBriefingBackGroundUI9", L"\\Image\\04. INTRODUCTION_STORY_NEWS\\STORY_Story02_Briefing_06~08.bmp");
		myScript->m_TexComp->m_tTexture[9] = ResourceManager::GetInstance()->LoadTexture(L"StoryBriefingBackGroundUI10", L"\\Image\\04. INTRODUCTION_STORY_NEWS\\STORY_Story02_Briefing_06~08.bmp");
		myScript->m_TexComp->m_tTexture[10] = ResourceManager::GetInstance()->LoadTexture(L"StoryBriefingBackGroundUI11", L"\\Image\\04. INTRODUCTION_STORY_NEWS\\STORY_Story02_Briefing_09.bmp");


		//myScript->m_iInputStop = 6;
		myScript->m_iTextureSize = 11;
		myScript->m_TexComp->m_iRenderFlag = 1;
		myScript->m_Transform.SetPosition(ScreenWidth / 2, ScreenHeight / 2, 0);

		myScript->m_eScene_Type = game::SCENE_TYPE::SALLY;
	}

	virtual ~StoryBriefingBackGroundUI() {};

private:

};