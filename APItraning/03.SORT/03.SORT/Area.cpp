#include "stdafx.h"
#include "Area.h"


Area::Area()
{
}
Area::Area(LONG & left, LONG & top, LONG & right, LONG & bottom)
{
    Initailizer(left, top, right, bottom);
}


Area::Area(CONST LONG & left, CONST LONG & top, CONST LONG & right, CONST LONG & bottom)
{
    Initailizer(left, top, right, bottom);
}

Area::Area(POSITION & fParam, POSITION & sParam)
{
    Initailizer(fParam, sParam);
}

Area::~Area()
{
}

VOID Area::Initailizer(LONG & left, LONG & top, LONG & right, LONG & bottom)
{
    _left       = left;
    _top        = top;
    _right      = right;
    _bottom     = bottom;

    SetArea();
    return VOID();
}

VOID Area::Initailizer(CONST LONG & left, CONST LONG & top, CONST LONG & right, CONST LONG & bottom)
{
    _left       = left;
    _top        = top;
    _right      = right;
    _bottom     = bottom;

    SetArea();
    return VOID();
}

VOID Area::Initailizer(POSITION & fParam, POSITION & sParam)
{
    _left       = fParam._x;
    _top        = fParam._y;
    _right      = sParam._x;
    _bottom     = sParam._y;

    SetArea();
    return VOID();
}

CONST POSITION & Area::GetLT()
{
    return _LT;
}

CONST POSITION & Area::GetRT()
{
    return _RT;
}

CONST POSITION & Area::GetLB()
{
    return _LB;
}

CONST POSITION & Area::GetRB()
{
    return _RB;
}

VOID Area::SetArea()
{
    _LT.SetPos(_left,   _top);
    _RT.SetPos(_right,  _top);
    _LB.SetPos(_left,   _bottom);
    _RB.SetPos(_right,  _bottom);
    return VOID();
}

VOID Area::DrawRect(HDC hdc, LPPOINT lppt)
{
    // _LT -> _RT
    MoveToEx(hdc, _LT._x, _LT._y, lppt);
    LineTo(hdc, _RT._x, _RT._y);
    // _LT -> _LB
    MoveToEx(hdc, _LT._x, _LT._y, lppt);
    LineTo(hdc, _LB._x, _LB._y);
    // _RB -> _LB
    MoveToEx(hdc, _RB._x, _RB._y, lppt);
    LineTo(hdc, _LB._x, _LB._y);
    // _RB -> _RT
    MoveToEx(hdc, _RB._x, _RB._y, lppt);
    LineTo(hdc, _RT._x, _RT._y);
    return VOID();
}
