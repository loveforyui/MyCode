// 03SORT.cpp: 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "03SORT.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE           hInst;                                // 현재 인스턴스입니다.
WCHAR               szTitle                 [MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR               szWindowClass           [MAX_LOADSTRING];  
Aarray       ary;

// 이 코드 모듈에 들어 있는 함수의 정방향 선언입니다.
ATOM                MyRegisterClass         (HINSTANCE hInstance);
BOOL                InitInstance            (HINSTANCE, int);
LRESULT CALLBACK    WndProc                 (HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About                   (HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Formview                (HWND, UINT, WPARAM, LPARAM);

int     APIENTRY    wWinMain(   _In_        HINSTANCE hInstance,
                                _In_opt_    HINSTANCE hPrevInstance,
                                _In_        LPWSTR    lpCmdLine,
                                _In_        int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW             (hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW             (hInstance, IDC_03SORT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass         (hInstance);

    // 응용 프로그램 초기화를 수행합니다.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable      = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_03SORT));

    MSG msg;

    // 기본 메시지 루프입니다.
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_03SORT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_03SORT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(   szWindowClass, szTitle,
                                WS_CAPTION       |
                                WS_SYSMENU       |
                                WS_MINIMIZEBOX,
                                CW_USEDEFAULT, CW_USEDEFAULT, 500, 500,
                                nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC                 hdc;
    //Area                area;
    static POSITION     pos[2];
    static UINT         posIndex = 0;
    static BOOL         bdraw = FALSE;
    switch (message)
    {
    case WM_LBUTTONDOWN:
        break;
    case WM_LBUTTONUP:
        pos[posIndex%2].SetPos(LOWORD(lParam), HIWORD(lParam));
        ++posIndex;
        break;
    case WM_RBUTTONDOWN:
        ary.push_back(new Area(pos[0], pos[1]));
        /*CreateWindow(L"pager", L"NULL",
            WS_CHILD |
            WS_VISIBLE |
            BS_PUSHBUTTON,
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
            hWnd, (HMENU)IDD_RBDIAG, hInst, NULL);*/
        //DialogBox(hInst, MAKEINTRESOURCE(IDD_RBDIAG), hWnd, Formview);
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다.
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다.
            EndPaint(hWnd, &ps);
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

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About      (HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK Formview   (HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);

    HDC hdc;

    switch (message)
    {
    case WM_INITDIALOG:
        //return (INT_PTR)TRUE;
        break;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case ID_RBOK:
            hdc = GetDC(hDlg);
            for (UINT i = 0; i < ary.GetCount(); ++i)
            {
                ary.GetAry(i)->DrawRect(hdc, NULL);
            }
            ReleaseDC(hDlg, hdc);
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        case ID_RBCAN:
            EndDialog(hDlg, LOWORD(wParam));
            break;
        /*case IDOK:
        case IDCANCEL:
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;*/
        }
        break;
    }
    return (INT_PTR)FALSE;
}

//hdc = GetDC(hWnd);
//ary.push_back(new Area(pos[0], pos[1]));
////area.Initailizer(pos[0], pos[1]);
//
//for (UINT i = 0; i < ary.GetCount(); ++i)
//{
//    ary.GetAry(i)->DrawRect(hdc, NULL);
//}
////area.DrawRect(hdc, NULL);
//ReleaseDC(hWnd, hdc);