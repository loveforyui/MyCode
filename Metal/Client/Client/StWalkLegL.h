#pragma once
#include "StateManager.h"

class CStWalkLegL
    : public CStateManager
{
public:
    CStWalkLegL();
    virtual ~CStWalkLegL();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};