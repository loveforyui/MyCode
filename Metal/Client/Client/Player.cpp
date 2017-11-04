#include "stdafx.h"
#include "Player.h"
#include "Obj.h"
#include "States.h"
#include "Bullet.h"
#include "Monster.h"
#include "Bomb.h"

CPlayer::CPlayer()
{
    m_tInfo.fCannonD = 30.f;
}

CPlayer::       ~CPlayer()
{
}

void CPlayer::Init()
{
    // Set Time
    m_tInfo.preState = OBJ_A_JUMP;

    m_tInfo.fCX = 15.f;
    m_tInfo.fCY = 15.f;

    m_tInfo.point = 0;

    m_dwOldt = GetTickCount();
    m_dwCurt = 0;

    char buf[256] = "";

    sprintf_s(buf, "%s%s", IMG_PATH, "sfx/bomb/");
    IMG_LOAD(L"sfx/bomb/", buf);
    m_vBombimg = IMG_GET_V(L"sfx/bomb/");

    //body
    sprintf_s(buf, "%s%s", IMG_PATH, "fio/st/body/");
    IMG_LOAD(L"fio/st/body/", buf);
    sprintf_s(buf, "%s%s", IMG_PATH, "fio/st/body_left/");
    IMG_LOAD(L"fio/st/body_left/", buf);
    sprintf_s(buf, "%s%s", IMG_PATH, "fio/walking/body/");
    IMG_LOAD(L"fio/walking/body/", buf);
    sprintf_s(buf, "%s%s", IMG_PATH, "fio/walking/body_left/");
    IMG_LOAD(L"fio/walking/body_left/", buf);
    sprintf_s(buf, "%s%s", IMG_PATH, "fio/jump/jmp_body/");
    IMG_LOAD(L"fio/jump/jmp_body/", buf);
    sprintf_s(buf, "%s%s", IMG_PATH, "fio/jump/jmp_body_left/");
    IMG_LOAD(L"fio/jump/jmp_body_left/", buf);
    sprintf_s(buf, "%s%s", IMG_PATH, "fio/st/up_body/");
    IMG_LOAD(L"fio/st/up_body/", buf);
    sprintf_s(buf, "%s%s", IMG_PATH, "fio/st/up_body_left/");
    IMG_LOAD(L"fio/st/up_body_left/", buf);
    // body - atk
    sprintf_s(buf, "%s%s", IMG_PATH, "fio/baseatk/st_atk/");
    IMG_LOAD(L"fio/baseatk/st_atk/", buf);
    sprintf_s(buf, "%s%s", IMG_PATH, "fio/baseatk/st_atk_left/");
    IMG_LOAD(L"fio/baseatk/st_atk_left/", buf);
    sprintf_s(buf, "%s%s", IMG_PATH, "fio/baseatk/up_atk/");
    IMG_LOAD(L"fio/baseatk/up_atk/", buf);
    sprintf_s(buf, "%s%s", IMG_PATH, "fio/baseatk/up_atk_left/");
    IMG_LOAD(L"fio/baseatk/up_atk_left/", buf);
    sprintf_s(buf, "%s%s", IMG_PATH, "fio/st/b_body/");
    IMG_LOAD(L"fio/st/b_body/", buf);
    sprintf_s(buf, "%s%s", IMG_PATH, "fio/st/b_body_left/");
    IMG_LOAD(L"fio/st/b_body_left/", buf);

    //leg
    sprintf_s(buf, "%s%s", IMG_PATH, "fio/walking/leg/");
    IMG_LOAD(L"fio/walking/leg/", buf);
    sprintf_s(buf, "%s%s", IMG_PATH, "fio/walking/leg_left/");
    IMG_LOAD(L"fio/walking/leg_left/", buf);
    sprintf_s(buf, "%s%s", IMG_PATH, "fio/st/leg/");
    IMG_LOAD(L"fio/st/leg/", buf);
    sprintf_s(buf, "%s%s", IMG_PATH, "fio/st/leg_left/");
    IMG_LOAD(L"fio/st/leg_left/", buf);
    sprintf_s(buf, "%s%s", IMG_PATH, "fio/jump/jmp_leg/");
    IMG_LOAD(L"fio/jump/jmp_leg/", buf);
    sprintf_s(buf, "%s%s", IMG_PATH, "fio/jump/jmp_leg_left/");
    IMG_LOAD(L"fio/jump/jmp_leg_left/", buf);

    //down
    sprintf_s(buf, "%s%s", IMG_PATH, "fio/down/sitdown/");
    IMG_LOAD(L"fio/down/sitdown/", buf);
    sprintf_s(buf, "%s%s", IMG_PATH, "fio/down/sitdown_left/");
    IMG_LOAD(L"fio/down/sitdown_left/", buf);
    sprintf_s(buf, "%s%s", IMG_PATH, "fio/down/sd_move/");
    IMG_LOAD(L"fio/down/sd_move/", buf);
    sprintf_s(buf, "%s%s", IMG_PATH, "fio/down/sd_move_left/");
    IMG_LOAD(L"fio/down/sd_move_left/", buf);
    sprintf_s(buf, "%s%s", IMG_PATH, "fio/down/atkr/");
    IMG_LOAD(L"fio/down/atkr/", buf);
    sprintf_s(buf, "%s%s", IMG_PATH, "fio/down/atkl/");
    IMG_LOAD(L"fio/down/atkl/", buf);

    //die
    sprintf_s(buf, "%s%s", IMG_PATH, "fio/die/");
    IMG_LOAD(L"fio/die/", buf);

    if (m_image.empty())
    {
        vector<ObjImg*>* imgVec = nullptr;
        CStateManager* tempState = nullptr;

        // body
        imgVec = IMG_GET_V(L"fio/st/body/");
        InsertImage(L"fio/st/body/", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CStBodyR, imgVec);
        m_scBody.AddState(L"fio/st/body/", tempState);

        imgVec = IMG_GET_V(L"fio/st/body_left/");
        InsertImage(L"fio/st/body_left/", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CStBodyL, imgVec);
        m_scBody.AddState(L"fio/st/body_left/", tempState);

        imgVec = IMG_GET_V(L"fio/walking/body/");
        InsertImage(L"fio/walking/body/", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CStWalkBodyR, imgVec);
        m_scBody.AddState(L"fio/walking/body/", tempState);

        imgVec = IMG_GET_V(L"fio/walking/body_left/");
        InsertImage(L"fio/walking/body_left/", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CStWalkBodyL, imgVec);
        m_scBody.AddState(L"fio/walking/body_left/", tempState);

        imgVec = IMG_GET_V(L"fio/jump/jmp_body/");
        InsertImage(L"fio/jump/jmp_body/", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CJmpBodyR, imgVec);
        m_scBody.AddState(L"fio/jump/jmp_body/", tempState);

        imgVec = IMG_GET_V(L"fio/jump/jmp_body_left/");
        InsertImage(L"fio/jump/jmp_body_left/", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CJmpBodyL, imgVec);
        m_scBody.AddState(L"fio/jump/jmp_body_left/", tempState);

        imgVec = IMG_GET_V(L"fio/st/up_body/");
        InsertImage(L"fio/st/up_body/", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CStUpBodyR, imgVec);
        m_scBody.AddState(L"fio/st/up_body/", tempState);

        imgVec = IMG_GET_V(L"fio/st/up_body_left/");
        InsertImage(L"fio/st/up_body_left/", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CStUpBodyL, imgVec);
        m_scBody.AddState(L"fio/st/up_body_left/", tempState);

        //body - atk
        imgVec = IMG_GET_V(L"fio/baseatk/st_atk/");
        InsertImage(L"fio/baseatk/st_atk/", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CStAtkBodyR, imgVec);
        m_scBody.AddState(L"fio/baseatk/st_atk/", tempState);

        imgVec = IMG_GET_V(L"fio/baseatk/st_atk_left/");
        InsertImage(L"fio/baseatk/st_atk_left/", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CStAtkBodyL, imgVec);
        m_scBody.AddState(L"fio/baseatk/st_atk_left/", tempState);

        imgVec = IMG_GET_V(L"fio/baseatk/up_atk/");
        InsertImage(L"fio/baseatk/up_atk/", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CStUpAtkBodyR, imgVec);
        m_scBody.AddState(L"fio/baseatk/up_atk/", tempState);

        imgVec = IMG_GET_V(L"fio/baseatk/up_atk_left/");
        InsertImage(L"fio/baseatk/up_atk_left/", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CStUpAtkBodyL, imgVec);
        m_scBody.AddState(L"fio/baseatk/up_atk_left/", tempState);

        imgVec = IMG_GET_V(L"fio/st/b_body/");
        InsertImage(L"fio/st/b_body/", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CBombBodyR, imgVec);
        m_scBody.AddState(L"fio/st/b_body/", tempState);

        imgVec = IMG_GET_V(L"fio/st/b_body_left/");
        InsertImage(L"fio/st/b_body_left/", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CBombBodyL, imgVec);
        m_scBody.AddState(L"fio/st/b_body_left/", tempState);

        //leg
        imgVec = IMG_GET_V(L"fio/st/leg/");
        InsertImage(L"fio/st/leg/", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CStdLeg, imgVec);
        m_scLeg.AddState(L"fio/st/leg/", tempState);

        imgVec = IMG_GET_V(L"fio/st/leg_left/");
        InsertImage(L"fio/st/leg_left/", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CStdLegLeft, imgVec);
        m_scLeg.AddState(L"fio/st/leg_left/", tempState);

        imgVec = IMG_GET_V(L"fio/walking/leg/");
        InsertImage(L"fio/walking/leg/", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CStWalkLegR, imgVec);
        m_scLeg.AddState(L"fio/walking/leg/", tempState);

        imgVec = IMG_GET_V(L"fio/walking/leg_left/");
        InsertImage(L"fio/walking/leg_left/", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CStWalkLegL, imgVec);
        m_scLeg.AddState(L"fio/walking/leg_left/", tempState);

        imgVec = IMG_GET_V(L"fio/jump/jmp_leg/");
        InsertImage(L"fio/jump/jmp_leg/", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CJmpLegR, imgVec);
        m_scLeg.AddState(L"fio/jump/jmp_leg/", tempState);

        imgVec = IMG_GET_V(L"fio/jump/jmp_leg_left/");
        InsertImage(L"fio/jump/jmp_leg_left/", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CJmpLegL, imgVec);
        m_scLeg.AddState(L"fio/jump/jmp_leg_left/", tempState);

        //down
        imgVec = IMG_GET_V(L"fio/down/sitdown/");
        InsertImage(L"fio/down/sitdown/", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CSitdown, imgVec);
        m_scLeg.AddState(L"fio/down/sitdown/", tempState);

        imgVec = IMG_GET_V(L"fio/down/sitdown_left/");
        InsertImage(L"fio/down/sitdown_left/", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CSitdownL, imgVec);
        m_scLeg.AddState(L"fio/down/sitdown_left/", tempState);

        imgVec = IMG_GET_V(L"fio/down/sd_move/");
        InsertImage(L"fio/down/sd_move/", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CSitdownMoveR, imgVec);
        m_scLeg.AddState(L"fio/down/sd_move/", tempState);

        imgVec = IMG_GET_V(L"fio/down/sd_move_left/");
        InsertImage(L"fio/down/sd_move_left/", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CSitdownMoveL, imgVec);
        m_scLeg.AddState(L"fio/down/sd_move_left/", tempState);

        imgVec = IMG_GET_V(L"fio/down/atkr/");
        InsertImage(L"fio/down/atkr/", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CSitdownAtk, imgVec);
        m_scLeg.AddState(L"fio/down/atkr/", tempState);

        imgVec = IMG_GET_V(L"fio/down/atkl/");
        InsertImage(L"fio/down/atkl/", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CSitdownAtkL, imgVec);
        m_scLeg.AddState(L"fio/down/atkl/", tempState);

        //die
        imgVec = IMG_GET_V(L"fio/die/");
        InsertImage(L"fio/die/", imgVec);
        tempState = MAKE_STATE(OBJ_PLAYER, CStdDie, imgVec);
        m_scLeg.AddState(L"fio/die/", tempState);
    }

    // 나중에 Abstract Factory로 바꿔야함

    m_scBody.SetState(L"fio/st/body/");
    m_scLeg.SetState(L"fio/st/leg/");

    // value setting
    m_tInfo.fJumpPow = 15.f;
    m_tInfo.fJumpAcc = 0.f;
    m_tInfo.fSpeed = 15.f;

    SetCXY();
}

