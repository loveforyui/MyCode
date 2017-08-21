#include "Node.h"

Node::Node()
{
    _name   = "root";
    _nameConst = "root";
    _parent = NULL;
}

Node::Node(string & name):_name(name)
{
    _parent = NULL;
    _nameConst = _name.c_str();
}

Node::Node(const char * name)
{
    _name = name;
    _nameConst = name;
}


Node::~Node()
{
    
}

Node * Node::CreateChild(string & nodeName)
{
    _childs.push_back(new Node(nodeName));
    FindNode(nodeName)->_parent = this;
    return FindNode(nodeName);
}
Node * Node::CreateChild(const char* nodeName)
{
    if (isExistNode(nodeName))
    {
        cout << "Aleady exist '" << nodeName << "' node name" << endl;
    }
    else
    {
        _childs.push_back(new Node(nodeName));
        FindNode(nodeName)->_parent = this;
        return FindNode(nodeName);
    }    
}

Node* Node::FindNode(string& nodeName)
{
    Node* temp = this;
    if (temp->_name == nodeName)
    {
        temp = this;
    }
    else
    {
        for (vector<Node*>::size_type i = 0; i < temp->_childs.size(); ++i)
        {
            temp = FindNode(*(temp->_childs[i]), temp->_nameConst);
            if (temp->_name == nodeName)
            {
                return temp;
            }
        }
    }
    return temp;
}



Node* Node::FindNode(const char* nodeName)
{
    // node ~ ���� �����ؼ� nodeName�� ���� node�� Find
    // node�� nameConst�� ã���� �ϴ� nodeName �̸� node�� ����
    // �ƴϸ� childs vector���� child ���� FindNode�� ���ȣ��.
    Node* result = this;
    if (!strcmp(result->_nameConst, nodeName))
    {
        result = this;
    }
    else
    {
        if (!result->_childs.empty())
        {
            Node* Nodefor = result;
            int size = result->_childs.size();
            for (vector<Node*>::size_type i = 0; i < size; ++i)
            {
                result = FindNode(*(Nodefor->_childs[i]), nodeName);
                if (result != NULL)
                {
                    if (!strcmp(result->_nameConst, nodeName))
                    {
                        return result;
                    }
                }
            }
        }
        else
        {
            result = NULL;
        }
    }
    return result;
}
Node* Node::FindNode(Node& node, const char* nodeName)
{
    // node ~ ���� �����ؼ� nodeName�� ���� node�� Find
    // node�� nameConst�� ã���� �ϴ� nodeName �̸� node�� ����
    // �ƴϸ� childs vector���� child ���� FindNode�� ���ȣ��.
    // return ���� ����� nodeName�� ������� result return
    // �ƴ϶�� ��� childs Ž��(���ȣ��)
    Node* result = &node;
    
    if (!strcmp(result->_nameConst, nodeName))
    {
        result = &node;
    }
    else
    {
        if (!result->_childs.empty())
        {
            Node* Nodefor = result;
            int size = result->_childs.size();
            for (vector<Node*>::size_type i = 0; i < size; ++i)
            {
                result = FindNode(*(Nodefor->_childs[i]), nodeName);
                if (result != NULL)
                {
                    if (!strcmp(result->_nameConst, nodeName))
                    {
                        return result;
                    }
                }                
            }
        }
        else
        {
            result = NULL;
        }
    }
    return result;
}

