#pragma once
#include "StateManager.h"

class CStHAtkR
    : public CStateManager
{
public:
    CStHAtkR();
    virtual ~CStHAtkR();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
    virtual int Update();
};