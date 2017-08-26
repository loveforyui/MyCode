#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Position
{
public:
    enum Stance { Space, Block };
    int _x;
    int _y;
    Stance _state;

    Position();
    Position(int x, int y);
    Position(int x, int y, Stance state);
    ~Position();

    Position& operator=(Position& ref);
    bool operator==(Position& ref);
    bool operator==(Position * ref);

    double GetDistance(Position& dest);
    double GetDistance(Position& dest, Position& src);
};

