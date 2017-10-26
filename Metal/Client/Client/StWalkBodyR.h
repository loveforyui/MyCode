#pragma once
#include "StateManager.h"

class CStWalkBodyR
    : public CStateManager
{
public:
    CStWalkBodyR();
    virtual ~CStWalkBodyR();

public:
    // CStateManager을(를) 통해 상속됨
    virtual void initialize() override;
    virtual void handle(HDC hdc) override;

private:
    //vector<ObjImg*>::iterator iter = m_vImage->begin()
};