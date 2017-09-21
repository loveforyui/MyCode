// GreedTest.cpp: 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "GreedTest.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE           hInst;                                // 현재 인스턴스입니다.
WCHAR               szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR               szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
UnitObj             unit;
UnitObj             mob                 (LONG(100), LONG(100));
HBITMAP             hBit;
vector<Greed*>      greeds;

// 이 코드 모듈에 들어 있는 함수의 정방향 선언입니다.
ATOM                MyRegisterClass     (HINSTANCE hInstance);
BOOL                InitInstance        (HINSTANCE, int);
LRESULT CALLBACK    WndProc             (HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About               (HWND, UINT, WPARAM, LPARAM);

void                MakeGreedSystem     (LPRECT pRect, vector<Greed*>& vec);
void                onTimer             (HWND hWnd);
void                DrawBitmap          (HDC hdc, int x, int y, HBITMAP hBit);
bool                checkEllipse        (RECT& greeds, RECT& sbjt);
void                moveLeft            ();
void                moveUp              ();
void                moveDown            ();
void                moveRight           ();

int     APIENTRY    wWinMain(   _In_        HINSTANCE   hInstance,
                                _In_opt_    HINSTANCE   hPrevInstance,
                                _In_        LPWSTR      lpCmdLine,
                                _In_        int         nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_GREEDTEST, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 응용 프로그램 초기화를 수행합니다.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GREEDTEST));

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



