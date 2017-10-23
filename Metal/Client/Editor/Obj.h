#pragma once

class CObj
{
public:
    CObj();
    virtual ~CObj();

public:
    virtual void    Init()              = 0;
    virtual void    Release()           = 0;
    virtual void    Render(HDC hdc)     = 0;
    virtual int     Update();

public:
    void            SetPos              (float x, float y);
    void            SetWH               (float cx, float cy);
    void            SetRect             (RECT rect) { m_tInfo.rect = rect; }
    void            SetImage            (ObjImg* img) { m_tInfo.image->push_back(img); }
    void            SetImage            (vector<ObjImg*>* img) { m_tInfo.image = img; }
    void            SetDead             () { m_tInfo.isDead = true; }

public:
    FLOAT           GetImgW             ();
    FLOAT           GetImgH             ();
    const INFO&     GetInfo             () { return m_tInfo; }
    bool            isDead              () { return m_tInfo.isDead; }
    float           GetSpeed            () { return m_tInfo.fSpeed; }

protected:
    INFO m_tInfo;

};