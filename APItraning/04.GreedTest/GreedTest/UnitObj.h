#ifndef __OBJ_H__
#define __OBJ_H__

class UnitObj
{
#pragma region Var
private:
    RECT        _rect;
    POS         _nowPos;
    DIRECTION   _diret;
public:
    OBJSTATE    _objstate;

#pragma endregion

#pragma region Constructor & Destroyer
public:
    UnitObj();
    UnitObj(POS);
    UnitObj(LONG x, LONG y);
    virtual ~UnitObj();
#pragma endregion

#pragma region System
protected:
    void makeRect();
#pragma endregion


#pragma region Getter & Setter
public:
    const RECT& getRect();
    const POS& getPos();

    void initPos(POS);
    void initPos(LONG, LONG);

#pragma endregion

#pragma region Render
    virtual void draw(HDC);
#pragma endregion

};

#endif // !__OBJ_H__
