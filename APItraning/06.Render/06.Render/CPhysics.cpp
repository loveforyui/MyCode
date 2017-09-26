#include "stdafx.h"
#include "CPhysics.h"
#include "Object.h"

/*
    수평방향으로 던진 물체의 낙하운동
    h = (1/2)gt^2
    r = v0 * root(2h/g)

    r = (curV + at) * root(2h/g)

[1]  V = Vo + at   ( v ; 속도   vo; 처음 속도   a ; 가속도    t ; 시간  )

  [공식설명]    나중 속도 = 처음 속도 + 늘어난 속도

                                      = 처음 속도 + (가속도 x 시간)

[2] S = Vo t + ½ at ²( s ; 거리   Vo; 처음 속도   a ; 가속도    t ; 시간  )

  [공식설명]  간 거리   =  평균속력 x 시간

                                  = (처음속도 + 나중 속도) / 2   x  시간

                                  = [처음속도 + 처음속도 +( 가속도 x 시간 )] /  2  x 시간

                                  = 처음속도 x 시간  + ( 가속도 x 시간 x 시간 ) / 2

[3] 2aS = V²- Vo²( s ; 거리   v ; 속도   vo; 처음 속도   a ; 가속도  )
*/
#pragma region construct
CPhysics::CPhysics()
{
}


CPhysics::~CPhysics()
{
}
#pragma endregion

#pragma region System
void CPhysics::SetWorldRect(HWND hWnd)
{
    GetClientRect(hWnd, &world);
}

POS CPhysics::activeGravity(Object & obj)
{
    /*h = (1/2)gt^2
    r = v0 * root(2h/g)

    r = (curV + at) * root(2h/g)*/

    POS         result;
    LONG        curX, curY;
    float       mass, vSpeed, hSpeed, aSpeed;
    
    curX        = obj.get_m_position    ().pos.x;
    curY        = obj.get_m_position    ().pos.y;
    mass        = obj.get_m_physic      ().mass;
    vSpeed      = obj.get_m_physic      ().verticalSpeed;
    hSpeed      = obj.get_m_physic      ().horizonSpeed;
    aSpeed      = obj.get_m_physic      ().accSpeed;

    result.y    = (curY) + ((1 / 2) * (GRAVITY) * (framerate * framerate));
    result.x    = (curX) + (vSpeed + (aSpeed * framerate)) * sqrt((2 * result.y) / (GRAVITY));

    return result;
}

float CPhysics::getV(Object & obj)
{ 
    return float(obj.get_m_physic().mass * get_GRAVITY());
}
#pragma endregion
