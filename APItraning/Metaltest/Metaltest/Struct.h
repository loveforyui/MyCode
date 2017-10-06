#ifndef __struct_h__
#define __struct_h__

typedef struct tagPosition
{
    LONG x;
    LONG y;
}position;

typedef struct tagObjInfo
{
public:
    tagObjInfo()
        : fX(0.f), fY(0.f), fCX(0.f), fCY(0.f)
        , speed(0.f), accel(0.f), vAccel(0.f), vSpeed(0.f) {}
    /*tagObjInfo(
        const FLOAT& x, const FLOAT& y, 
        const FLOAT& cx, const FLOAT& cy,
        const FLOAT& spd)
        : fX(x), fY(y), 
        fCX(cx), fCY(cy)
        , speed(spd)
    {
        accel = 0;
        makeRect();
    }*/
    tagObjInfo(
        const FLOAT& x, const FLOAT& y, 
        const FLOAT& cx, const FLOAT& cy)
        : fX(x), fY(y), 
        fCX(cx), fCY(cy)
        , speed(0.f), accel(0.f), vAccel(0.f), vSpeed(0.f)
    {
        makeRect();
    }
    ~tagObjInfo() {}
public:
    tagObjInfo& operator=(tagObjInfo& ref)
    {
        rect    = ref.rect;
        fX      = ref.fX;
        fY      = ref.fY;
        fCX     = ref.fCX;
        fCY     = ref.fCY;
        speed   = ref.speed;
        return *this;
    }

public:
    void makeRect()
    {
        rect.left       = fX - (fCX / 2);
        rect.right      = fX + (fCX / 2);
        rect.top        = fY - (fCY / 2);
        rect.bottom     = fY + (fCY / 2);
    }

    void setSpeed(const FLOAT& acc)
    {
        speed = acc;
    }
    void setSpeed(FLOAT& acc)
    {
        speed = acc;
    }

    void setPos(const FLOAT& x, const FLOAT& y)
    {
        fX = x;
        fY = y;
        makeRect();
    }
    void setPos(FLOAT& x, FLOAT& y)
    {
        fX = x;
        fY = y;
        makeRect();
    }

public:
    RECT    rect;
    FLOAT   fX;
    FLOAT   fY;
    FLOAT   fCX;
    FLOAT   fCY;
    FLOAT   speed;
    FLOAT   accel;
    FLOAT   vSpeed;
    FLOAT   vAccel;
}OBJINFO;

#endif // !__struct_h__
