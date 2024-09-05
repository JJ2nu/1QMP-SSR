#pragma once
#include "GameObject.h"
#include "CutSceneBossScript.h"
class CutSceneBossObject : public GameObject
{
private:
	CutSceneBossScript* m_Script;

public:
	CutSceneBossObject(SceneBase* Scene) : GameObject("Boss", Scene)
	{
		SetObjType(game::OBJECT_TYPE::BOSS);
		m_Script = CreateComponent<CutSceneBossScript>("BossScript");
	}
	virtual ~CutSceneBossObject() {};

	virtual void OnCollisionEnter(ColliderComponent* src)
	{
		m_Script->OnCollisionEnter(src);
	}
	virtual void OnCollisionExit(ColliderComponent* src)
	{
		m_Script->OnCollisionExit(src);
	}



};

