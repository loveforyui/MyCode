// Metaltest.cpp: 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Metaltest.h"
#include "MainManager.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE   hInst;                                // 현재 인스턴스입니다.
WCHAR       szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR       szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
HWND        g_hWnd;

// 이 코드 모듈에 들어 있는 함수의 정방향 선언입니다.
ATOM                MyRegisterClass (HINSTANCE hInstance);
BOOL                InitInstance    (HINSTANCE, int);
LRESULT CALLBACK    WndProc         (HWND, UINT, WPARAM, LPARAM);

int     APIENTRY    wWinMain        (   _In_        HINSTANCE hInstance,
                                        _In_opt_    HINSTANCE hPrevInstance,
                                        _In_        LPWSTR    lpCmdLine,
                                        _In_        int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW             (hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW             (hInstance, IDC_METALTEST, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass         (hInstance);

    // 응용 프로그램 초기화를 수행합니다.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_METALTEST));

    MSG msg;
    msg.message = WM_NULL;

    // 기본 메시지 루프입니다.

    MainManager::GetInst()->Initialize();

    DWORD dwOldTime = GetTickCount();
    DWORD dwCurTime = 0;

    while (TRUE)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (WM_QUIT == msg.message)
            {
                break;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        dwCurTime = GetTickCount();
        
        if (dwOldTime + 55 < dwCurTime)
        {
            dwOldTime = dwCurTime;

            // 실제 게임 루틴 수행.
            MainManager::GetInst()->Update();
            MainManager::GetInst()->Render();
            //MainManager::GetInst()->DrawSin();
        }
    }

    return (int) msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_METALTEST));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = nullptr;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   RECT wndClientRect{ 0, 0, WINCX, WINCY };

   //Wnd Compensate
   AdjustWindowRect(&wndClientRect, WS_OVERLAPPEDWINDOW, FALSE);

   HWND hWnd = CreateWindowW(
                szWindowClass, szTitle,
                WS_OVERLAPPEDWINDOW,
                CW_USEDEFAULT, 0, 
                wndClientRect.right - wndClientRect.left,
                wndClientRect.bottom - wndClientRect.top,
                nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }
   
   g_hWnd = hWnd;

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            DestroyWindow(hWnd);
            break;
        }
        break;
    case WM_DESTROY:
        MainManager::GetInst()->Release();
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}