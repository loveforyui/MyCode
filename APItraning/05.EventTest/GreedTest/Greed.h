#pragma once
class Greed
{
#pragma region Var
public:
    RECT        _rect;
    HWND        _hWnd;
    UINT        _msg;
    WPARAM      _wParam;
    LPARAM      _lParam;
    HDC         _hdc;
    OBJSTATE    _objstate;

#pragma endregion

#pragma region Constructor & Destroyer
public:
    Greed();
    Greed(RECT);
    Greed(HWND, UINT, WPARAM, LPARAM, HDC, RECT);
    ~Greed();

#pragma endregion

#pragma region Getter & Setter
public:
    void Initialize(HWND, UINT, WPARAM, LPARAM, HDC, RECT);

#pragma endregion

#pragma region Render
public:
    void Draw(HDC hdc);

#pragma endregion



};

