#include "Astar.h"



Astar::Astar()
{
    _dest       = new Position();
    _src        = new Position();
}

Astar::Astar(int dest_x, int dest_y, int src_x, int src_y)
{
    _dest       = new Position(dest_x, dest_y);
    _src        = new Position(src_x, src_y);
}


Astar::~Astar()
{
}

// param vector<Position*>, Position
// find position in vector
// return &Position
Position* Astar::DetectPosInList(vector<Position*>& list, Position & pos)
{
    if (list.empty())
    {
        return NULL;
    }
    else
    {
        for (vector<Position*>::size_type i = 0;
            i < list.size();
            ++i)
        {
            if (*list[i] == pos)
            {
                return list[i];
            }
        }
    }
}
Position* Astar::DetectPosInList(vector<Position*>& list, Position* pos)
{
    if (list.empty())
    {
        return NULL;
    }
    else
    {
        for (vector<Position*>::size_type i = 0;
            i < list.size();
            ++i)
        {
            if (*list[i] == *pos)
            {
                return list[i];
            }
        }
    }
}

void Astar::FindPath(Position & dest, Position & src)
{
    // ¼ø¼­
    // push -> src
    // browse 8 position of src
    // if DetectPosInList(openList, 8 position of src)
    //, then push open list
    _openList.push_back(&src);
    for (int y = -1; y < 2; ++y)
    {
        for (int x = -1; x < 2;++x)
        {
            Position* temp = DetectPosInList(_openList, new Position(src._x + x, src._y + y));
            if (temp == NULL)
            {
                PushInList(_openList, temp);
            }
        }
    }
}

int Astar::PushInList(vector<Position*>& list, Position* pos)
{
    if (!list.empty())
    {
        for (vector<Position*>::size_type i = 0;
            i < list.size();
            ++i)
        {
            list[i] = pos;
        }
    }
    return 0;
}
