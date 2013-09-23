#include "node.h"

template <typename T>
node<T>::node(T &_dato) :
    m_dato(_dato)
{}

template <typename T>
node<T>::~node()
{}

template <typename T>
void node<T>::kill_me() {
    if(m_pChildren[0])
        m_pChildren[0]->kill_me();
    if(m_pChildren[1])
        m_pChildren[1]->kill_me();
    delete this;
}
