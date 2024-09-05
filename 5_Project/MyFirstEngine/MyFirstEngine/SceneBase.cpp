#include "SceneBase.h"
#include "Observer.h"
#include "FadeInFadeOutObject.h"
#include "SceneManager.h"


SceneBase::SceneBase(std::string m_ObjName)
	:Object(m_ObjName)
{}

SceneBase::~SceneBase()
{
	//if (m_ColliderManager)
	//{
	//	delete m_ColliderManager;
	//}
	//if (m_ObjectManager)
	//{
	//	delete m_ObjectManager;
	//}
}

void SceneBase::AddCollider(ColliderComponent* collider, game::OBJECT_TYPE type)
{
	m_ColliderManager.AddColliderObject(collider, type);
}

void SceneBase::FixedUpdate(float fixedDeltaTime)
{
	if (Observer::GetInstance()->m_GameFlag != game::SCENE_TYPE::END && Observer::GetInstance()->m_GameFlag != game::SCENE_TYPE::CHANGE_EFFECT)
	{
		FadeInFadeOutObject* tmp = Observer::GetInstance()->m_FadeInFadeOut;
		if(!(tmp->m_Script->m_OnEffect))
			tmp->m_Script->SetSign(false);
		tmp->FixedUpdate(fixedDeltaTime);
		if (!tmp->m_Script->m_OnEffect)
			SceneManager::GetInstance()->ChangeScene(Observer::GetInstance()->m_GameFlag);
	}
	else if (Observer::GetInstance()->m_GameFlag == game::SCENE_TYPE::CHANGE_EFFECT)
	{
		FadeInFadeOutObject* tmp = Observer::GetInstance()->m_FadeInFadeOut;
		if (!(tmp->m_Script->m_OnEffect))
			tmp->m_Script->SetSign(true);
		tmp->FixedUpdate(fixedDeltaTime);
		if (!tmp->m_Script->m_OnEffect)
			Observer::GetInstance()->m_GameFlag = game::SCENE_TYPE::END;
	}
	else
	{
		m_ObjectManager.FixedUpdate(fixedDeltaTime);
		m_ColliderManager.FixedUpdate();
	}
}

void SceneBase::Update(float deltaTime)
{
	if (Observer::GetInstance()->m_GameFlag != game::SCENE_TYPE::END && Observer::GetInstance()->m_GameFlag != game::SCENE_TYPE::CHANGE_EFFECT)
	{}
	else if (Observer::GetInstance()->m_GameFlag == game::SCENE_TYPE::CHANGE_EFFECT)
	{}
	else
	{
		m_ObjectManager.Update(deltaTime);
	}
}

void SceneBase::Render()
{
	m_ObjectManager.Render();
	if (Observer::GetInstance()->m_GameFlag != game::SCENE_TYPE::END && Observer::GetInstance()->m_GameFlag != game::SCENE_TYPE::CHANGE_EFFECT)
	{
		FadeInFadeOutObject* tmp = Observer::GetInstance()->m_FadeInFadeOut;
		tmp->Render();
	
	}
	else if (Observer::GetInstance()->m_GameFlag == game::SCENE_TYPE::CHANGE_EFFECT)
	{
		FadeInFadeOutObject* tmp = Observer::GetInstance()->m_FadeInFadeOut;
		tmp->Render();
	}
}

void SceneBase::Destroy()
{
	m_ColliderManager.Destroy();
	m_ObjectManager.Destroy();
}

void SceneBase::Clear()
{
	m_ColliderManager.Clear();
	m_ObjectManager.Clear();
}

void SceneBase::AddObject(GameObject* obj, game::OBJECT_TYPE type)
{
	m_ObjectManager.AddObject(obj, type);
}

void SceneBase::EraseObject(game::OBJECT_TYPE type, std::string ObjName)
{
	m_ObjectManager.EraseObject(type, ObjName);
}
