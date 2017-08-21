#include <iostream>
#include "Node.h"

using namespace std;

void main()
{
    Node root = Node();

    root.CreateChild("first")->CreateChild("third");

    root.CreateChild("second");

    /*vector<Node*> ha;
    Node t1 = Node();
    Node t2 = Node();
    Node t3 = Node();
    Node* e1 = &t1;
    Node* e2 = &t2;
    Node* e3 = &t3;

    ha.push_back(e1);
    ha.push_back(e2);
    ha.push_back(e3);

    for (vector<Node*>::size_type i = 0; i < ha.size(); ++i)
    {
        cout << ha[i]->_name << endl;
    }
*/


    /*node.CreateChild("second");
    node.FindNode("first")->CreateChild("fivth");
    node.FindNode("first")->CreateChild("fivths");
    node.FindNode("second")->CreateChild("third");
    node.FindNode("second")->CreateChild("fourth");
*/
    //node.PrintChildsName(node._nameConst);

    /*node.PrintNodetoEnd("root");*/
    //node.FindNode("second")->PrintChildsName();

    system("pause>nul");
}