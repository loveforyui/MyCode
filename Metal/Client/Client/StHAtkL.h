#pragma once
#include "StateManager.h"

class CStHAtkL
    : public CStateManager
{
public:
    CStHAtkL();
    virtual ~CStHAtkL();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
    virtual int Update();
};