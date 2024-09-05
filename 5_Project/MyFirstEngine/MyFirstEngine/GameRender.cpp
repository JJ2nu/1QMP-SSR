#include "GameRender.h"
#include "WinApp.h"
#include <string>

#include "GameRender.h"
#include "AnimationResource.h"
#include "Texture.h"
#include "Transform.h"
#pragma comment(lib, "msimg32.lib")

GameRender* GameRender::instance = nullptr;

GameRender* GameRender::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new GameRender();
    }
    return instance;
}

void GameRender::DestroyInstance()
{
    if (instance != nullptr)
    {
        delete instance;
        instance = nullptr;
    }
}
SIZE GameRender::GetScreenSize()
{
    SIZE size;
    size.cx = nScreenWidth;
    size.cy = nScreenHeight;

    return size;
}
GameRender::GameRender() : hConsoleHandle(0), hScreenBuffer{} {}

GameRender::~GameRender() {}

HDC& GameRender::GetHDC()
{
    return backMemDC;
}

void GameRender::InitRender()
{
    hWnd = global::GetWinApp().GetWindow();

    frontMemDC = GetDC(hWnd);
    backMemDC = CreateCompatibleDC(frontMemDC);
    backBitmap = CreateCompatibleBitmap(frontMemDC, global::GetWinApp().GetWidth(), global::GetWinApp().GetHeight());
    
    // GDI+ 초기화
    ::SelectObject(backMemDC, backBitmap);
    Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    graphics = Gdiplus::Graphics::FromHDC(backMemDC);
    graphics->SetSmoothingMode(Gdiplus::SmoothingModeNone);
    graphics->SetPixelOffsetMode(Gdiplus::PixelOffsetModeNone);
    graphics->SetInterpolationMode(Gdiplus::InterpolationModeNearestNeighbor);
}

void GameRender::ClearScreen()
{
    ::PatBlt(backMemDC, 0, 0, global::GetWinApp().GetWidth(), global::GetWinApp().GetHeight(), WHITENESS);
}

void GameRender::BeginDraw()
{
    ClearScreen();

    ::SelectObject(backMemDC, backBitmap);
}

void GameRender::EndDraw()
{
    ::BitBlt(frontMemDC, 0, 0, global::GetWinApp().GetWidth(), global::GetWinApp().GetHeight(), backMemDC, 0, 0, SRCCOPY);
}

void GameRender::ReleaseRender()
{
    Gdiplus::GdiplusShutdown(gdiplusToken);
    DeleteObject(backBitmap);
    DeleteDC(backMemDC);
    ReleaseDC(hWnd, frontMemDC);
}

void GameRender::DrawAnimationResource(AnimationResource* m_pAnimationResource, int m_AnimationMotionIndex, int m_AnimationFrameIndex, float m_AnimationAccTime, bool m_AnimationFlip, float PosX, float PosY, UINT except, float Rotation)
{
    if (m_pAnimationResource && m_AnimationMotionIndex != -1)
    {
        auto& frame = m_pAnimationResource->m_motions[m_AnimationMotionIndex].Frames[m_AnimationFrameIndex];
        auto* bitmap = m_AnimationFlip ? m_pAnimationResource->m_bitmapFlip : m_pAnimationResource->m_bitmap;
        SIZE size = GetScreenSize();

        //int x = m_AnimationFlip ? (int)PosX - (frame.Size.cx - frame.CenterX) : (int)PosX - frame.CenterX;
        int x = m_AnimationFlip ? (int)PosX - (frame.CenterX)/2 : (int)PosX - frame.CenterX/2;
        int y = (int)PosY - frame.CenterY/2;
        int srcX = m_AnimationFlip ? m_pAnimationResource->m_bitmapFlip->GetWidth() - frame.Size.cx - frame.Source.left : frame.Source.left;
        int srcY = frame.Source.top;
        DrawImage(x, y, bitmap, srcX, srcY, frame.Size.cx, frame.Size.cy, except, Rotation);
    }
}

void GameRender::DrawFadeInFadeOut(Gdiplus::Image* m_Bitmap, int width, int height, int x, int y, bool to, float alpha)
{
    static Gdiplus::Graphics g(backMemDC); // Graphics 객체를 정적으로 생성하여 재사용
    Gdiplus::Color _alpha_Color(0, 0, 0, 0);
    static Gdiplus::ImageAttributes imgAtt; // ImageAttributes 객체를 정적으로 생성하여 재사용
    Gdiplus::ColorMatrix colorMatrix = {
        1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, alpha, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f, 1.0f
    };
    g.SetSmoothingMode(Gdiplus::SmoothingModeNone);
    g.SetPixelOffsetMode(Gdiplus::PixelOffsetModeNone);
    g.SetInterpolationMode(Gdiplus::InterpolationModeNearestNeighbor);
    imgAtt.SetColorMatrix(&colorMatrix, Gdiplus::ColorMatrixFlagsDefault, Gdiplus::ColorAdjustTypeBitmap);
    imgAtt.SetColorKey(_alpha_Color, _alpha_Color);
    Gdiplus::Rect destRect(x, y, width, height);
    g.DrawImage(m_Bitmap, destRect, 0, 0, m_Bitmap->GetWidth(), m_Bitmap->GetHeight(), Gdiplus::UnitPixel, &imgAtt);
}

