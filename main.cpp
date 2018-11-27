#include "radix_tree.h"
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    RadixTree* tree = new RadixTree();

    tree->insert("facebook");
    tree->insert("face");
    tree->insert("facebookfoda");
    tree->insert("fa");
    
    cout << endl;
    tree->startWith("faceb");

}