#include <iostream>
#include "avl_tree.h"

using namespace std;

int main()
{
    AVL_tree<int> Tr;
    int ins;

    for(int i = 0; i < 1000; i++) {
        ins = rand();
        Tr.insert(ins);
    }

    Tr.graph();

    return 0;
}

