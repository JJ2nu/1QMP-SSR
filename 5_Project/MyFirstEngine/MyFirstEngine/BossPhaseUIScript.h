#pragma once
#include "ScriptComponent.h"


class BossPhaseUIScript : public ScriptComponent
{
public:
	BossPhaseUIScript(GameObject* pOwner, std::string ObjName);

	virtual void Start(); // 시작 업데이트
	virtual void FixedUpdate(float fixedDeltaTime);

	TextureComponent* m_TexComp;

};

