#pragma once
#include "StateManager.h"
class FioStdBody :
    public StateManager
{
public:
    FioStdBody();
    ~FioStdBody();

    // StateManager��(��) ���� ��ӵ�
    virtual void handle(HDC) override;
    virtual void handlf(HDC) override;
};

