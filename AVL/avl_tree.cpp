#include "avl_tree.h"

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
void AVL_tree<T>::singleRotation(Node_T *&p, RotationWay way) {
    Node_T *q = p->m_pChildren[way];
    p->m_pChildren[way] = q->m_pChildren[!way];
    p->m_pChildren[!way] = p;
    p->balance_factor = q->balance_factor = 0;
    p = q;
}

template <typename T>
void AVL_tree<T>::doubleRotation(Node_T *&p, RotationWay way) {
    Node_T  *q = p->m_pChildren[!way],
            *r = q->m_pChildren[way];
    p->m_pChildren[!way] = r->m_pChildren[way];
    q->m_pChildren[way] = r->m_pChildren[!way];
    r->m_pChildren[!way] = q;
    r->m_pChildren[way] = p;
    switch (r->balance_factor) {
    case 0:
        p->balance_factor = q->balance_factor = 0;
        break;
    case -1:
        break;
    case -1:
        break;
    }
}

template <typename T>
bool AVL_tree<T>::insert(T &d, Node_T *&p = m_pRoot) {
    if(!p) {
        p = new Node_T(d);
        return true;
    }

    //Verificación de repeticiones, retorna false si encontró algún elemento
#ifndef ALLW_REP
    if(p->m_dato == d)
        return false;
#endif

    if(insert(d, p->m_pChildren[p->m_dato < d])) {
        p->balance_factor += (p->m_dato < d) ? 1 : -1;
        switch (p->balance_factor) {
        case 2:
            if()
            break;
        case -2:
            break;
        default:
            break;
        }
        return true;
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
//    REIMPLEMENTAR ---------------------------------->

}
