#ifndef RADIX_TREE_H
#define RADIX_TREE_H
#include "node.h"
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>


class RadixTree{    

    public:
        RadixTree();

        void insert(string name);
        void print();
        bool search(string name);
        bool startWith(string name);
    private:
        Node* root = new Node(false);
        char CASE;

        void printUtil();
};




#endif // RADIX_TREE_H