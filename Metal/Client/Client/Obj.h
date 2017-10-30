#pragma once

class CObj
{
public:
    CObj();
    CObj(INFO& info) 
    { 
        m_tInfo = info;
    }
    virtual ~CObj();

public:
    virtual void    Init()              = 0;
    virtual void    Release()           = 0;
    virtual void    Render(HDC hdc)     = 0;
    virtual int     Update();

public:
    void            SetAngle            (float fAngle)      { m_tInfo.fAngle    = fAngle; }
    void            SetPos              (float x, float y);
    void            SetWH               (float cx, float cy);
    void            SetRect             (RECT rect)         { m_tInfo.rect      = rect; }    
    void            SetImage            (vector<ObjImg*>* img)
    {
        m_tInfo.image = img;
        img_begin = m_tInfo.image->begin();
        img_end = m_tInfo.image->end();
    }
    void            SetDead             (bool b)            { m_tInfo.isDead    = b; }
    void            SetAcc              (float ac)          { m_tInfo.fAcc      = ac; }
    void            SetJAcc             (float ac)          { m_tInfo.fJumpAcc  = ac; }
    void            SetCurState         (eOBJSTATE eobj)    { m_tInfo.curState  = eobj; }
    void            SetCurState         (int eobj)          { m_tInfo.curState  = eobj; }
    void            SetSpeed            (float speed)       { m_tInfo.fSpeed    = speed; }
    void            SetHp               (int hp)            { m_tInfo.iMaxHp    = hp; m_tInfo.iHP = hp; }
    void            SetDamage           (int atk)           { m_tInfo.iHP -= atk; if (m_tInfo.iHP <= 0) { SetDead(true); } }

public:
    FLOAT           GetImgW             ();
    FLOAT           GetImgH             ();
    const INFO&     GetInfo             ()                  { return m_tInfo; }
    bool            isDead              ()                  { return m_tInfo.isDead; }
    float           GetSpeed            ()                  { return m_tInfo.fSpeed; }
    float           GetAngle            ()                  { return m_tInfo.fAngle; }
    INT             GetAtt              ()                  { return m_tInfo.iAtt; }
    map<const TCHAR*, vector<ObjImg*>*>& GetImgv()          { return m_image; }


public:
    void            AddImage            (ObjImg* img) 
    { 
        m_tInfo.image->push_back(img);
        img_begin = m_tInfo.image->begin();
        img_end = m_tInfo.image->end();
    }
    void            ImageRender(HDC hdc);

protected:
    INFO                                m_tInfo;

    map<const TCHAR*, vector<ObjImg*>*> m_image;
    vector<ObjImg*>::iterator           img_begin;
    vector<ObjImg*>::iterator           img_end;


};