#ifndef __AREA__
#define __AREA__

class Area
{
#pragma region Variable
private:
    LONG        _left;
    LONG        _top;
    LONG        _right;
    LONG        _bottom;

    POSITION    _LT;
    POSITION    _RT;
    POSITION    _LB;
    POSITION    _RB;
#pragma endregion

#pragma region Construct & Destroy
public:
    Area    ();
    Area    (LONG& left, LONG& top, LONG& right, LONG& bottom);
    Area    (   CONST LONG& left    = 0,
                CONST LONG& top     = 0,
                CONST LONG& right   = 0,
                CONST LONG& bottom  = 0);
    Area    (POSITION& fParam, POSITION& sParam);
    ~Area   ();
#pragma endregion

#pragma region Getter & Setter
public:
    VOID                Initailizer     (LONG& left, LONG& top, LONG& right, LONG& bottom);
    VOID                Initailizer     (   CONST LONG& left    = 0,
                                            CONST LONG& top     = 0,
                                            CONST LONG& right   = 0,
                                            CONST LONG& bottom  = 0);
    VOID                Initailizer     (POSITION& fParam, POSITION& sParam);

    CONST POSITION&     GetLT           ();
    CONST POSITION&     GetRT           ();
    CONST POSITION&     GetLB           ();
    CONST POSITION&     GetRB           ();
private:
    VOID                SetArea         ();
#pragma endregion

#pragma region Render
public:
    VOID DrawRect(HDC hdc, LPPOINT lppt);
#pragma endregion
    
};

#endif // !__AREA__