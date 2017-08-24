#include "Astar.h"



Astar::Astar()
{
    _dest           = new Position();
    _src            = new Position();
    _current        = new Position();
}

Astar::Astar(int dest_x, int dest_y, int src_x, int src_y)
{
    _dest           = new Position(dest_x, dest_y);
    _src            = new Position(src_x, src_y);
    _current        = new Position(src_x, src_y);
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
    // 순서
    // push -> src
    // browse 8 position of src
    // if DetectPosInList(openList, 8 position of src)
    //, then push open list
    _closeList.clear();
    _openList.clear();
    _F.clear();
    _closeList.push_back(&src);

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
    // F 비용 = 현재까지온 거리 + 리스트안의 포스에서 목표까지 거리
    // 를 계산한후 close list에 넣는다    
    for (vector<Position*>::size_type index = 0;
        index < _openList.size();
        ++index)
    {
        _F.push_back(_G + _dest->GetDistance(*_openList[index]));
    }

    double min = 9999999;
    vector<int>::size_type minst = -1;

    for (vector<int>::size_type i = 0;
        i < _F.size();
        ++i)
    {
        if (_F[i] < min)
        {

        }
    }
    
    PushInList(_closeList, );
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
