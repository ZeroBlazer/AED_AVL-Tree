#ifndef NODE_H
#define NODE_H

template<typename T>
T max(T &a, T &b) {
    return (a > b) ? a : b;
}

template <typename T>
class node
{
    public:
        T m_dato;
        node<T> *m_pChildren[2];
        int m_height;

    public:
        node(T &d) :
            m_dato(d),
            m_height(0)
        {
            m_pChildren[0] = NULL;
            m_pChildren[1] = NULL;
        }

        ~node(){}

        void kill_me();

        void update_height();

        int balance_factor();
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
    int left_h  = (m_pChildren[0]) ? m_pChildren[0]->m_height : -1;
        right_h = (m_pChildren[1]) ? m_pChildren[1]->m_height : -1;
    m_height = max(left_h, right_h) + 1;
}

template <typename T>
int node<T>::balance_factor()
{
    int left_h  = (m_pChildren[0]) ? m_pChildren[0]->m_height : -1;
        right_h = (m_pChildren[1]) ? m_pChildren[1]->m_height : -1;
    return right_h - left_h;
}

#endif // NODE_H
