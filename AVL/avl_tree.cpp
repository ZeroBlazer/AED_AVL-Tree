#include "avl_tree.h"

template <typename T>
AVL_tree<T>::AVL_tree() :
    m_pRoot(NULL)
{}

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
bool AVL_tree<T>::add(T &d) {
//    Node_T **p;
//    if(find(d, p))
//        return false;
//    *p = new Node_T(d);
//    return true;
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
//    return false;
}

template <typename T>
bool AVL_tree<T>::addRec(T &d, Node_T *&p) {
//    if(p)
//        return addRec(d, p->m_pChildren[p->m_dato < d]);
//    Node_T *neo = Node_T(d);
//    p = neo;
//    return true;
}

template <typename T>
bool AVL_tree<T>::findRec(T &d, Node_T *&p) {
//    if(p->m_dato == d)
//        return true;
//    return findRec(d, p->m_pChildren[p->m_dato < d]);
}

template <typename T>
void AVL_tree<T>::printElem(Node_T *&p) {
    cout << p->m_dato << "\t";
}

template <typename T>
void AVL_tree<T>::printIn(Node_T *p) {
    if(!p)  return;
    if(p->m_pChildren[0])   printIn(p->m_pChildren[0]);
    printElem(p);
    if(p->m_pChildren[1])   printIn(p->m_pChildren[1]);
}

template <typename T>
void AVL_tree<T>::printPre(Node_T *p) {
    if(!p)  return;
    printElem(p);
    if(p->m_pChildren[0])   printIn(p->m_pChildren[0]);
    if(p->m_pChildren[1])   printIn(p->m_pChildren[1]);
}

template <typename T>
void AVL_tree<T>::printPos(Node_T *p) {
    if(!p)  return;
    if(p->m_pChildren[0])   printIn(p->m_pChildren[0]);
    if(p->m_pChildren[1])   printIn(p->m_pChildren[1]);
    printElem(p);
}

template <typename T>
void AVL_tree<T>::printIn() {
    printIn(m_pRoot);
    cout << endl;
}

template <typename T>
void AVL_tree<T>::printPre() {
    printPre(m_pRoot);
    cout << endl;
}

template <typename T>
void AVL_tree<T>::printPos() {
    printPos(m_pRoot);
    cout << endl;
}

template <typename T>
size_t AVL_tree<T>::height(Node_T *&p) { //Calcula la profundidad partiendo del nodo que se pasa como parámetro
    if(p) {
        size_t height_left = height(p->m_pChildren[0]),
               height_right = height(p->m_pChildren[1]);
        return ((height_left < height_right) ? height_right : height_left) + 1;
    }

    return 0;
}

template <typename T>
size_t AVL_tree<T>::height() {                //B)
    return height(m_pRoot);
}
