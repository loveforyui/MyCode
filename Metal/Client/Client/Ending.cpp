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
	// 미디어 재생을 위한 인터페이스를 제공한다.
	m_hVideo = MCIWndCreate(g_hWnd, 0, MCIWNDF_NOPLAYBAR | WS_VISIBLE | WS_CHILD
		, L"../resource/video/heos.wmv");

	MoveWindow(m_hVideo, 0, 0, WINCX, WINCY, FALSE);

	// 동영상 재생
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
