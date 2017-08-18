#include "Node.h"



Node::Node()
{
    _name   = "root";
    _parent = NULL;
}

Node::Node(string & name):_name(name)
{
    _parent = NULL;
}


Node::~Node()
{
    
}

Node * Node::CreateChild(string & nodeName)
{
    _childs.push_back(new Node(nodeName));
    return FindNode(*this, nodeName);
}

Node * Node::FindNode(Node& node, string & nodeName)
{
    for (vector<Node*>::size_type i = 0; i < node._childs.size(); ++i)
    {
        if (node._childs[i]->_name == nodeName)
        {
            return node._childs[i];
        }
        else
        {
            return FindNode(*(node._childs[i]), nodeName);
        }
    }
    return nullptr;
}
Node * Node::FindNode(string & nodeName)
{
    for (vector<Node*>::size_type i = 0; i < this->_childs.size(); ++i)
    {
        if (this->_childs[i]->_name == nodeName)
        {
            return this->_childs[i];
        }
        else
        {
            return FindNode(*(this->_childs[i]), nodeName);
        }
    }
    return nullptr;
}

void Node::DeleteNode(string & nodeName)
{
    Node* temp;
    Node* tempParent = NULL;
    int parentChildIndex = 0;
    if (FindNode(*this,nodeName) != NULL)
    {
        temp = FindNode(*this,nodeName);
        if (temp->_parent != NULL)
        {
            tempParent = temp->_parent;
        }
    }
    //find parent _childs index for "nodeName" set NULL
    for (vector<Node*>::size_type i = 0; i < tempParent->_childs.size(); ++i)
    {
        if (tempParent->_childs[i] == temp)
        {
            tempParent->_childs[i] = NULL;
        }
    }
    _name = "";
    _parent = NULL;
    _childs.clear();
}

void Node::PrintNodeName()
{
    cout << _name << endl;
    //printf("%s\n", _name);
    for (vector<Node*>::size_type i = 0; i < _childs.size(); ++i)
    {
        //printf("%d : %s\t", i + 1, _childs[i]);
        cout << i + 1 << ": " << _childs[i]->_name << "\t";
    }
    cout << endl;
}
