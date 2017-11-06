#pragma once

class CObj;

template <typename T>
class CAbstractFactory
{
public:
    static CObj* CreateObj()
    {
        CObj* pObj = new T;
        pObj->Init();

        return pObj;
    }
    static CObj* CreateObj(float x, float y)
    {
        CObj* pObj = new T;
        pObj->SetPos(x, y);
        pObj->Init();        

        return pObj;
    }
    static CObj* CreateObj(float x, float y, float cx, float cy)
    {
        CObj* pObj = new T;
        pObj->Init();
        pObj->SetPos(x, y);
        pObj->SetWH(cx, cy);

        return pObj;
    }
    static CObj* CreateObj(float x, float y, float cx, float cy, float fAngle)
    {
        CObj* pObj = new T;
        pObj->Init();
        pObj->SetPos(x, y);
        pObj->SetWH(cx, cy);
        pObj->SetAngle(fAngle);

        return pObj;
    }
    static CObj* CreateObj(ObjImg* img)
    {
        CObj* pObj = new T;
        pObj->Init();
        pObj->SetPos(0.f, 0.f);
        pObj->SetImage(img);
        pObj->SetWH(img->image->GetWidth(), img->image->GetHeight());
        pObj->SetRect(RECT{ 0, 0, LONG(img->image->GetWidth()), LONG(img->image->GetHeight()) });

        return pObj;
    }
    static CObj* CreateObj(vector<ObjImg*>* img)
    {
        CObj* pObj = new T;
        pObj->Init();
        pObj->SetPos(0.f, 0.f);
        pObj->SetImage(img);
        pObj->SetWH(FLOAT((*(img->begin()))->image->GetWidth()), FLOAT((*(img->begin()))->image->GetHeight()));

        return pObj;
    }
    static CObj* CreateObj(vector<ObjImg*>* img, float x, float y, float fAngle)
    {
        CObj* pObj = new T;
        pObj->SetPos(x, y);
        pObj->SetAngle(fAngle);
        pObj->SetImage(img);
        pObj->SetWH(FLOAT((*(img->begin()))->image->GetWidth()), FLOAT((*(img->begin()))->image->GetHeight()));
        pObj->Init();

        return pObj;
    }
    static CObj* CreateObj(INFO& info)
    {
        // ekmb 설정
        CObj* pObj = new T(info);
        pObj->Init();

        return pObj;
    }
    static CObj* CreateObj(INFO& info, ITEMKINDE k)
    {
        // ekmb 설정
        CObj* pObj = new T(info);
        dynamic_cast<CItem*>(pObj)->kind = k;
        pObj->Init();

        return pObj;
    }
    static CObj* CreateObj(vector<ObjImg*>* img, float x, float y, float fAngle, float speed)
    {
        CObj* pObj = new T;
        pObj->SetPos(x, y);
        pObj->SetAngle(fAngle);
        pObj->SetImage(img);
        pObj->SetWH(FLOAT((*(img->begin()))->image->GetWidth()), FLOAT((*(img->begin()))->image->GetHeight()));
        pObj->Init();
        pObj->SetSpeed(speed);
        

        return pObj;

    }
};