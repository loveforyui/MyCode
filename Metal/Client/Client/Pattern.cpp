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
    // TODO: 여기에 반환 구문을 삽입합니다.
    FLOAT x, y, z;
    x = (obj->GetInfo().fX);
    y = (obj->GetInfo().fY);

    //pos.x -= obj->GetSpeed();
    y += obj->GetSpeed();

    return y;
}

FLOAT CPattern::Quadratic(CObj * obj)
{
    // 이차곡선 
    // TODO: 여기에 반환 구문을 삽입합니다.
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
    // 사인곡선
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


// obj 의 정보를 받아와서 수식에 따른 좌표를 변동후 y값을 리턴한다.
// 왜 여기서 값 변동을 안하는 이유는 스태틱함수라서 그렇다.
// 리턴한 y값으로 각 obj의 update에서 좌표를 재설정 해줘야한당.