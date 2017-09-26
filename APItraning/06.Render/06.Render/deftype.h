#ifndef __deftype_h__
#define __deftype_h__

typedef struct tagPosition
{
    LONG x;
    LONG y;

    tagPosition() : x(0), y(0) {}
    tagPosition(const LONG _x, const LONG _y) : x(_x), y(_y) {}
}POS;

typedef struct tagPos
{
    RECT rect;
    POS pos;

    tagPos() {}
    tagPos(RECT& ref)
    {
        rect = ref;
    }
    tagPos(const LONG _x, const LONG _y)
        : pos({_x, _y})
    {
        makeArea(pos.x, pos.y, 10);
    }
    void makeArea(const LONG _x, const LONG _y, int range)
    {
        rect.left   = _x - range;
        rect.right  = _x + range;
        rect.top    = _y - range;
        rect.bottom = _y + range;
    }
}BasePos;

typedef struct tagPhy
{
    float verticalSpeed;
    float horizonSpeed;
    float accSpeed;
    float mass;

    tagPhy() : verticalSpeed(0), horizonSpeed(0), accSpeed(0), mass(0) {}
    tagPhy(
        const float vSpeed,
        const float hSpeed, 
        const float a, 
        const float m)
        : verticalSpeed(vSpeed), horizonSpeed(hSpeed), accSpeed(a), mass(m)
    {
    }
}PHYSIC;

#endif // !__deftype_h__
