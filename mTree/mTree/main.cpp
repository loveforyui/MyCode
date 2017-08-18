#include <iostream>
#include "Node.h"

using namespace std;

void p(string& name)
{
    cout << name << endl;
}

void main()
{
    Node node = Node();

    string name = "first";

    node.CreateChild(name);
    name = "second";
    node.CreateChild(name);

    node.PrintNodeName();
    node.FindNode(name)->PrintNodeName();

    


    system("pause>nul");
}