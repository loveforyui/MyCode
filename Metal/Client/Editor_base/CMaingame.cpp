#include "stdafx.h"
#include "CMaingame.h"
#include "MyEdit.h"
#include "BackGround.h"
#include "Mouse.h"
//#include "Player.h"

#define PATH_RC "../resource/"

CMaingame::CMaingame()
{
}

CMaingame::~CMaingame()
{
	Release();
}

void CMaingame::Initialize()
{
    m_hdc = GetDC(g_hWnd);

    GdiplusStartupInput     m_GdiplusStartI;
    ULONG_PTR               m_GdiplusToken;
    GdiplusStartup(&m_GdiplusToken, &m_GdiplusStartI, nullptr);


    char fullPath[256] = "";
    sprintf_s(fullPath, "%s%s", PATH_RC, "background/");
    IMG_LOAD(L"BackGround", fullPath);

    vector<ObjImg*>* objimg = IMG_GET_V(L"BackGround");
    OBJ_MGR_GETLIST(OBJ_BACKGROUD).push_back(CAbstractFactory<CBackGround>::CreateObj(objimg));

    m_pEdit = new CMyEdit;
	m_pEdit->Initialize();

    OBJ_MGR_GETLIST(OBJ_MOUSE).push_back(CAbstractFactory<CMouse>::CreateObj());
}

void CMaingame::Update()
{
    m_pEdit->Update();

	CScrollMgr::GetInstance()->Update();
    CKeyMgr::GetInstance()->Update();
    CObjManager::GetInst()->Update();
}

void CMaingame::Render()
{
    HDC hdc = GetDC(g_hWnd);
    m_hdc = CreateCompatibleDC(hdc);
    m_hBitmap = CreateCompatibleBitmap(hdc, 3823, WINCY);
    m_hOldmap = (HBITMAP)SelectObject(m_hdc, m_hBitmap);

    //Rectangle(m_hdc, 0, 0, WINCX, WINCY);

    m_pEdit->Render(m_hdc);
    CObjManager::GetInst()->Render(m_hdc);
    CLineMgr::GetInstance()->Render(m_hdc);
    
	

    float fScrollX = CScrollMgr::GetInstance()->GetScrollX();

    //StretchBlt(hdc
    //    , 0, 0
    //    , 3823//*1.92f 
    //    , WINCY//*1.92f
    //    , m_hdc
    //    , -fScrollX, 0
    //    , 3823//*0.5f
    //    , WINCY//*0.5f
    //    , SRCCOPY);
    BitBlt(hdc
        , 0, 0
        , 3823//*1.92f 
        , WINCY//*1.92f
        , m_hdc
        , -fScrollX, 0
        , SRCCOPY);

    DeleteObject(SelectObject(m_hdc, m_hOldmap));
    DeleteDC(m_hdc);
    ReleaseDC(g_hWnd, hdc);
}

void CMaingame::Release()
{
	// EndPaint 함수도 WM_PAINT 메시지 처리 내부에서만 호출 가능.
	// ReleaseDC: 할당받은 DC를 해제해주는 함수.
	ReleaseDC(g_hWnd, m_hdc);	

    SafeDelete<CMyEdit*>(m_pEdit);

	CObjManager::GetInst()->Destroy();
	CScrollMgr::GetInstance()->DestroyInstance();
	CLineMgr::GetInstance()->DestroyInstance();
	CKeyMgr::GetInstance()->DestroyInstance();
}
