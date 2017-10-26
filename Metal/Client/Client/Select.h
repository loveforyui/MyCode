#pragma once
#include "Scene.h"

class CSelect
    : public CScene
{
public:
    CSelect();
    ~CSelect();

private:


    // CScene을(를) 통해 상속됨
    virtual void Initialize() override;

    virtual void Update() override;

    virtual void Render(HDC hDC) override;

    virtual void Release() override;

    void CharacterSelect_R(HDC hdc);

    void CharacterSelect_U();

protected:
    map<UINT, Image*>       m_imgSelect;
    UINT                    m_bSelect_hud;

};