//
//  함수: MyRegisterClass()
//
//  목적: 창 클래스를 등록합니다.
//
ATOM                MyRegisterClass     (HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GREEDTEST));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_GREEDTEST);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   목적: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   설명:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL                InitInstance        (HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

LRESULT CALLBACK    WndProc             (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static LPRECT tempRect = new RECT;
    static HANDLE hTimer;

    HDC hdc;
    PAINTSTRUCT ps;
    //HBRUSH mBrush, oBrush;

    switch (message)
    {
    case WM_TIMER:
		//time(&mytime);
		//str=ctime(&mytime);
		//InvalidateRect(hWnd, tempRect, TRUE);
        onTimer(hWnd);
		return 0;

    case WM_CREATE:
        {
            GetClientRect(hWnd, tempRect);
            MakeGreedSystem(tempRect, greeds);
            hTimer = (HANDLE)SetTimer(hWnd, 1, 16, NULL);
		    // str="";
		    SendMessage(hWnd, WM_TIMER, 1, 0);
        }
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

    case WM_LBUTTONDOWN:
        {
            mob._objstate = BLANC;
        }
        break;

    case WM_RBUTTONDOWN:
            mob._objstate = BLOCK;
        break;

    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        if (hBit)
            DrawBitmap(hdc, 0, 0, hBit);
        EndPaint(hWnd, &ps);
        break;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_LEFT:
            moveLeft();
            break;
        case VK_RIGHT:
            moveRight();
            break;
        case VK_UP:
            moveUp();
            break;
        case VK_DOWN:
            moveDown();
            break;
        }
        break;

    case WM_DESTROY:
        if (hBit)
        {
            DeleteObject(hBit);
        }
        PostQuitMessage(0);
        KillTimer(hWnd, 1);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK    About               (HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
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

void                MakeGreedSystem     (LPRECT pRect, vector<Greed*>& vec)
{
    // DEVIDESIZE 만큼 rectangle
    // windRect.left, top ~ windRect.left + DEVIDESIZE , top + DEVIDESIZE
    for (int y = 0; y < pRect->bottom; y += 50)
    {
        for (int x = 0; x < pRect->right; x += 50)
        {
            RECT temp;
            temp.left = x;
            temp.right = x + 50;
            temp.top = y;
            temp.bottom = y + 50;
            vec.push_back(new Greed(temp));
        }
    }
}

void                onTimer             (HWND hWnd)
{
    RECT wndRect;
    HDC hdc, hMemDC;
    HBITMAP oldBit;
    HPEN hPen, oldPen;
    HBRUSH hBrush, oldBrush;

    GetClientRect(hWnd, &wndRect);
    hdc = GetDC(hWnd);

    if (hBit == NULL)
        hBit = CreateCompatibleBitmap(hdc, wndRect.right, wndRect.bottom);

    hMemDC = CreateCompatibleDC(hdc);

    oldBit = (HBITMAP)SelectObject(hMemDC, hBit);

    FillRect(hMemDC, &wndRect, GetSysColorBrush(COLOR_WINDOW));

    //------------------------------------------------
    //map        
    hPen = CreatePen(PS_INSIDEFRAME, 1, RGB(0, 0, 0));
    oldPen = (HPEN)SelectObject(hMemDC, hPen);
    for (vector<Greed*>::iterator i = greeds.begin(); i != greeds.end(); ++i)
    {
        (*i)->Draw(hMemDC);
    }
    //obj
    /*-----------------------------------------------*/
    // draw player, monster
    hBrush = (HBRUSH)GetStockObject(BLACK_BRUSH);
    oldBrush = (HBRUSH)SelectObject(hMemDC, hBrush);
    mob.draw(hMemDC);
    SelectObject(hMemDC, oldBrush);

    hBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
    oldBrush = (HBRUSH)SelectObject(hMemDC, hBrush);
    unit.draw(hMemDC);
    SelectObject(hMemDC, oldBrush);
    /*-----------------------------------------------*/

    DeleteObject(SelectObject(hMemDC, oldPen));
    DeleteObject(SelectObject(hMemDC, oldBrush));

    SelectObject(hMemDC, oldBit);
    DeleteDC(hMemDC);
    ReleaseDC(hWnd, hdc);
    InvalidateRect(hWnd, NULL, FALSE);
}

void                DrawBitmap          (HDC hdc,int x,int y,HBITMAP hBit) 
{ 
    HDC MemDC;  
    HBITMAP OldBitmap; 
    int bx,by; 
    BITMAP bit; 

    MemDC=CreateCompatibleDC(hdc); 
    OldBitmap=(HBITMAP)SelectObject(MemDC, hBit); 

    GetObject(hBit,sizeof(BITMAP),&bit); 
    bx=bit.bmWidth; 
    by=bit.bmHeight; 

    BitBlt(hdc,x,y,bx,by,MemDC,0,0,SRCCOPY); 

    SelectObject(MemDC,OldBitmap); 
    DeleteDC(MemDC); 
}

bool                checkEllipse        (RECT& dest, RECT& sbjt)
{
    if (dest.left <= sbjt.left && sbjt.left <= dest.right)
    {
        if (dest.top <= sbjt.top && sbjt.top <= dest.bottom)
        {
            return true;
        }
    }

    if (dest.left <= sbjt.right && sbjt.right <= dest.right)
    {
        if (dest.top <= sbjt.top && sbjt.top <= dest.bottom)
        {
            return true;
        }
    }

    if (dest.left <= sbjt.left && sbjt.left <= dest.right)
    {
        if (dest.top <= sbjt.bottom && sbjt.bottom <= dest.bottom)
        {
            return true;
        }
    }

    if (dest.left <= sbjt.right && sbjt.right <= dest.right)
    {
        if (dest.top <= sbjt.bottom && sbjt.bottom <= dest.bottom)
        {
            return true;
        }
    }

    return false;
}

void                moveLeft            ()
{
    RECT subject = unit.getRect();
    bool ellipsed = false;

    subject.left -= 5;
    subject.right -= 5;
    for (vector<Greed*>::iterator iter = greeds.begin(); iter != greeds.end(); ++iter)
    {
        if((*iter)->_objstate == BLOCK)
            ellipsed = checkEllipse((*iter)->_rect, subject);
    }

    if (mob._objstate == BLOCK)
    {
        RECT temp = mob.getRect();
        ellipsed = checkEllipse(temp, subject);
    }
            

    if (ellipsed)
    {
        return;
    }
    else
    {
        unit.initPos(unit.getPos().X - 5, unit.getPos().Y);
    }
}

void                moveUp              ()
{
    RECT subject = unit.getRect();
    bool ellipsed = false;

    subject.bottom -= 5;
    subject.top -= 5;
    for (vector<Greed*>::iterator iter = greeds.begin(); iter != greeds.end(); ++iter)
    {
        if((*iter)->_objstate == BLOCK)
            ellipsed = checkEllipse((*iter)->_rect, subject);
    }

    if (mob._objstate == BLOCK)
    {
        RECT temp = mob.getRect();
        ellipsed = checkEllipse(temp, subject);
    }

    if (ellipsed)
    {
        return;
    }
    else
    {
        unit.initPos(unit.getPos().X, unit.getPos().Y - 5);
    }
}

void                moveDown            ()
{
    RECT subject = unit.getRect();
    bool ellipsed = false;

    subject.bottom += 5;
    subject.top += 5;
    for (vector<Greed*>::iterator iter = greeds.begin(); iter != greeds.end(); ++iter)
    {
        if((*iter)->_objstate == BLOCK)
            ellipsed = checkEllipse((*iter)->_rect, subject);
    }

    if (mob._objstate == BLOCK)
    {
        RECT temp = mob.getRect();
        ellipsed = checkEllipse(temp, subject);
    }

    if (ellipsed)
    {
        return;
    }
    else
    {
        unit.initPos(unit.getPos().X, unit.getPos().Y + 5);
    }
}

void                moveRight           ()
{
    RECT subject = unit.getRect();
    bool ellipsed = false;

    subject.left += 5;
    subject.right += 5;
    for (vector<Greed*>::iterator iter = greeds.begin(); iter != greeds.end(); ++iter)
    {
        if((*iter)->_objstate == BLOCK)
            ellipsed = checkEllipse((*iter)->_rect, subject);
    }

    if (mob._objstate == BLOCK)
    {
        RECT temp = mob.getRect();
        ellipsed = checkEllipse(temp, subject);
    }

    if (ellipsed)
    {
        return;
    }
    else
    {
        unit.initPos(unit.getPos().X + 5, unit.getPos().Y);
    }
}
//
//case WM_KEYDOWN:
//        switch (wParam)
//        {
//        case VK_LEFT:
//            unit.initPos(unit.getPos().X - 5, unit.getPos().Y);
//            break;
//        case VK_RIGHT:
//            unit.initPos(unit.getPos().X + 5, unit.getPos().Y);
//            break;
//        case VK_UP:
//            unit.initPos(unit.getPos().X, unit.getPos().Y - 5);
//            break;
//        case VK_DOWN:
//            unit.initPos(unit.getPos().X, unit.getPos().Y + 5);
//            break;
//        }