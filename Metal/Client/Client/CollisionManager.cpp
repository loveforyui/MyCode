#include "stdafx.h"
#include "CollisionManager.h"
#include "Obj.h"

CCollisionManager::CCollisionManager()
{
}

CCollisionManager::~CCollisionManager()
{
}

void CCollisionManager::        CollisionRect       (OBJLIST & dst, OBJLIST & src)
{
    for (auto Dst : dst)
	{
		if (true == Dst->isDead())
			continue;

		for (auto Src : src)
		{
			if (true == Src->isDead())
				continue;

			RECT rc = {};

			// IntersectRect: 두 사각형에 대한 충돌을 검사한다.
			// 충돌이 일어나면 첫번째 인자에 곂친 영역의 사각형을 기록하고 true를 반환한다.
			if (IntersectRect(&rc, &(Dst->GetInfo().rect), &(Src->GetInfo().rect)))
			{
				Dst->SetDead(true);
				Src->SetDead(true);
			}
		}
	}
}

void CCollisionManager::        CollisionSphere     (OBJLIST & dst, OBJLIST & src)
{
    for (auto Dst : dst)
	{
		if (true == Dst->isDead())
			continue;

		for (auto Src : src)
		{
			if (true == Src->isDead())
				continue;
			
			if (CheckSphere(Dst, Src))
			{
				//Dst->SetDead(true);
				Dst->SetDamage(Src->GetAtt());
				Src->SetDead(true);
			}
		}
	}
}

void CCollisionManager::        COllisionImage      (OBJLIST & dst, OBJLIST & src)
{
    for (OBJITER dstObj = dst.begin()
        ; dstObj != dst.end(); ++dstObj)
    {
        if (true == (*dstObj)->isDead())
            continue;

        for (OBJITER srcObj = dst.begin()
            ; srcObj != dst.end(); ++srcObj)
        {
            if (true == (*srcObj)->isDead())
                continue;


        }
    }
}

bool CCollisionManager::        CheckSphere         (CObj * dst, CObj * src)
{
 //   // 두 원의 반지름 합을 먼저 구한다.
	//float fRadSum = (dst->GetInfo().fCY / 2) + (src->GetInfo().fCY / 2);

	//// 두 원의 중점 간의 거리를 구한다.
	//// 피타고라스를 이용한다.
	//float fWidth = dst->GetInfo().fX - src->GetInfo().fX;
	//float fHeight = dst->GetInfo().fY - src->GetInfo().fY;
	//float fDist = sqrtf(fWidth * fWidth + fHeight * fHeight);

	//// 두 원의 반지름의 합이 중점 간의 거리보다 크거나 같으면 두 원은 충돌되었다!
	//if (fRadSum >= fDist)
	//	return true;

    float dx = FLOAT(dst->GetInfo().rect.left) + FLOAT(dst->GetInfo().rect.right - dst->GetInfo().rect.left) / 2.f;
    float dy = FLOAT(dst->GetInfo().rect.top) + FLOAT(dst->GetInfo().rect.bottom - dst->GetInfo().rect.top) / 2.f;

    float sx = FLOAT(src->GetInfo().rect.left) + FLOAT(src->GetInfo().rect.right - src->GetInfo().rect.left) / 2.f;
    float sy = FLOAT(src->GetInfo().rect.top) + FLOAT(src->GetInfo().rect.bottom - src->GetInfo().rect.top) / 2.f;

    float fRadSum = FLOAT(dst->GetInfo().rect.right - dst->GetInfo().rect.left) / 2.f + FLOAT(src->GetInfo().rect.right - src->GetInfo().rect.left);

    float fWidth = dx - sx;
    float fHeight = dy - sy;
    float fDist = sqrtf(fWidth * fWidth + fHeight * fHeight);

    if (fDist <= fRadSum)
        return true;
    
	return false;
}

bool CCollisionManager::        CheckImage          (CObj * dst, CObj * src)
{
    INT destW;// = dst->Get
    INT destH;

    return false;
}

