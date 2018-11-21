#include "radix_tree.h"
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

RadixTree::RadixTree(){
    CASE = 'a';
}

void RadixTree::insert(string name){
    int i = 0;
    Node* aux = root;

    while(i < word.size() && aux->edgeLabel()[(int)word[i] == (int)CASE){
        int index =(int)word[i] - (int)CASE, j = 0;
        string* label = aux->edgeLabel(index);  
        while(j < label.size() && i < word.size() && (int)label[j] == (int)word[i]){
            ++i;
            ++j;
        }
        if(j == label.size()){
            aux = aux->children[index];
        }else{
            if(i == word.size()){
                Node prt = aux->children[index];
                Node newChild = new Node(true);
                string remainingLabel = label.substr(j);
                label = label.substr(0,j-1);  
                aux->children[index] = newChild;
                newChild->children[(int)remainingLabel[0] - (int)CASE] = prt;
                newChild->edgeLabel[(int)remainingLabel[0] - (int)CASE] = remainingLabel;
            }else{ // insert partial matching words
                string remainingLabel = label.substr(j);
                Node newChild = new Node(true);
            }
        }
    }
    
}