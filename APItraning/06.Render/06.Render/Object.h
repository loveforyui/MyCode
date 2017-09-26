#ifndef __object_h__
#define __object_h__

class Object
{
#pragma region var
protected:
    RECT rect;
    
#pragma endregion

#pragma region GetSet
public:
    GetSet(RECT, rect);
#pragma endregion

public:
    Object();
    ~Object();
};

#endif // !__object_h__
