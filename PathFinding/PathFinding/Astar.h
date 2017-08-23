#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Astar
{
public:
    enum Stance {Space, Block};
    typedef struct
    {
        int     x;
        int     y;
        Stance  state;
    }Pos;

    double      _F;
    double      _G;
    double      _H;
    Pos*        _dest;
    Pos*        _src;

    Astar();
    Astar(int x, int y, int x2, int y2);
    ~Astar();

    double GetDistance(Pos& dest, Pos& src);
};

