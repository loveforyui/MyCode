#include "stdafx.h"
#include "CPhysics.h"
#include "Object.h"

/*
    ����������� ���� ��ü�� ���Ͽ
    h = (1/2)gt^2
    r = v0 * root(2h/g)

    r = (curV + at) * root(2h/g)

[1]  V = Vo + at   ( v ; �ӵ�   vo; ó�� �ӵ�   a ; ���ӵ�    t ; �ð�  )

  [���ļ���]    ���� �ӵ� = ó�� �ӵ� + �þ �ӵ�

                                      = ó�� �ӵ� + (���ӵ� x �ð�)

[2] S = Vo t + �� at ��( s ; �Ÿ�   Vo; ó�� �ӵ�   a ; ���ӵ�    t ; �ð�  )

  [���ļ���]  �� �Ÿ�   =  ��ռӷ� x �ð�

                                  = (ó���ӵ� + ���� �ӵ�) / 2   x  �ð�

                                  = [ó���ӵ� + ó���ӵ� +( ���ӵ� x �ð� )] /  2  x �ð�

                                  = ó���ӵ� x �ð�  + ( ���ӵ� x �ð� x �ð� ) / 2

[3] 2aS = V��- Vo��( s ; �Ÿ�   v ; �ӵ�   vo; ó�� �ӵ�   a ; ���ӵ�  )
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
