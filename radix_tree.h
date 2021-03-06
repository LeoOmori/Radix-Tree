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
        int startWith(string name);
        Node *root = new Node(false);
        void insertFile(RadixTree *tree,string path);
        int printSubString(string word);
    private:

        char CASE;

        void printUtilSubString(Node* node, string &str, string word, int &x);
        void printUtil(Node* node, string &name);
        void printPrefix(Node* node, string &name, bool i,bool full);
};




#endif // RADIX_TREE_H