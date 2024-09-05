#pragma once
#include "GameObject.h"
#include "TypingTextUIScript.h"

// 디테일 조정이 필요 해야 할 것 해당 씬이 되면 자동으로 넘어 가기
class Middle_Story_01_Dialog : public GameObject
{
public:
	TypingTextUIScript* myScript;
	Middle_Story_01_Dialog(SceneBase* Scene) : GameObject("Middle_Story_01_Dialog", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<TypingTextUIScript>("Middle_Story_01_Dialog");

		std::wstring dialogs[12] =
		{
		L"잘 해냈다, 코드네임-SSR. 임무 목표의 성공적인 제거로 모두가 안도의 한숨을 쉬고 있다.", 

		L"덕분에 승리까지 한 걸음 더 다가갔군. 인류 연맹에 영광을.", 

		L"감사합니다. 함께라면 어떤 임무도 완수할 수 있을 거라 믿습니다. 인류 연맹에 영광을.",

		L"그나저나, SSR. 너는 유로파 출신이었지? 지구에 대해서는 얼마나 알고 있나?",

		L"저는 유로파에서 자랐지만, 지구에 대한 이야기는 많이 들었습니다.",

		L"그 푸른 바다와 넓은 대지... 언젠가는 그 아름다움을 직접 눈으로 보고 싶어요.",

		L"그래, 지구. 우리의 고향 푸른 별. 정말 아름다운...",

		L"긴급 경보! 화성 궤도에서 적의 기함이 감지되었습니다.",

		L"잠깐, 먼저 상황을 정확히 파악하지. 시스템, 적 기함의 현재 위치와 이동 경로를 상세히 보고하도록. 우리에게 얼마나 시간이 남았는지도 계산해.",

		L"분석 중입니다. 적 기함은 아직 화성 궤도를 벗어나지 않았으나 지구 방향으로 고속 이동 중입니다. 예상 도착 시간은 48시간 내입니다.",

		L"알겠다. SSR! 새로운 임무를 하달하겠다. 임무 목표는 적의 기함을 추적하고 파괴하는 것이다. 우리 모두의 미래가 네 손에 달려있다.",

		L"너의 능력을 믿는다, SSR. 모든 시스템을 전투 모드로 전환하라. 인류 연맹에 영광을!"
		};

		
		myScript->m_eSoundChannel = game::eSoundChannel::Voice;
		myScript->m_eSoundList = game::eSoundList::STORY_Story05_Briefing;

		// 보스 씬
		myScript->m_eScene_Type = game::SCENE_TYPE::SHIP_DIRECTING_BOSS_02;

		myScript->SetMyColor(255, 255, 255);
		myScript->SetMyDialog(dialogs, 12);
		myScript->SetRectSizeAndTransform(650, 300, 630, 780);
		myScript->SetFontSize(50);

	}

	virtual ~Middle_Story_01_Dialog() {};
};