#pragma once
#include "Scene.h"

class CStage_01
    : public CScene
{
public:
    CStage_01();
    virtual ~CStage_01();

private:


    // CScene��(��) ���� ��ӵ�
    virtual void Initialize() override;

    virtual void Update() override;

    virtual void Render(HDC hDC) override;

    virtual void Release() override;

};
