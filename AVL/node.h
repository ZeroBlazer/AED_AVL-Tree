#ifndef NODE_H
#define NODE_H

template <typename T>
class node
{
public:
    T m_dato;
    node<T> *m_pChildren[2];
    int count[2];

public:
    node(T &_dato);

    void kill_me();
};

#include "node.cpp"

#endif // NODE_H
