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
        void startWith(string name);
        Node *root = new Node(false);
        void insertFile(RadixTree *tree,string path);
    private:

        char CASE;

        void printUtil(Node* node, string &name);
};




#endif // RADIX_TREE_H