#pragma once
#include "StateManager.h"
class FioStJmpBody :
    public StateManager
{
public:
    FioStJmpBody();
    ~FioStJmpBody();

    // StateManager��(��) ���� ��ӵ�
    virtual void handle(HDC) override;
    virtual void handlf(HDC) override;
};

