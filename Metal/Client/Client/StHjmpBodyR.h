#pragma once

#include "StateManager.h"

class CStHjmpBodyR
    : public CStateManager
{
public:
    CStHjmpBodyR();
    virtual ~CStHjmpBodyR();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
    virtual int  Update();
};