#pragma once
#include <iostream>

class Resource
{
private:
	std::wstring	m_sResKey;
	std::wstring	m_sResPath;

public:
	Resource();
	~Resource();

	void SetKey(std::wstring& _resKey);
	void SetPath(std::wstring& _resPath);

	std::wstring GetKey();
	std::wstring GetPath();
};

