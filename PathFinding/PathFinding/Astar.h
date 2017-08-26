#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "Position.h"

using namespace std;

class Astar
{
public:
    vector<double>      _F;
    //double              _F;
    double              _G;
    double              _H;

    Position*           _dest;
    Position*           _src;
    Position*           _current;

    vector<Position*>   _openList;
    vector<Position*>   _closeList;
    vector<Position*>   _closeList_;
    vector<Position*>   _closeList__;
    vector<Position*>   _printList;

    Astar();
    Astar(int dest_x, int dest_y, int src_x, int src_y);
    Astar(Position & dest, Position & src);
    ~Astar();
    
    Position* DetectPosInList(vector<Position*>& list, Position& pos);
    Position* DetectPosInList(vector<Position*>& list, Position * pos);

    void FindPath(Position& dest, Position& src);
    void FindPath(vector<Position*>& closelist, Position& dest, Position& src);

    int PushInList(vector<Position*>& list, Position* pos);

    Position* FindMinF(vector<Position*>& closelist);
};

