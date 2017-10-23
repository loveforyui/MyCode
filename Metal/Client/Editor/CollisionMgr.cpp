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

			// IntersectRect: �� �簢���� ���� �浹�� �˻��Ѵ�.
			// �浹�� �Ͼ�� ù��° ���ڿ� ��ģ ������ �簢���� ����ϰ� true�� ��ȯ�Ѵ�.
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
			
			float fMoveX = 0.f; // x������ �İ�� ��ŭ �о ��
			float fMoveY = 0.f; // x������ �İ�� ��ŭ �о ��

			if (CheckRect(Dst, Src, &fMoveX, &fMoveY))
			{
				if (fMoveX > fMoveY) // y�������� �о ��
				{
					float fX = Src->GetInfo().fX;
					float fY = Src->GetInfo().fY;

					if (Dst->GetInfo().fY > fY)
						fMoveY *= -1.f;

					Src->SetPos(fX, fY + fMoveY);
				}
				else // x�������� �о ��
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
	// �� ���� ������ ���� ���� ���Ѵ�.
	float fRadSum = (pDst->GetInfo().fCY / 2) + (pSrc->GetInfo().fCY / 2);

	// �� ���� ���� ���� �Ÿ��� ���Ѵ�.
	// ��Ÿ��󽺸� �̿��Ѵ�.
	float fWidth = pDst->GetInfo().fX - pSrc->GetInfo().fX;
	float fHeight = pDst->GetInfo().fY - pSrc->GetInfo().fY;
	float fDist = sqrtf(fWidth * fWidth + fHeight * fHeight);

	// �� ���� �������� ���� ���� ���� �Ÿ����� ũ�ų� ������ �� ���� �浹�Ǿ���!
	if (fRadSum >= fDist)
		return true;

	return false;
}

bool CCollisionMgr::CheckRect(CObj * pDst, CObj * pSrc, float * pMoveX, float * pMoveY)
{
	// �浹�� �� �簢���� ���� �������� ���� ���Ѵ�.
	float fRadSumX = pDst->GetInfo().fCX / 2 + pSrc->GetInfo().fCX / 2;

	// �浹�� �� �簢���� ���� �������� ���� ���Ѵ�.
	float fRadSumY = pDst->GetInfo().fCY / 2 + pSrc->GetInfo().fCY / 2;

	// �� �簢���� x ���� �Ÿ��� ���� ������ ���Ѵ�.
	float fWidth = abs(pDst->GetInfo().fX - pSrc->GetInfo().fX);

	// �� �簢���� y ���� �Ÿ��� ���� ������ ���Ѵ�.
	float fHeight = abs(pDst->GetInfo().fY - pSrc->GetInfo().fY);

	// �� ���� ���̸� �� �簢���� �浹�Ǿ���!
	if (fRadSumX >= fWidth && fRadSumY >= fHeight)
	{
		*pMoveX = fRadSumX - fWidth;
		*pMoveY = fRadSumY - fHeight;
		return true;
	}


	return false;
}
