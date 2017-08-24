#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include "Position.h"

using namespace std;

class Astar
{
public:
    double              _F;
    double              _G;
    double              _H;

    Position*           _dest;
    Position*           _src;

    vector<Position*>   _openList;
    vector<Position*>   _closeList;

    Astar();
    Astar(int dest_x, int dest_y, int src_x, int src_y);
    ~Astar();
    
    Position* DetectPosInList(vector<Position*>& list, Position& pos);
    Position * DetectPosInList(vector<Position*>& list, Position * pos);
    void FindPath(Position& dest, Position& src);

    int PushInList(vector<Position*>& list, Position * pos);
};

