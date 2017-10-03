#ifndef __mainmanager_h__
#define __mainmanager_h__

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
    void Initialize();
    void Update();
    void Render();
    void Release();
#pragma endregion

#pragma region Nomal Func
    void DrawSin();
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

    // objects
    Object* m_pPlayer;

    // test var
    double f;
    int y;
#pragma endregion

};

#endif // !__mainmanager_h__



