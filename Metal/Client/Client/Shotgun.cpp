#include "stdafx.h"
#include "Shotgun.h"

CShotgun::CShotgun()
{
}

CShotgun::~CShotgun()
{
}

void CShotgun::Init()
{
    char buf[256] = "";

    sprintf_s(buf, "%s%s", IMG_PATH, "sfx/shotgun/");
    IMG_LOAD(L"sfx/shotgun/", buf);
    m_image.insert(pair<const TCHAR*, vector<ObjImg*>*>(L"sfx/shotgun/", IMG_GET_V(L"sfx/shotgun/")));

    sprintf_s(buf, "%s%s", IMG_PATH, "sfx/shotgun_left/");
    IMG_LOAD(L"sfx/shotgun_left/", buf);
    m_image.insert(pair<const TCHAR*, vector<ObjImg*>*>(L"sfx/shotgun_left/", IMG_GET_V(L"sfx/shotgun_left/")));

    if (OBJ_MGR_GETLIST(OBJ_PLAYER).back()->GetInfo().direction == OBJ_D_RIGH)
    {
        img_begin = m_image.find(L"sfx/shotgun/")->second->begin();
        img_end = m_image.find(L"sfx/shotgun/")->second->end();
        m_tInfo.fX += 55.f;
    }
    else if (OBJ_MGR_GETLIST(OBJ_PLAYER).back()->GetInfo().direction == OBJ_D_LEFT)
    {
        img_begin = m_image.find(L"sfx/shotgun_left/")->second->begin();
        img_end = m_image.find(L"sfx/shotgun_left/")->second->end();
        m_tInfo.fX -= (*img_begin)->image->GetWidth() - 10.f;
    }

    m_tInfo.fCX = (*img_begin)->image->GetWidth();
    m_tInfo.fCY = (*img_begin)->image->GetHeight();
    m_tInfo.iAtt = 10;
}

void CShotgun::Release()
{
}

void CShotgun::Render(HDC hdc)
{
    IMG_DRAW_I(hdc
        , (*img_begin)->image
        , FLOAT(m_tInfo.fX - (*img_begin)->image->GetWidth() / 2.f)
        , FLOAT(m_tInfo.fY - (*img_begin)->image->GetHeight() / 2.f)
        , FLOAT((*img_begin)->image->GetWidth())//m_pObj->GetInfo().rect.right
        , FLOAT((*img_begin)->image->GetHeight())//m_pObj->GetInfo().rect.bottom
    );

    ++img_begin;
    if (img_begin == img_end)
    {
        end = 1;
    }

    //Rectangle(hdc
    //    , m_tInfo.rect.left
    //    , m_tInfo.rect.top
    //    , m_tInfo.rect.right
    //    , m_tInfo.rect.bottom
    //);
}

int CShotgun::Update()
{
    if (end)
        return 1;

    if (isDead())
        SetDead(false);
    m_tInfo.rect.left = m_tInfo.fX - (*img_begin)->image->GetWidth() / 2.f;
    m_tInfo.rect.top = m_tInfo.fY - (*img_begin)->image->GetHeight() / 2.f;
    m_tInfo.rect.right = m_tInfo.rect.left + m_tInfo.fCX;
    m_tInfo.rect.bottom =  m_tInfo.rect.top + m_tInfo.fCY;

    return 0;
}
