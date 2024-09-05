#pragma once
#include "GameObject.h"
#include "TypingTextUIScript.h"

class Story01_Dialog_News : public GameObject
{
	
public:
	TypingTextUIScript* myScript;
	Story01_Dialog_News(SceneBase* Scene) : GameObject("Story01_Dialog_News", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<TypingTextUIScript>("Story01_Dialog_NewsUIScript");


std::wstring dialogs[7] = 
		{			
			L" ", // 지직 거리는 소리

			L"긴급 뉴스를 전합니다. 오늘 오전, 우리의 방위 위성이 지구 궤도 외곽에서 비정상적인 움직임을 포착했습니다.",

			L"이는 반란군 함대가 지구 방어선에 접근하고 있음을 의미합니다.",

			L"모든 시민은 최대한 빨리 안전한 대피소로 이동하시길 당부드립니다.",

			L"우리의 지구 연합군은 이 위협에 맞서 싸우기 위해 즉시 대응 조치를 취하고 있습니다.",

			L"모든 조종사와 방위 부대에 출격 명령이 내려졌으며, 우리의 방어 시스템은 전투 준비 상태에 있습니다.	",

			L"우리는 이 위기를 함께 극복할 것입니다. 시민 여러분의 협조와 지지가 그 어느 때보다 중요합니다."

		};

		
		myScript->m_eSoundChannel = game::eSoundChannel::Voice;
		myScript->m_eSoundList = game::eSoundList::STORY_Story01_News;

		myScript->SetMyColor(255, 255, 255);
		myScript->SetMyDialog(dialogs, 7);
		myScript->SetRectSizeAndTransform(800, 500, 550, 730);
		myScript->SetFontSize(50);
		myScript->m_eScene_Type = game::SCENE_TYPE::INTRODUCTION_STORY_BRIEFING;
		
	};
	~Story01_Dialog_News(){};

private:

};
