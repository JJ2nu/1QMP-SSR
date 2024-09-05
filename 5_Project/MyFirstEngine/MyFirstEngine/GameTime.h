#pragma once
#include <Windows.h>

class GameTime
{
public:
	void InitTime();
	void UpdateTime();
	float GetDeltaTime();

	float GetTimeScale();
	void SetTimeScale(float n);

private:
	LARGE_INTEGER frequency;
	LARGE_INTEGER prevCounter;
	LARGE_INTEGER currentCounter;
	float deltaTime;
	float timeScale = 1.0f;


public:
	GameTime();
	~GameTime();
};
