#include "radix_tree.h"
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    RadixTree* tree = new RadixTree();

    tree->insertFile(tree,"bancoNome.txt");
    tree->printSubString("mir");

}