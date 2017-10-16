#ifndef __mainmanager_h__
#define __mainmanager_h__

#include "Gravity.h"

class Object;
class MainManager
{
#pragma region Construct
private:
    MainManager();

public:
    ~MainManager();
#pragma endregion
#pragma region system
public:
    VOID Initialize();
    VOID Update();
    VOID Render();
    VOID Release();
#pragma endregion

#pragma region Nomal Func
    VOID DrawSin();
    BOOL Collision(Object*, Object*);
    BOOL CollisionO(Object*, Object*);
#pragma endregion


#pragma region Getter
public:
    static MainManager* GetInst();
#pragma endregion

#pragma region MemberVar
private:
    static MainManager* inst;
    // DC
    HDC m_hdc;
    HDC m_hBackBuffer;

    // bitmap
    HBITMAP m_hBitmap;
    HBITMAP m_hOldmap;

    // WindowClientRect
    RECT m_wndRect;
    INT m_wndLimitX;
    INT m_wndLimitCX;

    // Physic
    Gravity m_gravity;

    // objects
    //OBJLIST m_
    Object* m_pPlayer;
    Object* m_pStage;

    // test var
    double f;
    int y;
#pragma endregion
};
#endif // !__mainmanager_h__



