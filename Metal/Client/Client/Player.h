#pragma once
#include "Obj.h"
#include "StateContext.h"

class CPlayer
    : public CObj
{
public:
    enum GUNSTATE {BASE, HEAVY, GUN_END};
public:
    CPlayer();
    ~CPlayer();

public:
    // CObj을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Release() override;
    virtual void Render(HDC hdc) override;
    virtual int  Update();

public:
    void InsertImage(const TCHAR* key, vector<ObjImg*>* vImg);
    void SetCXY();

private:
    void KeyInput();
    void IsJump();
    void IsCollisionLine();
    void CalcCannonPos();
    CObj * CreateBullet(vector<ObjImg*>* img, float fAngle);
    void GunState();

    void BaseGunKeyInput();

    void rectMake();

private:
    BOOL isKeyInput = false;

    const float m_fdegree = 30.f;

    CStateContext m_scBody;
    CStateContext m_scLeg;

    DWORD m_dwOldt;
    DWORD m_dwCurt;

    GUNSTATE m_curGun = CPlayer::BASE;
    GUNSTATE m_oldGun = CPlayer::GUN_END;

    vector<ObjImg*>* m_vBulletimg;

public:
    INT life = 3;
    INT reloadCnt = 0;
    INT bombCnt = 0;
    FLOAT limitAcc = 5.f;
};