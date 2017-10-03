#ifndef __struct_h__
#define __struct_h__

typedef struct tagObjInfo
{
public:
    tagObjInfo() : fX(0), fY(0), fCX(0), fCY(0){}
    tagObjInfo(
        const FLOAT& x, const FLOAT& y, 
        const FLOAT& cx, const FLOAT& cy,
        const FLOAT& spd)
        : fX(x), fY(y), 
        fCX(cx), fCY(cy)
        , speed(spd)
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
    
}OBJINFO;

#endif // !__struct_h__
