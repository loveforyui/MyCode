#pragma once
#include "Scene.h"

class CLogo
    : public CScene
{
public:
    CLogo();
    virtual ~CLogo();

private:


    // CScene��(��) ���� ��ӵ�
    virtual void Initialize() override;

    virtual void Update() override;

    virtual void Render(HDC hDC) override;

    virtual void Release() override;

private:
    FLOAT m_fas;
};
