// GreedTest.cpp: 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "GreedTest.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE           hInst;                                // 현재 인스턴스입니다.
HWND                childhWnd;
HWND                hmain;
WCHAR               szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR               szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
//UnitObj             unit;
//UnitObj             mob                 (LONG(100), LONG(100));
HBITMAP             hBit;
vector<Greed*>      greeds;

// 이 코드 모듈에 들어 있는 함수의 정방향 선언입니다.
ATOM                MyRegisterClass     (HINSTANCE hInstance);
//ATOM                MyRightChildRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance        (HINSTANCE, int);
//BOOL                ChildInitInstance   (HINSTANCE hInstance, int nCmdShow);
LRESULT CALLBACK    RightChildProc      (HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    WndProc             (HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About               (HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Store               (HWND, UINT, WPARAM, LPARAM);

void                MakeGreedSystem     (LPRECT pRect, vector<Greed*>& vec);
void                onTimer             (HWND hWnd);
void                DrawBitmap          (HDC hdc, int x, int y, HBITMAP hBit);
bool                checkEllipse        (RECT& greeds, RECT& sbjt);
bool                checkEllipse        (const RECT& dest, RECT& sbjt);
void                moveLeft            (HWND, UnitObj*);
void                moveUp              (HWND, UnitObj*);
void                moveDown            (HWND, UnitObj*);
void                moveRight           (HWND, UnitObj*);

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
    //MyRightChildRegisterClass(hInstance);

    // 응용 프로그램 초기화를 수행합니다.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }
    //ChildInitInstance(hInstance, nCmdShow);

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
    wcex.hbrBackground  = NULL;//(HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_GREEDTEST);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    

    /*wcex.lpfnWndProc    = RightChildProc;
    wcex.hbrBackground  = CreateSolidBrush(RGB(255, 255, 255));
    wcex.lpszClassName  = L"RIGHTCHILD";

    RegisterClassExW(&wcex);*/

    return RegisterClassExW(&wcex);
}
//
//ATOM                MyRightChildRegisterClass     (HINSTANCE hInstance)
//{
//    WNDCLASSEXW wcex;
//
//    wcex.cbSize = sizeof(WNDCLASSEX);
//
//    wcex.style          = CS_HREDRAW | CS_VREDRAW;
//    wcex.lpfnWndProc    = RightChildProc;
//    wcex.cbClsExtra     = 0;
//    wcex.cbWndExtra     = 0;
//    wcex.hInstance      = hInstance;
//    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GREEDTEST));
//    wcex.hCursor        = LoadCursor(nullptr, IDC_CROSS);
//    wcex.hbrBackground  = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
//    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_GREEDTEST);
//    wcex.lpszClassName  = L"RIGHTCHILD";
//    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
//
//    return RegisterClassExW(&wcex);
//}

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

   HWND hWnd = 
       CreateWindow(
           szWindowClass, 
           szTitle,
           WS_VISIBLE | WS_CAPTION | WS_SYSMENU,
           CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
           nullptr, nullptr, hInstance, nullptr);

   hmain = hWnd;
   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}
//BOOL                ChildInitInstance            (HINSTANCE hInstance, int nCmdShow)
//{
//    childhWnd =
//        CreateWindow(
//            L"RIGHTCHILD",
//            NULL,
//            WS_CHILD | WS_VISIBLE,
//            0, 0, 0, 0,
//            hmain, nullptr, hInst, nullptr);
//    if (!childhWnd)
//   {
//      return FALSE;
//   }
//
//   ShowWindow(childhWnd, nCmdShow);
//   UpdateWindow(childhWnd);
//
//   return TRUE;
//}
//
//LRESULT CALLBACK    RightChildProc      (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    HDC hdc;
//    PAINTSTRUCT ps;
//    TCHAR *mes = L"WINDOW";
//    switch (message)
//    {
//    case WM_CREATE:
//    {
//        
//    }
//        break;
//    case WM_LBUTTONDOWN:
//        MessageBeep(0);
//        break;
//    case WM_PAINT:
//        hdc = BeginPaint(hWnd, &ps);
//        SetBkMode(hdc, TRANSPARENT);
//        TextOut(hdc, 10, 50, mes, lstrlen(mes));
//        EndPaint(hWnd, &ps);
//        break;
//    case WM_DESTROY:
//        PostQuitMessage(0);
//        break;
//    }
//    return(DefWindowProc(hWnd, message, wParam, lParam));
//}

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

            UnitObj* mtemp = new NPC(INFO(L"Steive", 0, 100));
            mtemp->initPos(50, 50);
            dynamic_cast<NPC*>(mtemp)->AddItem(ITEM(L"SWORD", 10, 100, RIGHTHAND));
           
            GameManager::getInst()->npcObj.insert(pair<TCHAR*, UnitObj*>(L"Store", mtemp));

            hTimer = (HANDLE)SetTimer(hWnd, 1, 16, NULL);
		    // str="";
		    SendMessage(hWnd, WM_TIMER, 1, 0);
        }
        break;
    case WM_SIZE:
        if (wParam != SIZE_MINIMIZED)
        {
            //MoveWindow(childhWnd, 300, 0,tempRect->right - 300, 150, true);
        }
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다.
            switch (wmId)
            {
            case ID_FILE_NEW:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX2), hWnd, About);
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
        hdc = BeginPaint(hWnd, &ps);
        if (hBit)
            DrawBitmap(hdc, 0, 0, hBit);
        EndPaint(hWnd, &ps);
        break;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_LEFT:
            moveLeft(hWnd, (GameManager::getInst()->getPobj()));
            break;
        case VK_RIGHT:
            moveRight(hWnd, (GameManager::getInst()->getPobj()));
            break;
        case VK_UP:
            moveUp(hWnd, (GameManager::getInst()->getPobj()));
            break;
        case VK_DOWN:
            moveDown(hWnd, (GameManager::getInst()->getPobj()));
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
    case WM_RBUTTONDOWN:
    {
        LONG x = LOWORD(lParam);
        LONG y = HIWORD(lParam);

        UnitObj* mtemp = new Monster(INFO(L"slime", 10, 30, 30, 0, 1, 50));
        mtemp->initPos(x, y);

        GameManager::getInst()->mobObj.insert(pair<TCHAR*, UnitObj*>(L"slime", mtemp));
    }
    break;
    case WM_LBUTTONDOWN:
    {
        LONG x = LOWORD(lParam);
        LONG y = HIWORD(lParam);

        RECT mpos;
        mpos.left = x;
        mpos.top = y;
        mpos.right = x;
        mpos.bottom = y;

        for (map<TCHAR*, UnitObj*>::iterator iter = GameManager::getInst()->npcObj.begin();
            iter != GameManager::getInst()->npcObj.end(); ++iter)
        {
            if (checkEllipse(iter->second->getRect(), mpos))
            {
                DialogBox(hInst, MAKEINTRESOURCE(IDD_STORE), hmain, Store);
            }
        }
    }
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
// 캐릭생성
INT_PTR CALLBACK    About               (HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        //|| LOWORD(wParam) == IDCANCEL

        switch (LOWORD(wParam))
        {
        case IDOK:
        {
            if (GameManager::getInst()->getPobj() == NULL)
            {
                TCHAR temp[32];
                GetDlgItemText(hDlg, IDC_EDIT_NAME, temp, sizeof(temp) / sizeof(TCHAR));
                //GetWindowText(hDlg, temp, sizeof(temp) / sizeof(TCHAR));
                GameManager::getInst()->createPlayer(INFO(temp, 10, 100));
                GameManager::getInst()->getPobj()->initPos(300, 300);

                //UnitObj* mTemp = new Monster(INFO(L"SLIME", 10, 30));
                //mTemp->initPos(400, 400);

                //GameManager::getInst()->mobObj.insert(pair<TCHAR*, UnitObj*>(L"SLIME", mTemp));
                ////GameManager::getInst()->getMobObj().insert();
            }
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
            break;
        case IDCANCEL:
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        }
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK    Store               (HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HWND combo;
    //static HWND editName;
    //static HWND editAtk;
    //static HWND editGold;

    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        combo = GetDlgItem(hDlg, STORE_LIST);
        //editName = GetDlgItem(hDlg, STORE_EDIT_NAME);
        //editAtk = GetDlgItem(hDlg, STORE_EDIT_ATK);
        //editGold = GetDlgItem(hDlg, STORE_EDIT_GOLD);
        for (map<TCHAR*, UnitObj*>::iterator iter = GameManager::getInst()->npcObj.begin();
            iter != GameManager::getInst()->npcObj.end(); ++iter)
        {
            vector<ITEM> temp = iter->second->GetInfo().inven;
            
            for (vector<ITEM>::iterator viter = temp.begin();
                viter != temp.end(); ++viter)
            {
                SendMessage(combo, CB_ADDSTRING, 0, (LPARAM)(viter->szName));
                //SetDlgItemText(hDlg, STORE_LIST, viter->szName);
            }
            
        }
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case STORE_OK:
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        case STORE_CANCEL:
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        case STORE_LIST:
            // 원래는 DB에서 들고와서 선택된 템 정보 뿌림
            switch (HIWORD(wParam))
            {
            case CBN_SELCHANGE:
            {
                TCHAR itemName[32];
                int index;
                index = SendMessage(combo, CB_GETCURSEL, 0, 0);
                SendMessage(combo, CB_GETLBTEXT, index, (LPARAM)itemName);
                //GetDlgItemText(hDlg, STORE_LIST, itemName, sizeof(itemName) / sizeof(TCHAR));
                // 아이템 이름을 들고와서 DB검색후 정보 뿌려야함 원래는
                for (map<TCHAR*, UnitObj*>::iterator iter = GameManager::getInst()->npcObj.begin();
                    iter != GameManager::getInst()->npcObj.end(); ++iter)
                {
                    vector<ITEM> temp = iter->second->GetInfo().inven;

                    for (vector<ITEM>::iterator viter = temp.begin();
                        viter != temp.end(); ++viter)
                    {
                        if (!_tccmp(viter->szName, itemName))
                        {
                            SetDlgItemText(hDlg, STORE_EDIT_NAME, viter->szName);
                            SetDlgItemInt(hDlg, STORE_EDIT_ATK, viter->iAtt, true);
                            SetDlgItemInt(hDlg, STORE_EDIT_GOLD, viter->iGold, true);
                        }
                    }

                }
                break;
            }
            }
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
    // pRect->bottom
    for (int y = 0; y < 550; y += 50)
    {
        for (int x = 0; x < 1050; x += 50)
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
    //geed        
    hPen = CreatePen(PS_INSIDEFRAME, 1, RGB(0, 0, 0));
    oldPen = (HPEN)SelectObject(hMemDC, hPen);
    for (vector<Greed*>::iterator i = greeds.begin(); i != greeds.end(); ++i)
    {
        (*i)->Draw(hMemDC);
    }
    //obj
    /*-----------------------------------------------*/
    if (GameManager::getInst()->getPobj() != NULL)
    {
        hBrush = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
        oldBrush = (HBRUSH)SelectObject(hMemDC, hBrush);
        if (!GameManager::getInst()->npcObj.empty())
        {
            for (map<TCHAR*, UnitObj*>::iterator iter = GameManager::getInst()->npcObj.begin();
                iter != GameManager::getInst()->npcObj.end(); ++iter)
            {
                iter->second->draw(hMemDC);
            }
        }
        SelectObject(hMemDC, oldBrush);
    }    
    // draw player, monster
    hBrush = (HBRUSH)GetStockObject(BLACK_BRUSH);
    oldBrush = (HBRUSH)SelectObject(hMemDC, hBrush);
    //mob.draw(hMemDC);

    UnitObj* temp = GameManager::getInst()->getPobj();
    if (temp != NULL)
    {
        temp->draw(hMemDC);
    }
    //GameManager::getInst()->getPobj()->draw(hMemDC);
    SelectObject(hMemDC, oldBrush);

    hBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
    oldBrush = (HBRUSH)SelectObject(hMemDC, hBrush);
    map<TCHAR*,UnitObj*> mobAry = GameManager::getInst()->getMobObj();

    if (!mobAry.empty())
    {
        for (map<TCHAR*, UnitObj*>::iterator iter = mobAry.begin();
            iter != mobAry.end(); ++iter)
        {
            iter->second->draw(hMemDC);
        }
    }

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

bool                checkEllipse        (const RECT& dest, RECT& sbjt)
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

#pragma region Move Func
// Move Function
void                moveLeft            (HWND hWnd, UnitObj* src)
{
    if (src == NULL)
        return;
    RECT subject = src->getRect();
    bool ellipsed = false;

    subject.left -= 1;
    subject.right -= 1;
    //greed
    for (vector<Greed*>::iterator iter = greeds.begin(); iter != greeds.end(); ++iter)
    {
        if((*iter)->_objstate == BLOCK)
            ellipsed = checkEllipse((*iter)->_rect, subject);
    }

    if (!GameManager::getInst()->mobObj.empty())
    {
        for (map<TCHAR*, UnitObj*>::iterator iter = GameManager::getInst()->mobObj.begin();
            iter != GameManager::getInst()->mobObj.end();)
        {
            if (iter->second->GetInfo().objState == BLOCK)
            {
                RECT mRect = iter->second->getRect();
                ellipsed = checkEllipse(mRect, subject);
            }
            if (ellipsed)
            {
                // progress attack
                if (GameManager::getInst()->BattleObjtoObj(GameManager::getInst()->getPobj(), iter->second))
                {
                    iter = GameManager::getInst()->mobObj.erase(iter);
                }
                else
                {
                    ++iter;
                }
            }
            else
            {
                ++iter;
            }
        }
    }

    if (!GameManager::getInst()->npcObj.empty())
    {
        for (map<TCHAR*, UnitObj*>::iterator iter = GameManager::getInst()->npcObj.begin();
            iter != GameManager::getInst()->npcObj.end();++iter)
        {
            if (iter->second->GetInfo().objState == BLOCK)
            {
                RECT mRect = iter->second->getRect();
                ellipsed = checkEllipse(mRect, subject);
            }
            if (ellipsed)
            {
                // 상점 처리
                DialogBox(hInst, MAKEINTRESOURCE(IDD_STORE), hWnd, Store);
            }
        }
    }

    /*if (mob._objstate == BLOCK)
    {
        RECT temp = mob.getRect();
        ellipsed = checkEllipse(temp, subject);
    }*/

    if (ellipsed)
    {
        return;
    }
    else
    {
        src->initPos(src->getPos().X - 2, src->getPos().Y);
    }
}

void                moveUp              (HWND hWnd, UnitObj* src)
{
    if (src == NULL)
        return;
    RECT subject = src->getRect();
    bool ellipsed = false;

    subject.bottom -= 1;
    subject.top -= 1;
    for (vector<Greed*>::iterator iter = greeds.begin(); iter != greeds.end(); ++iter)
    {
        if((*iter)->_objstate == BLOCK)
            ellipsed = checkEllipse((*iter)->_rect, subject);
    }

    if (!GameManager::getInst()->mobObj.empty())
    {
        for (map<TCHAR*, UnitObj*>::iterator iter = GameManager::getInst()->mobObj.begin();
            iter != GameManager::getInst()->mobObj.end();)
        {
            if (iter->second->GetInfo().objState == BLOCK)
            {
                RECT mRect = iter->second->getRect();
                ellipsed = checkEllipse(mRect, subject);
            }
            if (ellipsed)
            {
                // progress attack
                if (GameManager::getInst()->BattleObjtoObj(GameManager::getInst()->getPobj(), iter->second))
                {
                    iter = GameManager::getInst()->mobObj.erase(iter);
                }
                else
                {
                    ++iter;
                }
            }
            else
            {
                ++iter;
            }
        }
    }

    if (!GameManager::getInst()->npcObj.empty())
    {
        for (map<TCHAR*, UnitObj*>::iterator iter = GameManager::getInst()->npcObj.begin();
            iter != GameManager::getInst()->npcObj.end();++iter)
        {
            if (iter->second->GetInfo().objState == BLOCK)
            {
                RECT mRect = iter->second->getRect();
                ellipsed = checkEllipse(mRect, subject);
            }
            if (ellipsed)
            {
                // 상점 처리
                DialogBox(hInst, MAKEINTRESOURCE(IDD_STORE), hWnd, Store);
            }
        }
    }

    /*if (mob._objstate == BLOCK)
    {
        RECT temp = mob.getRect();
        ellipsed = checkEllipse(temp, subject);
    }*/

    if (ellipsed)
    {
        return;
    }
    else
    {
        src->initPos(src->getPos().X, src->getPos().Y - 2);
    }
}

void                moveDown            (HWND hWnd, UnitObj* src)
{
    if (src == NULL)
        return;
    RECT subject = src->getRect();
    bool ellipsed = false;

    subject.bottom += 1;
    subject.top += 1;
    for (vector<Greed*>::iterator iter = greeds.begin(); iter != greeds.end(); ++iter)
    {
        if((*iter)->_objstate == BLOCK)
            ellipsed = checkEllipse((*iter)->_rect, subject);
    }

    if (!GameManager::getInst()->mobObj.empty())
    {
        for (map<TCHAR*, UnitObj*>::iterator iter = GameManager::getInst()->mobObj.begin();
            iter != GameManager::getInst()->mobObj.end();)
        {
            if (iter->second->GetInfo().objState == BLOCK)
            {
                RECT mRect = iter->second->getRect();
                ellipsed = checkEllipse(mRect, subject);
            }
            if (ellipsed)
            {
                // progress attack
                if (GameManager::getInst()->BattleObjtoObj(GameManager::getInst()->getPobj(), iter->second))
                {
                    iter = GameManager::getInst()->mobObj.erase(iter);
                }
                else
                {
                    ++iter;
                }
            }
            else
            {
                ++iter;
            }
        }
    }

    if (!GameManager::getInst()->npcObj.empty())
    {
        for (map<TCHAR*, UnitObj*>::iterator iter = GameManager::getInst()->npcObj.begin();
            iter != GameManager::getInst()->npcObj.end();++iter)
        {
            if (iter->second->GetInfo().objState == BLOCK)
            {
                RECT mRect = iter->second->getRect();
                ellipsed = checkEllipse(mRect, subject);
            }
            if (ellipsed)
            {
                // 상점 처리
                DialogBox(hInst, MAKEINTRESOURCE(IDD_STORE), hWnd, Store);
            }
        }
    }


    /*if (mob._objstate == BLOCK)
    {
        RECT temp = mob.getRect();
        ellipsed = checkEllipse(temp, subject);
    }*/

    if (ellipsed)
    {
        return;
    }
    else
    {
        src->initPos(src->getPos().X, src->getPos().Y + 2);
    }
}

void                moveRight           (HWND hWnd, UnitObj* src)
{
    if (src == NULL)
        return;
    RECT subject = src->getRect();
    bool ellipsed = false;

    subject.left += 1;
    subject.right += 1;
    for (vector<Greed*>::iterator iter = greeds.begin(); iter != greeds.end(); ++iter)
    {
        if((*iter)->_objstate == BLOCK)
            ellipsed = checkEllipse((*iter)->_rect, subject);
    }

    if (!GameManager::getInst()->mobObj.empty())
    {
        for (map<TCHAR*, UnitObj*>::iterator iter = GameManager::getInst()->mobObj.begin();
            iter != GameManager::getInst()->mobObj.end();)
        {
            if (iter->second->GetInfo().objState == BLOCK)
            {
                RECT mRect = iter->second->getRect();
                ellipsed = checkEllipse(mRect, subject);
            }
            if (ellipsed)
            {
                // progress attack
                if (GameManager::getInst()->BattleObjtoObj(GameManager::getInst()->getPobj(), iter->second))
                {
                    iter = GameManager::getInst()->mobObj.erase(iter);
                }
                else
                {
                    ++iter;
                }
            }
            else
            {
                ++iter;
            }
        }
    }

    if (!GameManager::getInst()->npcObj.empty())
    {
        for (map<TCHAR*, UnitObj*>::iterator iter = GameManager::getInst()->npcObj.begin();
            iter != GameManager::getInst()->npcObj.end();++iter)
        {
            if (iter->second->GetInfo().objState == BLOCK)
            {
                RECT mRect = iter->second->getRect();
                ellipsed = checkEllipse(mRect, subject);
            }
            if (ellipsed)
            {
                // 상점 처리
                DialogBox(hInst, MAKEINTRESOURCE(IDD_STORE), hWnd, Store);
            }
        }
    }


    /*if (mob._objstate == BLOCK)
    {
        RECT temp = mob.getRect();
        ellipsed = checkEllipse(temp, subject);
    }*/

    if (ellipsed)
    {
        return;
    }
    else
    {
        src->initPos(src->getPos().X + 2, src->getPos().Y);
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
#pragma endregion

