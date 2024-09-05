#pragma once
#include "GameObject.h"
#include "TypingTextUIScript.h"

class TypingTextUI : public GameObject
{
public:
	TypingTextUIScript* myScript;
	TypingTextUI(SceneBase* Scene) : GameObject("TypingTextUI", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<TypingTextUIScript>("TypingTextUIScript");

		
		std::wstring dialogs[9] = {
L"긴급 뉴스를 전합니다.\n\
오늘 오전, 우리의 방위 위성이 지구 궤도 외곽에서 비정상적인 움직임을 포착했습니다.\n\
이는 반란군 함대가 지구 방어선에 접근하고 있음을 의미합니다.\n\
모든 시민은 최대한 빨리 안전한 대피소로 이동하시길 당부드립니다.",

L"우리의 지구 연합군은 이 위협에 맞서 싸우기 위해 즉시 대응 조치를 취하고 있습니다.\n\
모든 조종사와 방위 부대에 출격 명령이 내려졌으며, 우리의 방어 시스템은 전투 준비 상태에 있습니다.\n\
우리는 이 위기를 함께 극복할 것입니다.\n\
시민 여러분의 협조와 지지가 그 어느 때보다 중요합니다.",

L"코드네임-SSR. 방금 전, 우리의 정찰 위성이 유로파 궤도에서 적 함선의 이동을 포착했다.\n\
직후 해당 위성과의 통신이 끊겼으며, 파괴된 것으로 추정된다.\n\
적은 실시간으로 우리 방위선을  전진하고 있으며, 상황은 심각하다.",

L"임무 목표는 명확하다. 방위 궤도에 접근 중인 적의 구축함을 식별, 추적, 그리고 파괴하는 것이다.",

L"적 구축함은 고도로 무장하고 있으며,\n\
다량의 유도 미사일과 대구경 레이저 주포로 무장하고 있다.\n\
이들을 효과적으로 상대하기 위해서는 정밀한 조준과 사격이 필요하다.\n\
또한, 적의 반격에 대비하여 항상 기동성을 유지하고 주변 상황을 주시해야 한다.",

L"지금까지의 작전 성공률 100%를 고려할 때, 네가 실패할 것이라고는 생각지 않는다.\n\
네 능력과 결단력에 의심의 여지는 없다.\n\
그럼, 행운을 빌지. 인류 연맹에 영광을.",

L"조종석에 앉은 주인공이 기체 시스템과 상호 점검을 시작합니다.\n\
기체의 컴퓨터 시스템과 대화하듯 체크리스트를 확인합니다.",

L"엔진 점검: \"엔진 시스템 점검 시작. 모든 엔진이 정상적으로 작동 중입니다.\"\n\
무기 시스템 점검 : \"무기 시스템 로드 및 검사 중. 모든 무기가 전투 준비 상태입니다.\"\n\
생명 유지 장치 검 : \"생명 유지 시스템 점검. 모든 시스템이 최적 상태입니다.\"\n\
시스템 최종 확인 : \"시스템 올 그린. 모든 시스템 작동 정상.\"",

L"출격 준비 완료: \"출격 준비 완료. 이륙합니다. 인류 연맹에 영광을.\""
		};

		myScript->SetMyColor(255, 0, 0);
		myScript->SetMyDialog(dialogs, 9);
		myScript->SetRectSizeAndTransform(1920, 1080, 500, 200);
		myScript->SetFontSize(40);
		myScript->m_eScene_Type = game::SCENE_TYPE::INTRODUCTION_STORY_BRIEFING;
	}
};