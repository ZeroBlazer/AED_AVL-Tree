#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "node.h"
#include <iostream>

using namespace std;

template <typename T>
class AVL_tree
{
    typedef node<T> Node_T;
private:
    Node_T *m_pRoot;

public:
    AVL_tree();

    ~AVL_tree();

    ~BinTree() {
        if(m_pRoot)
            m_pRoot->kill_me();
    }

    bool find(T &d, Node_T **&p);

    bool add(T &d);

    bool remove(T &d);

    bool addRec(T &d, Node_T *&p);

    bool findRec(T &d, Node_T *&p);

    void printIn(Node_T *p);

    void printPre(Node_T *p);

    void printPos(Node_T *p);

    void printIn();

    void printPre();

    void printPos();

    void printElem(Node_T *&p);

    size_t height(Node_T *&p);

    size_t height();
};

#include "avl_tree.cpp"

#endif // AVL_TREE_H
