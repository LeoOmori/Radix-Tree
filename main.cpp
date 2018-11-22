#include "radix_tree.h"
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    RadixTree* tree = new RadixTree();

    tree->insert("amante");
    tree->insert("amar");
    tree->insert("thereafter");
    tree->insert("therein");
    tree->insert("this");


    // cout << tree->root->children[0]->edgeLabel[17];
    tree->print();
}