#include <iostream>
#include "avl_tree.h"

using namespace std;

int main()
{
    AVL_tree<int> Tr;
    int a = 10, b = 20, c = 30, d = 40, e = 50;
    Tr.insert(d);
    Tr.insert(a);
    Tr.insert(e);
    Tr.insert(b);
    Tr.insert(c);
    Tr.printIn();

    return 0;
}

