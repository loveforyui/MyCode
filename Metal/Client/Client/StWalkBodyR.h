#pragma once
#include "StateManager.h"

class CStWalkBodyR
    : public CStateManager
{
public:
    CStWalkBodyR();
    virtual ~CStWalkBodyR();

public:
    // CStateManager��(��) ���� ��ӵ�
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;

private:
    //vector<ObjImg*>::iterator iter = m_vImage->begin()
};