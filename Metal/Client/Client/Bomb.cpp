#include "stdafx.h"
#include "Bomb.h"

CBomb::CBomb()
{
}

CBomb::~CBomb()
{
}

void CBomb::        Init            ()
{
    char buf[256] = "";

    sprintf_s(buf, "%s%s", IMG_PATH, "sfx/bomb_sfx/");
    IMG_LOAD(L"sfx/bomb_sfx/", buf);
    m_image.insert(pair<const TCHAR*, vector<ObjImg*>*>(L"sfx/bomb_sfx/", IMG_GET_V(L"sfx/bomb_sfx/")));

    m_tInfo.fSpeed      = 5.f;
    if (!m_tInfo.image->empty())
    {
        img_begin       = m_tInfo.image->begin();
        img_end         = m_tInfo.image->end();
    }
    m_tInfo.curState    = OBJ_A_JUMP;
    m_tInfo.fJumpAcc    = GRAVITY * 1.5f;
    m_tInfo.iAtt        = 20;
    m_tInfo.fJumpAcc    = 12.f;
    m_tInfo.fJumpPow    = 12.f;
    m_tInfo.direction   = OBJ_MGR_GETLIST(OBJ_PLAYER).back()->GetDirection();

    side = m_tInfo.fX + 50.f;
}

void CBomb::        Release         ()
{
}

void CBomb::        isJump          ()
{
    if (m_tInfo.curState & OBJ_A_JUMP)
    {
        POINT pt;
        pt.x = LONG(m_tInfo.fX);
        pt.y = LONG(m_tInfo.fY);
        if( m_tInfo.direction & OBJ_D_LEFT)
            pt = CPattern::GetInstance()->AngleLine(this, 180.f);
        if( m_tInfo.direction & OBJ_D_RIGH)
            pt = CPattern::GetInstance()->AngleLine(this, 0.f);

        m_tInfo.fJumpAcc -= 0.1592f*GRAVITY;

        m_tInfo.fY -= m_tInfo.fJumpAcc;
        m_tInfo.fX = FLOAT(pt.x);

        /*if (m_tInfo.fX < side)
        {
            POINT pt = CPattern::GetInstance()->AngleLine(this, 0.f);
            m_tInfo.fX = FLOAT(pt.x);
            m_tInfo.fY = FLOAT(pt.y);
        } 
        else
        {
            POINT pt = CPattern::GetInstance()->AngleLine(this, ttt--);
            m_tInfo.fX = FLOAT(pt.x);
            m_tInfo.fY = FLOAT(pt.y);
        }*/
    }
}

void CBomb::        Render          (HDC hdc)
{
    IMG_DRAW_A(
        hdc
        , (*img_begin)->image
        , m_tInfo.fX - FLOAT((*img_begin)->image->GetWidth() / 2.f)
        , m_tInfo.fY - FLOAT((*img_begin)->image->GetHeight() / 2.f)
        , FLOAT((*img_begin)->image->GetWidth())
        , FLOAT((*img_begin)->image->GetHeight())
        , m_tInfo.fAngle += 30.f
    );
    if (STATE_SAME(m_tInfo.curState, OBJ_A_DIE))
    {
        if (img_end == m_image.find(L"sfx/bomb_sfx/")->second->end())
        {
            CSoundMgr::GetInstance()->PlaySound(L"kagang.wav", CSoundMgr::CHANNEL_EFFECT);
        }
        --img_end;
        if (img_end == img_begin)
        {
            end = 1;
        }
        IMG_DRAW_I(
            hdc
            , (*img_end)->image
            , m_tInfo.fX - FLOAT((*img_end)->image->GetWidth() / 2.f)
            , m_tInfo.fY - FLOAT((*img_end)->image->GetHeight() / 2.f)
            , FLOAT((*img_end)->image->GetWidth())
            , FLOAT((*img_end)->image->GetHeight())
        );
    }
}

int CBomb::         Update          ()
{
    if (end)
        return 1;

    if (isDead() && !STATE_SAME(m_tInfo.curState, OBJ_A_DIE))
    {
        m_tInfo.curState = OBJ_A_DIE;
        img_begin   = m_image.find(L"sfx/bomb_sfx/")->second->begin();
        img_end     = m_image.find(L"sfx/bomb_sfx/")->second->end();
    }

    if (isDead())
    {
        m_tInfo.rect.left   = LONG(m_tInfo.fX - ((*img_begin)->image->GetWidth() / 2.f));
        m_tInfo.rect.top    = LONG(m_tInfo.fY - ((*img_begin)->image->GetHeight() / 2.f));
        m_tInfo.rect.right  = ((*img_begin)->image->GetWidth());
        m_tInfo.rect.bottom = ((*img_begin)->image->GetHeight());
    }
    else
    {
        CObj::Update();
    }


    isJump();
    isCollisionLine();
    return 0;
}

void CBomb::        isCollisionLine ()
{
    float fy = m_tInfo.fY;

    if (CLineMgr::GetInstance()->CollisionLineBomb(m_tInfo.fX, &fy))
    {
        m_tInfo.fJumpPow *= 0.7f;
        m_tInfo.fJumpAcc = m_tInfo.fJumpPow;
        if (m_tInfo.fJumpAcc < 6.f)
        {
            SetDead(true);
        }
    }
}