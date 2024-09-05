//#include "EventManager.h"
//EventManager* EventManager::instance = nullptr;
//
//EventManager* EventManager::GetInstance()
//{
//	if (instance == nullptr)
//	{
//		instance = new EventManager();
//	}
//	return instance;
//}
//
//void EventManager::DestroyInstance()
//{
//	if (instance != nullptr)
//	{
//		delete instance;
//		instance = nullptr;
//	}
//}
//
//void EventManager::AddEventListener(Event* target, IEventListener* listener)
//{
//	//m_eventListeners.find(target->m_eType).push_back(listener);
//
//}
//
//void EventManager::RemoveEventListener(Event* target, IEventListener* listener)
//{
//	//m_eventListeners.find(target->m_eType).erase(listener);
//}
//
////game::OBJECT_TYPE EventManager::GetEventType(Event* event)
////{
////	return event->m_eType;
////}
//
//Event* EventManager::getEventType(Event* event)
//{
//	return nullptr;
//}
//
//void EventManager::logEvent(Event* event)
//{
//
//}
