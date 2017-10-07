#ifndef __background_h__
#define __background_h__
#include "Object.h"

class BackGround :
    public Object
{
public:
    BackGround();
    ~BackGround();

public:
    // Object을(를) 통해 상속됨
    virtual void Initialize() override;
    virtual void Initialize(OBJINFO &) override;
    virtual void Render(HDC) override;
    virtual void Release() override;
    virtual int  Update();

private:
    BOOL isInit;
    vector<Image*> m_vStage;    
public:
    vector<Object*> m_vLineObj;
    vector<INT> m_vfStage;
};
#endif // !__background_h__