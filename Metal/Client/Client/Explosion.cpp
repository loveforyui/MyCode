#include "stdafx.h"
#include "Explosion.h"

CExplosion::CExplosion()
{
}

CExplosion::~CExplosion()
{
}

void CExplosion::Init()
{
    char buf[256] = "";

    sprintf_s(buf, "%s%s", IMG_PATH, "sfx/explosion/");
    IMG_LOAD(L"sfx/explosion/", buf);
    m_image.insert(pair<const TCHAR*, vector<ObjImg*>*>(L"sfx/explosion/", IMG_GET_V(L"sfx/explosion/")));

    img_begin = m_image.find(L"sfx/explosion/")->second->begin();
    img_end = m_image.find(L"sfx/explosion/")->second->end();
}

void CExplosion::Release()
{
}

void CExplosion::Render(HDC hdc)
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
        m_tInfo.isDead = true;
    }
}

int CExplosion::Update()
{
    if (isDead())
        return 1;
    return 0;
}
