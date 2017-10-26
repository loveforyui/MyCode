#include "stdafx.h"
#include "MyEdit.h"
#include "Line.h"
#include "Obj.h"
#include "Things.h"
#include "Mouse.h"
#include "Monster.h"

//#include "Building.h"

CMyEdit::CMyEdit()
    : m_iMode(1)
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
    
    tInfo.tLPoint.fX = CMouse::GetMousePos().x - fScrollX;
    tInfo.tLPoint.fY = CMouse::GetMousePos().y;

    if (KEY_UP('1'))
    {
        m_iMode = 1;
    }
    if (KEY_UP('2'))
    {
        m_iMode = 2;
    }
    if (KEY_UP('3'))
    {
        m_iMode = 3;
    }
    if (KEY_UP('4'))
    {
        m_iMode = 4;
    }

    if (1 == m_iMode)
    {
        if (!isClick)
        {
            if (KEY_DOWN(VK_LBUTTON))
            {
                isClick = true;
                // 마우스 좌 클릭 시 라인의 시작점 세팅.
                tInfo.tLPoint.fX = CMouse::GetMousePos().x - fScrollX;
                tInfo.tLPoint.fY = CMouse::GetMousePos().y;

                tInfo.tRPoint.fX = CMouse::GetMousePos().x - fScrollX;
                tInfo.tRPoint.fY = CMouse::GetMousePos().y;

                CLineMgr::GetInstance()->GetLineList().push_back(new CLine(tInfo));
            }
        }
        else
        {
            if (KEY_UP(VK_LBUTTON))
            {
                isClick = false;
                // KEY_UP 시에는 라인의 끝점 세팅.
                tInfo.tRPoint.fX = CMouse::GetMousePos().x - fScrollX;
                tInfo.tRPoint.fY = CMouse::GetMousePos().y;

                CLineMgr::GetInstance()->GetLineList().back()->SetRPoint(tInfo.tRPoint);
            }
        }
    }
    else if (2 == m_iMode)
    {
        if (!isClick)
        {
            if (KEY_UP(VK_LBUTTON))
            {
                isClick = true;

                POINT pt = {};
                GetCursorPos(&pt);
                ScreenToClient(g_hWnd, &pt);

                tInfo.tLPoint.fX = CMouse::GetMousePos().x - fScrollX;
                tInfo.tLPoint.fY = CMouse::GetMousePos().y;

                tInfo.tRPoint.fX = CMouse::GetMousePos().x - fScrollX;
                tInfo.tRPoint.fY = CMouse::GetMousePos().y;

                CObj* pObj = CAbstractFactory<CThings>::CreateObj(pt.x - fScrollX, pt.y);
                CObjManager::GetInst()->AddObj(pObj, OBJ_THINGS);

                //CLineMgr::GetInstance()->GetLineList().push_back(new CLine(tInfo));
            }
        }
        else
        {
            if (KEY_UP(VK_RBUTTON))
            {
                isClick = false;
                // KEY_UP 시에는 라인의 끝점 세팅.
                POINT pt = {};
                GetCursorPos(&pt);
                ScreenToClient(g_hWnd, &pt);
                tInfo.tRPoint.fX = CMouse::GetMousePos().x - fScrollX;
                tInfo.tRPoint.fY = CMouse::GetMousePos().y;
                
                float fcx = abs(OBJ_MGR_GETOBJ(OBJ_THINGS)->GetInfo().fX - tInfo.tRPoint.fX);
                float fcy = abs(OBJ_MGR_GETOBJ(OBJ_THINGS)->GetInfo().fY - tInfo.tRPoint.fY);
                float fx = OBJ_MGR_GETOBJ(OBJ_THINGS)->GetInfo().fX + (fcx / 2);
                float fy = OBJ_MGR_GETOBJ(OBJ_THINGS)->GetInfo().fY + (fcy / 2);

                OBJ_MGR_GETOBJ(OBJ_THINGS)->SetPos(fx, fy);
                OBJ_MGR_GETOBJ(OBJ_THINGS)->SetWH(fcx, fcy);
            }
        }
    }
    else if (3 == m_iMode)
    {
        if (KEY_DOWN(VK_LBUTTON))
        {
            isClick = true;

            POINT pt = {};
            GetCursorPos(&pt);
            ScreenToClient(g_hWnd, &pt);

            tInfo.tLPoint.fX = CMouse::GetMousePos().x - fScrollX;
            tInfo.tLPoint.fY = CMouse::GetMousePos().y;

            tInfo.tRPoint.fX = CMouse::GetMousePos().x - fScrollX;
            tInfo.tRPoint.fY = CMouse::GetMousePos().y;

            CObj* pObj = CAbstractFactory<CMonster>::CreateObj(pt.x - fScrollX, pt.y);
            CObjManager::GetInst()->AddObj(pObj, OBJ_MONSTER);

            //CLineMgr::GetInstance()->GetLineList().push_back(new CLine(tInfo));
        }
        if (KEY_UP(VK_RBUTTON))
        {
            isClick = false;
            // KEY_UP 시에는 라인의 끝점 세팅.
            POINT pt = {};
            GetCursorPos(&pt);
            ScreenToClient(g_hWnd, &pt);
            tInfo.tRPoint.fX = CMouse::GetMousePos().x - fScrollX;
            tInfo.tRPoint.fY = CMouse::GetMousePos().y;

            float fcx = abs(OBJ_MGR_GETOBJ(OBJ_MONSTER)->GetInfo().fX - tInfo.tRPoint.fX);
            float fcy = abs(OBJ_MGR_GETOBJ(OBJ_MONSTER)->GetInfo().fY - tInfo.tRPoint.fY);
            float fx = OBJ_MGR_GETOBJ(OBJ_MONSTER)->GetInfo().fX + (fcx / 2);
            float fy = OBJ_MGR_GETOBJ(OBJ_MONSTER)->GetInfo().fY + (fcy / 2);

            OBJ_MGR_GETOBJ(OBJ_MONSTER)->SetPos(fx, fy);
            OBJ_MGR_GETOBJ(OBJ_MONSTER)->SetWH(fcx, fcy);
        }
        if (KEY_UP('Q'))
        {
            if(!OBJ_MGR_GETLIST(OBJ_MONSTER).empty())
                OBJ_MGR_GETLIST(OBJ_MONSTER).pop_back();
        }
    }
    else if (4 == m_iMode)
    {

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
    if (KEY_PRESSING('Z'))
    {
        CCollisionMgr::CollisionRect(OBJ_MGR_GETLIST(OBJ_THINGS), OBJ_MGR_GETLIST(OBJ_MOUSE));
        CCollisionMgr::CollisionRect(OBJ_MGR_GETLIST(OBJ_MONSTER), OBJ_MGR_GETLIST(OBJ_MOUSE));
    }
}

