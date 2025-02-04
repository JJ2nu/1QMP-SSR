#include "AnimationResource.h"

#include <iostream>
#include <fstream>
#include <sstream>

AnimationResource::~AnimationResource()
{
	if (m_bitmap)
		delete m_bitmap;

	if (m_bitmapFlip)
		delete m_bitmapFlip;
}

void AnimationResource::LoadAnimImage(const WCHAR* fileName)
{
	m_bitmap = Gdiplus::Bitmap::FromFile(fileName);
	m_bitmapFlip = Gdiplus::Bitmap::FromFile(fileName);
	m_bitmapFlip->RotateFlip(Gdiplus::Rotate180FlipY); // 하나는 좌우 반전 이미지.
}

void AnimationResource::LoadAnimMotion(const WCHAR* fileName, bool IsLoop)
{
	std::wifstream file(fileName);
	if (!file.is_open()) {
		std::cout << "파일을 열 수 없습니다." << std::endl;
	}
	std::wstring line;			// 한줄의 문자열	
	Motion motion;
	{
		getline(file, line);		// 첫번째 줄 읽기
		std::wstringstream wss(line);
		wss >> motion.FrameCount;
	}

	for (int j = 0; j < motion.FrameCount; j++)
	{
		getline(file, line);		// 한줄 읽기
		std::wstringstream wss(line);    // 한줄을 읽어서 wstringstream에 저장
		std::wstring token;
		{
			getline(wss, token, L',');	// wss의 내용을 ,를 기준으로 문자열을 분리
			motion.Frames[j].Source.left = _wtoi(token.c_str());
			getline(wss, token, L',');
			motion.Frames[j].Source.top = _wtoi(token.c_str());
			getline(wss, token, L',');
			motion.Frames[j].Source.right = _wtoi(token.c_str());
			getline(wss, token, L',');
			motion.Frames[j].Source.bottom = _wtoi(token.c_str());
			getline(wss, token, L',');
			motion.Frames[j].CenterX = _wtoi(token.c_str());
			getline(wss, token, L',');
			motion.Frames[j].CenterY = _wtoi(token.c_str());

			motion.Frames[j].Size.cx = motion.Frames[j].Source.right - motion.Frames[j].Source.left + 1;
			motion.Frames[j].Size.cy = motion.Frames[j].Source.bottom - motion.Frames[j].Source.top + 1;
		}
	}
	motion.IsLoop = IsLoop;

	m_motions[m_motionCount] = motion;
	m_motionCount++;
}
