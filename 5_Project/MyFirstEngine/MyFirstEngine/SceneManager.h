#pragma once
#include <array>
#include "Define.h"

class SceneBase;
typedef unsigned int        UINT;

class SceneManager
{
private:
	static SceneManager* instance;

	SceneBase* m_SceneArr[(UINT)(game::SCENE_TYPE::END)];
	SceneBase* m_CurScene;

public:
	static SceneManager* GetInstance();
	static void DestroyInstance();

public:
	void FixedUpdate(float fixedDeltaTime);
	void Update(float deltaTime);
	void Render();
	void Destroy();		//삭제를 EventManager에서 하면 필요 없음 -> 만드는중


	// array로 하면 씬 초기화도 바꿔주어야 함 "확인 바람"
	void InitSceneManager();
	// 이것도 Array로 하면 std::String name으로 받아서 찾으면 될듯
	//	-> Scene도 Object상속받고 있어서 이름으로 찾을 수 있음
	void ChangeScene(game::SCENE_TYPE type);
	SceneBase* GetCurScene();
	void ReloadScene();

private:
	SceneManager();
	~SceneManager();
};

