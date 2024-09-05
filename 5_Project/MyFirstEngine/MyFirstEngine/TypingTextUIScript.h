#pragma once
#include "FontScript.h"

class TypingTextUIScript : public FontScript
{

public:
	TypingTextUIScript(GameObject* pOwner, std::string ObjName);
	virtual void Start(); // 시작 업데이트
	virtual void FixedUpdate(float fixedDeltaTime);
	virtual void Update(float deltaTime);


	int i_fontCount = 0; // 용도 한글자씩 출력하기 위해 만듬 카운터용
	float m_fDelayTime = 0.05f; // 딜레이 타임
	float m_fMaxDelayTime = m_fDelayTime; // 맥스 딜레이 타임

	bool m_bTextFlag = true;
	bool m_bFullFlag = false;
	
	game::SCENE_TYPE m_eScene_Type; // 씬 타입 전환용
	void SetMyLoadScene(); // 전환 씬 전달용
};

