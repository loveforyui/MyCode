#include "stdafx.h"
#include "Stage_01.h"
#include "BackGround.h"
#include "Player.h"
#include "Obj.h"
#include "UI.h"

CStage_01::CStage_01()
{
}

CStage_01::~CStage_01()
{
}

void CStage_01::Initialize()
{
    char buf[256] = "";
    strcpy_s(buf, IMG_PATH);
    strcat_s(buf, "background/");
    IMG_LOAD(L"background/", buf);
    m_vImage = IMG_GET_V(L"background/");

    if (OBJ_MGR_GETLIST(OBJ_BACKGROUD).empty())
    {
        vector<ObjImg*>* objimg = IMG_GET_V(L"background/");
        OBJ_MGR_GETLIST(OBJ_BACKGROUD).push_back(CAbstractFactory<CBackGround>::CreateObj(objimg));
    }
    if (OBJ_MGR_GETLIST(OBJ_PLAYER).empty())
    {
        CObj* pObj = CAbstractFactory<CPlayer>::CreateObj();

        pObj->SetPos(100.f, 50.f);

        OBJ_MGR_GETLIST(OBJ_PLAYER).push_back(pObj);
    }
    if (OBJ_MGR_GETLIST(OBJ_UI).empty())
    {
        CObj* pObj = CAbstractFactory<CUI>::CreateObj();
        OBJ_MGR_GETLIST(OBJ_UI).push_back(pObj);
    }

    CSoundMgr::GetInstance()->PlayBGM(L"MS3ALL_F_00010.wav");
}

void CStage_01::Update()
{
    CObjManager::GetInst()->Update();
    CScrollMgr::GetInstance()->Update();
}

void CStage_01::Render(HDC hDC)
{
    HDC hdc = GetDC(g_hWnd);

    float fScrollX = CScrollMgr::GetInstance()->GetScrollX();
    //float fScrollY = CScrollMgr::GetInstance()->GetScrollY();

    CObjManager::GetInst()->Render(hDC);
    CLineMgr::GetInstance()->Render(hDC);

    StretchBlt(hdc
        , INT(fScrollX * 4.f)
        , 0
        , INT(3823 * 4.f)
        , INT((WINCY)*4.f)
        , hDC
        , 0, 0
        , 3823, WINCY
        , SRCCOPY);

    ReleaseDC(g_hWnd, hdc);
}

void CStage_01::Release()
{
}