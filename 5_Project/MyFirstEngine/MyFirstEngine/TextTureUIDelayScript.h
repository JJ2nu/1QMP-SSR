#pragma once
#include "TextureUIScript.h"

class TextTureUIDelayScript : public TextureUIScript
{
public:
	TextTureUIDelayScript(GameObject* pOwner, std::string ObjName);

	virtual void Start(); // 시작 업데이트
	virtual void FixedUpdate(float fixedDeltaTime);
	virtual void Update(float deltaTime) {};

	int m_iDelayCount = 0; // 용도 몇번째 씬까지 얼마나 딜레이를 줄 것인가
	float m_fOtherMAXDelayTime = 0;

	float m_fStartDelayTime = 0.f;
	bool m_bStartDelayCheck = false;
};

