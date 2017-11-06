#include "stdafx.h"
#include "Item.h"
#include "Player.h"

CItem::CItem()
{
}

CItem::~CItem()
{
}

void CItem::Init()
{
    char buf[256] = "";
    sprintf_s(buf, "%s%s", IMG_PATH, "sfx/item/");
    IMG_LOAD(L"sfx/item/", buf);

    sprintf_s(buf, "%s%s", IMG_PATH, "sfx/bItem/");
    IMG_LOAD(L"sfx/bItem/", buf);

    sprintf_s(buf, "%s%s", IMG_PATH, "sfx/ishotgun/");
    IMG_LOAD(L"sfx/ishotgun/", buf);

    m_image.insert(pair<const TCHAR*, vector<ObjImg*>*>(L"sfx/item/", IMG_GET_V(L"sfx/item/")));
    m_image.insert(pair<const TCHAR*, vector<ObjImg*>*>(L"sfx/bItem/", IMG_GET_V(L"sfx/bItem/")));
    m_image.insert(pair<const TCHAR*, vector<ObjImg*>*>(L"sfx/ishotgun/", IMG_GET_V(L"sfx/ishotgun/")));

    switch (kind)
    {
    case IHEAVY:
        img_begin = m_image.find(L"sfx/item/")->second->begin();
        img_end = m_image.find(L"sfx/item/")->second->end();
        break;
    case IBOMB:
        img_begin = m_image.find(L"sfx/bItem/")->second->begin();
        img_end = m_image.find(L"sfx/bItem/")->second->end();
        break;
    case ISHOTGUN:
        img_begin = m_image.find(L"sfx/ishotgun/")->second->begin();
        img_end = m_image.find(L"sfx/ishotgun/")->second->end();
        break;
    case ITEMEND:
        break;
    }

    

    m_tInfo.fJumpAcc = 0.f;
    m_tInfo.fJumpPow = 0.f;
    m_tInfo.isDead = false;
}

void CItem::Release()
{
}

void CItem::Render(HDC hdc)
{
    IMG_DRAW_I(hdc
        , (*img_begin)->image
        , FLOAT(m_tInfo.fX - (*img_begin)->image->GetWidth() / 2.f)
        , FLOAT(m_tInfo.fY - (*img_begin)->image->GetHeight() / 2.f)
        , FLOAT((*img_begin)->image->GetWidth())//m_pObj->GetInfo().rect.right
        , FLOAT((*img_begin)->image->GetHeight())//m_pObj->GetInfo().rect.bottom
    );

    ++img_begin;
    if (img_begin == img_end)
    {
        switch (kind)
        {
        case IHEAVY:
            img_begin = m_image.find(L"sfx/item/")->second->begin();
            break;
        case IBOMB:
            img_begin = m_image.find(L"sfx/bItem/")->second->begin();
            break;
        case ISHOTGUN:
            img_begin = m_image.find(L"sfx/ishotgun/")->second->begin();
            break;
        }
    }
}

int CItem::Update()
{
    if (isDead())
        return 1;
    CObj::Update();
    
    CollisionSphere(OBJ_MGR_GETLIST(OBJ_PLAYER), OBJ_MGR_GETLIST(OBJ_ITEM));
    IsJump();
    IsCollisionLine();
    return 0;
}
void CItem::        CollisionSphere     (OBJLIST & dst, OBJLIST & src)
{
    for (auto Dst : dst)
	{
		if (true == Dst->isDead())
			continue;

		for (auto Src : src)
		{
			if (true == Src->isDead())
				continue;
			
			if (CCollisionManager::CheckSphere(Dst, Src))
			{
				//Dst->SetDead(true);
				//Dst->SetDamage(Src->GetAtt());
                switch (kind)
                {
                case IHEAVY:
                    dynamic_cast<CPlayer*>(Dst)->SetGun(CPlayer::HEAVY);
                    dynamic_cast<CPlayer*>(Dst)->SetReload(30);
                    CSoundMgr::GetInstance()->PlaySound(L"eff_heavy.wav", CSoundMgr::CHANNEL_EFFECT);
                    break;
                case IBOMB:
                    dynamic_cast<CPlayer*>(Dst)->bombCnt += 10;
                    break;
                case ISHOTGUN:
                    dynamic_cast<CPlayer*>(Dst)->SetGun(CPlayer::SHOTGUN);
                    dynamic_cast<CPlayer*>(Dst)->SetReload(10);
                    break;
                case ITEMEND:
                    break;
                }
                
				Src->SetDead(true);
			}
		}
	}
}

void CItem::      IsJump          ()
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

void CItem::      IsCollisionLine ()
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
                m_tInfo.preState = OBJ_A_STND;
            }
        }
    }
}