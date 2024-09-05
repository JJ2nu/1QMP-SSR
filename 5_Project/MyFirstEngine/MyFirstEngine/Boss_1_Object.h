#pragma once
#include "GameObject.h"
#include "Boss_1_Script.h"
class Boss_1_Object : public GameObject
{
public:
	Boss_1_Script* m_Script;

public:
	Boss_1_Object(SceneBase* Scene) : GameObject("Boss", Scene)
	{
		SetObjType(game::OBJECT_TYPE::BOSS);
		m_Script = CreateComponent<Boss_1_Script>("BossScript");
	}
	virtual ~Boss_1_Object() {};

	virtual void OnCollisionEnter(ColliderComponent* src)
	{
		m_Script->OnCollisionEnter(src);
	}
	virtual void OnCollisionExit(ColliderComponent* src)
	{
		m_Script->OnCollisionExit(src);
	}



};

