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
    Astar(int x, int y, int x2, int y2);
    ~Astar();

    
    Position* DetectPosInList(vector<Position*>& list, Position& pos);

};

