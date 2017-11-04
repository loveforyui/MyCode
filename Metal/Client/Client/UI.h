#pragma once
#include "Obj.h"

class CUI
    :public CObj
{
public:
    CUI();
    virtual ~CUI();
public:
    // CObj��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Release() override;
    virtual void Render(HDC hdc) override;
    virtual int  Update();
    void UserLife(HDC hdc);
    void UserGunBomb(HDC hdc);
    void infoDraw(HDC hdc, INT point, float fx, float fy, float fcx, float fcy);


private:
    vector<ObjImg*>::iterator gun_begin;
    vector<ObjImg*>::iterator gun_end;

    vector<ObjImg*>::iterator point_begin;
    vector<ObjImg*>::iterator point_end;

    vector<ObjImg*>::iterator cha_begin;
    vector<ObjImg*>::iterator cha_end;
};