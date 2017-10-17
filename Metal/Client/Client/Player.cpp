#include "stdafx.h"
#include "Player.h"
#include "Obj.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::Init()
{
    if (m_image.empty())
    {
        vector<ObjImg*>* imgVec = nullptr;

        imgVec = IMG_GET_V(L"fio/stand_r");
        InsertImage(L"fio/stand_r", imgVec);

        imgVec = IMG_GET_V(L"fio/stand_l");
        InsertImage(L"fio/stand_l", imgVec);

        imgVec = IMG_GET_V(L"fio/stand_leg");
        InsertImage(L"fio/stand_leg", imgVec);
    }
}

void CPlayer::Release()
{
}

void CPlayer::Render(HDC hdc)
{
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
