#pragma once
#include "Scene.h"

class CEnding
    : public CScene
{
public:
    CEnding();
    ~CEnding();

public:
    // CScene을(를) 통해 상속됨
    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render(HDC hDC) override;
    virtual void Release() override;

private:
    HWND m_hVideo;
};