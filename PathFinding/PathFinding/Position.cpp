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
