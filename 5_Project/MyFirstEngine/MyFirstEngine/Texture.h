#pragma once
#include <Windows.h>
#include "Resource.h"
#include "Vector3.h"

class Texture :
	public Resource
{
private:
	HDC		m_hDc;
	HBITMAP m_hBit;
	BITMAP	m_tBitInfo;
	Vector3 m_vCutOffsset;

	//텍스쳐는 오로지 recourceManage에서만 관리 가능하도록
private:
	Texture();
	~Texture();

public:
	void Load(std::wstring& _FilePath);
	UINT Width();
	UINT Height();
	UINT CutWidth();
	UINT CutHeight();
	void SetCutOffset(Vector3 cutOffset);
	void SetCutOffset(int x, int y, int z);

	HDC GetDC();

	//텍스쳐는 오로지 recourceManage에서만 관리 가능하도록
	friend class ResourceManager;
};

