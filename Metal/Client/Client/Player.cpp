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
        tempState = MAKE_STATE(OBJ_PLAYER, CStBodyR, imgVec);
        m_scBody.AddState(L"st_body_r", tempState);

        imgVec = IMG_GET_V(L"fio/stand_l");
        InsertImage(L"fio/stand_l", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CStBodyL, imgVec);
        m_scBody.AddState(L"st_body_l", tempState);

        imgVec = IMG_GET_V(L"fio/stand_leg");
        InsertImage(L"fio/stand_leg", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CStdLeg, imgVec);
        m_scLeg.AddState(L"std_leg", tempState);
    }

    // 나중에 Abstract Factory로 바꿔야함
    
    m_scBody.SetState(L"st_body_r");
    m_scLeg.SetState(L"std_leg");

    // value setting
    m_tInfo.fJumpPow = 15.f;
    m_tInfo.fJumpAcc = 0.f;
    m_tInfo.fSpeed = 5.f;

    SetCXY();
}

void CPlayer::Release()
{
}

void CPlayer::Render(HDC hdc)
{
    CObj::Update();
    //Rectangle(hdc, m_tInfo.rect.left, m_tInfo.rect.top, m_tInfo.rect.right, m_tInfo.rect.bottom);

    /*POINT pt{};
    
    float fx = CScrollMgr::GetInstance()->GetScrollX();
    GetCursorPos(&pt);
    ScreenToClient(g_hWnd, &pt);
    pt.x += fx;
    pt.x *= 1.92f;
    pt.y *= 1.92f;

    Ellipse(hdc, pt.x - 5.f, pt.y - 5.f, pt.x + 5.f, pt.y + 5.f);*/

    wchar_t         pos[64];
    swprintf_s(pos, L"X:%.2f Y:%.2f", m_tInfo.fX, m_tInfo.fY);
    //wsprintf();
    SetTextAlign(hdc, TA_CENTER);
    SetBkMode(hdc, TRANSPARENT);
    TextOut(hdc, m_tInfo.fX, m_tInfo.fY - 30, pos, wcslen(pos));

    m_scLeg.request(hdc);
    m_scBody.request(hdc);    
}   

int CPlayer::Update()
{
    KeyInput();
    CObj::Update();
    IsJump();
    IsCollisionLine();

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
    m_tInfo.curState = m_tInfo.preState;
    isKeyInput = false;
    if (KEY_PRESSING(VK_RIGHT))
    {
        if (m_tInfo.direction & OBJ_D_LEFT)
        {
            m_tInfo.fSpeed  = 0.f;
            m_tInfo.fAcc    = 0.f;
        }
                
        m_tInfo.curState |= OBJ_A_MOVE;
        m_tInfo.direction = OBJ_D_RIGH;

        if (m_tInfo.fAcc < 5.f)
        {
            m_tInfo.fAcc += 0.1f;
        }

        if (m_tInfo.fSpeed < 5.f)
            m_tInfo.fSpeed += m_tInfo.fAcc;

        isKeyInput = true;
    }

    if (KEY_PRESSING(VK_LEFT))
    {
        if (m_tInfo.direction & OBJ_D_RIGH)
        {
            m_tInfo.fSpeed  = 0.f;
            m_tInfo.fAcc    = 0.f;
        }
        m_tInfo.curState |= OBJ_A_MOVE;
        m_tInfo.direction = OBJ_D_LEFT;

        if (m_tInfo.fAcc < 5.f)
        {
            m_tInfo.fAcc += 0.1f;
        }

        if (m_tInfo.fSpeed < 5.f)
            m_tInfo.fSpeed += m_tInfo.fAcc;

        isKeyInput = true;
    }

    if (KEY_PRESSING(VK_UP))
    {
        m_tInfo.direction = OBJ_D_TOPP;
        isKeyInput = true;
    }

    if (KEY_PRESSING(VK_DOWN))
    {
        m_tInfo.direction = OBJ_D_BOTT;
        isKeyInput = true;
    }

    if (KEY_PRESSING(VK_SPACE))
    {
        isKeyInput = true;
    }

    if (KEY_PRESSING(VK_LCONTROL))
    {
        m_tInfo.curState |= OBJ_A_JUMP;
        isKeyInput = true;
    }

    if (KEY_PRESSING(VK_LSHIFT))
    {
        isKeyInput = true;
    }

    if (!isKeyInput)
    {
        if ( 0.f <= m_tInfo.fAcc)
        {
            m_tInfo.fAcc -= 1.1f;
        }
        if (m_tInfo.fAcc <= 0.f)
        {
            m_tInfo.fAcc = 0.f;
            m_tInfo.fSpeed = 0.f;
            m_tInfo.curState |= OBJ_A_STND;
        }
    }
    // Accel
    if (m_tInfo.curState & OBJ_A_MOVE)
    {
        m_tInfo.fAcc += 0.1f;
    }

    if (m_tInfo.direction & OBJ_D_RIGH)
    {
        m_tInfo.fX += m_tInfo.fSpeed;
    }

    if (m_tInfo.direction & OBJ_D_LEFT)
    {
        m_tInfo.fX -= m_tInfo.fSpeed;
    }

    if (m_tInfo.direction & OBJ_D_TOPP)
    {
        //m_tInfo.fAcc += 0.1f;
    }

    if (m_tInfo.direction & OBJ_D_BOTT)
    {
        //m_tInfo.fAcc += 0.1f;
    }

    m_tInfo.preState = m_tInfo.curState;
}

void CPlayer::IsJump()
{
    if (m_tInfo.preState & OBJ_A_JUMP)
    {
        m_tInfo.fJumpAcc += 0.3f;

        m_tInfo.fY -= m_tInfo.fJumpPow * m_tInfo.fJumpAcc - GRAVITY * m_tInfo.fJumpAcc * m_tInfo.fJumpAcc * 0.5f;
    }
}

void CPlayer::IsCollisionLine()
{
    float fy = m_tInfo.fY;

    if (CLineMgr::GetInstance()->CollisionLine(m_tInfo.fX, &fy))
    {
        if(!(m_tInfo.preState & OBJ_A_JUMP))
            m_tInfo.fY = fy - m_tInfo.fCY / 2;

        if (m_tInfo.fY >= fy - m_tInfo.fCY / 2) // 점프 중에 라인에 도달하면 라인을 타고
		{
			m_tInfo.fY = fy - m_tInfo.fCY / 2;
			m_tInfo.fJumpAcc = 0.f;
			m_tInfo.preState = OBJ_A_STND;
		}
    }
}
