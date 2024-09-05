#pragma once
#include "Component.h"

class ColliderComponent;

class ICollider
{
	virtual void OnCollision(ColliderComponent* src) = 0;
	virtual void OnCollisionEnter(ColliderComponent* src) = 0;
	virtual void OnCollisionExit(ColliderComponent* src) = 0;
};

class ColliderComponent : public Component, ICollider
{
private:
	static UINT s_uStaticID;

public:
	// ICollider을(를) 통해 상속됨
	void OnCollision(ColliderComponent* src) override;
	void OnCollisionEnter(ColliderComponent* src) override;
	void OnCollisionExit(ColliderComponent* src) override;

	// Component을(를) 통해 상속됨
	void FixedUpdate(float fixedDeltaTime) override;
	void Update(float deltaTime) override;
	void Render() override;

	//Get & Set
	UINT GetColliderID() { return m_uCollisionID; }
	// 동민이가 작업하다 못한 부분
	GameObject* GetOwner() const;

public:
	Transform m_Transform;

private:
	UINT	m_uCollisionID;
	UINT	m_uCollisionCount;
	COLORREF	m_RenderColor;

public:
	ColliderComponent(GameObject* pOwner, std::string ObjName);
	~ColliderComponent();

};

