#pragma once
#include "GameObject.h"
#include "Boss_2_Script.h"
class Boss_2_Object : public GameObject
{
private:
	Boss_2_Script* m_Script;

public:
	Boss_2_Object(SceneBase* Scene) : GameObject("Boss", Scene)
	{
		SetObjType(game::OBJECT_TYPE::MONSTER);
		m_Script = CreateComponent<Boss_2_Script>("Boss_2_Script");
	}
	virtual ~Boss_2_Object() {};

	virtual void OnCollisionEnter(ColliderComponent* src)
	{
		m_Script->OnCollisionEnter(src);
	}
	virtual void OnCollisionExit(ColliderComponent* src)
	{
		m_Script->OnCollisionExit(src);
	}



};