void CMyEdit::Render(HDC hdc)
{	
    if (isClick)
    {
        MoveToEx    (hdc, tInfo.tLPoint.fX, tInfo.tLPoint.fY, nullptr);
        LineTo      (hdc, tInfo.tRPoint.fX, tInfo.tRPoint.fY);
    }
    
    float fScrollX = CScrollMgr::GetInstance()->GetScrollX();
    wchar_t         pos[64];
    switch (m_iMode)
    {
    case 1:
        swprintf_s(pos, L"Mode: %s size: %d", L"Line", CLineMgr::GetInstance()->GetLineList().size());
        break;
    case 2:
        swprintf_s(pos, L"Mode: %s size: %d", L"Things", OBJ_MGR_GETLIST(OBJ_THINGS).size());
        break;
    case 3:
        swprintf_s(pos, L"Mode: %s size: %d", L"Monster", OBJ_MGR_GETLIST(OBJ_MONSTER).size());
        break;
    case 4:
        swprintf_s(pos, L"Mode: %s size: %d", L"MoveLine", OBJ_MGR_GETLIST(OBJ_MONSTER).size());
        break;
    }
    
    //wsprintf();
    SetTextAlign(hdc, TA_LEFT);
    SetBkMode(hdc, TRANSPARENT);
    TextOut(hdc, - fScrollX, 0, pos, wcslen(pos));
    //CObjManager::GetInst()->Render(hDC);
	//CLineMgr::GetInstance()->Render(hDC);
}

void CMyEdit::Release()
{
	//CLineMgr::GetInstance()->SaveData();
    //CObjManager::GetInst()->SaveData();
}
