#include "stdafx.h"
#include "player.h"


player::player()
{   
}


player::~player()
{
}

void player::Initialize()
{
    m_objInfo.fX = 0;
    m_objInfo.fY = 0;
    m_objInfo.fCX = 50;
    m_objInfo.fCY = 50;
    m_objInfo.setSpeed(10);
    m_objInfo.makeRect();
}

void player::Initialize(OBJINFO& ref)
{
    m_objInfo = ref;
    m_iState_body = PS_BODY_IDLE;
    m_iState_leg = PS_LEG_STANDING;
    isDEBUG = false;
}

void player::Render(HDC hdc)
{
    if (isDEBUG)
    {
        Rectangle(hdc
        , m_objInfo.rect.left
        , m_objInfo.rect.top
        , m_objInfo.rect.right
        , m_objInfo.rect.bottom);

        wchar_t buf[64];
        swprintf_s(buf, L"X:%.2f Y:%.2f", m_objInfo.fX, m_objInfo.fY);
        TextOut(hdc, m_objInfo.fX, m_objInfo.fY, buf, wcslen(buf));
    }    
    switch (m_iState_leg)
    {
    case PS_LEG_STANDING:
        m_state_leg.request(hdc);
        break;
    }
    switch (m_iState_body)
    {
    case PS_BODY_IDLE:
        // body, leg
        m_state_body.request(hdc);
        break;
    }

    
    
}

void player::Release()
{
}

int player::Update()
{
    Object::Update();
    
    if (GetAsyncKeyState(VK_LEFT)   & 0x8000)
    {
        m_objInfo.fX -= m_objInfo.speed;
    }		
    if (GetAsyncKeyState(VK_RIGHT)  & 0x8000)
    {
        m_objInfo.fX += m_objInfo.speed;
    }		
    if (GetAsyncKeyState(VK_UP)     & 0x8000)
    {
        m_objInfo.fY -= m_objInfo.speed;
    }		
    if (GetAsyncKeyState(VK_DOWN)   & 0x8000)
    {
        m_objInfo.fY += m_objInfo.speed;
    }
    if (GetAsyncKeyState(VK_LSHIFT)   & 0x8000)
    {
        isDEBUG = true;
    }
    else
    {
        isDEBUG = false;
    }
    return 0;
}

