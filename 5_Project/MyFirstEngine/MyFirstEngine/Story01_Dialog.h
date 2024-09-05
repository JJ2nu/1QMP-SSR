#pragma once
#include "GameObject.h"
#include "TypingTextUIScript.h"

class Story01_Dialog : public GameObject
{
	
public:
	TypingTextUIScript* myScript;
	Story01_Dialog(SceneBase* Scene) : GameObject("Story01_Dialog", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<TypingTextUIScript>("Story01_DialogUIScript");

		std::wstring dialogs[18] = {
			L" ", // 지직 거리는 소리

			L"긴급 뉴스를 전합니다.\
			\n오늘 오전, 우리의 방위 위성이 지구 궤도 외곽에서 비정상적인 움직임을 포착했습니다.",

			L"이는 반란군 함대가 지구 방어선에 접근하고 있음을 의미합니다.",

			L"모든 시민은 최대한 빨리 안전한 대피소로 이동하시길 당부드립니다."

			L"우리의 지구 연합군은 이 위협에 맞서 싸우기 위해 즉시 대응 조치를 취하고 있습니다.",

			L"모든 조종사와 방위 부대에 출격 명령이 내려졌으며, 우리의 방어 시스템은 전투 준비 상태에 있습니다.",

			L"우리는 이 위기를 함께 극복할 것입니다. 시민 여러분의 협조와 지지가 그 어느 때보다 중요합니다.	",

			L" " //홀로그램 켜지는 소리

			L"코드네임-SSR. 방금 전, 우리의 정찰 위성이 유로파 궤도에서 적 함선의 이동을 포착했다.",

			L"직후 해당 위성과의 통신이 끊겼으며, 파괴된 것으로 추정된다.",

			L"적은 실시간으로 우리 방위선을 향해 전진하고 있으며, 상황은 심각하다.",

			L"임무 목표는 명확하다. 방위 궤도에 접근 중인 적의 구축함을 식별, 추적, 그리고 파괴하는 것이다.",

			L"적 구축함은 고도로 무장하고 있으며, 다량의 유도 미사일과 대구경 레이저 주포로 무장하고 있다.",

			L"이들을 효과적으로 상대하기 위해서는 정밀한 조준과 사격이 필요하다.",

			L"또한, 적의 반격에 대비하여 항상 기동성을 유지하고 주변 상황을 주시해야 한다."

			L"지금까지의 작전 성공률 100%를 고려할 때, 네가 실패할 것이라고는 생각지 않는다. 네 능력과 결단력에 의심의 여지는 없다.",

			L"그럼, 행운을 빌지. 인류 연맹에 영광을."
		};

		myScript->SetMyColor(0, 0, 0);
		myScript->SetMyDialog(dialogs, 18);
		myScript->SetRectSizeAndTransform(1920, 1080, 300, 900);
		myScript->SetFontSize(25);
	};
	~Story01_Dialog(){};

private:

};
