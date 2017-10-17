#include "stdafx.h"
#include "MainGame.h"
#include "BackGround.h"
#include "Player.h"

#define PATH_RC "../resource/"

CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
}

void CMainGame::Initialize()
{
    // GDI+ setting
    GdiplusStartup(&m_GdiplusToken, &m_GdiplusStartI, nullptr);

    // Window Rect
    GetClientRect(g_hWnd, &m_wndRect);

    // DC Setting
    m_hdc = GetDC(g_hWnd);

    // Timer Setting
    m_dwOldT = GetTickCount();
    m_dwCurT = 0;

    //default val initialize
    m_bSelect_hud = 0x00000;

    // GameState Set
    m_GameState = eGameState::GS_START;
}

void CMainGame::Release()
{
}

void CMainGame::Render()
{
    HDC hdc = GetDC(g_hWnd);
    m_hdc = CreateCompatibleDC(hdc);
    m_hBitmap = CreateCompatibleBitmap(hdc, 3800, m_wndRect.bottom);
    m_hOldmap = (HBITMAP)SelectObject(m_hdc, m_hBitmap);

    switch (m_GameState)
    {
    case GS_START:
    {
        // BackGround Setting
        OBJITER iter = OBJ_MGR_GETLIST(OBJ_BACKGROUD).begin();

        (*iter)->Render(m_hdc);

        COLORREF rgb;
        for (int x = 0; x < (*iter)->GetImgW(); ++x)
        {
            for (int y = 0; y < (*iter)->GetImgH(); ++y)
            {
                rgb = GetPixel(m_hdc, INT(x), INT(y));

                if (255 == rgb)
                {
                    dynamic_cast<CBackGround*>(*iter)->AddFloorY(y);
                }
            }
        }

        m_GameState = eGameState::GS_SELECT;
    }
        break;
    case GS_LOAD:
    {
        
    }
        break;
    case GS_SELECT:
    {
        CharacterSelect_R(hdc);
        //m_GameState = eGameState::GS_RUN;
    }
        break;
    case GS_RUN:
    {
        for (INT id = 0; id < OBJID::OBJ_END; ++id)
        {
            OBJITER iter_begin  = OBJ_MGR_GETLIST(id).begin();
            OBJITER iter_end    = OBJ_MGR_GETLIST(id).end();

            for (; iter_begin != iter_end; ++iter_begin)
            {
                (*iter_begin)->Render(m_hdc);
            }
        }

        StretchBlt(hdc, 0, 0
            , 3800*1.92f
            , WINCY*1.92f
            , m_hdc, 0, 0, 3800, WINCY, SRCCOPY);
    }
        break;
    case GS_END:
        break;
    default:
        break;
    }
    //StretchBlt(hdc, 0, 0, 3800, WINCY, m_hdc, 0, 0, 3800, WINCY, SRCCOPY);

    DeleteObject(SelectObject(m_hdc, m_hOldmap));
    DeleteDC(m_hdc);
    ReleaseDC(g_hWnd, hdc);
}

void CMainGame::Update()
{
    switch (m_GameState)
    {
    case GS_START:
    {
        // Image Loading
        char fullPath[256] = "";
        // Hud/select Img Loadinng
        sprintf_s(fullPath, "%s%s", PATH_RC, "hud/select/");
        IMG_LOAD(L"hud/select", fullPath);

        // BackGround Img Loading
        sprintf_s(fullPath, "%s%s", PATH_RC, "background/");
        IMG_LOAD(L"BackGround", fullPath);

        // Player Img Loading
        sprintf_s(fullPath, "%s%s", PATH_RC, "fio/st/body/");
        IMG_LOAD(L"fio/stand_r", fullPath);
        sprintf_s(fullPath, "%s%s", PATH_RC, "fio/st/body_left/");
        IMG_LOAD(L"fio/stand_l", fullPath);
        sprintf_s(fullPath, "%s%s", PATH_RC, "fio/st/leg/");
        IMG_LOAD(L"fio/stand_leg", fullPath);

        // BackGround Setting
        if (OBJ_MGR_GETLIST(OBJ_BACKGROUD).empty())
        {
            vector<ObjImg*>* objimg = IMG_GET_V(L"BackGround");
           OBJ_MGR_GETLIST(OBJ_BACKGROUD).push_back(CAbstractFactory<CBackGround>::CreateObj(objimg));
        }
    }
        break;
    case GS_LOAD:
    {
        
    }
        break;
    case GS_SELECT:
    {
        CharacterSelect_U();
    }
        break;
    case GS_RUN:
        break;
    case GS_END:
        break;
    default:
        break;
    }

    CKeyManager::GetInst()->Update();
}

