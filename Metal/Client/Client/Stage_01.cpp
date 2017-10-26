#include "stdafx.h"
#include "Stage_01.h"
#include "BackGround.h"
#include "Player.h"
#include "Obj.h"

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

        pObj->SetPos(100.f, 100.f);

        OBJ_MGR_GETLIST(OBJ_PLAYER).push_back(pObj);
    }
}

void CStage_01::Update()
{
    CObjManager::GetInst()->Update();
    CScrollMgr::GetInstance()->Update();
}

void CStage_01::Render(HDC hDC)
{
    CObjManager::GetInst()->Render(hDC);
}

void CStage_01::Release()
{
}