#include "Astar.h"

// 해야 하는 것
// 벽 구현

Astar::Astar()
{
    _dest           = new Position();
    _src            = new Position();
    _current        = new Position();
    _G              = 0;
    _H              = 0;
}

Astar::Astar(int dest_x, int dest_y, int src_x, int src_y)
{
    _dest           = new Position(dest_x, dest_y);
    _src            = new Position(src_x, src_y);
    _current        = new Position(src_x, src_y);
    _G              = 0;
    _H              = 0;
}

Astar::Astar(Position& dest, Position& src)
{
    _dest           = &dest;
    _src            = &src;
    _current        = &src;
    _G              = 0;
    _H              = 0;
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
            if (list[i] == NULL)
            {
                continue;
            }
            else
            {
                if (*list[i] == *pos)
                {
                    return list[i];
                }
            }            
        }
    }
    return NULL;
}

void Astar::FindPath(Position & dest, Position & src)
{
    FindPath(_closeList, dest, src);
    FindPath(_closeList_, dest, src);
    FindPath(_closeList__, dest, src);
}

void Astar::FindPath(vector<Position*>& closelist, Position & dest, Position & src)
{
    // 순서
    // push -> src
    // browse 8 position of src
    // if DetectPosInList(openList, 8 position of src)
    //, then push open list
    _F.clear();
    // closeList 에 출발지가 없으면, 시작!
    if (DetectPosInList(closelist, _src) == NULL)
    {
        closelist.push_back(_src);
        _current = _src;
    }

    // closeList중 dst가 있으면 종료    
    //if(*_dest == *_current)
    //if(DetectPosInList(_closeList, _dest) != NULL)
    //{
    //    /*if (_closeList_.empty())
    //    {
    //        *_current = *_src;
    //        FindPath(dest, *_current);
    //    }
    //    if (_closeList__.empty())
    //    {
    //        *_current = *_src;
    //        FindPath(dest, *_current);
    //    }*/
    //    _printList.clear();
    //    _printList.assign(_closeList.begin(), _closeList.end());
    //    _openList.clear();
    //    _closeList.clear();
    //    return;
    //}

    // 현재 좌표에서 주변 좌표 중 openList에 없는 좌표들을 openlist에 push
    for (int y = -1; y < 2; ++y)
    {
        for (int x = -1; x < 2; ++x)
        {
            if (_current->_x + x < 0 || _current->_y + y < 0)
            {
                continue;
            }
            //지금은 벽에 대한 오브젝트가 없어서
            //position 생성자로 했지만
            //객체가 있으면 new 대신 오브젝트 좌표를 사용
            Position* isExistInOpen     = DetectPosInList(_openList, new Position(_current->_x + x, _current->_y + y));
            Position* isExistInClose    = DetectPosInList(closelist, new Position(_current->_x + x, _current->_y + y));

            if ((isExistInOpen == NULL) && (isExistInClose == NULL))
            {
                PushInList(_openList, new Position(_current->_x + x, _current->_y + y));
            }
            /*if (temp == NULL)
            {
                if ((_current->_x + x == _current->_x) && (_current->_x + x == _current->_y))
                {
                    continue;
                }
                else
                {
                    PushInList(_openList, new Position(_current->_x + x, _current->_y + y));
                }                
            }*/
        }
    }

    // F 비용 = 현재까지온 거리 + 리스트안의 포스에서 목표까지 거리
    // 를 계산한후 close list에 넣는다    
    for (vector<Position*>::size_type index = 0;
        index < _openList.size();
        ++index)
    {
        // H는 Pick된 좌표와 목적지까지의 거리
        // G는 지금까지 거쳐온 거리
        // F = G + H
        _H = _dest->GetDistance(*_openList[index]);
        _F.push_back(_G + _H);
    }

    // F 비용중 가작 작은 값을 찾아
    // openlist중 해당 index 에 있는 녀석을
    // closeList에 push 후 openlist에서는 삭제
    // current 좌표를 옮긴 애로 바꿈
    FindMinF(closelist);

    if (DetectPosInList(closelist, _dest) == NULL)
    {
        FindPath(closelist, dest, *_current);
    }
    else
    {
        *_current = *_src;
        _printList.clear();
        _printList.assign(closelist.begin(), closelist.end());
        //_openList.clear();
        //closelist.clear();
        return;
    }
}

int Astar::PushInList(vector<Position*>& list, Position* pos)
{
    if (list.empty())
    {
        list.push_back(pos);
    }
    else
    {
        for (vector<Position*>::size_type i = 0;
            i < list.size();
            ++i)
        {
            if (list[i] == NULL)
            {
                list[i] = pos;
                return 0;
            }
        }
        list.push_back(pos);
    }
    return 0;
}

Position* Astar::FindMinF(vector<Position*>& closelist)
{
    double min = 9999999;
    vector<int>::size_type minst = -1;

    for (vector<int>::size_type i = 0;
        i < _F.size();
        ++i)
    {
        if (_F[i] <= min)
        {
            min = _F[i];
            minst = i;
        }
    }
    _G += _openList[minst]->GetDistance(*_current);
    // push 하기전에 엘리멘트가 list에 있는지 확인
    PushInList(closelist, _openList[minst]);
    _current = _openList[minst];
    _openList[minst] = NULL;
    return _openList[minst];
}

