#include "Observer.h"
#include "PlayerGameObject.h"
#include "FadeInFadeOutObject.h"

Observer* Observer::instance = nullptr;

void Observer::SettingPlayerEnhance()
{
	m_Player->myScript->m_bShield = m_sPlayerInfo.m_bShield;
	m_Player->myScript->m_iMaxShield = m_sPlayerInfo.m_iMaxShield;

	m_Player->myScript->m_bInvincibility = m_sPlayerInfo.m_bInvincibility;

	for (int i = 0; i < m_sPlayerInfo.m_fEnhanceDamageRatio; i++)
	{
		m_Player->myScript->m_fEnhanceDamage = m_Player->myScript->m_fEnhanceDamage * 1.5f;
	}

	for (int i = 0; i < m_sPlayerInfo.m_iEnhanceBulletRate; i++)
	{
		m_Player->myScript->m_iEnhanceBulletRate = (float)m_Player->myScript->m_iEnhanceBulletRate / 1.5f;
	}

	m_Player->myScript->m_bPortal = m_sPlayerInfo.m_bPortal;
	if (m_Player->myScript->m_bPortal)
		m_Player->myScript->m_fPortalRange = 80.f;
}

Observer* Observer::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new Observer();
	}
	return instance;
}

void Observer::DestroyInstance()
{
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

Observer::Observer()
	:m_Player(nullptr)
	, m_Boss(nullptr)
{
	m_FadeInFadeOut = new FadeInFadeOutObject();
}

Observer::~Observer()
{
	delete m_FadeInFadeOut;
}
