#include "Resource.h"

Resource::Resource() {}

Resource::~Resource() {}

void Resource::SetKey(std::wstring& _resKey)
{
	m_sResKey = _resKey;
}

void Resource::SetPath(std::wstring& _resPath)
{
	m_sResPath = _resPath;
}

std::wstring Resource::GetKey()
{
	return m_sResKey;
}

std::wstring Resource::GetPath()
{
	return m_sResPath;
}