void GameRender::DrawTexture(Texture* hdcSrc, Transform transformSrc, UINT excep, int flag, UINT alpha)
{
    int texWid = (int)(hdcSrc->Width());
    int texHei = (int)(hdcSrc->Height());

    Vector3 pos = transformSrc.GetPosition();

    if (flag == 0)
    {
        TransparentBlt(backMemDC
            , pos.x - (float)(texWid / 2)
            , pos.y - (float)(texHei / 2)
            , (texWid * transformSrc.Scale.x) - hdcSrc->CutWidth(), (texHei * transformSrc.Scale.y) - hdcSrc->CutHeight()
            , hdcSrc->GetDC()
            , 0, 0, texWid - hdcSrc->CutWidth(), texHei - hdcSrc->CutHeight()
            , excep);
    }
    else if (flag == 1)
    {
        BitBlt(backMemDC
            , pos.x - (float)(texWid / 2)
            , pos.y - (float)(texHei / 2)
            , texWid, texHei
            , hdcSrc->GetDC()
            , 0, 0, SRCCOPY
            );
    }
    else if (flag == 2)
    {
        HDC AlphaDc = CreateCompatibleDC(backMemDC);
        HBITMAP AlphaHBITMAP = CreateCompatibleBitmap(backMemDC, ScreenWidth, ScreenHeight);

        HBITMAP preBit = (HBITMAP)SelectObject(AlphaDc, AlphaHBITMAP);
        DeleteObject(preBit);

        BitBlt(AlphaDc
            , 0, 0
            , texWid * transformSrc.Scale.y, texHei * transformSrc.Scale.y
            , backMemDC
            , (int)pos.x - (int)((float)texWid / 2)
            , (int)pos.y - (int)((float)texHei / 2), SRCCOPY);

        TransparentBlt(AlphaDc
            , 0
            , 0
            , texWid, texHei
            , hdcSrc->GetDC()
            , 0, 0, texWid, texHei
            , excep);


        BLENDFUNCTION bf;
        bf.BlendOp = AC_SRC_OVER;
        bf.BlendFlags = 0;
        bf.SourceConstantAlpha = alpha;
        bf.AlphaFormat = 0;
        AlphaBlend(backMemDC
            , pos.x - (float)(texWid / 2)
            , pos.y - (float)(texHei / 2)
            , texWid, texHei
            , AlphaDc
            , 0, 0, texWid, texHei
            , bf);

        DeleteDC(AlphaDc);
        DeleteObject(AlphaHBITMAP);
    }
}

void GameRender::DrawFPS(int& updateCount, float deltaTime)
{
    static float elapsedTime;
    static int ShowFPS;

    elapsedTime += deltaTime;
    while (elapsedTime >= 1.0f)
    {
        elapsedTime -= 1.0f;
        ShowFPS = updateCount;
        updateCount = 0;
    }
    std::string tmp = std::to_string(ShowFPS);
    std::string str = "FPS: " + tmp; 

    DrawText(10, 10, str.c_str(), RGB(255, 0, 0), L"궁서체", 20); 
}

void GameRender::DrawLine(int x1, int y1, int x2, int y2, COLORREF color)
{
    HPEN hPen = CreatePen(PS_SOLID, 5, color);

    HPEN hOldPen = (HPEN)SelectObject(backMemDC, hPen);

    MoveToEx(backMemDC, x1, y1, NULL);

    LineTo(backMemDC, x2, y2);

    SelectObject(backMemDC, hOldPen);

    DeleteObject(hPen);
}


void GameRender::DrawRect(int x, int y, int width, int height, COLORREF color)
{
    HPEN hPen = CreatePen(PS_SOLID, 1, color);

    HPEN hOldPen = (HPEN)SelectObject(backMemDC, hPen);

    HBRUSH hBrush = CreateSolidBrush(color);

    HBRUSH hOldBrush = (HBRUSH)SelectObject(backMemDC, hBrush);

    Rectangle(backMemDC, x, y, x + width, y + height);

    SelectObject(backMemDC, hOldPen);
    SelectObject(backMemDC, hOldBrush);

    DeleteObject(hPen);
    DeleteObject(hBrush);
}

