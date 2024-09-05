#pragma once

#include "GameObject.h"
#include "PlayerBulletScript.h"


class PlayerBulletObject : public GameObject
{
public:
	PlayerBulletScript* m_Script;
public:
	PlayerBulletObject(SceneBase* Scene) :GameObject("PlayerBullet", Scene)
	{
		SetObjType(game::OBJECT_TYPE::PLAYER_WEAPON);

		m_Script = CreateComponent<PlayerBulletScript>("PlayerBulletScript");
	}
	virtual ~PlayerBulletObject() {};

	virtual void OnCollisionEnter(ColliderComponent* src)
	{
		m_Script->OnCollisionEnter(src);
	};
};