#include "stdafx.h"
#include "Ending.h"

CEnding::CEnding()
{
}

CEnding::~CEnding()
{
}

void CEnding::Initialize()
{
	// MCI (Media Control Interface)
	// �̵�� ����� ���� �������̽��� �����Ѵ�.
	m_hVideo = MCIWndCreate(g_hWnd, 0, MCIWNDF_NOPLAYBAR | WS_VISIBLE | WS_CHILD
		, L"../resource/video/heos.wmv");

	MoveWindow(m_hVideo, 0, 0, WINCX, WINCY, FALSE);

	// ������ ���
	MCIWndPlay(m_hVideo);
}

void CEnding::Update()
{
}

void CEnding::Render(HDC hDC)
{
}

void CEnding::Release()
{
    MCIWndClose(m_hVideo);
}
