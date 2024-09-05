#pragma once
#include "GameObject.h"
#include "TextTureUI_Input_Script.h"


class Middle_Story_02_BackGroundUI : public GameObject
{
	TextTureUI_Input_Script* myScript;

public:

	Middle_Story_02_BackGroundUI(SceneBase* Scene) :GameObject("Middle_Story_02_BackGroundUI", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<TextTureUI_Input_Script>("Middle_Story_02_BackGroundUI");
		myScript->m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"Middle_Story_02_BackGroundUI1", L"\\Image\\13. MIDDLE_STORY_02\\STORY_Story07_Briefing_01.bmp");
		myScript->m_TexComp->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"Middle_Story_02_BackGroundUI2", L"\\Image\\13. MIDDLE_STORY_02\\STORY_Story07_Briefing_02~03.bmp");
		myScript->m_TexComp->m_tTexture[2] = ResourceManager::GetInstance()->LoadTexture(L"Middle_Story_02_BackGroundUI3", L"\\Image\\13. MIDDLE_STORY_02\\STORY_Story07_Briefing_02~03.bmp");
		myScript->m_TexComp->m_tTexture[3] = ResourceManager::GetInstance()->LoadTexture(L"Middle_Story_02_BackGroundUI4", L"\\Image\\13. MIDDLE_STORY_02\\STORY_Story07_Briefing_04~05.bmp");
		myScript->m_TexComp->m_tTexture[4] = ResourceManager::GetInstance()->LoadTexture(L"Middle_Story_02_BackGroundUI5", L"\\Image\\13. MIDDLE_STORY_02\\STORY_Story07_Briefing_04~05.bmp");
		myScript->m_TexComp->m_tTexture[5] = ResourceManager::GetInstance()->LoadTexture(L"Middle_Story_02_BackGroundUI6", L"\\Image\\13. MIDDLE_STORY_02\\STORY_Story07_Briefing_06.bmp");
		myScript->m_TexComp->m_tTexture[6] = ResourceManager::GetInstance()->LoadTexture(L"Middle_Story_02_BackGroundUI7", L"\\Image\\13. MIDDLE_STORY_02\\STORY_Story07_Briefing_07.bmp");
		myScript->m_TexComp->m_tTexture[7] = ResourceManager::GetInstance()->LoadTexture(L"Middle_Story_02_BackGroundUI8", L"\\Image\\13. MIDDLE_STORY_02\\STORY_Story07_Briefing_08.bmp");
	
		myScript->m_eScene_Type = game::SCENE_TYPE::SHIP_DIRECTING_BOSS_03;

		myScript->m_iTextureSize = 8;
		myScript->m_TexComp->m_iRenderFlag = 1;
		myScript->m_Transform.SetPosition(ScreenWidth / 2, ScreenHeight / 2, 0);
	}

	virtual ~Middle_Story_02_BackGroundUI(){};

private:

};


