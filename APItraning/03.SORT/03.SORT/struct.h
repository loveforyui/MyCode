#ifndef __STRUCT__
#define __STRUCT__

typedef struct tagPos
{
    LONG        _x;
    LONG        _y;

    tagPos& operator=(tagPos& ref)
    {
        _x       = ref._x;
        _y       = ref._y;

        return *this;
    }
    void SetPos (LONG& x, LONG& y)
    {
        _x      = x;
        _y      = y;
    }
    void SetPos (CONST LONG& x, CONST LONG& y)
    {
        _x      = x;
        _y      = y;
    }
}POSITION;


#endif // !__STRUCT__
