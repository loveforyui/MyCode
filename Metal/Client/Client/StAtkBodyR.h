#pragma once
#include "StateManager.h"

class CStAtkBodyR
    : public CStateManager
{
public:
    CStAtkBodyR();
    virtual ~CStAtkBodyR();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
    virtual int  Update();
};
