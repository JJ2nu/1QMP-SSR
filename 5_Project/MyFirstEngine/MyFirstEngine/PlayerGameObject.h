#pragma once
#include "GameObject.h"
#include "PlayerScript.h"
#include "Observer.h"

class PlayerGameObject :public GameObject
{
public:
	PlayerScript* myScript;
	std::vector<PlayerBulletObject*> m_PBullet;
public:
	PlayerGameObject(SceneBase* Scene) :GameObject("Player", Scene)
	{
		SetObjType(game::OBJECT_TYPE::PLAYER);
		myScript = CreateComponent<PlayerScript>("PlayerScript");
		Observer::GetInstance()->SetPlayer(this);
		Observer::GetInstance()->SettingPlayerEnhance();
	}
	virtual ~PlayerGameObject() {};

	virtual void OnCollisionEnter(ColliderComponent* src)
	{
		myScript->OnCollisionEnter(src);
	}
};