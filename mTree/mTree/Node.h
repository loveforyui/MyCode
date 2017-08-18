#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node
{
public:
    string _name;
    Node* _parent;
    vector<Node*> _childs;

    Node();
    Node(string& name);
    ~Node();

    Node* CreateChild(string& nodeName);
    Node* FindNode(Node& node, string& nodeName);
    Node* FindNode(string& nodeName);
    Node* FindNode(const char*);
    void DeleteNode(string& nodeName);
    void PrintNodeName();
};

