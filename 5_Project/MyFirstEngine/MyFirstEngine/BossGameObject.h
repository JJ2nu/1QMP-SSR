#pragma once
#include "GameObject.h"
#include "Observer.h"
#include "Boss1Script.h"
#include "Boss2Script.h"
#include "Boss3Script.h"


class BossObject : public GameObject
{
public:
	ScriptComponent* m_Script;
public:
	BossObject(SceneBase* Scene,int stageIndex) : GameObject("Boss", Scene)
	{
		SetObjType(game::OBJECT_TYPE::BOSS);
		switch (stageIndex)
		{
		case 1:
			m_Script = dynamic_cast<Boss1Script*>(m_Script);
			m_Script = CreateComponent<Boss1Script>("Boss1Script");
			break;

		case 2:
			m_Script = dynamic_cast<Boss2Script*>(m_Script);
			m_Script = CreateComponent<Boss2Script>("Boss2Script");
			
			break;

		case 3:
			m_Script = dynamic_cast<Boss3Script*>(m_Script);
			m_Script = CreateComponent<Boss3Script>("Boss3Script");
			break;
		}
	}
	virtual ~BossObject() {};

	virtual void OnCollisionEnter(ColliderComponent* src)
	{
		m_Script->OnCollisionEnter(src);
	}
	virtual void OnCollisionExit(ColliderComponent* src)
	{
		m_Script->OnCollisionExit(src);
	}



};