void CMainGame::CharacterSelect_R(HDC hdc)
{
    static FLOAT fas = 0.f;
    if (m_imgSelect.empty())
    {
        vector<ObjImg*>* select_img = IMG_GET_V(L"hud/select");
        UINT key = 0x00001;

        for (int i = 0; i < select_img->size(); ++i)
        {
            m_imgSelect[key] = select_img->at(i)->image;
            key = key << 1;
        }
    }    

    for (UINT index = 0x80000; index != 0x00000 ; index = index >> 1)
    {
        UINT result = m_bSelect_hud & index;
        if (result)
        {
#pragma region Close the door
            if (m_bSelect_hud == 0xF0FB1)
            {
                if ((result & 0x00400) == 0x00400)
                {
                    fas = fas + 3.f;
                    IMG_DRAW_I(m_hdc, m_imgSelect[0x00400], 0.f, fas, m_imgSelect[0x00400]->GetWidth(), m_imgSelect[0x00400]->GetHeight());
                    if (0 < fas)
                    {
                        fas = 0.f;
                        m_bSelect_hud = m_bSelect_hud ^ 0x00400;
                        m_bSelect_hud = m_bSelect_hud ^ 0x00200;
                        m_bSelect_hud = m_bSelect_hud ^ 0x00100;
                        m_bSelect_hud = m_bSelect_hud ^ 0x00080;
                        // Set Next State
                        m_GameState = eGameState::GS_RUN;
                    }
                    continue;
                }
                if ((result & 0x00200) == 0x00200)//(m_bSelect_hud & 0x00200) == 0x00200)
                {
                    fas = fas + 3.f;
                    IMG_DRAW_I(m_hdc, m_imgSelect[0x00200], 0.f, fas, m_imgSelect[0x00200]->GetWidth(), m_imgSelect[0x00200]->GetHeight());
                    continue;
                }

                if ((result & 0x00100) == 0x00100)
                {
                    fas = fas + 3.f;
                    IMG_DRAW_I(m_hdc, m_imgSelect[0x00100], 0.f, fas, m_imgSelect[0x00100]->GetWidth(), m_imgSelect[0x00100]->GetHeight());
                    continue;
                }

                if ((result & 0x00080) == 0x00080)
                {
                    fas = fas + 3.f;
                    IMG_DRAW_I(m_hdc, m_imgSelect[0x00080], 0.f, fas, m_imgSelect[0x00080]->GetWidth(), m_imgSelect[0x00080]->GetHeight());
                    continue;
                }
            }
#pragma endregion
#pragma region Open the door
            else
            {
                if ((result & 0x00400) == 0x00400)
                {
                    fas = fas - 3.f;
                    IMG_DRAW_I(m_hdc, m_imgSelect[0x00400], 0.f, fas, m_imgSelect[0x00400]->GetWidth(), m_imgSelect[0x00400]->GetHeight());
                    if (fas < -134.f)
                    {
                        m_bSelect_hud = m_bSelect_hud ^ 0x00400;
                        m_bSelect_hud = m_bSelect_hud ^ 0x00200;
                        m_bSelect_hud = m_bSelect_hud ^ 0x00100;
                        m_bSelect_hud = m_bSelect_hud ^ 0x00080;
                    }
                    continue;
                }
                if ((result & 0x00200) == 0x00200)//(m_bSelect_hud & 0x00200) == 0x00200)
                {
                    fas = fas - 3.f;
                    IMG_DRAW_I(m_hdc, m_imgSelect[0x00200], 0.f, fas, m_imgSelect[0x00200]->GetWidth(), m_imgSelect[0x00200]->GetHeight());
                    continue;
                }

                if ((result & 0x00100) == 0x00100)
                {
                    fas = fas - 3.f;
                    IMG_DRAW_I(m_hdc, m_imgSelect[0x00100], 0.f, fas, m_imgSelect[0x00100]->GetWidth(), m_imgSelect[0x00100]->GetHeight());
                    continue;
                }

                if ((result & 0x00080) == 0x00080)
                {
                    fas = fas - 3.f;
                    IMG_DRAW_I(m_hdc, m_imgSelect[0x00080], 0.f, fas, m_imgSelect[0x00080]->GetWidth(), m_imgSelect[0x00080]->GetHeight());
                    continue;
                }
            }
#pragma endregion
            
            IMG_DRAW_I(m_hdc, m_imgSelect[result], 0.f, 0.f, m_imgSelect[result]->GetWidth(), m_imgSelect[result]->GetHeight());
        }                    
    }

    //IMG_DRAW_I(m_hdc, Layer_Soldier_Select, 0.f, 0.f, Layer_Soldier_Select->GetWidth(), Layer_Soldier_Select->GetHeight());

    StretchBlt(hdc, 0, 0, WINCX*(FLOAT(WINCX)/m_imgSelect[1]->GetWidth()), WINCY*(FLOAT(WINCY)/m_imgSelect[1]->GetHeight()), m_hdc, 0, 0, WINCX, WINCY, SRCCOPY);
}

