#include "SceneManager.h"
#include "SceneBase.h"
#include "Observer.h"
#include "PrototypeScene.h"
// 씬 모음
#include "SceneSet.h"
SceneManager* SceneManager::instance = nullptr;
SceneManager* SceneManager::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new SceneManager();
    }
    return instance;
}
void SceneManager::DestroyInstance()
{
    if (instance != nullptr)
    {
        delete instance;
        instance = nullptr;
    }
}
void SceneManager::FixedUpdate(float fixedDeltaTime)
{
    m_CurScene->FixedUpdate(fixedDeltaTime);
}
void SceneManager::Update(float deltaTime)
{
    m_CurScene->Update(deltaTime);
}
void SceneManager::Render()
{
    m_CurScene->Render();
}
void SceneManager::Destroy()
{
    m_CurScene->Destroy();
}
void SceneManager::InitSceneManager()
{
    m_SceneArr[(UINT)game::SCENE_TYPE::START] = new Start_Menu;                                    // 시작 화면
    m_SceneArr[(UINT)game::SCENE_TYPE::MAIN_MENU] = new MainMenuScene;                             // 메인 메뉴 (난이도 버튼 클릭하여 씬이동)
    m_SceneArr[(UINT)game::SCENE_TYPE::STAGE_TUTORIAL] = new Tutorial_Scene;                       // 튜토리얼
    m_SceneArr[(UINT)game::SCENE_TYPE::SALLY] = new Sally_Scene;                                   // 출격씬
    m_SceneArr[(UINT)game::SCENE_TYPE::STAGE_NORMAL_01] = new Boss_01_Scene;                       // 보스1
    m_SceneArr[(UINT)game::SCENE_TYPE::STAGE_NORMAL_02] = new Boss_02_Scene;                       // 보스2
    m_SceneArr[(UINT)game::SCENE_TYPE::STAGE_NORMAL_03] = new Boss_03_Scene;                       // 보스3
    m_SceneArr[(UINT)game::SCENE_TYPE::INTRODUCTION_STORY_NEWS] = new Story_News_Scene;            // 도입 스토리(뉴스)
    m_SceneArr[(UINT)game::SCENE_TYPE::INTRODUCTION_STORY_BRIEFING] = new Story_Briefing_Scene;    // 도입 스토리(요약 보고)
    m_SceneArr[(UINT)game::SCENE_TYPE::PLAY] = new SampleScene;                                    // 일단 테스트씬 사용중  추후 삭제할예정
    m_SceneArr[(UINT)game::SCENE_TYPE::UPGRADE] = new Upgrade_Scene;                               // 업그레이드 씬
    m_SceneArr[(UINT)game::SCENE_TYPE::MIDDLE_STORY_01] = new Middle_Story_01_Scene;               // 1스테이지 클리어 중간 스토리
    m_SceneArr[(UINT)game::SCENE_TYPE::MIDDLE_STORY_02] = new Middle_Story_02_Scene;               // 2스테이지 클리어 중간 스토리
    m_SceneArr[(UINT)game::SCENE_TYPE::ENDING_STORY] = new Ending_Story_Scene;                     // 엔딩 스토리
    m_SceneArr[(UINT)game::SCENE_TYPE::SHIP_DIRECTING_BOSS_01] = new Ship_Directing_Boss_01_Scene; // 함선 보스1 애니메이션 연출
    m_SceneArr[(UINT)game::SCENE_TYPE::SHIP_DIRECTING_BOSS_02] = new Ship_Directing_Boss_02_Scene; // 함선 보스2 애니메이션 연출
    m_SceneArr[(UINT)game::SCENE_TYPE::SHIP_DIRECTING_BOSS_03] = new Ship_Directing_Boss_03_Scene; // 함선 보스3 애니메이션 연출
    m_SceneArr[(UINT)game::SCENE_TYPE::COKPIT] = new Cokpit_Script;                                // 함선 보스3 애니메이션 연출	// 예비씬
    m_SceneArr[(UINT)game::SCENE_TYPE::ENDING] = new Ending_Credits_Scene;                         // 엔딩크레딧
    
    
    m_CurScene = m_SceneArr[(UINT)game::SCENE_TYPE::START];
    // 현재 씬 설정
    m_CurScene->Enter();
}
void SceneManager::ChangeScene(game::SCENE_TYPE type)
{
    m_CurScene->Exit();
    m_CurScene->Clear();
    m_CurScene = m_SceneArr[(UINT)type];
    m_CurScene->Enter();
    Observer::GetInstance()->m_GameFlag = game::SCENE_TYPE::CHANGE_EFFECT;
    Observer::GetInstance()->m_CurSceneFlag = type;
}
SceneBase* SceneManager::GetCurScene()
{
    return m_CurScene;
}
SceneManager::SceneManager() : m_SceneArr{}, m_CurScene(nullptr)
{
}
SceneManager::~SceneManager()
{
}