#include "GameTime.h"
#include "cmath"


GameTime::GameTime() {}
GameTime::~GameTime() {}
	
void GameTime::InitTime()
{
	QueryPerformanceFrequency(&frequency);	// 고성능 타이머가 1초 동안 증가시킬수 있는 TickCount 값
	QueryPerformanceCounter(&prevCounter);  // 초기 TickCount 값
}

void GameTime::UpdateTime()
{
	QueryPerformanceCounter(&currentCounter); // 현재 TickCount 값
	deltaTime = static_cast<float>(currentCounter.QuadPart - prevCounter.QuadPart) /
		static_cast<float>(frequency.QuadPart);  // 카운터차이를 시간 초단위로 변환

	prevCounter = currentCounter;
}

float GameTime::GetTimeScale()
{
	return timeScale;
}
void GameTime::SetTimeScale(float n)
{
	if (n < 0)
		return;
	timeScale = n;
}
float GameTime::GetDeltaTime()
{
	return (deltaTime * timeScale);
}