void CMainGame::CharacterSelect_U()
{
    if (0x00000 == m_bSelect_hud)
        //m_bSelect_hud = 0xFFBB0;
        m_bSelect_hud = 0xFF7B0;
    else if (0xFF7B0 == m_bSelect_hud)
    {
        // 문 올리는 효과
        m_bSelect_hud = 0xF87B8;
    }
    else
    {
        UINT oldp   = m_bSelect_hud & 0x0000F;
        UINT oldc   = m_bSelect_hud & 0x0F000;
        UINT result = m_bSelect_hud & 0xF0FF0;
        // 좌우의 키입력에 따른 select hud 조절
        if (KEY_UP(VK_RIGHT))
        {
            oldp = (oldp >> 1);
            oldc = (oldc >> 1);

            if (oldp == 0x00000)
                oldp = 0x00008;
            if (oldc == 0x00800)
                oldc = 0x08000;

            UINT temp = oldp | oldc;
            
            m_bSelect_hud = result | temp;
            //m_bSelect_hud
        }
        //
        if (KEY_UP(VK_LEFT))
        {
            oldp = (oldp << 1);
            oldc = (oldc << 1);

            if (oldp == 0x00010)
                oldp = 0x00001;
            if (oldc == 0x10000)
                oldc = 0x01000;

            UINT temp = oldp | oldc;
            
            m_bSelect_hud = result | temp;
        }
        // 컨트롤 누를시 캐릭터 선택
        if (KEY_UP(VK_CONTROL))
        {
            m_bSelect_hud = 0xF0FB1;

            // player 생성
            if (OBJ_MGR_GETLIST(OBJ_PLAYER).empty())
            {
                vector<ObjImg*>* objimg = IMG_GET_V(L"fio/stand_r");
                OBJ_MGR_GETLIST(OBJ_PLAYER).push_back(CAbstractFactory<CPlayer>::CreateObj());
            }
        }
    }
}
