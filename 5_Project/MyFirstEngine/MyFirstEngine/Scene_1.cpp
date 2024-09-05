#include "Scene_1.h"
#include "Story_News_ButtonUI.h"

// 테스트용 UI 게이지바 숫자 표시용
#include "TestNumberPrintUI.h"
#include "TypingTextUI.h"
#include "StartStageUI.h"

// 스토리 씬
#include "Story01_Dialog_News.h"
#include "Story02_Dialog_Briefing.h"
#include "NewsBackGroundUI.h"

// 함선 출발 씬
#include "Sally_Object.h"
#include "ShipDirectingBoss_01_Object.h"
#include "ShipDirectingBoss_02_Object.h"
#include "ShipDirectingBoss_03_Object.h"
void Scene_1::Initialize()
{
}

void Scene_1::Finalize()
{

}

void Scene_1::Enter()
{
	// 백그라운드 이미지
	NewsBackGroundUI* newsBackGroundUI = new NewsBackGroundUI(this);
	AddObject(newsBackGroundUI, game::OBJECT_TYPE::UI);

	// 게이지바 %센트 숫자 출력용 UI  테스트용 추후 삭제
	TestNumberPrintUI* testNumberPrintUI = new TestNumberPrintUI(this);
	AddObject(testNumberPrintUI, game::OBJECT_TYPE::UI);

	// 글자 하나씩 찍기 테스트 버전
	TypingTextUI* typingTextUI = new TypingTextUI(this);
	AddObject(typingTextUI, game::OBJECT_TYPE::UI);

	// 게임 시작 UI
	StartStageUI* startStageUI = new StartStageUI(this);
	AddObject(startStageUI, game::OBJECT_TYPE::UI);

	// 뉴스 씬 대화
	Story01_Dialog_News* story01_Dialog_News = new Story01_Dialog_News(this);
	AddObject(story01_Dialog_News, game::OBJECT_TYPE::UI);

	// 빌딩 씬 대화
	Story02_Dialog_Briefing* story02_Dialog_Briefing = new Story02_Dialog_Briefing(this);
	AddObject(story02_Dialog_Briefing, game::OBJECT_TYPE::UI);

	Sally_Object* sally_object = new Sally_Object(this);
	AddObject(sally_object, game::OBJECT_TYPE::UI);

	//스킵버튼
	Story_News_ButtonUI* story_News_ButtonUI = new Story_News_ButtonUI(this);
	AddObject(story_News_ButtonUI, game::OBJECT_TYPE::UI);

	/*ShipDirectingBoss_01_Object* shipDirectingBoss_01_Object = new ShipDirectingBoss_01_Object(this);
	AddObject(shipDirectingBoss_01_Object, game::OBJECT_TYPE::UI);*/

	//ShipDirectingBoss_03_Object* shipDirectingBoss_03_Object = new ShipDirectingBoss_03_Object(this);
	//AddObject(shipDirectingBoss_03_Object, game::OBJECT_TYPE::UI);

}

void Scene_1::Exit()
{
	m_ColliderManager.ResetGroup();
}
