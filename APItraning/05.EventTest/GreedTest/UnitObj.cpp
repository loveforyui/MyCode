#include "stdafx.h"
#include "UnitObj.h"

#pragma region construct & destroyer
UnitObj::UnitObj()
{
    initPos(50, 50);
    makeRect();
}

UnitObj::UnitObj(POS pos)
{
    initPos(pos);
    makeRect();
}

UnitObj::UnitObj(LONG x, LONG y)
{
    initPos(x, y);
    makeRect();
}

UnitObj::UnitObj(INFO rInfo)
    : _info(rInfo)
{
}

UnitObj::~UnitObj()
{
}

#pragma endregion

#pragma region system
void UnitObj::makeRect()
{
    _rect.left = _nowPos.X - 20;
    _rect.bottom = _nowPos.Y;
    _rect.right = _nowPos.X + 20;
    _rect.top = _nowPos.Y - 50;
}
#pragma endregion

#pragma region Getter & Setter

const RECT & UnitObj::getRect()
{
    return _rect;
}

const POS & UnitObj::getPos()
{
    return _nowPos;
}

void UnitObj::initPos(POS pos)
{
    _nowPos = pos;
}

void UnitObj::initPos(LONG x, LONG y)
{
    _nowPos.setPos(x, y);
    makeRect();
}

void UnitObj::ProgHp(int var)
{
    _info.iHp += var;
}

void UnitObj::ProgExp(int var)
{
    _info.iExp += var;
}

void UnitObj::ProgGold(int var)
{
    _info.iGold += var;
}

void UnitObj::draw(HDC hdc)
{
    Rectangle(hdc, _rect.left, _rect.top, _rect.right, _rect.bottom);
}

#pragma endregion
