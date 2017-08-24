#include <iostream>
#include "Astar.h"
#include "Position.h"

using namespace std;

void main()
{

    Position pos1 = Position(0, 0, Position::Space);
    Position pos2 = Position(5, 5, Position::Space);

    Astar astar = Astar(pos2, pos1);
    astar.FindPath(pos2, pos1);

    for (vector<Position*>::size_type i = 0;
        i < astar._printList.size();
        ++i)
    {
        cout << "(" << astar._printList[i]->_x << ", " << astar._printList[i]->_y << ")" << endl;
    }

    system("pause");
}