void CPlayer::Release()
{
}

void CPlayer::Render(HDC hdc)
{
    CObj::Update();

    /*wchar_t         pos[64];
    swprintf_s(pos, L"X:%.1f Y:%.1f A:%.1f", m_tInfo.fX, m_tInfo.fY, m_tInfo.fAngle);
    SetTextAlign(hdc, TA_LEFT);
    SetBkMode(hdc, TRANSPARENT);
    TextOut(hdc, m_tInfo.fX, m_tInfo.fY - 30, pos, wcslen(pos));*/

    //Rectangle(hdc, m_tInfo.rect.left, m_tInfo.rect.top, m_tInfo.rect.right, m_tInfo.rect.bottom);
    if (STATE_SAME(m_tInfo.curState, OBJ_A_DIE))
    {
        m_scLeg.request(hdc);
    }
    else
    {
        if (!STATE_SAME(m_tInfo.preState, OBJ_A_SITD))
        {
            m_scLeg.request(hdc);
            m_scBody.request(hdc);
        }
        if (STATE_SAME(m_tInfo.preState, OBJ_A_SITD))
        {
            m_scLeg.request(hdc);
        }
    }

    //Rectangle(hdc, m_tInfo.fX - 5, m_tInfo.fY - 5, m_tInfo.fX + 5, m_tInfo.fY + 5);

    /*MoveToEx(hdc, m_tInfo.fX, m_tInfo.fY - 10, nullptr);
    LineTo(hdc, m_tInfo.fCannonX, m_tInfo.fCannonY);*/
}

