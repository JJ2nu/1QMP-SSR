#pragma once
#include "GameObject.h"
#include "BossScript.h"
#include "Observer.h"
class BossObject : public GameObject
{
public:
	BossScript* m_Script;

public :
	BossObject(SceneBase* Scene) : GameObject("Boss", Scene)
	{
		Observer::GetInstance()->SetBoss(this);
		SetObjType(game::OBJECT_TYPE::BOSS);
		m_Script = CreateComponent<BossScript>("BossScript");
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

