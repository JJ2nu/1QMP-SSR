#include <cstdlib>
#include <ctime>
#include "WinApp.h"
#include "GameManager.h"

namespace global
{
	WinApp winApp;

	const WinApp& GetWinApp()
	{
		return winApp;
	}
}

constexpr int SCREEN_START_LEFT = 0;

constexpr int SCREEN_START_TOP = 0;

constexpr int SCREEN_WIDTH = ScreenWidth;

constexpr int SCREEN_HEIGHT = ScreenHeight;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow){
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	global::winApp.Initialize(hInstance);

	global::winApp.Run();

	global::winApp.Finalize();

	return EXIT_SUCCESS;
}

void PlaceInCenterOfScreen(HWND window, DWORD style, DWORD exStyle)
{
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	RECT clientRect;
	GetClientRect(window, &clientRect);

	int clientWidth = clientRect.right - clientRect.left;
	int clientHeight = clientRect.bottom - clientRect.top;

	SetWindowPos(window, NULL,
		screenWidth / 2 - clientWidth / 2,
		screenHeight / 2 - clientHeight / 2,
		clientWidth, clientHeight, 0
	);
}

LRESULT CALLBACK WinApp::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
	{
		PlaceInCenterOfScreen(hWnd, WS_OVERLAPPEDWINDOW, WS_EX_APPWINDOW | WS_EX_WINDOWEDGE);
	}
	break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

void WinApp::Initialize(HINSTANCE hInstance)
{
	m_hInstance = hInstance;

	const TCHAR* appName = TEXT("Engine");

	//Step 1: Registering the Window Class

	WNDCLASS wndClass;

	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = WndProc;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = hInstance;
	wndClass.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	ShowCursor(false);
	wndClass.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = appName;

	RegisterClass(&wndClass);

	// Step 2: Creating the Window

	RECT rect{ SCREEN_START_LEFT, SCREEN_START_TOP,
	SCREEN_START_LEFT + SCREEN_WIDTH, SCREEN_START_TOP + SCREEN_HEIGHT };

	::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;
	//WS_OVERLAPPED
	//WS_POPUP
	m_hWnd = CreateWindow(appName, appName, WS_POPUP | WS_SYSMENU,
		SCREEN_START_LEFT, SCREEN_START_TOP, width, height, NULL, NULL, hInstance, NULL);
	//SW_SHOWNORMAL
	//SW_MAXIMIZE
	ShowWindow(m_hWnd, SW_MAXIMIZE);
	UpdateWindow(m_hWnd);

	// Step 3: Game Initialize Here
	GameManager::GetInstance()->Initialize();
}

void WinApp::Run()
{
	// Step 4: Game Loop Here
	GameManager::GetInstance()->Run();
}

void WinApp::Finalize()
{
	// Step 5: Game Finalize Here
	GameManager::GetInstance()->Finalize();
	GameManager::GetInstance()->DestroyInstance();
}
