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

private:

    bool insert(T &d, Node_T *&p = m_pRoot);

    void printElem(Node_T *&p);

    void singleRotation(Node_T *&p);

    void doubleRotation(Node_T *&p);

public:

    AVL_tree() :m_pRoot(0), m_size(0) {}

    ~AVL_tree();

    bool find(T &d, Node_T **&p);

    bool insert(T &d);

    bool remove(T &d);

    int height();

    void balance(Node_T *ptr = m_pRoot);

    void printIn();

    void printPre();

    void printPos();

    void printIn(Node_T *p);

    void printPre(Node_T *p);

    void printPos(Node_T *p);
};

//#include "avl_tree.cpp"

template <typename T>
AVL_tree<T>::~AVL_tree()
{
    if(m_pRoot)
        m_pRoot->kill_me();
}

template <typename T>
bool AVL_tree<T>::find(T &d, Node_T **&p) {
    p = &m_pRoot;
    while(*p) {
        if((*p)->m_dato == d)
            return true;
        p = &((*p)->m_pChildren[(*p)->m_dato < d]);
    }
    return false;
}

template <typename T>
void AVL_tree<T>::singleRotation(Node_T *&p, int way) {
    Node_T *Child = p->m_pChildren[!way],
           *tmp = Child->m_pChildren[way];
    Child->m_pChildren[way] = p;
    parent->m_pChildren[!way] = tmp;
    p = Child;
}

template <typename T>
void AVL_tree<T>::doubleRotation(Node_T *&p) {

}

template <typename T>
bool AVL_tree<T>::insert(T &d, Node_T *&p = m_pRoot) {
    if(!p) {
        p = new Node_T(d);
        return true;
    }

    if(insert(d, p->m_pChildren[p->m_dato < d])) {
        p->update_height();
        int balance_factor = p->balance_factor();   //Verificar el estado del árbol
        switch (balance_factor) {
        case 0:
        case -1:
        case 1:
            return true;
        case -2:    //Left Heavy
//          do_stuff();
            return true;
        case 2:     //Right Heavy
//          do_stuff();
            return true;
        default:
            throw 0;
        }
    }

}

template <typename T>
bool AVL_tree<T>::insert(T &d) {
    return insert(d, m_pRoot);
}

template <typename T>
bool AVL_tree<T>::remove(T &d) {
//    Node_T **p,
//           *tmp;

//    if(!find(d, p))
//        return false;
//    if((*p)->m_pChildren[0] && (*p)->m_pChildren[1]) {
//        tmp = (*p)->m_pChildren[0];
//        for(; tmp; tmp = (*p)->m_pChildren[1]);

//    }
//    else {
//        tmp = *p;
//        if((*p)->m_pChildren[0] && !(*p)->m_pChildren[1])
//            *p = tmp->m_pChildren[0];
//        else
//            *p = tmp->m_pChildren[1];
//        delete tmp;
//        return true;
//    }
    return false;
}


/*******TERMINADO*******/
template <typename T>
void AVL_tree<T>::printElem(Node_T *&p) {
    cout << p->m_dato << "\t";
}

/*******TERMINADO*******/
template <typename T>
void AVL_tree<T>::printIn(Node_T *p) {
    if(!p)  return;
    if(p->m_pChildren[0])   printIn(p->m_pChildren[0]);
    printElem(p);
    if(p->m_pChildren[1])   printIn(p->m_pChildren[1]);
}

/*******TERMINADO*******/
template <typename T>
void AVL_tree<T>::printPre(Node_T *p) {
    if(!p)  return;
    printElem(p);
    if(p->m_pChildren[0])   printIn(p->m_pChildren[0]);
    if(p->m_pChildren[1])   printIn(p->m_pChildren[1]);
}

/*******TERMINADO*******/
template <typename T>
void AVL_tree<T>::printPos(Node_T *p) {
    if(!p)  return;
    if(p->m_pChildren[0])   printIn(p->m_pChildren[0]);
    if(p->m_pChildren[1])   printIn(p->m_pChildren[1]);
    printElem(p);
}

/*******TERMINADO*******/
template <typename T>
void AVL_tree<T>::printIn() {
    printIn(m_pRoot);
    cout << endl;
}

/*******TERMINADO*******/
template <typename T>
void AVL_tree<T>::printPre() {
    printPre(m_pRoot);
    cout << endl;
}

/*******TERMINADO*******/
template <typename T>
void AVL_tree<T>::printPos() {
    printPos(m_pRoot);
    cout << endl;
}

/*******TERMINADO*******/
template <typename T>
int AVL_tree<T>::height() {
    if(!m_pRoot) return -1;
    return m_pRoot->m_height;
}

#endif // AVL_TREE_H
