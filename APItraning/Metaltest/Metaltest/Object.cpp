#include "stdafx.h"
#include "Object.h"
#include "EriIdle.h"
#include "EriIdleLeg.h"


Object::Object()
{
    m_state_body.SetObj(this);
    m_state_leg.SetObj(this);
    m_state_body.SetState(new EriIdle);
    m_state_leg.SetState(new EriIdleLeg);
}


Object::~Object()
{
}

int Object::Update()
{
    m_objInfo.makeRect();
    return 0;
}

void Object::SetPos(FLOAT x, FLOAT y)
{
    m_objInfo.fX = x;
    m_objInfo.fY = y;
    m_objInfo.makeRect();
}

const OBJINFO& Object::GetInfo()
{
    return m_objInfo;
}
