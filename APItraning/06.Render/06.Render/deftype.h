#ifndef __deftype_h__
#define __deftype_h__

const float GRAVITY = 9.8f;

typedef struct tagBased
{
    RECT rect;

    tagBased() {}
    tagBased(RECT& ref)
    {
        rect = ref;
    }
}BasedInfo;

#endif // !__deftype_h__
