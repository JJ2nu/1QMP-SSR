#include "ColliderManager.h"
#include "ColliderComponent.h"
#include "GameObject.h"
#include "Transform.h"
#include "Object.h"
#include <iostream>


ColliderManager::ColliderManager() : m_uCheckArr{} {}
ColliderManager::~ColliderManager() {}

void ColliderManager::Clear()
{
	//m_vColliderArr의 내부 Component는 GameObject가 삭제 해줌
	for (int i = 0; i < (UINT)game::OBJECT_TYPE::END; i++)
	{
		m_vColliderArr[i].clear();
	}
}

void ColliderManager::CollisionCheck(game::OBJECT_TYPE lhs, game::OBJECT_TYPE rhs)
{
	const std::vector<ColliderComponent*>& LGroup = m_vColliderArr[(UINT)lhs];
	const std::vector<ColliderComponent*>& RGroup = m_vColliderArr[(UINT)rhs];


	bool PrevCollision;
	for (UINT i = 0; i < LGroup.size(); i++)
	{
		if (LGroup[i]->GetStatus() != game::Status::Active
			|| LGroup[i]->GetOwner()->GetStatus() != game::Status::Active)
			continue;
		int num = RGroup.size();
		for (UINT j = 0; j < RGroup.size(); j++)
		{
			if (LGroup[i] == RGroup[j] 
				|| RGroup[j]->GetStatus() != game::Status::Active  
				|| RGroup[j]->GetOwner()->GetStatus() != game::Status::Active)
				continue;

			//두 충돌체의 고유한 키값
			ColliderID ID;
			ID.LeftID = LGroup[i]->GetColliderID();
			ID.RightID = RGroup[j]->GetColliderID();


			std::unordered_map<long long, bool>::iterator iter = m_mCollisionInfo.find(ID.ID);
			if (iter == m_mCollisionInfo.end())
			{
				m_mCollisionInfo.insert({ ID.ID, false });
				iter = m_mCollisionInfo.find(ID.ID);
			}

			//현재 충돌 중
			if (IsCollision(LGroup[i], RGroup[j]))
			{
				//이전에도 충돌중이고 지금도 충돌중
				if (iter->second)
				{
					LGroup[i]->OnCollision(RGroup[j]);
					RGroup[j]->OnCollision(LGroup[i]);
				}
				else //이전에는 충돌하지 않았지만 지금은 충돌중 -> 방금 만남
				{
					LGroup[i]->OnCollisionEnter(RGroup[j]);
					RGroup[j]->OnCollisionEnter(LGroup[i]);
					iter->second = true;
				}
			}
			else
			{
				//이전에도 충돌중이지만 지금 충돌X
				if (iter->second)
				{
					LGroup[i]->OnCollisionExit(RGroup[j]);
					RGroup[j]->OnCollisionExit(LGroup[i]);
					iter->second = false;
				}
			}
		}
	}
}


//
	//수정 //이것도 AABB말고 거리 기반으로 바꾸끼 -> 원과 사각형 충동 등 다 가능
//
bool ColliderManager::IsCollision(ColliderComponent* lhs, ColliderComponent* rhs)
{
	Transform LTranform = lhs->m_Transform;
	Transform RTranform = rhs->m_Transform;

	bool A2 = (LTranform.Position.y + LTranform.Scale.y / 2.f) < (RTranform.Position.y - RTranform.Scale.y / 2.f);
	bool A1 = (LTranform.Position.y - LTranform.Scale.y / 2.f) > (RTranform.Position.y + RTranform.Scale.y / 2.f);
	bool B1 = (LTranform.Position.x + LTranform.Scale.x / 2.f) < (RTranform.Position.x - RTranform.Scale.x / 2.f);
	bool B2 = (LTranform.Position.x - LTranform.Scale.x / 2.f) > (RTranform.Position.x + RTranform.Scale.x / 2.f);
	if (A1 || A2 || B1 || B2)
		return false;
	return true;
}

void ColliderManager::Initialize()
{

}

void ColliderManager::FixedUpdate()
{
	for (UINT row = 0; row < (UINT)game::OBJECT_TYPE::END; row++)
	{
		for (UINT col = row; col < (UINT)game::OBJECT_TYPE::END; col++)
		{
			if (m_uCheckArr[row] & (1 << col))
			{
				//작은 숫자의 그룹이 왼쪽으로
				CollisionCheck((game::OBJECT_TYPE)row, (game::OBJECT_TYPE)col);
			}
		}
	}
}

void ColliderManager::AddColliderObject(ColliderComponent* collider, game::OBJECT_TYPE type)
{
	m_vColliderArr[(int)type].push_back(collider);
}


void ColliderManager::CheckGroup(game::OBJECT_TYPE lhs, game::OBJECT_TYPE rhs)
{
	UINT row = (UINT)lhs;
	UINT col = (UINT)rhs;

	if (col < row)
	{
		row = (UINT)rhs;
		col = (UINT)lhs;
	}

	//있으면
	if (m_uCheckArr[row] & (1 << col))
	{
		//뺴기
		m_uCheckArr[row] &= ~(1 << col);
	}
	else
	{
		//채우기
		m_uCheckArr[row] |= (1 << col);
	}
}

void ColliderManager::ResetGroup()
{
	memset(m_uCheckArr, 0, sizeof(UINT) * (UINT)game::OBJECT_TYPE::END);
}

void ColliderManager::Destroy()
{
	for (UINT i = 0; i < (UINT)game::OBJECT_TYPE::END; i++)
	{
		std::vector<ColliderComponent*>::iterator iter = m_vColliderArr->begin();
		while (iter != m_vColliderArr->end())
		{
			if ((*iter)->GetStatus() == game::Status::Destroy)
			{
				iter = m_vColliderArr->erase(iter);
				continue;;
			}
			iter++;
		}
	}
}
