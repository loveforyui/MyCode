#pragma once

class CObj;
class CPattern
{
private:
    CPattern();
    ~CPattern();

public:
    FLOAT   EqualLine       (CObj* obj);
    FLOAT   Quadratic       (CObj* obj);
    FLOAT   SinLine         (CObj* obj);
    FLOAT   Boss            (CObj* obj);
    FLOAT   SingleLine      (CObj* obj);
    FLOAT   SingleLineR     (CObj* obj);
    //INFO    AngleLine       (CObj* obj, FLOAT angle);
    POINT   AngleLine       (CObj* obj, FLOAT angle);
    //INFO    HeosBomb        (CObj * obj);

public:
    static CPattern* GetInstance()
    {
        if (nullptr == m_pInstance)
            m_pInstance = new CPattern;

        return m_pInstance;
    }
private:
    static CPattern* m_pInstance;
};