bool Node::isExistNode(const char * nodeName)
{
    Node* temp = FindNode(nodeName);
    if (temp != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//
//Node * Node::FindNode(Node& node, string & nodeName)
//{
//    if (node._name == nodeName)
//    {
//        return &node;
//    }
//    else
//    {
//        for (vector<Node*>::size_type i = 0; i < node._childs.size(); ++i)
//        {
//            if (node._childs[i]->_name == nodeName)
//            {
//                return node._childs[i];
//            }
//            else
//            {
//                return FindNode(*(node._childs[i]), nodeName);
//            }
//        }
//    }
//    return nullptr;
//}
//Node * Node::FindNode(string & nodeName)
//{
//    if (this != NULL)
//    {
//        if (this->_name == nodeName)
//        {
//            return this;
//        }
//        else
//        {
//            for (vector<Node*>::size_type i = 0; i < this->_childs.size(); ++i)
//            {
//                if (this->_childs[i]->_name == nodeName)
//                {
//                    return this->_childs[i];
//                }
//                else
//                {
//                    return FindNode(*(this->_childs[i]), nodeName);
//                }
//            }
//        }
//    }    
//    return nullptr;
//}
//Node * Node::FindNode(Node& node, const char * nodeName)
//{
//    if ((node._nameConst == nodeName))
//    {
//        return &node;
//    }
//    else
//    {
//        for (vector<Node*>::size_type i = 0; i < node._childs.size(); ++i)
//        {
//            if ((node._childs[i]->_nameConst == nodeName))
//            {
//                return node._childs[i];
//            }
//            else
//            {
//                return FindNode(*(node._childs[i]), nodeName);
//            }
//        }
//    }    
//    return nullptr;
//}
//Node * Node::FindNode(const char * nodeName)
//{
//    if (this != NULL)
//    {
//        if (this->_nameConst == nodeName)
//        {
//            return this;
//        }
//        else
//        {
//            for (vector<Node*>::size_type i = 0; i < this->_childs.size(); ++i)
//            {
//                if (this->_childs[i]->_nameConst == nodeName)
//                {
//                    return this->_childs[i];
//                }
//                else
//                {
//                    FindNode(*(this->_childs[i]), nodeName);
//                }
//            }
//        }
//    }
//    
//    return nullptr;
//}
//
//void Node::DeleteNode(string & nodeName)
//{
//    Node* temp;
//    Node* tempParent = NULL;
//    int parentChildIndex = 0;
//    if (FindNode(*this, nodeName) != NULL)
//    {
//        temp = FindNode(*this, nodeName);
//        if (temp->_parent != NULL)
//        {
//            tempParent = temp->_parent;
//        }
//    }
//    //find parent _childs index for "nodeName" set NULL
//    for (vector<Node*>::size_type i = 0; i < tempParent->_childs.size(); ++i)
//    {
//        if (tempParent->_childs[i] == temp)
//        {
//            tempParent->_childs[i] = NULL;
//        }
//    }
//    _name = "";
//    _parent = NULL;
//    _childs.clear();
//}
//
//void Node::PrintNodetoEnd(const char * nodeName)
//{
//    Node* temp = FindNode(nodeName);
//    bool result = false;
//    //�ڽ� ��尡 ������, �ڱ��ڽ��� �̸��� ����ϰ� ����
//    //�ڽ� ��尡 ������, �ڽĳ���� �̸��� �Ű������� ��� ȣ��
//    if (temp != NULL)
//    {
//        if (temp->_childs.empty())
//        {
//            cout << temp->_nameConst << endl;
//        }
//        else
//        {
//            cout << temp->_name << endl;
//            for (vector<Node*>::size_type i = 0; i < temp->_childs.size(); ++i)
//            {
//                PrintNodetoEnd(temp->_childs[i]->_nameConst);
//            }            
//        }
//    }
//}
//*if (temp != NULL)
//{
//if (!temp->_childs.empty())
//{
//cout << endl;
//cout << temp->_nameConst << endl;
//for (vector<Node*>::size_type i = 0; i < temp->_childs.size(); ++i)
//{
//if (temp->_childs[i] != NULL)
//{
//result = true;
//cout << temp->_childs[i]->_nameConst << "\t";
//PrintNodetoEnd(temp->_childs[i]->_nameConst);
//}
//}
//}
//}*/
//
//void Node::PrintChildsName()
//{
//    if (this != NULL)
//    {
//        cout << _name << endl;
//        //printf("%s\n", _name);
//        for (vector<Node*>::size_type i = 0; i < _childs.size(); ++i)
//        {
//            //printf("%d : %s\t", i + 1, _childs[i]);
//            cout << i + 1 << ": " << _childs[i]->_name << "\t";
//        }
//        cout << endl;
//    }
//    else
//    {
//        cout << "not exist." << endl;
//    }
//
//}
//void Node::PrintChildsName(const char* nodeName)
//{
//    Node* temp = FindNode(nodeName);
//    if (temp != NULL)
//    {
//        cout << temp->_name << endl;
//        //printf("%s\n", _name);
//        for (vector<Node*>::size_type i = 0; i < temp->_childs.size(); ++i)
//        {
//            //printf("%d : %s\t", i + 1, _childs[i]);
//            cout << i + 1 << ": " << temp->_childs[i]->_name << "\t";
//        }
//        cout << endl;
//    }
//    else
//    {
//        cout << nodeName << " not exist." << endl;
//    }
//}