#include <iostream>
#include "Node.h"

using namespace std;

void main()
{
    Node root = Node();

    // root �� �ڽ� first�� ����� first �� �ڽ� third�� ����
    root.CreateChild("first")->CreateChild("third");
    // root�� �ڽ� second�� ����� second�� �ڽ� fourth�� ����
    root.CreateChild("second")->CreateChild("fourth");
    // root�� �ڽ� fifth�� ����
    root.CreateChild("fifth");

    // ���� �̷������� ��.
    // �� �Լ����� ������ node* ������ ������
    // ��� ���� ����.

    // findNode ����
    root.FindNode("fifth")->CreateChild("sixth");

    //root.PrintNodeNChilds("root");

    root.PrintNodeNChilds(root);

    root.DeleteNodeToName("second");

    root.PrintNodeNChilds(root);

    system("pause>nul");
}