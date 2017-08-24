#include "Position.h"



Position::Position()
{
}

Position::Position(int x, int y) : _x(x), _y(y)
{

}

Position::Position(int x, int y, Stance state) : _x(x), _y(y), _state(state)
{
}

Position::~Position()
{
}

double Position::GetDistance(Position & dest)
{
    double result = 0;

    result = sqrt(pow(abs(dest._x - _x), 2) + pow(abs(dest._y - _y), 2));

    return result;
}