#ifndef __STRUCT_H__
#define __STRUCT_H__

template <typename T>
struct Node
{
    T data;
    Node<T>* left;
    Node<T>* right;

    Node()
        : left(NULL), right(NULL)
    {
    }
    Node(T var)
        : data(var), left(NULL), right(NULL)
    {
    }
};

#endif // !__STRUCT_H__
