#pragma once
#include "GameObject.h"
#include "Boss_3_Script.h"
class Boss_3_Object : public GameObject
{
private:
	Boss_3_Script* m_Script;

public:
	Boss_3_Object(SceneBase* Scene) : GameObject("Boss", Scene)
	{
		SetObjType(game::OBJECT_TYPE::MONSTER);
		m_Script = CreateComponent<Boss_3_Script>("BossScript");
	}
	virtual ~Boss_3_Object() {};

	virtual void OnCollisionEnter(ColliderComponent* src)
	{
		m_Script->OnCollisionEnter(src);
	}
	virtual void OnCollisionExit(ColliderComponent* src)
	{
		m_Script->OnCollisionExit(src);
	}



};

