#pragma once
#include "StateManager.h"

class CStHupAtkL
    : public CStateManager
{
public:
    CStHupAtkL();
    virtual ~CStHupAtkL();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;
    virtual int Update();
};