int CPlayer::Update()
{
    KeyInput(); // 우선순위 0번
    GunState();
    IsJump();
    IsCollisionLine();
    CalcCannonPos();
    m_scBody.Update();
    m_scLeg.Update();

    if (isDead())
    {
        if (!STATE_SAME(m_tInfo.curState, OBJ_A_DIE))
        {
            m_tInfo.preState = OBJ_A_DIE;
            m_tInfo.curState = OBJ_A_DIE;
            if (0 != life)
            {
                --life;
            }
            CSoundMgr::GetInstance()->PlaySound(L"sula.wav", CSoundMgr::CHANNEL_PLAYER);
        }
        m_scLeg.SetState(L"fio/die/");
    }

    return 0;
}

void CPlayer::InsertImage(const TCHAR * key, vector<ObjImg*>* vImg)
{
    m_image.insert(pair<const TCHAR*, vector<ObjImg*>*>(key, vImg));
}

void CPlayer::SetCXY()
{
    m_tInfo.fCX = FLOAT((*(m_image.begin()->second->begin()))->image->GetWidth());
    m_tInfo.fCY = FLOAT((*(m_image.begin()->second->begin()))->image->GetHeight());
}

void CPlayer::KeyInput()
{
    switch (m_curGun)
    {
    case CPlayer::BASE:
    {
        BaseGunKeyInput();
    }
    break;
    case CPlayer::HEAVY:
        break;
    case CPlayer::GUN_END:
        break;
    default:
        break;
    }
}

