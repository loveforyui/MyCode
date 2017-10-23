#include "stdafx.h"
#include "MyEdit.h"
#include "Line.h"
#include "Building.h"

CMyEdit::CMyEdit()
{
}


CMyEdit::~CMyEdit()
{
	Release();
}

void CMyEdit::Initialize()
{

}

void CMyEdit::Update()
{
	float fScrollX = CScrollMgr::GetInstance()->GetScrollX();

	LINEINFO tInfo;

    tInfo.tLPoint.fX = float(CMouse::GetMousePos().x - fScrollX);
    tInfo.tLPoint.fY = float(CMouse::GetMousePos().y);

	if (KEY_DOWN(VK_LBUTTON))
	{
		// 마우스 좌 클릭 시 라인의 시작점 세팅.
		tInfo.tLPoint.fX = float(CMouse::GetMousePos().x - fScrollX);
		tInfo.tLPoint.fY = float(CMouse::GetMousePos().y);

		tInfo.tRPoint.fX = float(CMouse::GetMousePos().x - fScrollX);
		tInfo.tRPoint.fY = float(CMouse::GetMousePos().y);

		CLineMgr::GetInstance()->GetLineList().push_back(new CLine(tInfo));
	}

	if (KEY_UP(VK_LBUTTON))
	{
		// KEY_UP 시에는 라인의 끝점 세팅.
		tInfo.tRPoint.fX = float(CMouse::GetMousePos().x - fScrollX);
		tInfo.tRPoint.fY = float(CMouse::GetMousePos().y);

		CLineMgr::GetInstance()->GetLineList().back()->SetRPoint(tInfo.tRPoint);
	}

    if (KEY_UP('R'))
    {
        CLineMgr::GetInstance()->LoadData();
        CObjManager::GetInst()->LoadData();
    }
    if (KEY_UP('S'))
    {
        CLineMgr::GetInstance()->SaveData();
        CObjManager::GetInst()->SaveData();
    }
    if (KEY_UP(VK_LCONTROL))
    {
        CObj* pObj = CAbstractFactory<CBuilding>::CreateObj(
            float(CMouse::GetMousePos().x - fScrollX)
            , float(CMouse::GetMousePos().y)
        , 100.f, 100.f);
        CObjManager::GetInst()->AddObj(pObj, OBJ_THINGS);
    }
    if (KEY_PRESSING('Z'))
    {
        CCollisionManager::CollisionRect(OBJ_MGR_GETLIST(OBJ_THINGS), OBJ_MGR_GETLIST(OBJ_MOUSE));
    }
}

void CMyEdit::Render(HDC hDC)
{	
 //   CObjManager::GetInst()->Render(hDC);
	//CLineMgr::GetInstance()->Render(hDC);
}

void CMyEdit::Release()
{
	CLineMgr::GetInstance()->SaveData();
    CObjManager::GetInst()->SaveData();
}
