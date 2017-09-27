#include "stdafx.h"
#include "Object.h"


Object::Object()
{
}


Object::~Object()
{
}

void Object::Draw(HDC hdc)
{
    Rectangle(hdc, m_position.rect.left, m_position.rect.top, m_position.rect.right, m_position.rect.bottom);
}
