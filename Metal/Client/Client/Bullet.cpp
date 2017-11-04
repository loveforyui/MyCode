#include "stdafx.h"
#include "Bullet.h"

CBullet::CBullet()
{
}

CBullet::~CBullet()
{
}

void CBullet::      Init                ()
{
    m_tInfo.fSpeed      = 5.f;
    if (!m_tInfo.image->empty())
    {
        img_begin       = m_tInfo.image->begin();
        img_end         = --m_tInfo.image->end();
    }
    m_tInfo.curState    = OBJ_A_JUMP;
    m_tInfo.fJumpAcc    = GRAVITY * 1.5f;
    m_tInfo.fY          -= 10.f;
    m_tInfo.iAtt        = 5;

    minAngle = m_tInfo.fAngle - 90.f;
    maxAngle = m_tInfo.fAngle + 90.f;
    cAngle = minAngle;                                
}

void CBullet::      Release             ()
{
}

void CBullet::      Render              (HDC hdc)
{
    m_tInfo.fCX = FLOAT((*img_begin)->image->GetWidth());
    m_tInfo.fCY = FLOAT((*img_begin)->image->GetHeight());

    if (m_pattern == UDO)
    {
        CImageMgr::GetInst()->DrawImg(hdc
            , (*img_begin)->image
            , m_tInfo.fX - (m_tInfo.fCX / 2.f)
            , m_tInfo.fY - (m_tInfo.fCY / 2.f)
            , m_tInfo.fCX
            , m_tInfo.fCY
            , -cAngle
        );
    }
    else
    {
        IMG_DRAW_I(
            hdc
            , (*img_begin)->image
            , m_tInfo.fX - (m_tInfo.fCX / 2.f)
            , m_tInfo.fY - (m_tInfo.fCY / 2.f)
            , m_tInfo.fCX
            , m_tInfo.fCY);
    }
    

    ++img_begin;

    if (img_begin == img_end)
    {
        img_begin = m_tInfo.image->begin();
    }

    /*if (1 < m_end)
    {
        img_begin = m_tInfo.image->end();
        --img_begin;
        return;
    }
    if (img_begin == (img_end - 2))
    {
        img_begin = m_tInfo.image->begin();
    }*/
}

int CBullet::       Update              ()
{
    ++m_distSum;
    if (isDead())
        return 1;

    if (STATE_SAME(m_tInfo.curState, OBJ_A_STND))
    {
        ++m_end;
        img_begin = img_end;
        if (30 < m_end)
            return 1;
    }

    if (m_end == 0)
    {
        switch (m_pattern)
        {
        case CBullet::LINE:
            Line();
            break;
        case CBullet::CONIC:
            Conic();
            break;
        case CBullet::UDO:
            Udo();
            break;
        case CBullet::PAT_END:
            break;
        }
    }


    IsCollisionLine();

    RECT rc = {
        LONG(m_tInfo.fX - (*img_begin)->image->GetWidth()/2.f)// m_pObj->GetInfo().fCX / 2
        , LONG(m_tInfo.fY - (*img_begin)->image->GetHeight()/2.f)
        , LONG(m_tInfo.fX + (*img_begin)->image->GetWidth()/2.f)
        , LONG(m_tInfo.fY + (*img_begin)->image->GetHeight()/2.f)
    };

    m_tInfo.rect = rc;

    if (m_tInfo.fX < 0 || 3823 < m_tInfo.fX)
        return 1;

    if (m_tInfo.fY < -30 || WINCY < m_tInfo.fY)
        return 1;

    //if (50 <= m_distSum)
    //          return 1;

    return 0;
}

void CBullet::      Line                ()
{
    POINT info = CPattern::GetInstance()->AngleLine(this, m_tInfo.fAngle);

    m_tInfo.fX = float(info.x);
    m_tInfo.fY = float(info.y);
}

void CBullet::      Conic               ()
{
    POINT info = CPattern::GetInstance()->AngleLine(this, m_tInfo.fAngle);
    m_tInfo.fX = float(info.x);
    m_tInfo.fY = float(info.y);

    m_tInfo.fAngle += m_tInfo.fSpeed;
    if (240.f <= m_tInfo.fAngle)
        m_tInfo.fAngle = 240.f;
}

void CBullet::Udo()
{
    m_tInfo.fSpeed = 3.f;

    CObj* player = CObjManager::GetInst()->GetObjlst(OBJ_PLAYER).back();

    float dist = _Distance<float>(
        player->GetInfo().fX
        , player->GetInfo().fY
        , m_tInfo.fX
        , m_tInfo.fY
        );

    //minAngle = acosf((m_tInfo.fX - player->GetInfo().fX) / dist) - 90;
    //maxAngle = acosf((m_tInfo.fX - player->GetInfo().fX) / dist) + 90;

    if ( cAngle < minAngle)
    {
        incA = -incA;
    }
    if (maxAngle < cAngle)
    {
        incA = -incA;
    }

    cAngle += incA;

    POINT info = CPattern::GetInstance()->AngleLine(this, cAngle);
    m_tInfo.fX = float(info.x);
    m_tInfo.fY = float(info.y);
}

void CBullet::      IsCollisionLine     ()
{
    float fy = m_tInfo.fY;

    if (CLineMgr::GetInstance()->CollisionLine(m_tInfo.fX, &fy))
    {
        if (!(m_tInfo.curState & OBJ_A_JUMP))
        {
            m_tInfo.fY = fy - m_tInfo.fCY / 2;
        }
        if (m_tInfo.fY >= fy - m_tInfo.fCY / 2) // 점프 중에 라인에 도달하면 라인을 타고
		{
			m_tInfo.fY = fy - m_tInfo.fCY / 2;
			m_tInfo.fJumpAcc = 0.f;
            m_tInfo.curState = OBJ_A_STND;
		}
    }
}