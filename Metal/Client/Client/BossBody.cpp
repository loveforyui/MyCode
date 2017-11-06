#include "stdafx.h"
#include "BossBody.h"
#include "Monster.h"

CBossBody::CBossBody()
{
}

CBossBody::~CBossBody()
{
}

void CBossBody::        Init        ()
{
    char buf[256] = "";

    sprintf_s(buf, "%s%s", IMG_PATH, "monster/stage01/body/");
    IMG_LOAD(L"monster/stage01/body/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"monster/stage01/body/", IMG_GET_V(L"monster/stage01/body/"));
    m_mImage    = &(m_pObj->GetImgv());

    sprintf_s(buf, "%s%s", IMG_PATH, "sfx/explosion/");
    IMG_LOAD(L"sfx/explosion/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"sfx/explosion/", IMG_GET_V(L"sfx/explosion/"));
    m_mImage    = &(m_pObj->GetImgv());

    sprintf_s(buf, "%s%s", IMG_PATH, "sfx/heos/");
    IMG_LOAD(L"sfx/heos/", buf);
    dynamic_cast<CMonster*>(m_pObj)->InsertImage(L"sfx/heos/", IMG_GET_V(L"sfx/heos/"));
    m_mImage    = &(m_pObj->GetImgv());

    sprintf_s(buf, "%s%s", IMG_PATH, "monster/stage01/right_broken/");
    IMG_LOAD(L"monster/stage01/right_broken/", buf);

    iter_begin  = m_mImage->find(L"monster/stage01/body/")->second->begin();
    iter_end    = m_mImage->find(L"monster/stage01/body/")->second->end();

    m_pObj->SetCurState(OBJ_A_STND);
    m_pObj->SetHp(15);

    INFO info;
    info.fX = m_pObj->GetInfo().fX;
    info.fY = m_pObj->GetInfo().fY;
    info.curState = OBJ_A_STND;
    info.m_eKind = eKMOB::MOB_K_BOSSLEFT;
    info.fSpeed = m_pObj->GetInfo().fSpeed;

    // tower
    m_left = CAbstractFactory<CMonster>::CreateObj(info);
    CObjManager::GetInst()->AddObj(m_left, OBJ_SUBMON);

    info.fX = m_pObj->GetInfo().fX;
    info.fY = m_pObj->GetInfo().fY;
    info.m_eKind = eKMOB::MOB_K_BOSSRIGHT;
    m_right = CAbstractFactory<CMonster>::CreateObj(info);
    CObjManager::GetInst()->AddObj(m_right, OBJ_SUBMON);

    info.fX = m_pObj->GetInfo().fX;
    info.fY = m_pObj->GetInfo().fY;
    info.m_eKind = eKMOB::MOB_K_BOSSTOP;
    m_top = CAbstractFactory<CMonster>::CreateObj(info);
    CObjManager::GetInst()->AddObj(m_top, OBJ_SUBMON);

    rotateX = FLOAT(m_pObj->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2.f);
    rotateY = FLOAT(m_pObj->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2.f);
    rotateW = FLOAT((*iter_begin)->image->GetWidth());
    rotateH = FLOAT((*iter_begin)->image->GetHeight());
}

void CBossBody::        Render      (HDC hdc)
{
    if (m_pObj->GetInfo().iHP <= 0)
    {
        IMG_DRAW_A(hdc
            , (*iter_begin)->image
            , rotateX
            , rotateY
            , rotateW
            , rotateH
            , rotate *= 1.2f
        );
    }
    else
    {
        if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_STND))
        {
            IMG_DRAW_I(hdc
                , (*iter_begin)->image
                , FLOAT(m_pObj->GetInfo().fX - (*iter_begin)->image->GetWidth() / 2.f)
                , FLOAT(m_pObj->GetInfo().fY - (*iter_begin)->image->GetHeight() / 2.f)
                , FLOAT((*iter_begin)->image->GetWidth())//m_pObj->GetInfo().rect.right
                , FLOAT((*iter_begin)->image->GetHeight())//m_pObj->GetInfo().rect.bottom
            );
        }
    }
}

void CBossBody::        Release     ()
{
}

int CBossBody::         Update      ()
{
    RECT rc = {
        LONG(m_pObj->GetInfo().fX - m_pObj->GetInfo().fCX/2)// m_pObj->GetInfo().fCX / 2
        , LONG(m_pObj->GetInfo().fY - m_pObj->GetInfo().fCY/2)
        , LONG(m_pObj->GetInfo().fX + m_pObj->GetInfo().fCX/2)
        , LONG(m_pObj->GetInfo().fY + m_pObj->GetInfo().fCY/2)
    };

    m_pObj->SetRect(rc);

    if (STATE_SAME(m_pObj->GetInfo().curState, OBJ_A_DIE))
    {
        rotateW += rotateW * 0.1f;
        rotateH += rotateH * 0.1f;
        rotateX = m_pObj->GetInfo().fX - rotateW / 2;
        rotateY = m_pObj->GetInfo().fY - rotateH / 2;
        
        CSoundMgr::GetInstance()->StopSoundAll();
        if(700.f <= rotateW)
            CSceneMgr::GetInstance()->SceneChange(CSceneMgr::ENDING);
    }
    else
        BothDeath();

    switch (stance)
    {
    case CBossBody::WAIT:
        Wait();
        break;
    case CBossBody::STAY:
        Stay();
        break;
    case CBossBody::PATROL:
        Patrol();
        break;
    }

    return 0;
}

