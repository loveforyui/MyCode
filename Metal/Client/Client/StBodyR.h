#pragma once
#include "StateManager.h"

class CStBodyR :
    public CStateManager
{
public:
    CStBodyR();
    virtual ~CStBodyR();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void handle(HDC hdc) override;

private:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
};