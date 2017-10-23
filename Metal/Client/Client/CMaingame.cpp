#include "stdafx.h"
#include "Maingame.h"
#include "Player.h"

CMaingame::CMaingame()
{
}

CMaingame::~CMaingame()
{
	Release();
}

void CMaingame::Initialize()
{
	srand(unsigned(time(nullptr)));
	// GetDC: DC의 핸들을 얻어오는 함수.
	// BeginPaint는 WM_PAINT 메시지 내부에서만 수행 가능한 함수라서 외부에서는 GetDC로 얻어와야함.
	m_hDC = GetDC(g_hWnd);

	CObjMgr::GetInstance()->AddObject(CAbstractFactory<CPlayer>::CreateObj()
		, OBJ_PLAYER);	

	CLineMgr::GetInstance()->Initialize();

	CBmpMgr::GetInstance()->GetMapBit().insert(make_pair(L"Back"
		, (new CMyBmp)->LoadBmp(L"../Image/Back.bmp")));

	CBmpMgr::GetInstance()->GetMapBit().insert(make_pair(L"Background"
		, (new CMyBmp)->LoadBmp(L"../Image/Background.bmp")));

	CBmpMgr::GetInstance()->GetMapBit().insert(make_pair(L"BackBuffer"
		, (new CMyBmp)->LoadBmp(L"../Image/BackBuffer.bmp")));
}

void CMaingame::Update()
{
	CObjMgr::GetInstance()->Update();
	CScrollMgr::GetInstance()->Update();
	CSoundMgr::GetInstance()->Update();
	CKeyMgr::GetInstance()->Update();
}

void CMaingame::Render()
{
	// 더블 버퍼링을 해보자!
	// 후면버퍼에 게임에 필요한 비트맵들을 몽땅 미리 그려넣고
	// 최종적으로 전면버퍼에 최종 결과물을 고속 복사하여 출력하면
	// 결국 우리 눈에는 깜빡이지 않는 최종 결과물을 확인할 수 있다.

	// 후면 버퍼를 얻어온다.
	CMyBmp* pBmp = CBmpMgr::GetInstance()->FindImage(L"BackBuffer");

	if (nullptr == pBmp)
		return;

	HDC hBackBuff = pBmp->GetMemDC();

	// 출력할 모든 비트맵을 후면버퍼에 몽땅 미리 그려놓는다.

	// 잔상 제거용 비트맵 출력
	pBmp = CBmpMgr::GetInstance()->FindImage(L"Back");

	if (nullptr == pBmp)
		return;

	BitBlt(hBackBuff, 0, 0, WINCX, WINCY,
		pBmp->GetMemDC(), 0, 0, SRCCOPY);

	// 실제 게임의 배경이될 비트맵 출력
	pBmp = CBmpMgr::GetInstance()->FindImage(L"Background");

	if (nullptr == pBmp)
		return;

	// GdiTransparentBlt: 사용자가 지정한 색상 값을 제거하여 비트맵을 출력하는 함수.
	RECT rc = { 790, 700, 1920, 1200 };

	float fScrollX = CScrollMgr::GetInstance()->GetScrollX();

	GdiTransparentBlt(hBackBuff, fScrollX, 0, 1920, 1200
		, pBmp->GetMemDC(), rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top
		, RGB(1,0,0));

	CObjMgr::GetInstance()->Render(hBackBuff);
	CLineMgr::GetInstance()->Render(hBackBuff);

	// 미리 그려진 최종 결과물을 이제 전면버퍼(화면DC)에 고속 복사하여 출력한다.
	BitBlt(m_hDC, 0, 0, WINCX, WINCY,
		hBackBuff, 0, 0, SRCCOPY);
}

void CMaingame::Release()
{
	// EndPaint 함수도 WM_PAINT 메시지 처리 내부에서만 호출 가능.
	// ReleaseDC: 할당받은 DC를 해제해주는 함수.
	ReleaseDC(g_hWnd, m_hDC);	

	CObjMgr::GetInstance()->DestroyInstance();
	CScrollMgr::GetInstance()->DestroyInstance();
	CLineMgr::GetInstance()->DestroyInstance();
	CSoundMgr::GetInstance()->DestroyInstance();
	CKeyMgr::GetInstance()->DestroyInstance();
	CBmpMgr::GetInstance()->DestroyInstance();
}
