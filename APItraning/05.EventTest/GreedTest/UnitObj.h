#ifndef __OBJ_H__
#define __OBJ_H__

class UnitObj
{
#pragma region Var
protected:
    RECT        _rect;
    POS         _nowPos;
    DIRECTION   _diret;

    // Game var
    INFO        _info;

#pragma endregion

#pragma region Constructor & Destroyer
public:
    UnitObj                             ();
    UnitObj                             (POS);
    UnitObj                             (LONG x, LONG y);
    UnitObj                             (INFO rInfo);
    virtual ~UnitObj                    ();
#pragma endregion

#pragma region System
protected:
    virtual void        makeRect        ();
public:
    virtual void        Initialize      () = 0;
#pragma endregion

#pragma region Getter & Setter
public:
    const   RECT&       getRect         ();
    const   POS&        getPos          ();

    void                initPos         (POS);
    void                initPos         (LONG, LONG);

    const   INFO&       GetInfo         () const { return _info; }
    void                ProgHp          (int var);
    void                ProgExp         (int var);
    void                ProgGold        (int var);

#pragma endregion

#pragma region Render
    void                draw            (HDC);
#pragma endregion

};


#endif // !__OBJ_H__
