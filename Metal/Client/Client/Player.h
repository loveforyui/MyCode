#pragma once
#include "Obj.h"
#include "StateContext.h"

class CPlayer
    : public CObj
{
public:
    enum GUNSTATE {BASE, HEAVY, SHOTGUN,GUN_END};
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
    CObj * CreateBulletA(vector<ObjImg*>* img, float fAngle);
    CObj * CreateBomb(vector<ObjImg*>* img, float fAngle);
    void GunState();

    void HeavyKeyInput();

    void BaseGunKeyInput();

    void rectMake();
public:
    void SetGun(GUNSTATE state) { m_curGun = state; }
    void SetReload(const int& cnt) { reloadCnt += cnt; }

private:
    BOOL isKeyInput = false;

    const float m_fdegree = 30.f;

    CStateContext m_scBody;
    CStateContext m_scLeg;

    DWORD m_dwOldt;
    DWORD m_dwCurt;

    DWORD m_dwcIdlet = 0;
    DWORD m_dwoIdlet = GetTickCount();

    GUNSTATE m_curGun = CPlayer::BASE;
    GUNSTATE m_oldGun = CPlayer::GUN_END;

    vector<ObjImg*>* m_vBulletimg;
    vector<ObjImg*>* m_vBombimg;

public:
    INT life = 3;
    INT reloadCnt = 0;
    INT bombCnt = 0;
    FLOAT limitAcc = 5.f;
};