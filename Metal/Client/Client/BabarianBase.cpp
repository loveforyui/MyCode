#include "stdafx.h"
#include "BabarianBase.h"
#include "Bullet.h"
#include "Monster.h"

CBabarian::CBabarian()
{
    Init();
}

CBabarian::~CBabarian()
{
}

void CBabarian::    Init            ()
{
    m_dwOAtkDelay = GetTickCount();
    char buf[256] = "";
    //body
    sprintf_s(buf, "%s%s", IMG_PATH, "sfx/babarian/swrd/");
    IMG_LOAD(L"sfx/babarian/swrd/", buf);
    dynamic_cast<CMonster*>(m_pObj)->SetBulletImg(IMG_GET_V(L"sfx/babarian/swrd/"));
}

void CBabarian::    Render          (HDC hdc)
{
    //Image* img      = m_curImg->image;
    HBRUSH hBrush = nullptr;
    HBRUSH hOldsh = nullptr;

    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_STND)
        || STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_JUMP))
    {
        hBrush = CreateSolidBrush(RGB(255, 0, 0));
        hOldsh = (HBRUSH)SelectObject(hdc, hBrush);
        Rectangle(
            hdc
            , m_pObj->GetInfo().rect.left
            , m_pObj->GetInfo().rect.top
            , m_pObj->GetInfo().rect.right
            , m_pObj->GetInfo().rect.bottom
        );
    }
    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_ATTK))
    {
        hBrush = CreateSolidBrush(RGB(200, 0, 0));
        hOldsh = (HBRUSH)SelectObject(hdc, hBrush);
        Rectangle(
            hdc
            , m_pObj->GetInfo().rect.left
            , m_pObj->GetInfo().rect.top
            , m_pObj->GetInfo().rect.right
            , m_pObj->GetInfo().rect.bottom
        );
    }

    wchar_t         pos[64];
    swprintf_s(pos, L"X:%.1f Y:%.1f d:%d", m_pObj->GetInfo().fX, m_pObj->GetInfo().fY, m_pObj->GetInfo().curState);
    SetTextAlign(hdc, TA_CENTER);
    SetBkMode(hdc, TRANSPARENT);
    TextOut(hdc, m_pObj->GetInfo().fX, m_pObj->GetInfo().fY - 30, pos, wcslen(pos));


    SelectObject(hdc, hOldsh);
    DeleteObject(hBrush);
}

void CBabarian::    Release         ()
{
}

int CBabarian::     Update          ()
{
    PatternA();
    IsJump();
    PrecessState();
    return 0;
}

void CBabarian::    PatternA        ()
{
    CObj* player = CObjManager::GetInst()->GetObjlst(OBJ_PLAYER).back();

    float dist = _Distance<float>(
        player->GetInfo().fX
        , player->GetInfo().fY
        , m_pObj->GetInfo().fX
        , m_pObj->GetInfo().fY
    );
    // 일정 거리가 되면 뒤로 점프해서 도망감
    if ((dist < 60.f))
    {
        if (!((m_pObj->GetInfo().curState & OBJ_A_JUMP) == OBJ_A_JUMP))
        {
            //이미 방향은 그대로 점프 뛴다.
            m_pObj->SetJAcc(GRAVITY * 2.5f);
            m_pObj->SetCurState(OBJ_A_JUMP);
        }
    }
    if ((m_pObj->GetInfo().curState & OBJ_A_STND) == OBJ_A_STND)
    {
        if (100.f <= dist && dist <= 200.f)
        {
            POINT pt = CPattern::GetInstance()->AngleLine(m_pObj, 180.f);
            m_pObj->SetPos(float(pt.x), float(pt.y));
        }
        if ((dist < 100.f))
        {
            if (!STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_ATTK))
            {
                m_dwOAtkDelay = GetTickCount();
                int cur = m_pObj->GetInfo().curState;
                cur |= OBJ_A_ATTK;
                m_pObj->SetCurState(cur);
            }
        }
    }
    if ((m_pObj->GetInfo().curState & OBJ_A_ATTK) == OBJ_A_ATTK)
    {
        m_dwCAtkDelay = GetTickCount();
    }
}

void CBabarian::    IsJump          ()
{
    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_JUMP))
    {
        //m_tInfo.fJumpAcc += 0.3f;
        //m_tInfo.fY -= m_tInfo.fJumpPow * m_tInfo.fJumpAcc - GRAVITY * m_tInfo.fJumpAcc * m_tInfo.fJumpAcc * 0.5f;

        //FLOAT y = m_tInfo.fY;
        float acc = m_pObj->GetInfo().fJumpAcc;
        float fy = m_pObj->GetInfo().fY;
        acc -= 0.5*GRAVITY;
        fy -= m_pObj->GetInfo().fJumpAcc;

        m_pObj->SetJAcc(acc);
        m_pObj->SetPos(m_pObj->GetInfo().fX + 10.f, fy);
    }
}

void CBabarian::    PrecessState    ()
{
    if (m_dwOAtkDelay + 1140 < m_dwCAtkDelay)
    {
        // Attack Motion
        int cur = m_pObj->GetInfo().curState;
        if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_ATTK))
        {
            cur ^= OBJ_A_ATTK;
            m_pObj->SetCurState(cur);
            m_dwOAtkDelay = GetTickCount();

            CObjManager::GetInst()->AddObj(CreateBullet(dynamic_cast<CMonster*>(m_pObj)->GetBulletImg(), 90.f), OBJ_M_BULLET);
        }
    }
}

CObj* CBabarian::   CreateBullet    (vector<ObjImg*>* img, float fAngle)
{
    CObj* pObj = CAbstractFactory<CBullet>::CreateObj(img, m_pObj->GetInfo().fX, m_pObj->GetInfo().fY, fAngle);
    dynamic_cast<CBullet*>(pObj)->SetBullPettern(CBullet::CONIC);
    return pObj;
}