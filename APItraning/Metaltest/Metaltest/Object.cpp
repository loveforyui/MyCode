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
    m_iDirection = OBJ_D_RIGHT;
}


Object::~Object()
{
}

BOOL Object::operator&&(Object & src)
{
    BOOL result = FALSE;

    //аб, ©Л
    if ((src.m_objInfo.rect.top <= m_objInfo.rect.bottom) && (m_objInfo.rect.bottom <= src.m_objInfo.rect.bottom))
    {
        if ((src.m_objInfo.rect.left <= m_objInfo.rect.right) && (m_objInfo.rect.left <= src.m_objInfo.rect.left))
        {
            //m_objInfo.fX -= m_objInfo.speed;
            result = TRUE;
            //return result;
        }
        if ((m_objInfo.rect.left <= src.m_objInfo.rect.right) && (src.m_objInfo.rect.right <= m_objInfo.rect.right))
        {
            //m_objInfo.fX += m_objInfo.speed;
            result = TRUE;
            //return result;
        }
          
    }
    else if ((src.m_objInfo.rect.top <= m_objInfo.rect.top) && (m_objInfo.rect.top <= src.m_objInfo.rect.bottom))
    {
        if ((src.m_objInfo.rect.left <= m_objInfo.rect.right) && (m_objInfo.rect.left <= src.m_objInfo.rect.left))
        {
            //m_objInfo.fX -= m_objInfo.speed;
            result = TRUE;
            //return result;
        }
        if ((m_objInfo.rect.left <= src.m_objInfo.rect.right) && (src.m_objInfo.rect.right <= m_objInfo.rect.right))
        {
            //m_objInfo.fX += m_objInfo.speed;
            result = TRUE;
            //return result;
        }
    }

    // го, ╩С
    if ((src.m_objInfo.rect.left <= m_objInfo.rect.left) && (m_objInfo.rect.left <= src.m_objInfo.rect.right))
    {
        if ((m_objInfo.rect.top <= src.m_objInfo.rect.bottom) && (src.m_objInfo.rect.bottom <= m_objInfo.rect.bottom))
        {
            m_objInfo.fY += m_GRAVITY;
            result = TRUE;
            SetStanding();
            //return result;
        }
        if ((src.m_objInfo.rect.top <= m_objInfo.rect.bottom) && (m_objInfo.rect.top <= src.m_objInfo.rect.top))
        {
            m_objInfo.fY -= m_GRAVITY;
            result = TRUE;

            SetStanding();            
            //return result;
        }
    }
    else if ((src.m_objInfo.rect.left <= m_objInfo.rect.right) && (m_objInfo.rect.right <= src.m_objInfo.rect.right))
    {
        if ((m_objInfo.rect.top <= src.m_objInfo.rect.bottom) && (src.m_objInfo.rect.bottom <= m_objInfo.rect.bottom))
        {
            m_objInfo.fY += m_GRAVITY;
            result = TRUE;
            SetStanding();
            //return result;
        }
        if ((src.m_objInfo.rect.top <= m_objInfo.rect.bottom) && (m_objInfo.rect.top <= src.m_objInfo.rect.top))
        {
            m_objInfo.fY -= m_GRAVITY;
            result = TRUE;
            SetStanding();
            //return result;
        }
    }

    return result;
}

BOOL Object::operator||(Object &src)
{
     BOOL result = FALSE;

    // аб, ©Л
    if ((src.m_objInfo.rect.top <= m_objInfo.rect.bottom) && (m_objInfo.rect.bottom <= src.m_objInfo.rect.bottom))
    {
        if ((src.m_objInfo.rect.left <= m_objInfo.rect.right) && (m_objInfo.rect.left <= src.m_objInfo.rect.left))
        {
            m_objInfo.fX += m_objInfo.speed;
            result = TRUE;
            //return result;
        }
        if ((m_objInfo.rect.left <= src.m_objInfo.rect.right) && (src.m_objInfo.rect.right <= m_objInfo.rect.right))
        {
            m_objInfo.fX -= m_objInfo.speed;
            result = TRUE;
            //return result;
        }
          
    }
    else if ((src.m_objInfo.rect.top <= m_objInfo.rect.top) && (m_objInfo.rect.top <= src.m_objInfo.rect.bottom))
    {
        if ((src.m_objInfo.rect.left <= m_objInfo.rect.right) && (m_objInfo.rect.left <= src.m_objInfo.rect.left))
        {
            m_objInfo.fX += m_objInfo.speed;
            result = TRUE;
            //return result;
        }
        if ((m_objInfo.rect.left <= src.m_objInfo.rect.right) && (src.m_objInfo.rect.right <= m_objInfo.rect.right))
        {
            m_objInfo.fX -= m_objInfo.speed;
            result = TRUE;
            //return result;
        }
    }

    // го, ╩С
    if ((src.m_objInfo.rect.left <= m_objInfo.rect.left) && (m_objInfo.rect.left <= src.m_objInfo.rect.right))
    {
        if ((m_objInfo.rect.top <= src.m_objInfo.rect.bottom) && (src.m_objInfo.rect.bottom <= m_objInfo.rect.bottom))
        {
            m_objInfo.fY -= m_GRAVITY;

            SetStanding();
            /*if (PS_LEG_ST_JMP == m_iState_leg)
            {
                m_iState_leg = PS_LEG_STANDING;
                m_iState_body = PS_BODY_IDLE;
            }*/

            result = TRUE;
            //return result;
        }
        if ((src.m_objInfo.rect.top <= m_objInfo.rect.bottom) && (m_objInfo.rect.top <= src.m_objInfo.rect.top))
        {
            m_objInfo.fY += m_objInfo.speed;
            isJump = false;
            result = TRUE;
            //return result;
        }
    }
    else if ((src.m_objInfo.rect.left <= m_objInfo.rect.right) && (m_objInfo.rect.right <= src.m_objInfo.rect.right))
    {
        if ((m_objInfo.rect.top <= src.m_objInfo.rect.bottom) && (src.m_objInfo.rect.bottom <= m_objInfo.rect.bottom))
        {
            m_objInfo.fY -= m_GRAVITY;

            SetStanding();

            /*if (PS_LEG_ST_JMP == m_iState_leg)
            {
                m_iState_leg = PS_LEG_STANDING;
                m_iState_body = PS_BODY_IDLE;
            }*/
            result = TRUE;
            //return result;
        }
        if ((src.m_objInfo.rect.top <= m_objInfo.rect.bottom) && (m_objInfo.rect.top <= src.m_objInfo.rect.top))
        {
            m_objInfo.fY += m_objInfo.speed;
            isJump = false;
            result = TRUE;
            //return result;
        }
    }

    return result;
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

const INT Object::GetStateLeg()
{
    return m_iState_leg;
}

const INT Object::GetStateBody()
{
    return m_iState_body;
}

void Object::SetStateLeg(const INT& ref)
{
    m_iState_leg = ref;
}

void Object::SetStateBody(const INT& ref)
{
    m_iState_body = ref;
}

void Object::SetStanding()
{
    isJump = false;
    m_objInfo.vAccel = 0.f;
    m_iState_leg = PS_LEG_STANDING;
    m_iState_body = PS_BODY_IDLE;
}
