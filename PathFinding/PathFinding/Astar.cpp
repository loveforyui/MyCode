#include "Astar.h"



Astar::Astar()
{
    _dest       = new Position();
    _src        = new Position();
}

Astar::Astar(int dest_x, int dest_y, int src_x, int src_y)
{
    _dest       = new Position();
    _src        = new Position();

    _dest->x    = dest_x;
    _dest->y    = dest_y;
    
    _src->x     = src_x;
    _src->y     = src_y;
}


Astar::~Astar()
{
}



Pos* Astar::DetectPosInList(vector<Pos*>& list, Pos & pos)
{
    if (list.empty())
    {
        return NULL;
    }
    else
    {

    }
}
