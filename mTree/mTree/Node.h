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
    vector<Node*> _trashs;

    Node();
    Node(string& name);
    Node(const char* name);
    ~Node();

    Node* CreateChild(string& nodeName);
    Node* CreateChild(const char* nodeName);

    Node* FindNode(Node& node, const char * nodeName);
    Node* FindNode(const char* nodeName);
    Node* FindNode(string& nodeName);

    Node * DeleteNodeToName(const char * nodeName);

    Node * MoveNodeToTrash(const char* nodeName);

    Node * MoveNodeToTrash(Node & nodeName);

    bool isExistNode(const char* nodeName);

    bool isExistNode(string & nodeName);

    void ShowErrorMessage(Node * ERROR_NO);

    Node* PrintNodeNChilds(const char* nodeName);

    Node* PrintNodeNChilds(Node & node);

    /*Node* FindNode(Node& node, string& nodeName);
    
    
    void DeleteNode(string& nodeName);

    void PrintNodetoEnd(const char* nodeName);

    void PrintChildsName();
    void PrintChildsName(const char* nodeName);*/
};

