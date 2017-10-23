#pragma once

class CObj;
class CLine;
class CCollisionMgr
{
public:
	CCollisionMgr();
	~CCollisionMgr();

public:
	static void CollisionRect(OBJLIST& DstList, OBJLIST& SrcList);
	static void CollisionRectEX(OBJLIST& DstList, OBJLIST& SrcList);
	static void CollisionSphere(OBJLIST& DstList, OBJLIST& SrcList);
    static void CollisionLine(OBJLIST& DstList, list<CLine*> SrcList);

private:
	static bool CheckSphere(CObj* pDst, CObj* pSrc);
	static bool CheckRect(CObj* pDst, CObj* pSrc, float* pMoveX, float* pMoveY);
};

