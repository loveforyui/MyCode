#ifndef __eri_idle_h__
#define __eri_idle_h__

#include "StateManager.h"
class EriIdle :
    public StateManager
{
public:
    EriIdle();
    virtual ~EriIdle();

    // StateManager을(를) 통해 상속됨
    virtual void handle(HDC) override;

};

#endif // !__eri_idle_h__