void CPlayer::IsJump()
{
    if (m_tInfo.preState & OBJ_A_JUMP)
    {
        //m_tInfo.fJumpAcc += 0.3f;
        //m_tInfo.fY -= m_tInfo.fJumpPow * m_tInfo.fJumpAcc - GRAVITY * m_tInfo.fJumpAcc * m_tInfo.fJumpAcc * 0.5f;

        //FLOAT y = m_tInfo.fY;
        m_tInfo.fJumpAcc -= 0.1592f*GRAVITY;

        m_tInfo.fY -= m_tInfo.fJumpAcc;
    }
}

void CPlayer::IsCollisionLine()
{
    float fy = m_tInfo.fY;

    if (CLineMgr::GetInstance()->CollisionLine(m_tInfo.fX, &fy))
    {
        if (STATE_SAME(m_tInfo.preState, OBJ_A_SITD) || STATE_SAME(m_tInfo.preState, OBJ_A_STND))
            m_tInfo.fY = fy - m_tInfo.fCY / 2;

        if (STATE_SAME(m_tInfo.preState, OBJ_A_JUMP))
        {
            if (m_tInfo.fY >= fy - m_tInfo.fCY / 2) // 점프 중에 라인에 도달하면 라인을 타고
            {
                m_tInfo.fY = fy - m_tInfo.fCY / 2;
                m_tInfo.fJumpAcc = 0.f;
                if (m_tInfo.preState & OBJ_A_ATTK)
                {
                    if (m_tInfo.preState & OBJ_A_MOVE)
                        m_tInfo.preState = OBJ_A_MOVE | OBJ_A_ATTK;
                    else
                        m_tInfo.preState = OBJ_A_STND | OBJ_A_ATTK;
                }
                else
                {
                    //m_tInfo.preState ^= OBJ_A_JUMP;
                    m_tInfo.preState = OBJ_A_STND;
                }
            }
        }
    }
    else
    {
        //m_tInfo.preState ^= OBJ_A_STND;
        m_tInfo.preState = OBJ_A_JUMP;
    }
}

void CPlayer::CalcCannonPos()
{
    // 아이템에 따라 포신 위치가 바뀜
    if (m_tInfo.fAngle < 0)
    {
        if (STATE_SAME(m_tInfo.preState, OBJ_A_SITD))
        {
            m_tInfo.fCannonX = -8 + m_tInfo.fX + cosf(abs(m_tInfo.fAngle)*PI / 180.f)*m_tInfo.fCannonD;
            m_tInfo.fCannonY = -3 + m_tInfo.fY + sinf(abs(m_tInfo.fAngle)*PI / 180.f)*m_tInfo.fCannonD;

        }
        else
        {
            m_tInfo.fCannonX = -8 + m_tInfo.fX + cosf(abs(m_tInfo.fAngle)*PI / 180.f)*m_tInfo.fCannonD;
            m_tInfo.fCannonY = -11 + m_tInfo.fY + sinf(abs(m_tInfo.fAngle)*PI / 180.f)*m_tInfo.fCannonD;
        }
    }
    else
    {
        if (STATE_SAME(m_tInfo.preState, OBJ_A_SITD))
        {
            m_tInfo.fCannonX = -8 + m_tInfo.fX + cosf(abs(m_tInfo.fAngle)*PI / 180.f)*m_tInfo.fCannonD;
            m_tInfo.fCannonY = -3 + m_tInfo.fY - sinf(abs(m_tInfo.fAngle)*PI / 180.f)*m_tInfo.fCannonD;
        }
        else
        {
            m_tInfo.fCannonX = -8 + m_tInfo.fX + cosf(abs(m_tInfo.fAngle)*PI / 180.f)*m_tInfo.fCannonD;
            m_tInfo.fCannonY = -11 + m_tInfo.fY - sinf(abs(m_tInfo.fAngle)*PI / 180.f)*m_tInfo.fCannonD;
        }
    }
}

