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
    tree->insert("a");
    tree->insert("thereafter");
    tree->insert("therein");
    tree->insert("this");


    tree->print();
}