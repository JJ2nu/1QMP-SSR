#pragma once
#include "GameObject.h"
#include "EndingStory_TextureScript.h"


class EndingStoryBackGroundUI : public GameObject
{
	EndingStory_TextureScript* myScript;

public:
	EndingStoryBackGroundUI(SceneBase* Scene) :GameObject("EndingStoryBackGroundUI", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<EndingStory_TextureScript>("TextureUIScript");
		// 추후 이미지 변경 필요 변경시 주석 삭제

		myScript->m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"EndingStoryBackGroundUI6", L"\\Image\\17. ENDING\\ending (1).bmp");

		myScript->m_TexComp->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"EndingStoryBackGroundUI8", L"\\Image\\17. ENDING\\ending (3).bmp");

		myScript->m_TexComp->m_tTexture[2] = ResourceManager::GetInstance()->LoadTexture(L"EndingStoryBackGroundUI10", L"\\Image\\17. ENDING\\ending (5).bmp");

		myScript->m_TexComp->m_tTexture[3] = ResourceManager::GetInstance()->LoadTexture(L"EndingStoryBackGroundUI17", L"\\Image\\17. ENDING\\ending (12).bmp");

		myScript->m_TexComp->m_tTexture[4] = ResourceManager::GetInstance()->LoadTexture(L"EndingStoryBackGroundUI19", L"\\Image\\17. ENDING\\ending (14).bmp");

		myScript->m_TexComp->m_tTexture[5] = ResourceManager::GetInstance()->LoadTexture(L"EndingStoryBackGroundUI22", L"\\Image\\17. ENDING\\ending (17).bmp");
		myScript->m_TexComp->m_tTexture[6] = ResourceManager::GetInstance()->LoadTexture(L"EndingStoryBackGroundUI23", L"\\Image\\17. ENDING\\ending (18).bmp");
		myScript->m_TexComp->m_tTexture[7] = ResourceManager::GetInstance()->LoadTexture(L"EndingStoryBackGroundUI24", L"\\Image\\17. ENDING\\ending (19).bmp");
		myScript->m_TexComp->m_tTexture[8] = ResourceManager::GetInstance()->LoadTexture(L"EndingStoryBackGroundUI25", L"\\Image\\17. ENDING\\ending (20).bmp");
		myScript->m_TexComp->m_tTexture[9] = ResourceManager::GetInstance()->LoadTexture(L"EndingStoryBackGroundUI26", L"\\Image\\17. ENDING\\ending (21).bmp");

		myScript->m_TexComp->m_tTexture[10] = ResourceManager::GetInstance()->LoadTexture(L"EndingStoryBackGroundUI27", L"\\Image\\17. ENDING\\ending (22).bmp");
		myScript->m_TexComp->m_tTexture[11] = ResourceManager::GetInstance()->LoadTexture(L"EndingStoryBackGroundUI28", L"\\Image\\17. ENDING\\ending (23).bmp");
		myScript->m_TexComp->m_tTexture[12] = ResourceManager::GetInstance()->LoadTexture(L"EndingStoryBackGroundUI29", L"\\Image\\17. ENDING\\ending (24).bmp");
		myScript->m_TexComp->m_tTexture[13] = ResourceManager::GetInstance()->LoadTexture(L"EndingStoryBackGroundUI30", L"\\Image\\17. ENDING\\ending (25).bmp");
		myScript->m_TexComp->m_tTexture[14] = ResourceManager::GetInstance()->LoadTexture(L"EndingStoryBackGroundUI31", L"\\Image\\17. ENDING\\ending (26).bmp");


		myScript->m_TexComp->m_iRenderFlag = 1;
		myScript->m_Transform.SetPosition(ScreenWidth / 2, ScreenHeight / 2, 0);
	}

	virtual ~EndingStoryBackGroundUI(){};

private:

};

