#pragma once
#include "GameObject.h"
#include "TypingTextUIScript.h"

// 디테일 조정이 필요 해야 할 것 해당 씬이 되면 자동으로 넘어 가기
class Middle_Story_02_Dialog : public GameObject
{
public:
	TypingTextUIScript* myScript;
	Middle_Story_02_Dialog(SceneBase* Scene) : GameObject("Middle_Story_02_Dialog", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<TypingTextUIScript>("Middle_Story_02_DialogScript");

		std::wstring dialogs[8] =
		{
		L"이런 젠장, 적 기함이 워프 엔진을 가동했다. 시스템! 워프 목적지를 추적해!",

		L"적 좌표 추적 중입니다...... 분석 완료. 적 기함의 워프 목적지는 지구입니다.",

		L"이 경우, 작전명 '별의 구원' 임무 하달을 권장합니다. 관련 데이터를 전투 지휘 시스템에 업로드하겠습니다.",

		L"긴급 상황이다, SSR. 적 기함이 워프를 통해 지구로 도주했다. 따라서, 임무 내용을 갱신하겠다.",

		L"다음 목표는 기밀 작전 '별의 구원'을 실행하는 것이다. 네가 이 작전의 핵심이다.",

		L"'별의 구원'... 말입니까?",

		L"그렇다. SSR, 즉시 워프 엔진을 가동하라. 목적지는 지구.",

		L"임무 확인. 워프 엔진 기동. 좌표 설정 지구 궤도. 출격합니다!"
		};

		
		myScript->m_eSoundChannel = game::eSoundChannel::Voice;
		myScript->m_eSoundList = game::eSoundList::STORY_Story07_Briefing;

		// 보스 씬
		myScript->m_eScene_Type = game::SCENE_TYPE::SHIP_DIRECTING_BOSS_03;

		myScript->SetMyColor(255, 255, 255);
		myScript->SetMyDialog(dialogs, 8);
		myScript->SetRectSizeAndTransform(650, 300, 630, 780);
		myScript->SetFontSize(50);

	}

	virtual ~Middle_Story_02_Dialog() {};
};