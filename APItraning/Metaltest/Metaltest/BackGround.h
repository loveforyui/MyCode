#ifndef __background_h__
#define __background_h__
#include "Object.h"


class BackGround :
    public Object
{
public:
    BackGround();
    ~BackGround();

    // Object을(를) 통해 상속됨
    virtual void Initialize() override;
    virtual void Initialize(OBJINFO &) override;
    virtual void Render(HDC) override;
    virtual void Release() override;
    virtual int  Update();

private:
    vector<Image*> m_vStage;
};
#endif // !__background_h__
