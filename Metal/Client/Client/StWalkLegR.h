#pragma once
#include "StateManager.h"

class CStWalkLegR
    : public CStateManager
{
public:
    CStWalkLegR();
    virtual ~CStWalkLegR();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
};
