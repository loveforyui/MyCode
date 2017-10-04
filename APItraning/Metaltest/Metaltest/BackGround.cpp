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
        delete (*iter);
        (*iter) = nullptr;
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

    m_vStage.push_back(new Image(L"../resource/background/stage01-01.png"));
}

void BackGround::Render(HDC hdc)
{
    Graphics rend(hdc);
    rend.DrawImage(m_vStage[0], m_objInfo.rect.left, m_objInfo.rect.top + 25);
}

void BackGround::Release()
{
}

int BackGround::Update()
{
    return 0;
}
