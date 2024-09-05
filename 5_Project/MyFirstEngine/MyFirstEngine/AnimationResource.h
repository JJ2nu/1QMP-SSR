#pragma once
#include "Resource.h"
#include <Windows.h>
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")
#include <ole2.h>


struct Frame
{
	RECT Source = { 0, };			// 부분출력할 이미지 영역
	SIZE Size = { 0, };			// 출력 크기
	int CenterX = 0, CenterY = 0;	// 중심이 되는 이동 위치 
};

struct Motion
{
	Frame Frames[20];		// 프레임 컨테이너
	int FrameCount = 0;			// 전체 프레임 수
	bool IsLoop = false;	// 반복 여부
};

class AnimationResource :
    public Resource
{
public: 
	void LoadAnimImage(const WCHAR* fileName);
	void LoadAnimMotion(const WCHAR* fileName, bool IsLoop = true);


public:
	Gdiplus::Bitmap* m_bitmap = nullptr;		// Origin Image
	Gdiplus::Bitmap* m_bitmapFlip = nullptr;	// Flip Image
	Motion m_motions[10];	// 최대 10개의 동작을 가질 수 있음
	int m_motionCount = 0;	// 현재 동작의 개수

private:
	AnimationResource() = default;
	~AnimationResource();	// GDI+가 파괴되기전에 비트맵 메모리 해제해야한다.

public:
	friend class ResourceManager;
};
