#pragma once
#include "StateManager.h"

class CStdLeg :
    public CStateManager
{
public:
    CStdLeg();
    virtual ~CStdLeg();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void handle(HDC hdc) override;

    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
};