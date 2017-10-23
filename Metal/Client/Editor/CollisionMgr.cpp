#include "stdafx.h"
#include "CollisionMgr.h"
#include "Obj.h"


CCollisionMgr::CCollisionMgr()
{
}

CCollisionMgr::~CCollisionMgr()
{
}

void CCollisionMgr::CollisionRect(OBJLIST& DstList, OBJLIST& SrcList) 
{
	for (auto Dst : DstList)
	{
		if (true == Dst->isDead())
			continue;

		for (auto Src : SrcList)
		{
			if (true == Src->isDead())
				continue;

			RECT rc = {};

			// IntersectRect: 두 사각형에 대한 충돌을 검사한다.
			// 충돌이 일어나면 첫번째 인자에 곂친 영역의 사각형을 기록하고 true를 반환한다.
			if (IntersectRect(&rc, &(Dst->GetInfo().rect), &(Src->GetInfo().rect)))
			{
				Dst->SetDead();
				//Src->SetDead();
			}
		}
	}
}

void CCollisionMgr::CollisionRectEX(OBJLIST & DstList, OBJLIST & SrcList)
{
	for (auto Dst : DstList)
	{
		if (true == Dst->isDead())
			continue;

		for (auto Src : SrcList)
		{
			if (true == Src->isDead())
				continue;
			
			float fMoveX = 0.f; // x축으로 파고든 만큼 밀어낼 양
			float fMoveY = 0.f; // x축으로 파고든 만큼 밀어낼 양

			if (CheckRect(Dst, Src, &fMoveX, &fMoveY))
			{
				if (fMoveX > fMoveY) // y방향으로 밀어낼 것
				{
					float fX = Src->GetInfo().fX;
					float fY = Src->GetInfo().fY;

					if (Dst->GetInfo().fY > fY)
						fMoveY *= -1.f;

					Src->SetPos(fX, fY + fMoveY);
				}
				else // x방향으로 밀어낼 것
				{
					float fX = Src->GetInfo().fX;
					float fY = Src->GetInfo().fY;

					if (Dst->GetInfo().fX > fX)
						fMoveX *= -1.f;

					Src->SetPos(fX + fMoveX, fY);
				}
			}
		}
	}
}

void CCollisionMgr::CollisionSphere(OBJLIST& DstList, OBJLIST& SrcList)
{
	for (auto Dst : DstList)
	{
		if (true == Dst->isDead())
			continue;

		for (auto Src : SrcList)
		{
			if (true == Src->isDead())
				continue;
			
			if (CheckSphere(Dst, Src))
			{
				//Dst->SetDead();
				//Dst->SetDamage(Src->GetAtt());
				Src->SetDead();
			}
		}
	}
}

void CCollisionMgr::CollisionLine(OBJLIST & DstList, list<CLine*> SrcList)
{
}

bool CCollisionMgr::CheckSphere(CObj* pDst, CObj* pSrc)
{
	// 두 원의 반지름 합을 먼저 구한다.
	float fRadSum = (pDst->GetInfo().fCY / 2) + (pSrc->GetInfo().fCY / 2);

	// 두 원의 중점 간의 거리를 구한다.
	// 피타고라스를 이용한다.
	float fWidth = pDst->GetInfo().fX - pSrc->GetInfo().fX;
	float fHeight = pDst->GetInfo().fY - pSrc->GetInfo().fY;
	float fDist = sqrtf(fWidth * fWidth + fHeight * fHeight);

	// 두 원의 반지름의 합이 중점 간의 거리보다 크거나 같으면 두 원은 충돌되었다!
	if (fRadSum >= fDist)
		return true;

	return false;
}

bool CCollisionMgr::CheckRect(CObj * pDst, CObj * pSrc, float * pMoveX, float * pMoveY)
{
	// 충돌할 두 사각형의 가로 반지름의 합을 구한다.
	float fRadSumX = pDst->GetInfo().fCX / 2 + pSrc->GetInfo().fCX / 2;

	// 충돌할 두 사각형의 세로 반지름의 합을 구한다.
	float fRadSumY = pDst->GetInfo().fCY / 2 + pSrc->GetInfo().fCY / 2;

	// 두 사각형의 x 중점 거리를 절대 값으로 구한다.
	float fWidth = abs(pDst->GetInfo().fX - pSrc->GetInfo().fX);

	// 두 사각형의 y 중점 거리를 절대 값으로 구한다.
	float fHeight = abs(pDst->GetInfo().fY - pSrc->GetInfo().fY);

	// 두 축이 곂이면 두 사각형은 충돌되었다!
	if (fRadSumX >= fWidth && fRadSumY >= fHeight)
	{
		*pMoveX = fRadSumX - fWidth;
		*pMoveY = fRadSumY - fHeight;
		return true;
	}


	return false;
}
