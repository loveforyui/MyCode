#pragma once
#include "Object.h"
class player :
    public Object
{
public:
    player();
    virtual ~player();

public:
    // Object을(를) 통해 상속됨
    virtual void    Initialize();
    virtual void    Initialize(OBJINFO&);
    virtual void    Render(HDC);
    virtual void    Release();
    virtual int     Update();

public:
    void SetLine(vector<INT>*);

private:
    // 총구 각도
    FLOAT           m_fRadian;
    // 주인공 이름
    SHORT           m_iName;
    // 디버그 모드
    BOOL            isDEBUG;
    // 이미지 상태
    StateManager*   m_hState_leg;
    StateManager*   m_hState_body;
    // 선충돌
    vector<INT>*    m_pLine;
    //
};

