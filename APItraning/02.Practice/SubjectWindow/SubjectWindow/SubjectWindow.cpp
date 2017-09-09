// SubjectWindow.cpp: 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "SubjectWindow.h"

//#define MWCSCAT(SRC, N)                                         \
//        WCHAR DEST[64];                                         \
//        wcscpy_s(DEST, sizeof(DEST), SRC);                      \
//        WCHAR temp[32];                                         \
//        wsprintf(temp, L"%d", N);                               \
//        wcscat_s(DEST, wcslen(DEST) + wcslen(temp) + 1, temp);

// 전역 변수:
HINSTANCE               hInst;                                              // 현재 인스턴스입니다.
WCHAR                   szTitle         [MAX_LOADSTRING];                   // 제목 표시줄 텍스트입니다.
WCHAR                   szWindowClass   [MAX_LOADSTRING];                   // 기본 창 클래스 이름입니다.
WCHAR                   szName[32]      = {};
//WCHAR

//Subject                 sbjt;
vector<Subject*>        sbjt;

HWND                    hList;

FILE*                   fp              = NULL;


// 이 코드 모듈에 들어 있는 함수의 정방향 선언입니다.
ATOM                    MyRegisterClass (HINSTANCE hInstance);
BOOL                    InitInstance    (HINSTANCE, int);

LRESULT     CALLBACK    WndProc         (HWND,  UINT, WPARAM, LPARAM);
INT_PTR     CALLBACK    About           (HWND,  UINT, WPARAM, LPARAM);
BOOL        CALLBACK    SubjectWnd      (HWND,  UINT, WPARAM, LPARAM);
WCHAR&                  m_wcscat        (WCHAR src[], UINT  uInt);
WCHAR&                  m_wcscat        (WCHAR src[], FLOAT uInt);


int         APIENTRY    wWinMain        (
            _In_                        HINSTANCE hInstance,
            _In_opt_                    HINSTANCE hPrevInstance,
            _In_                        LPWSTR    lpCmdLine,    
            _In_                        int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_SUBJECTWINDOW, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 응용 프로그램 초기화를 수행합니다.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SUBJECTWINDOW));

    MSG msg;

    // 변수들 정의
    

    // 기본 메시지 루프입니다.
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage    (&msg);
            DispatchMessage     (&msg);
        }
    }

    return (int) msg.wParam;
}

