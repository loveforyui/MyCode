#pragma once
#include "StateManager.h"

class CStUpBodyL
    : public CStateManager
{
public:
    CStUpBodyL();
    virtual ~CStUpBodyL();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};