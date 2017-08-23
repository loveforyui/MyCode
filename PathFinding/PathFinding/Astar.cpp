#include "Astar.h"



Astar::Astar()
{
}

Astar::Astar(int dest_x, int dest_y, int src_x, int src_y)
{
    _dest->x = dest_x;
    _dest->y = dest_y;
    _src->x = src_x;
    _src->y = src_y;
}


Astar::~Astar()
{
}

double Astar::GetDistance(Pos & dest, Pos & src)
{
    double result = 0;

    result = sqrt(pow(abs(dest.x - src.x), 2) + pow(abs(dest.y - src.y), 2));

    return result;
}
