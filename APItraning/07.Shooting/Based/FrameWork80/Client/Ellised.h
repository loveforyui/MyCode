#pragma once
#include "StateManager.h"
class Ellised :
    public StateManager
{
public:
    Ellised();
    ~Ellised();

    // StateManager��(��) ���� ��ӵ�
    virtual void Handle() override;
};

