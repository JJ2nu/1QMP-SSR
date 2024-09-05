#pragma once
#include "GameObject.h"
#include "TypingTextUIScript.h"


// 디테일 조정이 필요 해야 할 것 해당 씬이 되면 자동으로 넘어 가기
class Story02_Dialog_Briefing : public GameObject
{
public:
	TypingTextUIScript* myScript;
	Story02_Dialog_Briefing(SceneBase* Scene) : GameObject("Story02_Dialog_Briefing", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<TypingTextUIScript>("Story02_Dialog_BriefingUIScript");

		std::wstring dialogs[11] = 
{
L"..", // 텍스트 X

L"..", // 텍스트 X
			
L"코드네임-SSR. 방금 전, 우리의 정찰 위성이 유로파 궤도에서 적 함선의 이동을 포착했다.",

L"직후 해당 위성과의 통신이 끊겼으며, 파괴된 것으로 추정된다.",

L"적은 실시간으로 우리 방위선을 향해 전진하고 있으며, 상황은 심각하다.",

L"임무 목표는 명확하다. 방위 궤도에 접근 중인 적의 구축함을 식별, 추적, 그리고 파괴하는 것이다.",

L"적 구축함은 고도로 무장하고 있으며, 다량의 유도 미사일과 대구경 레이저 주포로 무장하고 있다.",

L"이들을 효과적으로 상대하기 위해서는 정밀한 조준과 사격이 필요하다.",

L"또한, 적의 반격에 대비하여 항상 기동성을 유지하고 주변 상황을 주시해야 한다.",

L"지금까지의 작전 성공률 100%를 고려할 때, 네가 실패할 것이라고는 생각지 않는다. 네 능력과 결단력에 의심의 여지는 없다.",

L"그럼, 행운을 빌지. 인류 연맹에 영광을.",

};

		myScript->m_eSoundChannel = game::eSoundChannel::Voice;
		myScript->m_eSoundList = game::eSoundList::STORY_Story02_Briefing;
	
		myScript->m_eScene_Type = game::SCENE_TYPE::SALLY;

		myScript->SetMyColor(255, 255, 255);
		myScript->SetMyDialog(dialogs, 11);
		myScript->SetRectSizeAndTransform(690, 300, 610, 770);
		myScript->SetFontSize(50);

	}

	virtual ~Story02_Dialog_Briefing() {};
};