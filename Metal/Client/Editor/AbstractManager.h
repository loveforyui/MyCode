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
        pObj->Init();
        pObj->SetPos(x, y);

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
    static CObj* CreateObj(ObjImg* img)
    {
        CObj* pObj = new T;
        pObj->Init();
        pObj->SetPos(0.f, 0.f);
        pObj->SetWH(img->image->GetWidth(), img->image->GetHeight());
        pObj->SetRect(RECT{ 0, 0, LONG(img->image->GetWidth()), LONG(img->image->GetHeight()) });
        pObj->SetImage(img);

        return pObj;
    }
    static CObj* CreateObj(vector<ObjImg*>* img)
    {
        CObj* pObj = new T;
        pObj->Init();
        pObj->SetPos(0.f, 0.f);
        pObj->SetImage(img);
        pObj->SetWH((*(img->begin()))->image->GetWidth(), (*(img->begin()))->image->GetHeight());        

        return pObj;
    }
    static CObj* CreateObj(INFO& info)
    {
        // ekmb ¼³Á¤
        CObj* pObj = new T(info);
        pObj->Init();

        return pObj;
    }
};