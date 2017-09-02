#include <iostream>
#include <Windows.h>
#include "Astar.h"
#include "Position.h"

using namespace std;

void GotoXY(int x, int y, const char c);

void main()
{

    Position pos1 = Position(1, 0, Position::Space);
    Position pos2 = Position(6, 6, Position::Space);

    Astar astar = Astar(pos2, pos1);
    astar.FindPath(pos2, pos1);

    for (vector<Position*>::size_type i = 0;
        i < astar._closeList.size();
        ++i)
    {
        GotoXY(astar._closeList[i]->_x, astar._closeList[i]->_y, 'o');
        //cout << "(" << astar._printList[i]->_x << ", " << astar._printList[i]->_y << ")" << endl;
    }
    GotoXY(0, 32, ' ');

    system("pause>nul");
}

void GotoXY(int x, int y, const char c)
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

    cout << c;
}