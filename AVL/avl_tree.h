#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "node.h"
#include <iostream>

using namespace std;

template <typename T>
class AVL_tree
{
    enum RotationWay {
        LEFT = 0,
        RIGHT = 1
    };

    typedef node<T> Node_T;

private:

    Node_T *m_pRoot;

private:

    bool insert(T &d, Node_T *&p = m_pRoot);

    void printElem(Node_T *&p);

    void singleRotation(Node_T *&p, RotationWay way);

    void doubleRotation(Node_T *&p, RotationWay way);

public:

    AVL_tree() :m_pRoot(0), m_size(0) {}

    ~AVL_tree();

    bool find(T &d, Node_T **&p);

    bool insert(T &d);

    bool remove(T &d);

    void AVL_tree<T>::graph();

    void printIn();

    void printPre();

    void printPos();

    void printIn(Node_T *p);

    void printPre(Node_T *p);

    void printPos(Node_T *p);

    int height();
};

#include "avl_tree.cpp"

#endif // AVL_TREE_H
