#pragma once
#include "ScriptComponent.h"

class CharacterPlayUIScript : public ScriptComponent
{
public:
	CharacterPlayUIScript(GameObject* pOwner, std::string ObjName);
	virtual void Start(); // 시작 업데이트
	TextureComponent* m_cPortraitTexture;
	TextureComponent* m_cShipTexture;
	virtual void FixedUpdate(float fixedDeltaTime);

	int index = 0;
};

