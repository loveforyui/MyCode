#pragma once
#include "StateManager.h"

class CStUpAtkBodyL
    : public CStateManager
{
public:
    CStUpAtkBodyL();
    virtual ~CStUpAtkBodyL();
public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};