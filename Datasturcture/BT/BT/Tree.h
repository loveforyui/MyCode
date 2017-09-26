#ifndef __TREE_H__
#define __TREE_H__

template <typename T>
class Tree
{
#pragma region var
protected:
    Node<T>* root;

private:
    static Tree<T>* inst;
#pragma endregion

#pragma region construct
private:
    Tree()
    { 
    }
    ~Tree() {}
#pragma endregion

#pragma region getter
public:
    static Tree<T>* getinst()
    {
        if (inst == NULL)
        {
            inst = new Tree<T>;
        }
        return inst;
    }
#pragma endregion

#pragma region functions

private:
    void searchEmptyNode(T var, Node<T>* next)
    {
        if (var <= next->data)
        {
            if (next->left == NULL)
            {
                next->left = new Node<T>(var);
            }
            else
            {
                searchEmptyNode(var, next->left);
            }
        }
        else
        {
            if (next->right == NULL)
            {
                next->right = new Node<T>(var);
            }
            else
            {
                searchEmptyNode(var, next->right);
            }
        }
    }
    int getHight(Node<T>* next)
    {

    }
public:
    void insert(T var)
    {
        if (root == NULL)
        {
            root = new Node<T>(var);
        }
        else
        {
            searchEmptyNode(var, root);
        }
    }
#pragma endregion

};


#endif // !__TREE_H__

