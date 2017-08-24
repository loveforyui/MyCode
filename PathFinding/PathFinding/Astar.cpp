#include "Astar.h"



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
    // ����
    // push -> src
    // browse 8 position of src
    // if DetectPosInList(openList, 8 position of src)
    //, then push open list
    _F.clear();
    // closeList �� ������� ������, ����!
    if (DetectPosInList(_closeList, _src) == NULL)
    {
        _closeList.push_back(_src);
        _current = _src;
    }
    // closeList�� dst�� ������ ����
    
    if(*_current == *_dest)
    {
        _printList.clear();
        _printList.assign(_closeList.begin(), _closeList.end());
        _openList.clear();
        _closeList.clear();
        return;
    }

    // ���� ��ǥ���� �ֺ� ��ǥ �� openList�� ���� ��ǥ���� openlist�� push
    for (int y = -1; y < 2; ++y)
    {
        for (int x = -1; x < 2; ++x)
        {
            if (src._x + x < 0 || src._y + y < 0)
            {
                continue;
            }
            //������ ���� ���� ������Ʈ�� ���
            //position �����ڷ� ������
            //��ü�� ������ new ��� ������Ʈ ��ǥ�� ���
            Position* temp = DetectPosInList(_openList, new Position(src._x + x, src._y + y));
            if (temp == NULL)
            {
                if ((x == _current->_x) && (y == _current->_y))
                {
                    continue;
                }
                else
                {
                    PushInList(_openList, new Position(src._x + x, src._y + y));
                }                
            }
        }
    }

    // F ��� = ��������� �Ÿ� + ����Ʈ���� �������� ��ǥ���� �Ÿ�
    // �� ������� close list�� �ִ´�    
    for (vector<Position*>::size_type index = 0;
        index < _openList.size();
        ++index)
    {
        // H�� Pick�� ��ǥ�� ������������ �Ÿ�
        // G�� ���ݱ��� ���Ŀ� �Ÿ�
        // F = G + H
        _H = _dest->GetDistance(*_openList[index]);
        _F.push_back(_G + _H);
    }

    // F ����� ���� ���� ���� ã��
    // openlist�� �ش� index �� �ִ� �༮��
    // closeList�� push �� openlist������ ����
    // current ��ǥ�� �ű� �ַ� �ٲ�
    double min = 9999999;
    vector<int>::size_type minst = -1;

    for (vector<int>::size_type i = 0;
        i < _F.size();
        ++i)
    {
        if (_F[i] < min)
        {
            min = _F[i];
            minst = i;
        }
    }

    _G += _openList[minst]->GetDistance(*_current);

    PushInList(_closeList, _openList[minst]);

    _current = _openList[minst];

    _openList[minst] = NULL;

    if (DetectPosInList(_closeList, _dest) == NULL)
    {
        FindPath(dest, *_current);
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
