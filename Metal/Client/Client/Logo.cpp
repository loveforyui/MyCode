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
    CImageMgr::GetInst()->LoadImgFile(L"Logo", IMG_PATH);
    m_vImage = IMG_GET_V(L"Logo");
}

void CLogo::Update()
{
	if (KEY_DOWN(VK_RETURN))
		CSceneMgr::GetInstance()->SceneChange(CSceneMgr::MENU);
}

void CLogo::Render(HDC hDC)
{
    float fScrollX = CScrollMgr::GetInstance()->GetScrollX();
    for (vector<ObjImg*>::iterator iter = m_vImage->begin()
        ; iter != m_vImage->end(); ++iter)
    {
        IMG_DRAW_I(
        hDC
        , (*iter)->image
        , fScrollX, 0
        , (*iter)->image->GetWidth()
        , (*iter)->image->GetHeight());
        
    }
}

void CLogo::Release()
{
}