void CBossBody::        Wait        ()
{
    CObj* player = CObjManager::GetInst()->GetObjlst(OBJ_PLAYER).back();

    float dist = _Distance<float>(
        player->GetInfo().fX
        , player->GetInfo().fY
        , m_pObj->GetInfo().fX
        , m_pObj->GetInfo().fY
        );

    if (dist < 150.f)
    {
        stance = STAY;
    }
}

void CBossBody::        Patrol      ()
{
    CObj* player = CObjManager::GetInst()->GetObjlst(OBJ_PLAYER).back();

    float dist_l = abs(m_pObj->GetInfo().fX - 90.f);
    float dist_r = abs(m_pObj->GetInfo().fX + 90.f);
    
    POINT pt;
    pt.x = LONG(m_pObj->GetInfo().fX);
    pt.y = LONG(m_pObj->GetInfo().fY);

    if (dist_l <= player->GetInfo().fX && player->GetInfo().fX <= m_pObj->GetInfo().fX)
    {
        //왼쪽이 -> 오른쪽으로 
        pt = CPattern::GetInstance()->AngleLine(m_pObj, 0.f);
        
    }
    else if (m_pObj->GetInfo().fX <= player->GetInfo().fX && player->GetInfo().fX <= dist_r)
    {
        //오른쪽이 -> 왼쪽으로
        pt = CPattern::GetInstance()->AngleLine(m_pObj, 180.f);
    }
    else if (dist_r < player->GetInfo().fX)
    {
        pt = CPattern::GetInstance()->AngleLine(m_pObj, 0.f);
    }
    else if (player->GetInfo().fX < dist_l)
    {
        pt = CPattern::GetInstance()->AngleLine(m_pObj, 180.f);
    }

    //화면 밖나갈때 처리
    if (3820 <= (m_pObj->GetInfo().fX))
    {
        pt = CPattern::GetInstance()->AngleLine(m_pObj, 180.f);
    }
    if ((m_pObj->GetInfo().fX) <= 3823 - 390)
    {
        pt = CPattern::GetInstance()->AngleLine(m_pObj, 0.f);
    }

    m_pObj->SetPos(FLOAT(pt.x), FLOAT(pt.y));
    m_left->SetPos(FLOAT(pt.x), FLOAT(pt.y));
    m_right->SetPos(FLOAT(pt.x), FLOAT(pt.y));
    m_top->SetPos(FLOAT(pt.x), FLOAT(pt.y));
}

void CBossBody::        Stay        ()
{
    if (FLOAT(m_pObj->GetInfo().iMaxHp * 0.7f) < FLOAT(m_pObj->GetInfo().iHP) && FLOAT(m_pObj->GetInfo().iHP) <= FLOAT(m_pObj->GetInfo().iMaxHp * 1.0f))
    {
        m_top->SetCurState(OBJ_A_MOVE);
    }
    if (FLOAT(m_pObj->GetInfo().iMaxHp * 0.3f) < FLOAT(m_pObj->GetInfo().iHP) && FLOAT(m_pObj->GetInfo().iHP) <= FLOAT(m_pObj->GetInfo().iMaxHp * 0.7f))
    {
        iter_begin = m_mImage->find(L"monster/stage01/body/")->second->begin() + 1;
        stance = PATROL;
        m_top->SetCurState(OBJ_A_DIE);
        m_right->SetCurState(OBJ_A_ATTK);
        m_left->SetCurState(OBJ_A_ATTK);
    }
    if (FLOAT(m_pObj->GetInfo().iMaxHp * 0.0f) < FLOAT(m_pObj->GetInfo().iHP) && FLOAT(m_pObj->GetInfo().iHP) <= FLOAT(m_pObj->GetInfo().iMaxHp * 0.3f))
    {
        iter_begin = m_mImage->find(L"monster/stage01/body/")->second->begin() + 2;
    }
}

void CBossBody::        BothDeath       ()
{
    if (m_pObj->GetInfo().iHP <= 0)
    {

        iter_begin = m_mImage->find(L"monster/stage01/body/")->second->begin() + 4;

        if (rotateW <= 5.f)
        {
            iter_begin = m_mImage->find(L"sfx/heos/")->second->begin();

            rotateW = (*iter_begin)->image->GetWidth() * 0.001f;
            rotateH = (*iter_begin)->image->GetHeight() * 0.001f;
            //rotateX = m_pObj->GetInfo().fX - rotateW / 2;
            //rotateY = m_pObj->GetInfo().fY - rotateH / 2;

            m_pObj->SetCurState(OBJ_A_DIE);
        }
        else
        {
            rotateW -= rotateW * 0.1f;
            rotateH -= rotateH * 0.1f;
            rotateX = m_pObj->GetInfo().fX - rotateW / 2;
            rotateY = m_pObj->GetInfo().fY - rotateH / 2;
        }


        if (nullptr != m_left)
            m_left->SetCurState(OBJ_A_DIE);
        if (nullptr != m_right)
            m_right->SetCurState(OBJ_A_DIE);
        if (nullptr != m_top)
            m_top->SetCurState(OBJ_A_DIE);
    }
}