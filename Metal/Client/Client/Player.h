#pragma once
#include "Obj.h"

class CPlayer
    : public CObj
{
public:
    CPlayer();
    ~CPlayer();

public:
    // CObj을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Release() override;
    virtual void Render(HDC hdc) override;
    virtual int  Update();

public:
    void InsertImage(const TCHAR* key, vector<ObjImg*>* vImg);

private:
    void KeyInput();

private:
    map<const TCHAR*, vector<ObjImg*>*> m_image;
};