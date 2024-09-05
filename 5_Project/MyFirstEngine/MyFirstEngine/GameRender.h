#pragma once
#include <Windows.h>
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")
#include <ole2.h>

// Foreground
#define FG_BLACK		0
//FG_BLACK 강조는 없음

#define FG_RED			FOREGROUND_RED|FOREGROUND_INTENSITY
#define FG_GREEN		FOREGROUND_GREEN|FOREGROUND_INTENSITY
#define FG_BLUE			FOREGROUND_BLUE|FOREGROUND_INTENSITY

#define FG_RED_DARK		FOREGROUND_RED
#define FG_GREEN_DARK	FOREGROUND_GREEN 
#define FG_BLUE_DARK	FOREGROUND_BLUE

#define FG_YELLOW		FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY
#define FG_SKY			FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY
#define FG_PINK			FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY

#define FG_YELLOW_DARK	FOREGROUND_RED|FOREGROUND_GREEN
#define FG_SKY_DARK		FOREGROUND_GREEN|FOREGROUND_BLUE
#define FG_PINK_DARK	FOREGROUND_RED|FOREGROUND_BLUE

#define FG_GRAY			FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE
#define FG_WHITE		FG_GRAY|FOREGROUND_INTENSITY

// Background
#define BG_BLACK		0
//FG_BLACK 강조는 없음

#define BG_RED			BACKGROUND_RED|BACKGROUND_INTENSITY
#define BG_GREEN		BACKGROUND_GREEN|BACKGROUND_INTENSITY
#define BG_BLUE			BACKGROUND_BLUE|BACKGROUND_INTENSITY

#define BG_RED_DARK		BACKGROUND_RED
#define BG_GREEN_DARK	BACKGROUND_GREEN
#define BG_BLUE_DARK	BACKGROUND_BLUE

#define BG_YELLOW		BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_INTENSITY
#define BG_SKY			BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_INTENSITY
#define BG_PINK			BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_INTENSITY

#define BG_YELLOW_DARK	BACKGROUND_RED|BACKGROUND_GREEN
#define BG_SKY_DARK		BACKGROUND_GREEN|BACKGROUND_BLUE
#define BG_PINK_DARK	BACKGROUND_RED|BACKGROUND_BLUE

#define BG_GRAY			BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE
#define BG_WHITE		BG_GRAY|BACKGROUND_INTENSITY

class Transform;
class Texture;
class AnimationResource;

class GameRender
{
private:
	static GameRender* instance;

public:
	HDC& GetHDC();

	void InitRender();
	void ClearScreen();
	void BeginDraw();
	void EndDraw();
	void ReleaseRender();

	//Animation Draw
	void DrawAnimationResource(AnimationResource* m_pAnimationResource,
		int m_AnimationMotionIndex,
		int m_AnimationFrameIndex,
		float m_AnimationAccTime,
		bool m_AnimationFlip,
		float PosX, float PosY,
		UINT except, float Rotation = 0);
	void DrawFadeInFadeOut(Gdiplus::Image* m_Bitmap, int width, int height, int x, int y, bool to, float alpha);


	//BitMap Draw
	//flag 0: TransparentBlt, 1: BitBlt, 2: AlphaBlend
	void DrawTexture(Texture* hdcSrc, Transform transformSrc, UINT excep, int flag = 0, UINT alpha = 0);

	//Text Draw
	void DrawText(int x, int y, const char* text, COLORREF color);
	void DrawText(int x, int y, const char* text, COLORREF color, const wchar_t* fontName, int fontSize);
	void DrawText(int x, int y, const char* text, COLORREF color, const wchar_t* fontName, int fontSize, RECT& rect);
	
	//Simple Draw
	void DrawFPS(int& updateCount, float deltaTime);
	void DrawLine(int x1, int y1, int x2, int y2, COLORREF color);
	void DrawRect(int x, int y, int width, int height, COLORREF color);
	void DrawRectLine(int x, int y, int width, int height, COLORREF color);
	void DrawCircle(int x, int y, int radius, COLORREF color);
	void DrawPolygon(POINT points[], int count, COLORREF color);
	void DrawImage(int x, int y, Gdiplus::Bitmap* bitmap, int srcX, int srcY, int srcWitdh, int srcHeight, UINT except, int Rotaiton);

private:
	HWND hWnd;

	HDC frontMemDC;    // 앞면 DC
	HDC backMemDC;    // 뒷면 DC

	HBITMAP backBitmap = nullptr;


	HANDLE	hConsoleHandle;
	HANDLE	hScreenBuffer[2];
	int		nScreenWidth = 0;
	int		nScreenHeight = 0;
	int		nScreenBufferSize = 0;
	int		nScreenBufferIndex = 0;

	//GDIPlus
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	Gdiplus::Graphics* graphics = nullptr;

public:
	static GameRender* GetInstance();
	static void DestroyInstance();

	SIZE GetScreenSize();

private:
	GameRender();
	~GameRender();
};