void GameRender::DrawRectLine(int x, int y, int width, int height, COLORREF color)
{
    HPEN hPen = CreatePen(PS_SOLID, 1, color);

    HPEN hOldPen = (HPEN)SelectObject(backMemDC, hPen);

    HBRUSH hBrush = (HBRUSH)GetStockObject(HOLLOW_BRUSH);

    HBRUSH hOldBrush = (HBRUSH)SelectObject(backMemDC, hBrush);

    Rectangle(backMemDC, x, y, x + width, y + height);

    SelectObject(backMemDC, hOldPen);
    SelectObject(backMemDC, hOldBrush);

    DeleteObject(hPen);
    DeleteObject(hBrush);
}


void GameRender::DrawCircle(int x, int y, int radius, COLORREF color)
{
    HPEN hPen = CreatePen(PS_SOLID, 1, color);

    HPEN hOldPen = (HPEN)SelectObject(backMemDC, hPen);

    HBRUSH hBrush = CreateSolidBrush(color);

    HBRUSH hOldBrush = (HBRUSH)SelectObject(backMemDC, hBrush);

    Ellipse(backMemDC, x - radius, y - radius, x + radius, y + radius);

    SelectObject(backMemDC, hOldPen);
    SelectObject(backMemDC, hOldBrush);

    DeleteObject(hPen);
    DeleteObject(hBrush);

}

void GameRender::DrawPolygon(POINT points[], int count, COLORREF color)
{
    HPEN hPen = CreatePen(PS_SOLID, 1, color);

    HPEN hOldPen = (HPEN)SelectObject(backMemDC, hPen);

    HBRUSH hBrush = CreateSolidBrush(color);

    HBRUSH hOldBrush = (HBRUSH)SelectObject(backMemDC, hBrush);

    Polygon(backMemDC, points, count);

    SelectObject(backMemDC, hOldPen);
    SelectObject(backMemDC, hOldBrush);

    DeleteObject(hPen);
    DeleteObject(hBrush);

}

void GameRender::DrawImage(int x, int y, Gdiplus::Bitmap* bitmap, int srcX, int srcY, int srcWitdh, int srcHeight, UINT except, int Rotation)
{
    if (bitmap == nullptr)
        return;
    Gdiplus::Color _alpha_Color = except;
    Gdiplus::ImageAttributes imgAtt = {};
    imgAtt.SetColorKey(_alpha_Color, _alpha_Color);\
    Gdiplus::Matrix mat;
    mat.RotateAt(Rotation, Gdiplus::PointF((float)x + srcWitdh / 2.f, (float)y + srcHeight / 2.f));
    graphics->SetTransform(&mat);
    Gdiplus::Rect srcRect(srcX, srcY, srcWitdh, srcHeight); // 소스의 영역
    Gdiplus::Rect destRect(x, y, srcRect.Width, srcRect.Height); // 화면에 그릴 영역		
    // 이미지 그리기

    graphics->DrawImage(bitmap, destRect, srcRect.X, srcRect.Y, srcRect.Width, srcRect.Height, Gdiplus::UnitPixel, &imgAtt);
}

void GameRender::DrawText(int x, int y, const char* text, COLORREF color)
{
    SetTextColor(backMemDC, color);

    TextOutA(backMemDC, x, y, text, strlen(text));
}

void GameRender::DrawText(int x, int y,
    const char* text, COLORREF color,
    const wchar_t* fontName, int fontSize, RECT& rect)
{
    AddFontResource(fontName);
    HFONT hFont = CreateFont(fontSize, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("사월십육일 TTF 약속"));

    HFONT hOldFont = (HFONT)SelectObject(backMemDC, hFont);
    SetTextColor(backMemDC, color);
    SetBkMode(backMemDC, TRANSPARENT);//배경색 투영하기.

    // DrawTextA를 사용하여 텍스트를 출력
    DrawTextA(backMemDC, text, -1, &rect, DT_LEFT | DT_WORDBREAK);

    SelectObject(backMemDC, hFont);
    DeleteObject(hFont);
}
void GameRender::DrawText(int x, int y,
    const char* text, COLORREF color,
    const wchar_t* fontName, int fontSize)
{
    HFONT hFont = CreateFontW(fontSize, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,

        CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, fontName);

    HFONT hOldFont = (HFONT)SelectObject(backMemDC, hFont);
    SetTextColor(backMemDC, color);
    SetBkMode(backMemDC, TRANSPARENT);//배경색 투영하기.

    TextOutA(backMemDC, x, y, text, strlen(text));


    SelectObject(backMemDC, hFont);
    DeleteObject(hFont);
}

