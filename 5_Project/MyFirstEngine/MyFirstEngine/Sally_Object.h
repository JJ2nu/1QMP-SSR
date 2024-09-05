#pragma once
#include "GameObject.h"
#include "TextTureUIDelayScript.h"

class Sally_Object : public GameObject
{
	TextTureUIDelayScript* myScript;

public:
	Sally_Object(SceneBase* Scene) :GameObject("Sally_Object", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<TextTureUIDelayScript>("Sally_ObjectUIScript");
		myScript->m_Transform.SetPosition(ScreenWidth / 2, ScreenHeight / 2, 0);

		myScript->m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_1", L"\\Image\\05. SALLY\\bg_light_on (1)_1.bmp");
		myScript->m_TexComp->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_2", L"\\Image\\05. SALLY\\bg_light_on (1)_2.bmp");
		myScript->m_TexComp->m_tTexture[2] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_3", L"\\Image\\05. SALLY\\bg_light_on (1)_3.bmp");
		myScript->m_TexComp->m_tTexture[3] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_4", L"\\Image\\05. SALLY\\bg_light_on (1)_4.bmp");
		myScript->m_TexComp->m_tTexture[4] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_5", L"\\Image\\05. SALLY\\bg_light_on (1)_5.bmp");
		myScript->m_TexComp->m_tTexture[5] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_6", L"\\Image\\05. SALLY\\bg_sally (1).bmp");
		myScript->m_TexComp->m_tTexture[6] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_7", L"\\Image\\05. SALLY\\bg_sally (2).bmp");
		myScript->m_TexComp->m_tTexture[7] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_8", L"\\Image\\05. SALLY\\bg_sally (3).bmp");
		myScript->m_TexComp->m_tTexture[8] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_9", L"\\Image\\05. SALLY\\bg_sally (4).bmp");
		myScript->m_TexComp->m_tTexture[9] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_10", L"\\Image\\05. SALLY\\bg_sally (5).bmp");
		myScript->m_TexComp->m_tTexture[10] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_11", L"\\Image\\05. SALLY\\bg_sally (6).bmp");
		myScript->m_TexComp->m_tTexture[12] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_12", L"\\Image\\05. SALLY\\bg_sally (7).bmp");
		myScript->m_TexComp->m_tTexture[13] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_13", L"\\Image\\05. SALLY\\bg_sally (8).bmp");
		myScript->m_TexComp->m_tTexture[14] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_14", L"\\Image\\05. SALLY\\bg_sally (9).bmp");
		myScript->m_TexComp->m_tTexture[15] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_15", L"\\Image\\05. SALLY\\bg_sally (10).bmp");
		myScript->m_TexComp->m_tTexture[16] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_16", L"\\Image\\05. SALLY\\bg_sally (12).bmp");
		myScript->m_TexComp->m_tTexture[17] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_17", L"\\Image\\05. SALLY\\bg_sally (13).bmp");
		myScript->m_TexComp->m_tTexture[18] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_18", L"\\Image\\05. SALLY\\bg_sally (14).bmp");
		myScript->m_TexComp->m_tTexture[19] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_19", L"\\Image\\05. SALLY\\bg_sally (15).bmp");
		myScript->m_TexComp->m_tTexture[20] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_20", L"\\Image\\05. SALLY\\bg_sally (16).bmp");
		myScript->m_TexComp->m_tTexture[21] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_21", L"\\Image\\05. SALLY\\bg_sally (17).bmp");
		myScript->m_TexComp->m_tTexture[22] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_22", L"\\Image\\05. SALLY\\bg_sally (18).bmp");
		myScript->m_TexComp->m_tTexture[23] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_23", L"\\Image\\05. SALLY\\bg_sally (19).bmp");
		myScript->m_TexComp->m_tTexture[24] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_24", L"\\Image\\05. SALLY\\bg_sally (21).bmp");
		myScript->m_TexComp->m_tTexture[25] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_25", L"\\Image\\05. SALLY\\bg_sally (22).bmp");
		myScript->m_TexComp->m_tTexture[26] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_26", L"\\Image\\05. SALLY\\bg_sally (23).bmp");
		myScript->m_TexComp->m_tTexture[27] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_27", L"\\Image\\05. SALLY\\bg_sally (24).bmp");
		myScript->m_TexComp->m_tTexture[28] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_28", L"\\Image\\05. SALLY\\bg_sally (25).bmp");
		myScript->m_TexComp->m_tTexture[29] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_29", L"\\Image\\05. SALLY\\bg_sally (26).bmp");
		myScript->m_TexComp->m_tTexture[30] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_30", L"\\Image\\05. SALLY\\bg_sally (27).bmp");
		myScript->m_TexComp->m_tTexture[31] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_31", L"\\Image\\05. SALLY\\bg_sally (28).bmp");
		myScript->m_TexComp->m_tTexture[32] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_32", L"\\Image\\05. SALLY\\bg_sally (29).bmp");
		myScript->m_TexComp->m_tTexture[33] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_33", L"\\Image\\05. SALLY\\bg_sally (30).bmp");
		myScript->m_TexComp->m_tTexture[34] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_34", L"\\Image\\05. SALLY\\bg_sally (31).bmp");
		myScript->m_TexComp->m_tTexture[35] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_35", L"\\Image\\05. SALLY\\bg_sally (32).bmp");
		myScript->m_TexComp->m_tTexture[36] = ResourceManager::GetInstance()->LoadTexture(L"Sally_Object_36", L"\\Image\\05. SALLY\\bg_sally (33).bmp");

		//myScript->SetMyPoldeo(myScript->m_sObjName, myScript->m_sRoute, 37);

		//ResourceManager::GetInstance()->PlayMusic(game::eSoundList::STORY_Story03_Takeoff, 0, game::eSoundChannel::Voice);

		myScript->m_bObjectType = true; // 애니메이션
		myScript->m_iTextureSize = 37; // 이미지 갯수
		myScript->m_fMovieMAXDelayTime = 0.17f; // MAX 델타

		myScript->m_iDelayCount = 5; // 몇번째 씬까지 느리게 할것인지
	//	myScript->m_fOtherMAXDelayTime = 2.f; // 느리게 할 초

		myScript->m_fSceneDelayTime = 0.7f; // 씬전환 시간
		myScript->m_fStartDelayTime = 30.0f; // 시작 딜레이 타임 

		myScript->m_eScene_Type = game::SCENE_TYPE::SHIP_DIRECTING_BOSS_01;

		myScript->m_TexComp->m_iRenderFlag = 1; // 배경이면 꼭 이거 해주어야 한다
	}
};