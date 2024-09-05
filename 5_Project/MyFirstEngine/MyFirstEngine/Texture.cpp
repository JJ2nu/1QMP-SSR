#include "Texture.h"
#include "GameRender.h"
#include <cassert>

Texture::Texture() : m_hDc(NULL), m_hBit(NULL), m_tBitInfo{}, m_vCutOffsset{}  {}
Texture::~Texture()
{
	DeleteDC(m_hDc);
	DeleteObject(m_hBit);
}

void Texture::Load(std::wstring& _FilePath)
{
	//https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-loadimagea
	//WIn 제공 함수 관련 내용
	// LPCTSTR = const char *
	m_hBit = (HBITMAP)LoadImage(nullptr, _FilePath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	assert(m_hBit);

	m_hDc = CreateCompatibleDC(GameRender::GetInstance()->GetHDC());

	//??
	HBITMAP preBit = (HBITMAP)SelectObject(m_hDc, m_hBit);
	DeleteObject(preBit);

	//비트맵 정보
	GetObject(m_hBit, sizeof(BITMAP), &m_tBitInfo);

}
UINT Texture::Width()
{
	return m_tBitInfo.bmWidth;
}
UINT Texture::Height()
{
	return m_tBitInfo.bmHeight;
}
UINT Texture::CutWidth()
{
	return m_vCutOffsset.x;
}
UINT Texture::CutHeight()
{
	return m_vCutOffsset.y;
}
void Texture::SetCutOffset(Vector3 cutOffset)
{
	m_vCutOffsset = cutOffset;
}
void Texture::SetCutOffset(int x, int y, int z)
{
	m_vCutOffsset.x = x;
	m_vCutOffsset.y = y;
	m_vCutOffsset.z = z;
}
HDC Texture::GetDC()
{
	return m_hDc;
}