CObj* CPlayer::CreateBullet(vector<ObjImg*>* img, float fAngle)
{
    return CAbstractFactory<CBullet>::CreateObj(img, m_tInfo.fCannonX, m_tInfo.fCannonY + 10.f, fAngle, 15.f);
}

CObj* CPlayer::CreateBomb(vector<ObjImg*>* img, float fAngle)
{
    if (STATE_SAME(m_tInfo.preState, OBJ_A_MOVE))
    {
        return CAbstractFactory<CBomb>::CreateObj(img, m_tInfo.fX, m_tInfo.fY, fAngle, 4.f + m_tInfo.fSpeed);
    }

    return CAbstractFactory<CBomb>::CreateObj(img, m_tInfo.fX, m_tInfo.fY, fAngle, 4.f);
}

void CPlayer::GunState()
{
    if (m_oldGun != m_curGun)
    {
        char buf[256] = "";
        switch (m_curGun)
        {
        case CPlayer::BASE:
            //bullet
            if (nullptr == m_vBulletimg)
            {
                sprintf_s(buf, "%s%s", IMG_PATH, "sfx/base_bullet/");
                IMG_LOAD(L"sfx/base_bullet/", buf);
                m_vBulletimg = IMG_GET_V(L"sfx/base_bullet/");
            }
            break;
        case CPlayer::HEAVY:
            break;
        case CPlayer::GUN_END:
            break;
        }
    }
}

