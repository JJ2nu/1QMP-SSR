#pragma once
#include "FontScript.h"
// 여기 보면 폰트 스크립트 상속 받고

class NumberPrintUIScript : public FontScript
{
public:
	NumberPrintUIScript(GameObject* pOwner, std::string ObjName);
	virtual void Start(); // 시작 업데이트
	virtual void FixedUpdate(float fixedDeltaTime);


	int m_iNumber; // 만든 용도 여기에다 static으로 값 받아서 누적해서 사용하면 됨
	std::wstring m_sNumber;

};


