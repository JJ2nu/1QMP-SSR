#pragma once
#include "GameObject.h"
#include "MonsterScript.h"


class MonsterGameObject :public GameObject
{
private:
    float moveSpeed = 500.0f;
public:
	MonsterGameObject(SceneBase* Scene) :GameObject("Monster", Scene)
	{
		SetObjType(game::OBJECT_TYPE::MONSTER);
		CreateComponent<ColliderComponent>("MonsterColliderComponent");
		//CreateComponent<AnimationComponent>("PlayerAnimationComponent");
		CreateComponent<TextureComponent>("MonsterTextureComponent");


		CreateComponent<MonsterScript>("MonsterScript");
	}
	virtual ~MonsterGameObject() {};
};