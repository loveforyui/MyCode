#include "stdafx.h"
#include "player.h"
#include "playerstate.h"


player::player()
{   
}


player::~player()
{
}

void player::Initialize()
{
    m_objInfo.fX        = 0;
    m_objInfo.fY        = 0;
    m_objInfo.fCX       = 50;
    m_objInfo.fCY       = 50;
    m_objInfo.setSpeed  (10);
    m_objInfo.makeRect  ();
}

void player::Initialize(OBJINFO& ref)
{
    m_objInfo           = ref;
    m_iState_body       = PS_BODY_ST_JMP;
    m_iState_leg        = PS_LEG_ST_JMP;
    isJump              = true;
    isDEBUG             = false;

    m_state_leg.m_mState.insert(pair<string, StateManager*>("PS_LEG_STANDING", new EriIdleLeg));
    m_state_leg.m_mState.insert(pair<string, StateManager*>("PS_LEG_ST_JMP", new EriStJmpLeg));
    m_state_leg.m_mState.insert(pair<string, StateManager*>("PS_LEG_WRK", new EriWrkLeg));

    m_state_body.m_mState.insert(pair<string, StateManager*>("PS_BODY_IDLE", new EriIdle));
    m_state_body.m_mState.insert(pair<string, StateManager*>("PS_BODY_ST_JMP", new EriStJmpBody));
    m_state_body.m_mState.insert(pair<string, StateManager*>("PS_BODY_WRK", new EriWrkBody));

    for (map<string, StateManager*>::iterator iter = m_state_leg.m_mState.begin();
        iter != m_state_leg.m_mState.end(); ++iter)
    {
        (*iter).second->SetObj(this);
    }

    for (map<string, StateManager*>::iterator iter = m_state_body.m_mState.begin();
        iter != m_state_body.m_mState.end(); ++iter)
    {
        (*iter).second->SetObj(this);
    }

    m_hState_leg    = m_state_leg.m_mState["PS_LEG_ST_JMP"];
    m_hState_body   = m_state_body.m_mState["PS_BODY_ST_JMP"];
}

void player::Render(HDC hdc)
{
    if (isDEBUG)
    {
        Rectangle(hdc
        , m_objInfo.rect.left
        , m_objInfo.rect.top
        , m_objInfo.rect.right
        , m_objInfo.rect.bottom);

        wchar_t pos[64];
        swprintf_s(pos, L"X:%.2f Y:%.2f", m_objInfo.fX, m_objInfo.fY);
        SetTextAlign(hdc, TA_CENTER);
        TextOut(hdc, m_objInfo.fX, m_objInfo.fY - 30, pos, wcslen(pos));
    }    

    switch (m_iDirection)
    {
    case OBJ_D_RIGHT:
        m_hState_leg->handle(hdc);
        m_hState_body->handle(hdc);
        break;
    case OBJ_D_LEFT:
        m_hState_leg->handlf(hdc);
        m_hState_body->handlf(hdc);
        break;
    }
        

    

}

void player::Release()
{
}

