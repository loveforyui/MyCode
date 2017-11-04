#include "stdafx.h"
#include "Logo.h"

CLogo::CLogo()
{
}


CLogo::~CLogo()
{
	Release();
}

void CLogo::Initialize()
{
    char buf[256] = "";
    strcpy_s(buf, IMG_PATH);
    strcat_s(buf, "Logo/");
    IMG_LOAD(L"Logo/", buf);
    m_vImage = IMG_GET_V(L"Logo/");
}

void CLogo::Update()
{
	if (KEY_DOWN(VK_RETURN))
		CSceneMgr::GetInstance()->SceneChange(CSceneMgr::LOAD);
}

void CLogo::Render(HDC hDC)
{
    HDC hdc = GetDC(g_hWnd);
    float fScrollX = CScrollMgr::GetInstance()->GetScrollX();
    UINT img_w = 0;
    UINT img_h = 0;

    for (vector<ObjImg*>::iterator iter = m_vImage->begin()
        ; iter != m_vImage->end(); ++iter)
    {
        img_w = (*iter)->image->GetWidth();
        img_h = (*iter)->image->GetHeight();
        IMG_DRAW_I(
            hdc
            , (*iter)->image
            , WINCX/2.f - img_w/2.f
            , WINCY/2.f - img_h/2.f
            , FLOAT(img_w)
            , FLOAT(img_h)
        );

    }

    //StretchBlt(hDC, WINCX/2.f - img_w/2.f, WINCY/2.f - img_h/2.f, WINCX, WINCY, hdc, 0, 0, img_w, img_h, SRCCOPY);
    //BitBlt(hdc, INT(fScrollX), 0, WINCX, WINCY, hDC, 0, -100, SRCCOPY);
    ReleaseDC(g_hWnd, hdc);
}

void CLogo::Release()
{
}
