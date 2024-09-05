#pragma once
#include "TextureUIScript.h"

class TextTureUIIoopScript : public TextureUIScript
{
public :
	TextTureUIIoopScript(GameObject* pOwner, std::string ObjName);

	virtual void Start(); // 시작 업데이트
	virtual void FixedUpdate(float fixedDeltaTime);
	virtual void Update(float deltaTime){};

	bool m_bSwitch = true;
};

