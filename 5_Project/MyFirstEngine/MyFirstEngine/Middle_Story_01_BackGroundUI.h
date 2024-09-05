#pragma once
#include "GameObject.h"
#include "TextTureUI_Input_Script.h"


class Middle_Story_01_BackGroundUI : public GameObject
{
	TextTureUI_Input_Script* myScript;

public:

	Middle_Story_01_BackGroundUI(SceneBase* Scene) :GameObject("Middle_Story_01_BackGroundUI", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<TextTureUI_Input_Script>("Middle_Story_01_BackGroundUI");
		myScript->m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"Middle_Story_01_BackGroundUI", L"\\Image\\09. MIDDLE_STORY_01\\STORY_Story05_Briefing_01~02.bmp");
		myScript->m_TexComp->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"Middle_Story_02_BackGroundUI", L"\\Image\\09. MIDDLE_STORY_01\\STORY_Story05_Briefing_01~02.bmp");
		myScript->m_TexComp->m_tTexture[2] = ResourceManager::GetInstance()->LoadTexture(L"Middle_Story_03_BackGroundUI", L"\\Image\\09. MIDDLE_STORY_01\\STORY_Story05_Briefing_03.bmp");
		myScript->m_TexComp->m_tTexture[3] = ResourceManager::GetInstance()->LoadTexture(L"Middle_Story_04_BackGroundUI", L"\\Image\\09. MIDDLE_STORY_01\\STORY_Story05_Briefing_04.bmp");
		myScript->m_TexComp->m_tTexture[4] = ResourceManager::GetInstance()->LoadTexture(L"Middle_Story_05_BackGroundUI", L"\\Image\\09. MIDDLE_STORY_01\\STORY_Story05_Briefing_05~06.bmp");
		myScript->m_TexComp->m_tTexture[5] = ResourceManager::GetInstance()->LoadTexture(L"Middle_Story_06_BackGroundUI", L"\\Image\\09. MIDDLE_STORY_01\\STORY_Story05_Briefing_05~06.bmp");
		myScript->m_TexComp->m_tTexture[6] = ResourceManager::GetInstance()->LoadTexture(L"Middle_Story_07_BackGroundUI", L"\\Image\\09. MIDDLE_STORY_01\\STORY_Story05_Briefing_07.bmp");
		myScript->m_TexComp->m_tTexture[7] = ResourceManager::GetInstance()->LoadTexture(L"Middle_Story_08_BackGroundUI", L"\\Image\\09. MIDDLE_STORY_01\\STORY_Story05_Briefing_09.bmp");
		myScript->m_TexComp->m_tTexture[8] = ResourceManager::GetInstance()->LoadTexture(L"Middle_Story_09_BackGroundUI", L"\\Image\\09. MIDDLE_STORY_01\\STORY_Story05_Briefing_10~13.bmp");
		myScript->m_TexComp->m_tTexture[9] = ResourceManager::GetInstance()->LoadTexture(L"Middle_Story_10_BackGroundUI", L"\\Image\\09. MIDDLE_STORY_01\\STORY_Story05_Briefing_10~13.bmp");
		myScript->m_TexComp->m_tTexture[10] = ResourceManager::GetInstance()->LoadTexture(L"Middle_Story_11_BackGroundUI", L"\\Image\\09. MIDDLE_STORY_01\\STORY_Story05_Briefing_10~13.bmp");
		myScript->m_TexComp->m_tTexture[11] = ResourceManager::GetInstance()->LoadTexture(L"Middle_Story_12_BackGroundUI", L"\\Image\\09. MIDDLE_STORY_01\\STORY_Story05_Briefing_10~13.bmp");

		myScript->m_eScene_Type = game::SCENE_TYPE::SHIP_DIRECTING_BOSS_02;

		myScript->m_iTextureSize = 11;
		myScript->m_TexComp->m_iRenderFlag = 1;
		myScript->m_Transform.SetPosition(ScreenWidth / 2, ScreenHeight / 2, 0);
	}

	virtual ~Middle_Story_01_BackGroundUI() {};

private:

};
