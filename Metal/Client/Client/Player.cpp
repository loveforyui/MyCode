#include "stdafx.h"
#include "Player.h"
#include "Obj.h"
#include "States.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::Init()
{
    // player image setting
    if (m_image.empty())
    {
        vector<ObjImg*>* imgVec = nullptr;
        CStateManager* tempState = nullptr;

        imgVec = IMG_GET_V(L"fio/stand_r");
        InsertImage(L"fio/stand_r", imgVec);        
        tempState = MAKE_STATE(OBJ_PLAYER, imgVec);
        m_state.AddState(L"st_body_r", tempState);

        imgVec = IMG_GET_V(L"fio/stand_l");
        InsertImage(L"fio/stand_l", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, imgVec);
        m_state.AddState(L"st_body_l", tempState);

        imgVec = IMG_GET_V(L"fio/stand_leg");
        InsertImage(L"fio/stand_leg", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, imgVec);
        m_state.AddState(L"std_leg", tempState);
    }
    // 나중에 Abstract Factory로 바꿔야함
    
    m_state.SetState(L"st_body_r");

    SetCXY();
}

void CPlayer::Release()
{
}

void CPlayer::Render(HDC hdc)
{
    CObj::Update();
    Rectangle(hdc, m_tInfo.rect.left, m_tInfo.rect.top, m_tInfo.rect.right, m_tInfo.rect.bottom);

    wchar_t         pos[64];
    swprintf_s(pos, L"X:%.2f Y:%.2f", m_tInfo.fX, m_tInfo.fY);
    //wsprintf();
    SetTextAlign(hdc, TA_CENTER);
    SetBkMode(hdc, TRANSPARENT);
    TextOut(hdc, m_tInfo.fX, m_tInfo.fY - 30, pos, wcslen(pos));

    m_state.request(hdc);
}   

int CPlayer::Update()
{
    CObj::Update();
    KeyInput();
    return 0;
}

void CPlayer::InsertImage(const TCHAR * key, vector<ObjImg*>* vImg)
{
    m_image.insert(pair<const TCHAR*, vector<ObjImg*>*>(key, vImg));
}

void CPlayer::SetCXY()
{
    m_tInfo.fCX = (*(m_image.begin()->second->begin()))->image->GetWidth();
    m_tInfo.fCY = (*(m_image.begin()->second->begin()))->image->GetHeight();

}

void CPlayer::KeyInput()
{
    if (KEY_PRESSING(VK_RIGHT))
    {

    }
    if (KEY_PRESSING(VK_LEFT))
    {

    }
    if (KEY_PRESSING(VK_UP))
    {

    }
    if (KEY_PRESSING(VK_DOWN))
    {

    }
    if (KEY_PRESSING(VK_SPACE))
    {

    }
    if (KEY_PRESSING(VK_LCONTROL))
    {

    }
    if (KEY_PRESSING(VK_LSHIFT))
    {

    }
}
