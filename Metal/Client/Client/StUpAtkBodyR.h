#pragma once
#include "StateManager.h"

class CStUpAtkBodyR
    : public CStateManager
{
public:
    CStUpAtkBodyR();
    virtual ~CStUpAtkBodyR();
public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
    virtual int Update();
};