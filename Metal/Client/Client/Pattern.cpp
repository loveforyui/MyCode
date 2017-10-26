#include "stdafx.h"
#include "Pattern.h"
#include "Obj.h"
#include "Bullet.h"

CPattern* CPattern::m_pInstance = nullptr;

CPattern::CPattern()
{
}

CPattern::~CPattern()
{
}

FLOAT CPattern::EqualLine(CObj* obj)
{
    // TODO: ���⿡ ��ȯ ������ �����մϴ�.
    FLOAT x, y, z;
    x = (obj->GetInfo().fX);
    y = (obj->GetInfo().fY);

    //pos.x -= obj->GetSpeed();
    y += obj->GetSpeed();

    return y;
}

FLOAT CPattern::Quadratic(CObj * obj)
{
    // ����� 
    // TODO: ���⿡ ��ȯ ������ �����մϴ�.
    FLOAT x, y, z;
    x = obj->GetInfo().fX;
    y = obj->GetInfo().fY;

    x += obj->GetSpeed();
    y = -(3.f/ WINCX)*x*(x - WINCX);

    //obj->SetPos(x, y);
    return y;
}

FLOAT CPattern::SinLine(CObj* obj)
{
    // ���ΰ
    FLOAT x, y, z;
    x = obj->GetInfo().fX;
    y = obj->GetInfo().fY;

    y = -sinf(x * PI * 180.f) * 100 + 150;

    return y;
}

FLOAT CPattern::Boss(CObj* obj)
{
    FLOAT x, y, z;
    x = obj->GetInfo().fX;
    y = obj->GetInfo().fY;

    if (y < 200.f)
    {
        y += obj->GetSpeed();
    }
    return y;
}

FLOAT CPattern::SingleLine(CObj* obj)
{
    FLOAT x, y, z;
    x = obj->GetInfo().fX;
    y = obj->GetInfo().fY;

    y -= obj->GetSpeed();
    
    return y;
}

FLOAT CPattern::SingleLineR(CObj* obj)
{
    FLOAT x, y, z;
    x = obj->GetInfo().fX;
    y = obj->GetInfo().fY;

    y += obj->GetSpeed();

    return y;
}

INFO CPattern::AngleLine(CObj* obj, FLOAT angle)
{
    FLOAT rad   = angle * PI / 180.f;
    FLOAT radR  = (90 - angle) * PI / 180.f;

    FLOAT x, y, cx, cy;
    x = obj->GetInfo().fX;
    y = obj->GetInfo().fY;
    cx = obj->GetInfo().fCX;
    cy = obj->GetInfo().fCY;

    x += cosf(rad)*obj->GetSpeed();
    y += -cosf(radR)*obj->GetSpeed();
    INFO info = { x, y, cx, cy };

    return info;
}

//INFO CPattern::HeosBomb(CObj* obj)
//{
//    FLOAT y, x;
//    x = obj->GetInfo().fX;
//    y = obj->GetInfo().fY;
//
//    if(WINCY*(2.f /5.f) < y )
//        y -= sinf(WINCX / 2 * PI * 180.f) + 10;
//    else
//    {
//        RECT rect = dynamic_cast<CBullet*>(obj)->GetMrect();
//
//        
//        if (rect.right - rect.left < 200)
//        {
//            --rect.left;
//            ++rect.right;
//            --rect.top;
//            ++rect.bottom;
//            //dynamic_cast<CBullet*>(obj)->SetMRect(rect);
//            obj->SetWH(FLOAT(rect.right - rect.left), FLOAT(rect.bottom - rect.top));
//        }
//        else
//        {
//            TCHAR buf[256] = L"";
//            static int i = 0;
//            static bool reverse = false;
//
//            if (15 < i)
//                reverse = true;
//            else if (i < 2)
//                reverse = false;
//
//            if (reverse)
//            {
//                swprintf_s(buf, L"%d.png", --i);
//                obj->SetImage(CImageMgr::GetInstance()->GetImage(L"heos", buf));
//            }
//            else
//            {
//                swprintf_s(buf, L"%d.png", ++i);
//                obj->SetImage(CImageMgr::GetInstance()->GetImage(L"heos", buf));
//            }
//        }
//        
//    }
//
//    //if (size < x)
//    //    x = 0.f;
//    INFO info = {obj->GetInfo().fX, y, 0.f, 0.f};
//
//    return info;
//}


// obj �� ������ �޾ƿͼ� ���Ŀ� ���� ��ǥ�� ������ y���� �����Ѵ�.
// �� ���⼭ �� ������ ���ϴ� ������ ����ƽ�Լ��� �׷���.
// ������ y������ �� obj�� update���� ��ǥ�� �缳�� ������Ѵ�.