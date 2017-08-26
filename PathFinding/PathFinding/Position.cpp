#include "Position.h"

// 포지션에서 F, G, 값을 들고있어야겠다?

Position::Position()
{
    _state = Space;
}

Position::Position(int x, int y) : _x(x), _y(y)
{
    _state = Space;
}

Position::Position(int x, int y, Stance state) : _x(x), _y(y), _state(state)
{
}

Position::~Position()
{
}

Position & Position::operator=(Position & ref)
{
    // TODO: 여기에 반환 구문을 삽입합니다.
    _x      = ref._x;
    _y      = ref._y;
    _state  = ref._state;
}

bool Position::operator==(Position & ref)
{
    // TODO: 여기에 반환 구문을 삽입합니다.
    if (&ref == NULL)
    {
        return false;
    }
    else
    {
        if ((_x == ref._x) && (_y == ref._y) && (_state == ref._state))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
}

bool Position::operator==(Position* ref)
{
    // TODO: 여기에 반환 구문을 삽입합니다.
    if (&ref == NULL)
    {
        return false;
    }
    else
    {
        if ((_x == ref->_x) && (_y == ref->_y) && (_state == ref->_state))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}

double Position::GetDistance(Position & dest)
{
    double result = 0;

    result = sqrt(pow(abs(dest._x - _x), 2) + pow(abs(dest._y - _y), 2));

    return result;
}

double Position::GetDistance(Position & dest, Position & src)
{
    double result = 0;

    result = sqrt(pow(abs(dest._x - src._x), 2) + pow(abs(dest._y - src._y), 2));

    return result;
}
