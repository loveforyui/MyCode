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
	// GetDC: DC�� �ڵ��� ������ �Լ�.
	// BeginPaint�� WM_PAINT �޽��� ���ο����� ���� ������ �Լ��� �ܺο����� GetDC�� ���;���.
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
	// ���� ���۸��� �غ���!
	// �ĸ���ۿ� ���ӿ� �ʿ��� ��Ʈ�ʵ��� ���� �̸� �׷��ְ�
	// ���������� ������ۿ� ���� ������� ��� �����Ͽ� ����ϸ�
	// �ᱹ �츮 ������ �������� �ʴ� ���� ������� Ȯ���� �� �ִ�.

	// �ĸ� ���۸� ���´�.
	CMyBmp* pBmp = CBmpMgr::GetInstance()->FindImage(L"BackBuffer");

	if (nullptr == pBmp)
		return;

	HDC hBackBuff = pBmp->GetMemDC();

	// ����� ��� ��Ʈ���� �ĸ���ۿ� ���� �̸� �׷����´�.

	// �ܻ� ���ſ� ��Ʈ�� ���
	pBmp = CBmpMgr::GetInstance()->FindImage(L"Back");

	if (nullptr == pBmp)
		return;

	BitBlt(hBackBuff, 0, 0, WINCX, WINCY,
		pBmp->GetMemDC(), 0, 0, SRCCOPY);

	// ���� ������ ����̵� ��Ʈ�� ���
	pBmp = CBmpMgr::GetInstance()->FindImage(L"Background");

	if (nullptr == pBmp)
		return;

	// GdiTransparentBlt: ����ڰ� ������ ���� ���� �����Ͽ� ��Ʈ���� ����ϴ� �Լ�.
	RECT rc = { 790, 700, 1920, 1200 };

	float fScrollX = CScrollMgr::GetInstance()->GetScrollX();

	GdiTransparentBlt(hBackBuff, fScrollX, 0, 1920, 1200
		, pBmp->GetMemDC(), rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top
		, RGB(1,0,0));

	CObjMgr::GetInstance()->Render(hBackBuff);
	CLineMgr::GetInstance()->Render(hBackBuff);

	// �̸� �׷��� ���� ������� ���� �������(ȭ��DC)�� ��� �����Ͽ� ����Ѵ�.
	BitBlt(m_hDC, 0, 0, WINCX, WINCY,
		hBackBuff, 0, 0, SRCCOPY);
}

void CMaingame::Release()
{
	// EndPaint �Լ��� WM_PAINT �޽��� ó�� ���ο����� ȣ�� ����.
	// ReleaseDC: �Ҵ���� DC�� �������ִ� �Լ�.
	ReleaseDC(g_hWnd, m_hDC);	

	CObjMgr::GetInstance()->DestroyInstance();
	CScrollMgr::GetInstance()->DestroyInstance();
	CLineMgr::GetInstance()->DestroyInstance();
	CSoundMgr::GetInstance()->DestroyInstance();
	CKeyMgr::GetInstance()->DestroyInstance();
	CBmpMgr::GetInstance()->DestroyInstance();
}
