#pragma once
#include "StateManager.h"
class EriStJmpBody :
    public StateManager
{
public:
    EriStJmpBody();
    virtual ~EriStJmpBody();

    // StateManager��(��) ���� ��ӵ�
    virtual void handle(HDC) override;
};

