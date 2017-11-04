#include "stdafx.h"
#include "UI.h"
#include "Player.h"

CUI::CUI()
{
}

CUI::~CUI()
{
}

void CUI::Init()
{
    char buf[256] = "";
    sprintf_s(buf, "%s%s", IMG_PATH, "hud/ui/");
    IMG_LOAD(L"hud/ui/", buf);
    m_image.insert(pair<const TCHAR*, vector<ObjImg*>*>(L"hud/ui/", IMG_GET_V(L"hud/ui/")));

    sprintf_s(buf, "%s%s", IMG_PATH, "hud/character/");
    IMG_LOAD(L"hud/character/", buf);
    m_image.insert(pair<const TCHAR*, vector<ObjImg*>*>(L"hud/character/", IMG_GET_V(L"hud/character/")));

    sprintf_s(buf, "%s%s", IMG_PATH, "hud/number/");
    IMG_LOAD(L"hud/number/", buf);
    m_image.insert(pair<const TCHAR*, vector<ObjImg*>*>(L"hud/number/", IMG_GET_V(L"hud/number/")));

    gun_begin   = m_image.find(L"hud/ui/")->second->begin();
    gun_end     = m_image.find(L"hud/ui/")->second->end();

    point_begin = m_image.find(L"hud/number/")->second->begin();
    point_end   = m_image.find(L"hud/number/")->second->end();

    cha_begin = m_image.find(L"hud/character/")->second->begin();
    cha_end   = m_image.find(L"hud/character/")->second->end();
}

void CUI::Release()
{
}

void CUI::Render(HDC hdc)
{
    // Player info
    float fScollX = CScrollMgr::GetInstance()->GetScrollX();

    CObj* player = OBJ_MGR_GETLIST(OBJ_PLAYER).back();

    infoDraw(hdc, (player->GetInfo().point), (5.f - fScollX), 2.f, 8.f, 8.f);
    UserLife(hdc);
    UserGunBomb(hdc);
    // gun
    IMG_DRAW_I(
        hdc
        , (*gun_begin)->image
        , 50.f - fScollX, 0.f
        , (*gun_begin)->image->GetWidth() * 0.9f
        , (*gun_begin)->image->GetHeight() * 0.9f
    );
}

int CUI::Update()
{
    return 0;
}//

void CUI::UserLife(HDC hdc)
{
    CObj* player = OBJ_MGR_GETLIST(OBJ_PLAYER).back();
    float fScollX = CScrollMgr::GetInstance()->GetScrollX();
    IMG_DRAW_I(hdc, (*(point_begin + 1))->image, 5.f - fScollX, 11.f, 8.f, 8.f);
    IMG_DRAW_I(hdc, (*(cha_begin + 2))->image, 13.f - fScollX, 11.f, 8.f, 8.f);
    IMG_DRAW_I(hdc, (*(cha_begin + 1))->image, 21.f - fScollX, 11.f, 8.f, 8.f);
    IMG_DRAW_I(hdc, (*(cha_begin + 0))->image, 29.f - fScollX, 11.f, 8.f, 8.f);

    infoDraw(hdc, dynamic_cast<CPlayer*>(player)->life, (40.f - fScollX), 11.f, 8.f, 8.f);
}

void CUI::UserGunBomb(HDC hdc)
{
    float fScollX = CScrollMgr::GetInstance()->GetScrollX();

    CObj* player = OBJ_MGR_GETLIST(OBJ_PLAYER).back();
    if (dynamic_cast<CPlayer*>(player)->reloadCnt == 0)
    {
        IMG_DRAW_I(hdc, (*(cha_end - 1))->image, (58.f - fScollX), 19.f, 22.f, 10.f);
    }
    else
    {
        infoDraw(hdc, dynamic_cast<CPlayer*>(player)->reloadCnt, (65.f - fScollX), 19.f, 8.f, 8.f);
    }
    infoDraw(hdc, dynamic_cast<CPlayer*>(player)->bombCnt, (95.f - fScollX), 19.f, 8.f, 8.f);
}

void CUI::infoDraw(HDC hdc, INT point, float fx, float fy, float fcx, float fcy)
{ 
    char buf[256] = "";
    sprintf_s(buf, "%d", point);

    for (size_t i = 0; i < sizeof(buf); ++i)
    {
        if (buf[i] == '0')
        {
            IMG_DRAW_I(hdc, (*(point_begin + 0))->image, fx + (i * fcx), fy, fcx, fcy);
        }
        else if (buf[i] == '1')
        {
            IMG_DRAW_I(hdc, (*(point_begin + 1))->image, fx + (i * fcx), fy, fcx, fcy);
        }
        else if (buf[i] == '2')
        {
            IMG_DRAW_I(hdc, (*(point_begin + 2))->image, fx + (i * fcx), fy, fcx, fcy);
        }
        else if (buf[i] == '3')
        {
            IMG_DRAW_I(hdc, (*(point_begin + 3))->image, fx + (i * fcx), fy, fcx, fcy);
        }
        else if (buf[i] == '4')
        {
            IMG_DRAW_I(hdc, (*(point_begin + 4))->image, fx + (i * fcx), fy, fcx, fcy);
        }
        else if (buf[i] == '5')
        {
            IMG_DRAW_I(hdc, (*(point_begin + 5))->image, fx + (i * fcx), fy, fcx, fcy);
        }
        else if (buf[i] == '6')
        {
            IMG_DRAW_I(hdc, (*(point_begin + 6))->image, fx + (i * fcx), fy, fcx, fcy);
        }
        else if (buf[i] == '7')
        {
            IMG_DRAW_I(hdc, (*(point_begin + 7))->image, fx + (i * fcx), fy, fcx, fcy);
        }
        else if (buf[i] == '8')
        {
            IMG_DRAW_I(hdc, (*(point_begin + 8))->image, fx + (i * fcx), fy, fcx, fcy);
        }
        else if (buf[i] == '9')
        {
            IMG_DRAW_I(hdc, (*(point_begin + 9))->image, fx + (i * fcx), fy, fcx, fcy);
        }
    }
}