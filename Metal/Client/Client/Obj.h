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
    void            SetAngle            (float fAngle) { m_tInfo.fAngle = fAngle; }
    void            SetPos              (float x, float y);
    void            SetWH               (float cx, float cy);
    void            SetRect             (RECT rect) { m_tInfo.rect = rect; }    
    void            SetImage            (vector<ObjImg*>* img)
    {
        m_tInfo.image = img;
        img_begin = m_tInfo.image->begin();
        img_end = m_tInfo.image->end();
    }
    void            SetDead             () { m_tInfo.isDead = true; }

public:
    FLOAT           GetImgW             ();
    FLOAT           GetImgH             ();
    const INFO&     GetInfo             () { return m_tInfo; }
    bool            isDead              () { return m_tInfo.isDead; }
    float           GetSpeed            () { return m_tInfo.fSpeed; }
    float           GetAngle            () { return m_tInfo.fAngle; }

public:
    void            AddImage            (ObjImg* img) 
    { 
        m_tInfo.image->push_back(img);
        img_begin = m_tInfo.image->begin();
        img_end = m_tInfo.image->end();
    }
    void            ImageRender(HDC hdc);

protected:
    INFO m_tInfo;

    map<const TCHAR*, vector<ObjImg*>*> m_image;
    vector<ObjImg*>::iterator img_begin;
    vector<ObjImg*>::iterator img_end;


};