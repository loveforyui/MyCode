#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node
{
public:
    const char* _nameConst;
    string _name;

    Node* _parent;
    vector<Node*> _childs;

    Node();
    Node(string& name);
    Node(const char* name);
    ~Node();

    Node* CreateChild(string& nodeName);
    Node* CreateChild(const char* nodeName);

    Node* FindNode(Node& node, const char * nodeName);
    Node* FindNode(const char* nodeName);
    Node* FindNode(string& nodeName);

    bool isExistNode(const char* name);

    /*Node* FindNode(Node& node, string& nodeName);
    
    
    void DeleteNode(string& nodeName);

    void PrintNodetoEnd(const char* nodeName);

    void PrintChildsName();
    void PrintChildsName(const char* nodeName);*/
};

