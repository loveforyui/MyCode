#pragma once
#include "Scene.h"

class CLoad
    : public CScene
{
public:
    CLoad();
    ~CLoad();

public:
    // CScene��(��) ���� ��ӵ�
    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render(HDC hDC) override;
    virtual void Release() override;

private:
    HWND m_hVideo;
};