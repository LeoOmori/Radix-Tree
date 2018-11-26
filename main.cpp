#include "radix_tree.h"
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    RadixTree* tree = new RadixTree();

    tree->insert("face");
    tree->insert("facebook");
    tree->insert("facebookfoda");
    tree->insert("facebookfodazika");



    // tree->print();
    cout << endl;
    tree->startWith("facebookfod");
}