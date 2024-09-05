#pragma once
#include "Object.h"
#include "ColliderComponent.h"

#include <vector>

class Component;
class SceneBase;

class GameObject : public Object, public ICollider
{
public:
	template<typename T>
	T* CreateComponent(const std::string& Name)
	{
		bool b_IsBase = std::is_base_of<Component, T>::value;
		assert(b_IsBase == true);
		T* p_Component = new T(this, Name);
		m_vComponentList.push_back(p_Component);
		return p_Component;
	}

	Component* GetComponent(const std::string& ComponentType);
	template<typename T>
	T* GetComponent()
	{
		for (auto& p_Component : m_vComponentList)
		{
			T* p_CastComponent = dynamic_cast<T*>(p_Component);
			if (p_CastComponent)
			{
				return p_CastComponent;
			}
		}
		return nullptr;
	}

	void AddChildGameObject(GameObject* _GameObject);
	
	void SetTransform(Transform Transform) { m_Transform = Transform; }
	Transform GetTransform() { return m_Transform; }

	//void SetSceneBase(SceneBase* Scene) { m_pScene = Scene; }
	SceneBase* GetSceneBase() { return m_pScene; }

public:
	Transform m_Transform;

protected:
	std::vector<Component*> m_vComponentList;
	std::vector<GameObject*> m_vChildGameObject;
	SceneBase* m_pScene;

public:
	// Object을(를) 통해 상속됨
	virtual void FixedUpdate(float fixedDeltaTime);
	virtual void Update(float deltaTime);
	virtual void Render();

	// ICollider을(를) 통해 상속됨
	virtual void OnCollision(ColliderComponent* src);
	virtual void OnCollisionEnter(ColliderComponent* src);
	virtual void OnCollisionExit(ColliderComponent* src);

public:
	GameObject(std::string ObjName, SceneBase* Scene);
	virtual ~GameObject();

};

