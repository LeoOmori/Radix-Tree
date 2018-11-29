#include "radix_tree.h"
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    RadixTree* tree = new RadixTree();
    string x;

    

    tree->insertFile(tree,"bancoPalavras.txt");
    cout << "pesquise uma palavra" << endl;
    cin >> x;
    // cout << "talvez você queiria digitar:"<< endl;
    bool y = tree->search(x);
    cout << y << endl;




}