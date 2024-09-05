#pragma once
#include "FontScript.h"

class StartStageUIScript : public FontScript
{
public:
	StartStageUIScript(GameObject* pOwner, std::string ObjName);
	virtual void Start(); // 시작 업데이트
	virtual void FixedUpdate(float fixedDeltaTime);

	void SetAllText(); // 배열 복사

	float MaxdelayTime = 0.f;
	//void DialogReset(int _DialogCount)
	//{
	//	if(m_sDialog != nullptr)
	//		delete[] m_sDialog;
	//	m_sDialog = new std::string[_DialogCount];
	//}

};

