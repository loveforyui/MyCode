#ifndef __STRUCT_H__
#define __STRUCT_H__

typedef struct tagPos
{
    LONG X;
    LONG Y;

    tagPos& operator=(tagPos& ref)
    {
        X = ref.X;
        Y = ref.Y;
        return *this;
    }

    void setPos(LONG xPos, LONG yPos)
    {
        X = xPos;
        Y = yPos;
    }
}POS;

#endif // !__STRUCT_H__
