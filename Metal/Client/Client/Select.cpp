#include "stdafx.h"
#include "Select.h"

CSelect::CSelect()
{
}

CSelect::~CSelect()
{
    Release();
}

void CSelect::Initialize()
{
    char buf[256] = "";
    strcpy_s(buf, IMG_PATH);
    strcat_s(buf, "hud/select/");
    IMG_LOAD(L"hud/select/", buf);
    m_vImage = IMG_GET_V(L"hud/select/");
}

void CSelect::Update()
{
    CharacterSelect_U();
}

void CSelect::Render(HDC hDC)
{
    CharacterSelect_R(hDC);
}

void CSelect::Release()
{
}

void CSelect::CharacterSelect_R(HDC hDC)
{
    HDC hdc = GetDC(g_hWnd);
    static FLOAT fas = 0.f;
    if (m_imgSelect.empty())
    {
        vector<ObjImg*>* select_img = IMG_GET_V(L"hud/select/");
        UINT key = 0x00001;

        for (UINT i = 0; i < select_img->size(); ++i)
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
                    IMG_DRAW_I(hDC, m_imgSelect[0x00400], 0.f, fas, FLOAT(m_imgSelect[0x00400]->GetWidth()), FLOAT(m_imgSelect[0x00400]->GetHeight()));
                    if (0 < fas)
                    {
                        fas = 0.f;
                        m_bSelect_hud = m_bSelect_hud ^ 0x00400;
                        m_bSelect_hud = m_bSelect_hud ^ 0x00200;
                        m_bSelect_hud = m_bSelect_hud ^ 0x00100;
                        m_bSelect_hud = m_bSelect_hud ^ 0x00080;
                        // Set Next State
                        //m_GameState = eGameState::GS_RUN;
                        CSceneMgr::GetInstance()->SceneChange(CSceneMgr::STAGE);
                        return;
                    }
                    continue;
                }
                if ((result & 0x00200) == 0x00200)//(m_bSelect_hud & 0x00200) == 0x00200)
                {
                    fas = fas + 3.f;
                    IMG_DRAW_I(hDC, m_imgSelect[0x00200], 0.f, fas, FLOAT(m_imgSelect[0x00200]->GetWidth()), FLOAT(m_imgSelect[0x00200]->GetHeight()));
                    continue;
                }

                if ((result & 0x00100) == 0x00100)
                {
                    fas = fas + 3.f;
                    IMG_DRAW_I(hDC, m_imgSelect[0x00100], 0.f, fas, FLOAT(m_imgSelect[0x00100]->GetWidth()), FLOAT(m_imgSelect[0x00100]->GetHeight()));
                    continue;
                }

                if ((result & 0x00080) == 0x00080)
                {
                    fas = fas + 3.f;
                    IMG_DRAW_I(hDC, m_imgSelect[0x00080], 0.f, fas, FLOAT(m_imgSelect[0x00080]->GetWidth()), FLOAT(m_imgSelect[0x00080]->GetHeight()));
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
                    IMG_DRAW_I(hDC, m_imgSelect[0x00400], 0.f, fas, FLOAT(m_imgSelect[0x00400]->GetWidth()), FLOAT(m_imgSelect[0x00400]->GetHeight()));
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
                    IMG_DRAW_I(hDC, m_imgSelect[0x00200], 0.f, fas, FLOAT(m_imgSelect[0x00200]->GetWidth()), FLOAT(m_imgSelect[0x00200]->GetHeight()));
                    continue;
                }

                if ((result & 0x00100) == 0x00100)
                {
                    fas = fas - 3.f;
                    IMG_DRAW_I(hDC, m_imgSelect[0x00100], 0.f, fas, FLOAT(m_imgSelect[0x00100]->GetWidth()), FLOAT(m_imgSelect[0x00100]->GetHeight()));
                    continue;
                }

                if ((result & 0x00080) == 0x00080)
                {
                    fas = fas - 3.f;
                    IMG_DRAW_I(hDC, m_imgSelect[0x00080], 0.f, fas, FLOAT(m_imgSelect[0x00080]->GetWidth()), FLOAT(m_imgSelect[0x00080]->GetHeight()));
                    continue;
                }
            }
#pragma endregion
            
            IMG_DRAW_I(hDC, m_imgSelect[result], 0.f, 0.f, FLOAT(m_imgSelect[result]->GetWidth()), FLOAT(m_imgSelect[result]->GetHeight()));
        }                    
    }

    //IMG_DRAW_I(m_hdc, Layer_Soldier_Select, 0.f, 0.f, Layer_Soldier_Select->GetWidth(), Layer_Soldier_Select->GetHeight());

    StretchBlt(
        hdc
        , 0, 0
        , INT(WINCX*(FLOAT(WINCX)/m_imgSelect[1]->GetWidth()))
        , INT(WINCY*(FLOAT(WINCY)/m_imgSelect[1]->GetHeight()))
        , hDC
        , 0, 0
        , WINCX
        , WINCY
        , SRCCOPY);
    ReleaseDC(g_hWnd, hdc);
}

void CSelect::CharacterSelect_U()
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
            // Line 생성
            CLineMgr::GetInstance()->Initialize();

            
            // player 생성
            /*if (OBJ_MGR_GETLIST(OBJ_PLAYER).empty())
            {
                CObj* pObj = CAbstractFactory<CPlayer>::CreateObj();

                pObj->SetPos(100.f, 100.f);

                OBJ_MGR_GETLIST(OBJ_PLAYER).push_back(pObj);
            }*/
        }
    }
}
