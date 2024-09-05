#pragma once

#include "GameTime.h"
#include "GameRender.h"
#include "GameObject.h"

class GameManager
{
public:
	static GameManager* GetInstance();
	static void DestroyInstance();

	void Initialize();
	void Update(float deltaTime);
	void FixeUpdate();
	void Render();
	void Finalize();
	void Run();

private:
	static GameManager* instance;
	GameTime m_Time;

private:
	int m_UpdateCount = 0;
	int m_FixedUpdateCount = 0;

private:
	GameManager();
	~GameManager();
};
