#include "stdafx.h"
#include "Load.h"

CLoad::CLoad()
{
}

CLoad::~CLoad()
{
}

void CLoad::Initialize()
{
    // MCI (Media Control Interface)
	// 미디어 재생을 위한 인터페이스를 제공한다.
	m_hVideo = MCIWndCreate(g_hWnd, 0, MCIWNDF_NOPLAYBAR | WS_VISIBLE | WS_CHILD
		, L"../resource/video/load.wmv");

	MoveWindow(m_hVideo, 0, 0, WINCX, WINCY, FALSE);

	// 동영상 재생
	MCIWndPlay(m_hVideo);
}

void CLoad::Update()
{
    if (KEY_DOWN(VK_RETURN))
    {
        MCIWndStop(m_hVideo);
        MCIWndClose(m_hVideo);
		CSceneMgr::GetInstance()->SceneChange(CSceneMgr::SELEC);
    }
}

void CLoad::Render(HDC hDC)
{
}

void CLoad::Release()
{
    MCIWndClose(m_hVideo);
}
