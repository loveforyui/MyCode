#include "stdafx.h"
#include "Greed.h"


Greed::Greed()
{
}

Greed::Greed(RECT rect)
{
    _rect = rect;
}

Greed::Greed(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam, HDC hdc, RECT rect)
{
    _hWnd           = hWnd;
    _msg            = msg;
    _wParam         = wParam;
    _lParam         = lParam;
    _rect           = rect;
    _hdc            = hdc;
    _objstate       = BLANC;
}

Greed::~Greed()
{
}

void Greed::Initialize(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam, HDC hdc, RECT rect)
{
    _hWnd           = hWnd;
    _msg            = msg;
    _wParam         = wParam;
    _lParam         = lParam;
    _rect           = rect;
    _hdc            = hdc;
}

void Greed::Draw(HDC hdc)
{
    Rectangle(hdc, _rect.left, _rect.top, _rect.right, _rect.bottom);
}
