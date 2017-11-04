#pragma once
#include "Scene.h"

class CEnding
    : public CScene
{
public:
    CEnding();
    ~CEnding();

public:
    // CScene��(��) ���� ��ӵ�
    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render(HDC hDC) override;
    virtual void Release() override;

private:
    HWND m_hVideo;
};