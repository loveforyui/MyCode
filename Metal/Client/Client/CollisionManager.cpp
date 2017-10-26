#include "stdafx.h"
#include "CollisionManager.h"
#include "Obj.h"

CCollisionManager::CCollisionManager()
{
}

CCollisionManager::~CCollisionManager()
{
}

void CCollisionManager::CollisionRect(OBJLIST & dst, OBJLIST & src)
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

			// IntersectRect: �� �簢���� ���� �浹�� �˻��Ѵ�.
			// �浹�� �Ͼ�� ù��° ���ڿ� ��ģ ������ �簢���� ����ϰ� true�� ��ȯ�Ѵ�.
			if (IntersectRect(&rc, &(Dst->GetInfo().rect), &(Src->GetInfo().rect)))
			{
				Dst->SetDead();
				Src->SetDead();
			}
		}
	}
}

void CCollisionManager::CollisionSphere(OBJLIST & dst, OBJLIST & src)
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
				Dst->SetDead();
				//Dst->SetDamage(Src->GetAtt());
				Src->SetDead();
			}
		}
	}
}

void CCollisionManager::COllisionImage(OBJLIST & dst, OBJLIST & src)
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

bool CCollisionManager::CheckSphere(CObj * dst, CObj * src)
{
    // �� ���� ������ ���� ���� ���Ѵ�.
	float fRadSum = (dst->GetInfo().fCY / 2) + (src->GetInfo().fCY / 2);

	// �� ���� ���� ���� �Ÿ��� ���Ѵ�.
	// ��Ÿ��󽺸� �̿��Ѵ�.
	float fWidth = dst->GetInfo().fX - src->GetInfo().fX;
	float fHeight = dst->GetInfo().fY - src->GetInfo().fY;
	float fDist = sqrtf(fWidth * fWidth + fHeight * fHeight);

	// �� ���� �������� ���� ���� ���� �Ÿ����� ũ�ų� ������ �� ���� �浹�Ǿ���!
	if (fRadSum >= fDist)
		return true;

	return false;
}

bool CCollisionManager::CheckImage(CObj * dst, CObj * src)
{
    INT destW;// = dst->Get
    INT destH;

    return false;
}

