#include <iostream>
#include "Node.h"

using namespace std;

void main()
{
    Node root = Node();

    // root 의 자식 first를 만들고 first 에 자식 third를 만듬
    root.CreateChild("first")->CreateChild("third");
    // root의 자식 second를 만들고 second에 자식 fourth를 만듬
    root.CreateChild("second")->CreateChild("fourth");
    // root의 자식 fifth를 만듬
    root.CreateChild("fifth");

    // 대충 이런식으로 씀.
    // 각 함수들은 리턴을 node* 형으로 리턴함
    // 즉시 쓸수 있음.

    // findNode 예제
    root.FindNode("fifth")->CreateChild("sixth");

    //root.PrintNodeNChilds("root");

    root.PrintNodeNChilds(root);

    root.DeleteNodeToName("second");

    root.PrintNodeNChilds(root);

    system("pause>nul");
}