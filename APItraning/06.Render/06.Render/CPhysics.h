#ifndef __physics_h__
#define __physics_h__

class Object;
class CPhysics
{
#pragma region var
private:
    const LONG  GRAVITY = 10;
    const float framerate = 0.03f;

    RECT        world;
#pragma endregion

#pragma region GetSet
public:
    const LONG get_GRAVITY() { return GRAVITY; }
#pragma endregion

#pragma region construct
public:
    CPhysics();
    ~CPhysics();

#pragma endregion

#pragma region SystemFunctions
public:
    void SetWorldRect(HWND hWnd);
    
#pragma endregion

#pragma region Functions
public:
    POS activeGravity(Object& obj);
    float getV(Object& obj);

#pragma endregion

};

#endif // !__physics_h__