//
//  함수: MyRegisterClass()
//
//  목적: 창 클래스를 등록합니다.
//
ATOM                    MyRegisterClass (HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SUBJECTWINDOW));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_SUBJECTWINDOW);
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
BOOL                    InitInstance    (HINSTANCE hInstance, int nCmdShow)
{
   hInst                = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd            = CreateWindowW(szWindowClass, szTitle,
                        WS_CAPTION       |
                        WS_SYSMENU       |
                        WS_MINIMIZEBOX,
                        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                        nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  목적:  주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 응용 프로그램 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT     CALLBACK    WndProc         (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT         ps;
    HDC                 hdc;
    WCHAR*              sbjtScore[5]    = {NULL};
    errno_t             err;
    Subject*            fileMember      = NULL;
    RECT                rt              = {};
    time_t              mTime;
    static HANDLE       hTimer;
    vector<Subject*>::iterator i = sbjt.begin();
    
    int                 listIndex       = 0;
    int                 fileSizeCnt     = 0;

    switch (message)
    {
    case WM_CREATE:
        //DialogBox(hInst, MAKEINTRESOURCE(IDD_CONTAINER), hWnd, ContainerD);
        hList = CreateWindow(L"listbox", NULL,
            WS_CHILD    |
            WS_VISIBLE  |
            WS_BORDER   |
            LBS_NOTIFY,
            10, 10, 100, 200, hWnd, (HMENU)ID_LISTBOX, hInst, NULL);

        //hTimer = (HANDLE)SetTimer(hWnd, 1, 1000, NULL);
        //SendMessage(hWnd, WM_TIMER, 1, 0);
        return 0;
    case WM_TIMER:
        return 0;
    case WM_COMMAND:
        {
            // 메뉴 선택을 구문 분석합니다.
            switch (LOWORD(wParam))
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            case IDM_FILE_NEW:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_FILENEW), hWnd, SubjectWnd);
                break;
            case IDM_FILE_LOAD:
                err = fopen_s(&fp, PATH, "rb");

                fseek(fp, 0, SEEK_END);
                fileSizeCnt = ftell(fp) / sizeof(Subject);
                fseek(fp, 0, SEEK_SET);

                if (err == 0)
                {
                    for (int i = 0; i < fileSizeCnt; ++i)
                    {
                        fileMember = new Subject();
                        fread(fileMember, sizeof(Subject), 1, fp);
                        sbjt.push_back(fileMember);
                        fileMember = NULL;
                    }                    
                    fclose(fp);
                }
                else
                {
                    return 0;
                }
                if (!sbjt.empty())
                {
                    for (vector<Subject*>::iterator i = sbjt.begin(); i != sbjt.end(); ++i)
                    {
                        SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)((*i)->GetUserInfo()._name_wc));
                    }
                }                
                break;
            case ID_LISTBOX:
                // ListBox Event
                switch (HIWORD(wParam))
                {
                case LBN_SELCHANGE:
                    //InvalidateRect(hWnd, NULL, TRUE);
                    listIndex = SendMessage(hList, LB_GETCURSEL, 0, 0);
                    SendMessage(hList, LB_GETTEXT, listIndex, (LPARAM)szName);
                    
                    hdc = GetDC(hWnd);                    
                    for (;i != sbjt.end(); ++i)
                    {
                        if (!wcscmp((*i)->GetUserInfo()._name_wc, szName))
                        {
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    if (!sbjt.empty())
                    {
                        //InvalidateRect(hWnd, NULL, FALSE);
                        sbjtScore[0] = &(m_wcscat((*i)->m_subjectName_wc[0], (*i)->GetUserInfo()._korean_ui));
                        TextOut(hdc, 120, 20, sbjtScore[0], wcslen(sbjtScore[0]));

                        sbjtScore[1] = &(m_wcscat((*i)->m_subjectName_wc[1], (*i)->GetUserInfo()._english_ui));
                        TextOut(hdc, 120, 40, sbjtScore[1], wcslen(sbjtScore[1]));


                        sbjtScore[2] = &(m_wcscat((*i)->m_subjectName_wc[2], (*i)->GetUserInfo()._math_ui));
                        TextOut(hdc, 120, 60, sbjtScore[2], wcslen(sbjtScore[2]));


                        sbjtScore[3] = &(m_wcscat((*i)->m_subjectName_wc[3], (*i)->GetUserInfo()._total_ui));
                        TextOut(hdc, 120, 80, sbjtScore[3], wcslen(sbjtScore[3]));


                        sbjtScore[4] = &(m_wcscat((*i)->m_subjectName_wc[4], (*i)->GetUserInfo()._avg_f));
                        TextOut(hdc, 120, 100, sbjtScore[4], wcslen(sbjtScore[4]));
                    }
                    
                    ReleaseDC(hWnd, hdc);
                    break;
                }
                return 0;
            }
        }
        break;
    case WM_PAINT:
        {
            hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다.
            //TextOut(hdc, 120, 20, sbjt.m_subjectName_wc[0], lstrlen(sbjt.m_subjectName_wc[0]));
            //InvalidateRect(hWnd, NULL, FALSE);
            
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
INT_PTR     CALLBACK    About           (HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
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

BOOL        CALLBACK    SubjectWnd      (HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UINT        kor, eng, math;
    LPWSTR      str                 = NULL;
    WCHAR       str2[32]            = { };
    Subject*    temp_sbjt           = NULL;
    errno_t     err;

    switch (message)
    {
    case WM_INITDIALOG:
        //SetDlgItemText(hDlg, IDC_NAME, &(sbjt.GetUserInfoName()));
        SetDlgItemText                  (hDlg, IDC_NAME, str2);
        SetDlgItemInt                   (hDlg, IDC_KOR, 0, FALSE);
        SetDlgItemInt                   (hDlg, IDC_ENG, 0, FALSE);
        SetDlgItemInt                   (hDlg, IDC_MATH, 0, FALSE);
        return TRUE;
    case WM_COMMAND:
        switch (wParam)
        {
        case ID_FILENEW_OK:
            GetDlgItemText                  (hDlg, IDC_NAME, str2, 32);
            kor         = GetDlgItemInt     (hDlg, IDC_KOR, NULL, FALSE);
            eng         = GetDlgItemInt     (hDlg, IDC_ENG, NULL, FALSE);
            math        = GetDlgItemInt     (hDlg, IDC_MATH, NULL, FALSE);

            temp_sbjt   = new Subject       ();
            temp_sbjt->CreateUser           (str2, kor, eng, math);

            SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)temp_sbjt->GetUserInfo()._name_wc);

            sbjt.push_back(temp_sbjt);
            err = fopen_s(&fp, PATH, "wb");
            
            if (err == 0)
            {
                for (vector<Subject*>::iterator i = sbjt.begin(); i != sbjt.end(); ++i)
                {
                    fwrite(*i, sizeof(Subject), 1, fp);
                }
                //fwrite(&sbjt, sizeof(sbjt), 1, fp);
                fclose(fp);
            }
            else
            {
                return FALSE;
            }
            EndDialog(hDlg,0);
            return TRUE;

        case ID_FILENEW_CANCEL:
            EndDialog(hDlg,0);
            return TRUE;
        }
        break;
    }
    return FALSE;
}

WCHAR&                  m_wcscat        (WCHAR src[], UINT uInt)
{
    WCHAR*  dest            = NULL;
    WCHAR   temp[32]        = {};
    UINT    destSize        = 0;
    wsprintf                (temp, L"%5d", uInt);

    destSize                = wcslen(src) + wcslen(temp) + 1;

    dest                    = new WCHAR[destSize];

    wcscpy_s                (dest, destSize, src);
    
    wcscat_s                (dest, wcslen(dest) + wcslen(temp) + 1, temp);

    return *dest;
}

WCHAR&                  m_wcscat        (WCHAR src[], FLOAT uInt)
{
    WCHAR*  dest            = NULL;
    WCHAR   temp[32]        = {};
    UINT    destSize        = 0;
    swprintf                (temp, 32, L"%5.2f", uInt);

    destSize                = wcslen(src) + wcslen(temp) + 1;

    dest                    = new WCHAR[destSize];

    wcscpy_s                (dest, destSize, src);
    
    wcscat_s                (dest, wcslen(dest) + wcslen(temp) + 1, temp);

    return *dest;
}