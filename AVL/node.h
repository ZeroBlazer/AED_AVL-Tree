#ifndef NODE_H
#define NODE_H

template <typename T>
class node
{
    public:
        T m_dato;
        node<T> *m_pChildren[2];
        int m_height;

    public:
        node(T &d) : m_dato(d), m_height(-1) {}
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
void update_height()
{

}

#endif // NODE_H
