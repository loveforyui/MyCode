#ifndef __object_h__
#define __object_h__

class Object
{
#pragma region var
protected:
    BasePos m_position;
    PHYSIC m_physic;
    
#pragma endregion

#pragma region GetSet
public:
    GetSet(BasePos, m_position);
    GetSet(PHYSIC, m_physic);
#pragma endregion

#pragma region construct
public:
    Object();
    ~Object();
#pragma endregion


#pragma region Functions
public:
    void Draw(HDC);
#pragma endregion

};

#endif // !__object_h__
