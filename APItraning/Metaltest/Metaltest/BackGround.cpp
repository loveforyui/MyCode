#include "stdafx.h"
#include "BackGround.h"


BackGround::BackGround()
{
}


BackGround::~BackGround()
{
    for (vector<Image*>::iterator iter = m_vStage.begin();
        iter != m_vStage.end(); ++iter)
    {
        SafeDelete<Image*>((*iter));
    }
    for (vector<Object*>::iterator iter = m_vLineObj.begin();
        iter != m_vLineObj.end(); ++iter)
    {
        SafeDelete<Object*>((*iter));
    }
}

void BackGround::Initialize()
{
}

void BackGround::Initialize(OBJINFO & ref)
{
    m_objInfo = ref;
    m_iState_body = 0;
    m_iState_leg = 0;
    isInit = true;

    m_vStage.push_back(new Image(L"../resource/background/background_line.png"));
    m_vStage.push_back(new Image(L"../resource/background/bg_cloud.png"));
    m_vStage.push_back(new Image(L"../resource/background/bg_01.png"));
    m_vStage.push_back(new Image(L"../resource/background/stage01-01.png"));
}

void BackGround::Render(HDC hdc)
{
    Graphics rend(hdc);
    if (isInit)
    {
        rend.DrawImage(m_vStage[0], m_objInfo.rect.left, m_objInfo.rect.top);
        isInit = false;
    }
    else
    {
        for (vector<Image*>::size_type iter = 1;
            iter < m_vStage.size(); ++iter)
        {
            rend.DrawImage(m_vStage[iter], m_objInfo.rect.left, m_objInfo.rect.top);
        }
        
    }
}

void BackGround::Release()
{
}

int BackGround::Update()
{
    return 0;
}
