#pragma once
#include "StateManager.h"

class CStHupAtkR
    : public CStateManager
{
public:
    CStHupAtkR();
    virtual ~CStHupAtkR();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
    virtual int Update();
};