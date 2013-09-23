#ifndef NODE_H
#define NODE_H

template<typename T>
T max(T&a, T&b) {if(a>b) return a; else return b;}

template <typename T>
class node
{
    public:
        T m_dato;
        node<T> *m_pChildren[2];
        int m_height;

    public:
        node(T &d) : m_dato(d), m_height(0) {m_pChildren[0]=0; m_pChildren[1]=0;}
        ~node(){}

        void kill_me();
        void update_height();
};

//#include "node.cpp"

template <typename T>
void node<T>::kill_me()
{
    if(m_pChildren[0])
        m_pChildren[0]->kill_me();
    if(m_pChildren[1])
        m_pChildren[1]->kill_me();
    delete this;
}

template <typename T>
void node<T>::update_height()
{
    int left_h,right_h;
    if(m_pChildren[0])
        left_h=m_pChildren[0]->m_height;
    else left_h=-1;
    if(m_pChildren[1])
        right_h=m_pChildren[1]->m_height;
    else right_h=-1;
    m_height = max(left_h,right_h)+1;
}

#endif // NODE_H
