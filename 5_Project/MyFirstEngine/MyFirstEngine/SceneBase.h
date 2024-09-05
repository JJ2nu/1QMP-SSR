#pragma once
#include "Object.h"
#include "ColliderManager.h"
#include "ObjectManager.h"

class SceneBase : public Object
{
public:
	virtual void Initialize() = 0;
	virtual void Finalize() = 0;

	//모든 Scene의 기능이 똑같은데 상속받아서 할 이유가 있나? 싶어서 일단 이렇게 만듬
	// 바꿀꺼면 언제든지
	void FixedUpdate(float fixedDeltaTime);
	void Update(float deltaTime);
	void Render();
	void Destroy();

	void Clear();

	
	void AddObject(GameObject* obj, game::OBJECT_TYPE type);
	void EraseObject(game::OBJECT_TYPE type, std::string ObjName);
	
	virtual void Enter() = 0;
	virtual void Exit() = 0;

public:
	SceneBase(std::string m_ObjName);
	virtual ~SceneBase();

protected:
//public:
	//EvnetManager안에 들어갈 가능성이 농후??
	ColliderManager m_ColliderManager;
	ObjectManager m_ObjectManager;

public:
	void AddCollider(ColliderComponent* collider, game::OBJECT_TYPE type = game::OBJECT_TYPE::DEFAULT);

};

