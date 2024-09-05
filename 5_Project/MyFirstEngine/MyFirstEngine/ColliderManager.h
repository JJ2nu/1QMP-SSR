#pragma once

#include <Windows.h>
#include <vector>
#include <unordered_map>
#include "Define.h"

class Collider;
class ColliderComponent;

class ColliderManager
{
public:
	void AddColliderObject(ColliderComponent* collider, game::OBJECT_TYPE type);
	void CheckGroup(game::OBJECT_TYPE lhs, game::OBJECT_TYPE rhs);
	void ResetGroup();


public:
	void Initialize();
	void FixedUpdate();
	void Destroy();
	void Clear();

public:
	ColliderManager();
	~ColliderManager();

private:
	std::vector<ColliderComponent*>	m_vColliderArr[(UINT)game::OBJECT_TYPE::END];
	UINT					m_uCheckArr[(UINT)game::OBJECT_TYPE::END];
	//이전 프레임의 충돌 정보
	//이것이 있어야지 들어왔는지 충돌중인지 나갔는지 알 수 있다.
	//고유한 아이디를 통해 두개의 조합으로 Hash를 통하여 값을 저장
	//UNION을 통해 아이디 1, 아이디 2를 한개의 변수로 볼 수 있음
	std::unordered_map<long long, bool> m_mCollisionInfo;

	union ColliderID
	{
		struct {
			UINT LeftID;
			UINT RightID;
		};
		LONGLONG ID;
	};

private:
	void CollisionCheck(game::OBJECT_TYPE lhs, game::OBJECT_TYPE rhs);
	bool IsCollision(ColliderComponent* lhs, ColliderComponent* rhs);

};