void CPlayer::BaseGunKeyInput()
{
    m_dwCurt = GetTickCount();
    m_tInfo.curState = m_tInfo.preState;
    isKeyInput = false;

    if (KEY_UP('1'))
    {
        m_tInfo.fX = 3400.f;
        m_tInfo.fY = 150.f;
        CScrollMgr::GetInstance()->SetScrollX(-(m_tInfo.fX - CScrollMgr::GetInstance()->GetOffset()));

        INFO infoh;
        infoh.fX = 3700.f;
        infoh.fY = 60.f;
        infoh.fCX = 150.f;
        infoh.fCY = 50.f;
        infoh.curState = OBJ_A_IDLE;
        infoh.m_eKind = eKMOB::MOB_K_BOSSBODY;
        infoh.fSpeed = 4.5f;

        // tower
        CObj* boss = CAbstractFactory<CMonster>::CreateObj(infoh);
        CObjManager::GetInst()->AddObj(boss, OBJ_MONSTER);
    }

    if (KEY_UP('0'))
    {

    }

    if (KEY_PRESSING(VK_RIGHT))
    {
        if (m_tInfo.direction & OBJ_D_LEFT)
        {
            m_tInfo.fSpeed = 0.f;
            m_tInfo.fAcc = 0.f;
            m_tInfo.fAngle = 0.f;
        }
        if (KEY_PRESSING(VK_UP))
        {
            m_tInfo.direction = OBJ_D_RIGH | OBJ_D_TOPP;
            if (m_tInfo.curState & OBJ_A_JUMP)
                m_tInfo.fAngle = 60.f;
            else
                m_tInfo.fAngle = 30.f;
        }
        else if (KEY_PRESSING(VK_DOWN))
        {
            m_tInfo.direction = OBJ_D_RIGH | OBJ_D_BOTT;
        }
        else
            m_tInfo.direction = OBJ_D_RIGH;

        m_tInfo.curState |= OBJ_A_MOVE;


        // degree
        if (0 < m_tInfo.fAngle && m_tInfo.fAngle <= 90)
        {
            m_tInfo.fAngle -= 10.f;
        }
        if (-90 <= m_tInfo.fAngle && m_tInfo.fAngle < 0)
        {
            m_tInfo.fAngle += 10.f;
        }

        if (STATE_SAME(m_tInfo.curState, OBJ_A_SITD))
            limitAcc = 0.5f;
        else
            limitAcc = 5.f;

        // Accel
        if (m_tInfo.fAcc < limitAcc)
        {
            m_tInfo.fAcc += 0.1f;
        }

        if (m_tInfo.fSpeed < limitAcc)
            m_tInfo.fSpeed += m_tInfo.fAcc;

        isKeyInput = true;
    }

    if (KEY_PRESSING(VK_LEFT))
    {
        if (m_tInfo.direction & OBJ_D_RIGH)
        {
            m_tInfo.fSpeed = 0.f;
            m_tInfo.fAcc = 0.f;
            m_tInfo.fAngle = 180.f;
        }
        if (KEY_PRESSING(VK_UP))
        {
            m_tInfo.direction = OBJ_D_LEFT | OBJ_D_TOPP;
            if (m_tInfo.curState & OBJ_A_JUMP)
                m_tInfo.fAngle = 120.f;
            else
                m_tInfo.fAngle = 150.f;
        }
        else if (KEY_PRESSING(VK_DOWN))
        {
            m_tInfo.direction = OBJ_D_LEFT | OBJ_D_BOTT;
        }
        else
            m_tInfo.direction = OBJ_D_LEFT;

        m_tInfo.curState |= OBJ_A_MOVE;

        // degree
        if (180 < m_tInfo.fAngle && m_tInfo.fAngle <= 270)
        {
            m_tInfo.fAngle -= 10.f;
        }
        if (90 <= m_tInfo.fAngle && m_tInfo.fAngle < 180)
        {
            m_tInfo.fAngle += 10.f;
        }

        if (STATE_SAME(m_tInfo.curState, OBJ_A_SITD))
            limitAcc = 0.5f;
        else
            limitAcc = 5.f;

        // Accel
        if (m_tInfo.fAcc < limitAcc)
        {
            m_tInfo.fAcc += 0.1f;
        }

        if (m_tInfo.fSpeed < limitAcc)
            m_tInfo.fSpeed += m_tInfo.fAcc;

        isKeyInput = true;
    }

    if (KEY_DOWN(VK_SPACE))
    {
        isKeyInput = true;
        if (STATE_SAME(m_tInfo.curState, OBJ_A_JUMP))
        {
        }

        else if (!STATE_SAME(m_tInfo.curState, OBJ_A_JUMP))
        {
            if (STATE_SAME(m_tInfo.curState, OBJ_A_STND))
                m_tInfo.curState ^= OBJ_A_STND;
            if (STATE_SAME(m_tInfo.curState, OBJ_A_SITD))
                m_tInfo.curState ^= OBJ_A_SITD;

            m_tInfo.curState |= OBJ_A_JUMP;
            m_tInfo.fJumpAcc = GRAVITY * 1.5f;
        }
    }

    if (KEY_UP(VK_RIGHT))
    {
        m_tInfo.curState ^= OBJ_A_MOVE;
        m_tInfo.curState |= OBJ_A_STND;
    }

    if (KEY_UP(VK_LEFT))
    {
        m_tInfo.curState ^= OBJ_A_MOVE;
        m_tInfo.curState |= OBJ_A_STND;
    }

    if (KEY_PRESSING(VK_UP))
    {
        m_tInfo.direction |= OBJ_D_TOPP;
        if (m_tInfo.direction & OBJ_D_RIGH)
        {
            if (0.f <= m_tInfo.fAngle && m_tInfo.fAngle <= 90.f)
                m_tInfo.fAngle += m_fdegree;
            if (90.f <= m_tInfo.fAngle)
                m_tInfo.fAngle = 90.f;
        }
        if (m_tInfo.direction & OBJ_D_LEFT)
        {
            if (90.f <= m_tInfo.fAngle && m_tInfo.fAngle <= 180.f)
                m_tInfo.fAngle -= m_fdegree;
            if (m_tInfo.fAngle <= 90.f)
                m_tInfo.fAngle = 90.f;
        }
    }
    // 나중에 총구각도 계산할때 점프 아래키는 360 - 각도로 계산
    if (KEY_PRESSING(VK_DOWN))
    {
        if (m_tInfo.curState & OBJ_A_JUMP)
        {
            m_tInfo.direction |= OBJ_D_BOTT;
            if (m_tInfo.direction & OBJ_D_RIGH)
            {
                if (-90.f < m_tInfo.fAngle && m_tInfo.fAngle <= 0.f)
                    m_tInfo.fAngle -= m_fdegree;
                if (m_tInfo.fAngle <= -90.f)
                    m_tInfo.fAngle = -90.f;
            }
            if (m_tInfo.direction & OBJ_D_LEFT)
            {
                if (180.f <= m_tInfo.fAngle && m_tInfo.fAngle < 270.f)
                    m_tInfo.fAngle += m_fdegree;
                if (270.f <= m_tInfo.fAngle)
                    m_tInfo.fAngle = 270.f;
            }
        }
        else
        {
            //sitdown
            if (STATE_SAME(m_tInfo.curState, OBJ_A_STND))
                m_tInfo.curState ^= OBJ_A_STND;
            if (STATE_SAME(m_tInfo.curState, OBJ_A_JUMP))
                m_tInfo.curState ^= OBJ_A_JUMP;

            m_tInfo.curState |= OBJ_A_SITD;
        }
    }

    // Item 에 따라 바꿈 -> pressing
    if (KEY_DOWN(VK_LCONTROL))
    {
        if (STATE_SAME(m_tInfo.curState, OBJ_A_BOMB))
        {
            m_tInfo.curState ^= OBJ_A_BOMB;
        }

        if ((m_tInfo.preState & OBJ_A_ATTK) == 0)
        {
            m_dwOldt = GetTickCount();
            m_tInfo.curState |= OBJ_A_ATTK;
            isKeyInput = true;

            CSoundMgr::GetInstance()->PlaySound(L"ALL_00073.wav", CSoundMgr::CHANNEL_PLAYER);

            CObjManager::GetInst()->AddObj(CreateBullet(m_vBulletimg, m_tInfo.fAngle), OBJ_P_BULLET);
        }

    }

#pragma region StateChangeToTime
    if (m_dwOldt + 300 < m_dwCurt)
    {
        if (m_tInfo.curState & OBJ_A_ATTK)
        {
            m_tInfo.curState ^= OBJ_A_ATTK;
        }
    }
#pragma endregion

    if (KEY_DOWN('Z'))
    {
        if (STATE_SAME(m_tInfo.curState, OBJ_A_ATTK))
        {
            m_tInfo.curState ^= OBJ_A_ATTK;
        }
        m_tInfo.curState |= OBJ_A_BOMB;
        isKeyInput = true;
        CSoundMgr::GetInstance()->PlaySound(L"tong.wav", CSoundMgr::CHANNEL_EFFECT);
        CObjManager::GetInst()->AddObj(CreateBomb(m_vBombimg, 0.f), OBJ_P_BOMB);
    }

    if (!isKeyInput)//
    {
        if (0.f <= m_tInfo.fAcc)
        {
            m_tInfo.fAcc -= 2.1f;
        }
        if (m_tInfo.fAcc <= 0.f)
        {
            m_tInfo.fAcc = 0.f;

            m_tInfo.fSpeed = 0.f;
            if (m_tInfo.curState & OBJ_A_MOVE)
                m_tInfo.curState ^= OBJ_A_MOVE;
            m_tInfo.curState |= OBJ_A_STND;

            if (m_tInfo.direction & OBJ_D_RIGH)
            {
                if (0 < m_tInfo.fAngle)
                    m_tInfo.fAngle -= 20.f;
                if (m_tInfo.fAngle < 0)
                    m_tInfo.fAngle = 0.f;
            }
            if (m_tInfo.direction & OBJ_D_LEFT)
            {
                if (m_tInfo.fAngle < 180)
                    m_tInfo.fAngle += 20.f;
                if (180 <= m_tInfo.fAngle)
                    m_tInfo.fAngle = 180.f;
            }
        }
    }

#pragma region Movement
    // Accel
    if (m_tInfo.curState & OBJ_A_MOVE)
    {
        if (STATE_SAME(m_tInfo.curState, OBJ_A_SITD))
            m_tInfo.fAcc += 0.05f;
        else
            m_tInfo.fAcc += 0.1f;
    }

    if (m_tInfo.direction & OBJ_D_RIGH)
    {
        float fScrollX = CScrollMgr::GetInstance()->GetScrollX();

        if (m_tInfo.rect.right <= -fScrollX + 320.f)
            m_tInfo.fX += m_tInfo.fSpeed;
    }

    if (m_tInfo.direction & OBJ_D_LEFT)
    {
        float fScrollX = CScrollMgr::GetInstance()->GetScrollX();

        if (-fScrollX < m_tInfo.rect.left)
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
#pragma endregion

#pragma region ImgUpdate
    // Move
    if (m_tInfo.curState & OBJ_A_MOVE)
    {
        if (m_tInfo.curState & OBJ_A_JUMP)
        {
            // 이동중 점프 모션
        }
        else
        {
            if (STATE_SAME(m_tInfo.curState, OBJ_A_SITD))
            {
                //
                if (m_tInfo.direction & OBJ_D_LEFT)
                {
                    m_scLeg.SetState(L"fio/down/sd_move_left/");
                }
                else if (m_tInfo.direction & OBJ_D_RIGH)
                {
                    m_scLeg.SetState(L"fio/down/sd_move/");
                }
            }
            else
            {
                if (m_tInfo.direction & OBJ_D_LEFT)
                {
                    m_scBody.SetState(L"fio/walking/body_left/");
                    m_scLeg.SetState(L"fio/walking/leg_left/");
                }
                else if (m_tInfo.direction & OBJ_D_RIGH)
                {
                    m_scBody.SetState(L"fio/walking/body/");
                    m_scLeg.SetState(L"fio/walking/leg/");
                }
            }
        }
    }
    else if (m_tInfo.curState & OBJ_A_STND)
    {
        if (STATE_SAME(m_tInfo.curState, OBJ_A_JUMP))
        {
            if (m_tInfo.direction & OBJ_D_LEFT)
            {
                m_scBody.SetState(L"fio/jump/jmp_body_left/");
                m_scLeg.SetState(L"fio/jump/jmp_leg_left/");
            }
            else if (m_tInfo.direction & OBJ_D_RIGH)
            {
                m_scBody.SetState(L"fio/jump/jmp_body/");
                m_scLeg.SetState(L"fio/jump/jmp_leg/");
            }
        }
        else if (STATE_SAME(m_tInfo.curState, OBJ_A_SITD))
        {
            if (DIREC_SAME(m_tInfo.direction, OBJ_D_RIGH))
            {
                m_scLeg.SetState(L"fio/down/sitdown/");
            }
            else if (DIREC_SAME(m_tInfo.direction, OBJ_D_LEFT))
            {
                m_scLeg.SetState(L"fio/down/sitdown_left/");
            }
        }
        else
        {
            if (m_tInfo.direction & OBJ_D_LEFT)
            {
                m_scBody.SetState(L"fio/st/body_left/");
                m_scLeg.SetState(L"fio/st/leg_left/");
            }
            else if (m_tInfo.direction & OBJ_D_RIGH)
            {
                m_scBody.SetState(L"fio/st/body/");
                m_scLeg.SetState(L"fio/st/leg/");
            }
        }
    }

    if (90 < m_tInfo.fAngle && m_tInfo.fAngle < 180) //m_tInfo.direction & OBJ_D_LEFT
    {
        if (m_tInfo.direction & OBJ_D_TOPP)
        {
            m_scBody.SetState(L"fio/st/up_body_left/");
            //m_scLeg.SetState(L"fio/st/leg_left/");
        }
        else
        {
            m_scBody.SetState(L"fio/st/body_left/");
            //m_scLeg.SetState(L"fio/st/leg_left/");
        }
    }
    else if (0 < m_tInfo.fAngle && m_tInfo.fAngle < 90) //m_tInfo.direction & OBJ_D_RIGH
    {
        if (m_tInfo.direction & OBJ_D_TOPP)
        {
            m_scBody.SetState(L"fio/st/up_body/");
            //m_scLeg.SetState(L"fio/st/leg/");
        }
        else
        {

            m_scBody.SetState(L"fio/st/body/");
            //m_scLeg.SetState(L"fio/st/leg/");
        }
    }

    if (m_tInfo.curState & OBJ_A_ATTK)
    {
        if (m_tInfo.direction & OBJ_D_LEFT)
        {
            if (m_tInfo.fAngle <= 110.f)
            {
                //CStateManager* pState = new CStUpAtkBodyL;
                m_scBody.SetState(L"fio/baseatk/up_atk_left/");
            }
            else
            {
                if (STATE_SAME(m_tInfo.curState, OBJ_A_SITD))
                {
                    m_scLeg.SetState(L"fio/down/atkl/");
                }
                else
                    m_scBody.SetState(L"fio/baseatk/st_atk_left/");
            }

            //m_scLeg.SetState(L"fio/st/leg_left/");
        }
        else if (m_tInfo.direction & OBJ_D_RIGH)
        {
            if (70.f <= m_tInfo.fAngle)
            {
                //CStateManager* pState = new CStUpAtkBodyR;
                m_scBody.SetState(L"fio/baseatk/up_atk/");
            }
            else
            {
                if (STATE_SAME(m_tInfo.curState, OBJ_A_SITD))
                {
                    m_scLeg.SetState(L"fio/down/atkr/");
                }
                else
                    m_scBody.SetState(L"fio/baseatk/st_atk/");
            }
        }
    }

    if (STATE_SAME(m_tInfo.curState, OBJ_A_BOMB))
    {
        if (m_tInfo.direction & OBJ_D_LEFT)
        {
            m_scBody.SetState(L"fio/st/b_body_left/");
        }
        else if (m_tInfo.direction & OBJ_D_RIGH)
        {
            m_scBody.SetState(L"fio/st/b_body/");
        }
    }
#pragma endregion
    m_tInfo.preState = m_tInfo.curState;
}

void CPlayer::rectMake()
{
    /*m_tInfo.rect.left   = m_tInfo.fX - (*m_scBody.GetState()->GetImgVector()->begin())->image->GetWidth() / 2.f;
    m_tInfo.rect.right  = m_tInfo.fX + (*m_scBody.GetState()->GetImgVector()->begin())->image->GetWidth() / 2.f;
    m_tInfo.rect.top    = m_tInfo.fY - (*m_scBody.GetState()->GetImgVector()->begin())->image->GetHeight() / 2.f;
    m_tInfo.rect.bottom = m_tInfo.fY + (*m_scBody.GetState()->GetImgVector()->begin())->image->GetHeight() / 2.f;*/

    Image* img = (*m_scBody.GetState()->GetImgIter())->image;

    m_tInfo.rect.left = LONG(-5 + m_tInfo.fX - img->GetWidth() / 2.f);
    m_tInfo.rect.right = LONG(-5 + m_tInfo.fX + img->GetWidth() / 2.f);
    m_tInfo.rect.top = LONG(m_tInfo.fY - img->GetHeight() / 2.f);
    m_tInfo.rect.bottom = LONG(m_tInfo.fY + img->GetHeight() / 2.f);
}