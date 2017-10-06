#include "stdafx.h"
#include "floor.h"
#include "Object.h"

Floor::Floor()
{
}


Floor::~Floor()
{
}

void Floor::Initialize()
{
}

void Floor::Initialize(OBJINFO & ref)
{
    m_objInfo = ref;
    m_iState_body = 0;
    m_iState_leg = 0;
}

void Floor::Render(HDC hdc)
{
    /*Rectangle(hdc
        , m_objInfo.rect.left
        , m_objInfo.rect.top
        , m_objInfo.rect.right
        , m_objInfo.rect.bottom);*/

}

void Floor::Release()
{
}

int Floor::Updatee()
{
    return 0;
}
