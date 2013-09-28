#include <iostream>
#include "avl_tree.h"

using namespace std;

int main()
{
    AVL_tree<int> Tr;
    int ins = 50;
    Tr.insert(ins);
    Tr.printPre();
    ins = 10;
    Tr.insert(ins);
    Tr.printPre();
    ins = 60;
    Tr.insert(ins);
    Tr.printPre();
    ins = 55;
    Tr.insert(ins);
    Tr.printPre();
    ins = 70;
    Tr.insert(ins);
    Tr.printPre();
    ins = 57;
    Tr.insert(ins);
    Tr.printPre();

    return 0;
}

