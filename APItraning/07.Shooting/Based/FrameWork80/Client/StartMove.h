#pragma once
#include "StateManager.h"
class StartMove :
    public StateManager
{
public:
    StartMove();
    virtual ~StartMove();

    // StateManager��(��) ���� ��ӵ�
    virtual void Handle() override;
};