int player::Update()
{
    Object::Update();
    isKeyInput = false;

    // 이동시 가속도 처리
    if (GetAsyncKeyState(VK_LEFT)   & 0x8000)
    {
        isKeyInput = true;
        if (m_iDirection == OBJ_D_RIGHT)
        {
            m_objInfo.speed = 0.f;
            m_objInfo.accel = 0.f;
        }
        m_iDirection = OBJ_D_LEFT;

        if (!isJump)
        {
            m_iState_leg    = PS_LEG_WRK;
            m_iState_body   = PS_BODY_WRK;
        }

        if (m_objInfo.accel < 5.f)
        {
            m_objInfo.accel += 0.1f;
        }
        if(m_objInfo.speed < 5.f)
            m_objInfo.speed += m_objInfo.accel;
    }		
    if (GetAsyncKeyState(VK_RIGHT)  & 0x8000)
    {
        isKeyInput = true;
        if (m_iDirection == OBJ_D_LEFT)
        {
            m_objInfo.speed = 0.f;
            m_objInfo.accel = 0.f;
        }  
        m_iDirection = OBJ_D_RIGHT;

        if (!isJump)
        {
            m_iState_leg    = PS_LEG_WRK;
            m_iState_body   = PS_BODY_WRK;
        }

        if (m_objInfo.accel < 5.f)
        {
            m_objInfo.accel += 0.1f;
        }
        if(m_objInfo.speed < 5.f)
            m_objInfo.speed += m_objInfo.accel;
    }		
    if (GetAsyncKeyState(VK_UP)     & 0x8000)
    {
        m_iDirection = OBJ_D_UP;
    }		
    if (GetAsyncKeyState(VK_DOWN)   & 0x8000)
    {
        m_iDirection = OBJ_D_DOWN;
    }
    if (GetAsyncKeyState(VK_CONTROL) & 0x8000)
    {
        isJump          = true;
        m_iState_body   = PS_BODY_ST_JMP;
        m_iState_leg    = PS_LEG_ST_JMP;
        if (m_objInfo.vAccel != m_GRAVITY * 5)
        {
            m_objInfo.vAccel = m_GRAVITY * 5;
            m_objInfo.vSpeed = m_objInfo.vAccel;
        }
    }
    // 다음 : 플레이어 이동 가속도 처리

    // move progressing
    // 먼저 앞으로 간 좌표의 Y값의 bottom이 라인의 y보다 클때
    // 위로(bottom - y) 올려준다.
    FLOAT x, y;
    x = m_objInfo.fX - m_objInfo.speed;
    y = m_objInfo.rect.bottom;

    if (OBJ_D_LEFT == m_iDirection)
    {
        if (!isJump)
        {
            if ((*m_pLine)[INT(x)] <= y)
            {
                m_objInfo.fY = m_objInfo.fY - (m_objInfo.rect.bottom - (*m_pLine)[INT(x)]);
            }
            else
            {
                m_objInfo.fY = m_objInfo.fY + ((*m_pLine)[INT(x)] - m_objInfo.rect.bottom);
            }
        }
        else
        {
            if ((*m_pLine)[INT(x)] < y - 2)
            {
                //m_objInfo.fY = m_objInfo.fY - (m_objInfo.rect.bottom - (*m_pLine)[INT(x)]);
                Object::SetStanding();
            }
        }
        m_objInfo.fX -= m_objInfo.speed;
    }
    if (OBJ_D_RIGHT == m_iDirection)
    {
        if (!isJump)
        {
            if ((*m_pLine)[INT(x)] <= y)
            {
                m_objInfo.fY = m_objInfo.fY - (m_objInfo.rect.bottom - (*m_pLine)[INT(x)]);
            }
            else
            {
                m_objInfo.fY = m_objInfo.fY + ((*m_pLine)[INT(x)] - m_objInfo.rect.bottom);
            }
        }
        else
        {
            if ((*m_pLine)[INT(x)] < y - 2)
            {
                //m_objInfo.fY = m_objInfo.fY - (m_objInfo.rect.bottom - (*m_pLine)[INT(x)]);
                Object::SetStanding();
            }
        }
        m_objInfo.fX += m_objInfo.speed;
    }
    if (OBJ_D_UP == m_iDirection)
    {

    }
    if (OBJ_D_DOWN == m_iDirection)
    {

    }
    // 점프중일때 점프하는 속도는 중력가속도 만큼 감소하고 정점에서 주역 가속도 만큼 까진다.
    if (isJump)
    {
        m_objInfo.vSpeed -= m_GRAVITY*0.8f;
        if (m_objInfo.vSpeed < 0)
            m_objInfo.vSpeed = 0;
        
        m_objInfo.fY -= m_objInfo.vSpeed;
    }
    // No input
    // 입력이 없는 상태 -> 가만히 서 있는 상태 처리
    if ((!isKeyInput) && (PS_LEG_ST_JMP != m_iState_leg))
    {
        if (0.f <= m_objInfo.accel)
        {
            m_objInfo.accel -= 1.1f;
        } 
        if (m_objInfo.accel <= 0.f)
        {
            m_objInfo.accel     = 0.f;
            m_objInfo.speed     = 0.f;
            m_objInfo.vAccel    = 0.f;
            isJump              = false;
            m_iState_leg        = PS_LEG_STANDING;
            m_iState_body       = PS_BODY_IDLE;
        } 
    }
    //debug mode
    if (GetAsyncKeyState(VK_LSHIFT)   & 0x8000)
    {
        isDEBUG = true;
    }
    else
    {
        isDEBUG = false;
    }

    switch (m_iState_leg)
    {
    case PS_LEG_STANDING:
        m_hState_leg = m_state_leg.SetState("PS_LEG_STANDING");
        //m_state_leg.SetState(new EriIdleLeg);
        break;
    case PS_LEG_ST_JMP:
        m_hState_leg = m_state_leg.SetState("PS_LEG_ST_JMP");
        //m_state_leg.SetState(new EriStJmpLeg);
        break;
    case PS_LEG_WRK:
        m_hState_leg = m_state_leg.SetState("PS_LEG_WRK");
        //m_state_leg.SetState(new EriWrkLeg);
        break;
    }
    switch (m_iState_body)
    {
    case PS_BODY_IDLE:
        // body, leg
        m_hState_body = m_state_body.SetState("PS_BODY_IDLE");
        //m_state_body.SetState(new EriIdle);
        break;
    case PS_BODY_ST_JMP:
        m_hState_body = m_state_body.SetState("PS_BODY_ST_JMP");
        //m_state_body.SetState(new EriStJmpBody);
        break;
    case PS_BODY_WRK:
        m_hState_body = m_state_body.SetState("PS_BODY_WRK");
        break;
    }
    return 0;
}

void player::SetLine(vector<INT>* ptr)
{
    m_pLine = ptr;
}

