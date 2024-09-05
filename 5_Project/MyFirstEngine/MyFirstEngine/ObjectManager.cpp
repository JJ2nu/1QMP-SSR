#include "ObjectManager.h"

//
//ObjectManager* ObjectManager::instance = nullptr;
//
//ObjectManager* ObjectManager::GetInstance()
//{
//	if (instance == nullptr)
//	{
//		instance = new ObjectManager();
//	}
//	return instance;
//}
//
//void ObjectManager::DestroyInstance()
//{
//	if (instance != nullptr)
//	{
//		delete instance;
//		instance = nullptr;
//	}
//}

void ObjectManager::Initialize()
{

}

void ObjectManager::Update(float deltaTime)
{
	for (size_t i = (UINT)game::OBJECT_TYPE::DEFAULT; i != (UINT)game::OBJECT_TYPE::END; i++)
	{
		for (auto iter : m_ObjectList[i])
		{
			if ((*iter).GetStatus() == game::Status::InActive)
				continue;
			(*iter).Update(deltaTime);
		}
	}
}

void ObjectManager::FixedUpdate(float fixedDeltaTime)
{
	for (size_t i = (UINT)game::OBJECT_TYPE::DEFAULT; i != (UINT)game::OBJECT_TYPE::END; i++)
	{
		for (auto iter : m_ObjectList[i])
		{
			if ((*iter).GetStatus() == game::Status::InActive)
				continue;
			(*iter).FixedUpdate(fixedDeltaTime);
		}
	}
}

void ObjectManager::Render()
{
	for (size_t i = (UINT)game::OBJECT_TYPE::DEFAULT; i != (UINT)game::OBJECT_TYPE::END; i++)
	{
		for (auto iter : m_ObjectList[i])
		{
			if ((*iter).GetStatus() == game::Status::InActive)
				continue;
			(*iter).Render();
		}
	}
}

void ObjectManager::Destroy()
{
}
void ObjectManager::Finalize()
{

}
void ObjectManager::Clear()
{
	for (int i = 0; i < (UINT)game::OBJECT_TYPE::END; ++i) {
		for (auto obj : m_ObjectList[i]) {
			delete obj;
		}
		m_ObjectList[i].clear();
	}
}

void ObjectManager::AddObject(GameObject* obj, game::OBJECT_TYPE type)
{
	m_ObjectList[(UINT)type].push_back(obj);
}

void ObjectManager::EraseObject(game::OBJECT_TYPE type, std::string ObjName)
{

	for (auto dead = m_ObjectList[(UINT)type].begin(); dead != m_ObjectList[(UINT)type].end();)
	{
		if ((*dead)->GetObjName().compare(ObjName)==0)
		{
			(*dead)->SetStatus(game::Status::Destroy);
		}

	}
}

GameObject* ObjectManager::FindObejectByName(const std::string _name)
{
	for (size_t i = (UINT)game::OBJECT_TYPE::DEFAULT; i != (UINT)game::OBJECT_TYPE::END; i++)
	{
		for (GameObject* iter : m_ObjectList[i])
		{
			if (iter->GetObjName() == _name)
				return iter;
		}
	}
	return nullptr;
}

GameObject* ObjectManager::FindObejectByName(game::OBJECT_TYPE _type, const std::string _name)
{
	for (GameObject* iter : m_ObjectList[(UINT)_type])
	{
		if (iter->GetObjName() == _name)
			return iter;
	}
	return nullptr;
}

