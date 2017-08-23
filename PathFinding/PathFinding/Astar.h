#pragma once
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Astar
{
public:
    double          _F;
    double          _G;
    double          _H;

    Pos*            _dest;
    Pos*            _src;

    vector<Pos*>    _openList;
    vector<Pos*>    _closeList;

    Astar();
    Astar(int x, int y, int x2, int y2);
    ~Astar();

    
    Pos* DetectPosInList(vector<Pos*>& list, Pos& pos);

};

