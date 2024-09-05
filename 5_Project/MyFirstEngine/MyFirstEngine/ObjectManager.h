#pragma once
#include <list>
#include "Define.h"
#include "GameObject.h"

class GameObject;

class ObjectManager
{
private:
	//static ObjectManager* instance;
	std::list<GameObject*> m_ObjectList[(UINT)game::OBJECT_TYPE::END];

public:
	//static ObjectManager* GetInstance();
	//static void DestroyInstance();

	void Initialize();
	void Update(float deltaTime);
	void FixedUpdate(float fixedDeltaTime);
	void Render();
	void Destroy();
	void Finalize();
	void Clear();

	void AddObject(GameObject* obj, game::OBJECT_TYPE type);
	void EraseObject(game::OBJECT_TYPE type, std::string ObjName);
	/*
	Object* GetObjectSrc(OBJECT_TYPE _type, const char* _name);
	Object* Scene::GetObjectSrc(OBJECT_TYPE _type, const char* _name)
	{
		for (UINT j = 0; j < objArr[(UINT)_type].Size(); j++)
		{
			if (!strcmp(objArr[(UINT)_type][j]->objName, _name))
				return objArr[(UINT)_type][j];
		}
		return nullptr;
	} 
	*/
	GameObject* FindObejectByName(const std::string _name);
	GameObject* FindObejectByName(game::OBJECT_TYPE _type , const std::string _name);

	

};

