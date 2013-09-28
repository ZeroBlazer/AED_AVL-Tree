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
        int balance_factor;

    public:
        node(T &d) :
            m_dato(d),
            balance_factor(0)
        {
            m_pChildren[0] = m_pChildren[1] = NULL;
        }

        ~node(){}

        void kill_me();
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

#endif // NODE_H
