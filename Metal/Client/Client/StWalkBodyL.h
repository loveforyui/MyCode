#pragma once

#include "StateManager.h"
class CStWalkBodyL
    : public CStateManager
{
public:
    CStWalkBodyL();
    virtual ~CStWalkBodyL();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};