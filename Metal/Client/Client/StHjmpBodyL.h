#pragma once

#include "StateManager.h"

class CStHjmpBodyL
    : public CStateManager
{
public:
    CStHjmpBodyL();
    virtual ~CStHjmpBodyL();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
    virtual int  Update();
};