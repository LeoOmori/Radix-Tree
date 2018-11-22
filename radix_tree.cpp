#include "radix_tree.h"
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

RadixTree::RadixTree(){
    CASE = 'a';
}

void RadixTree::insert(string word){
    int i = 0;
    Node* aux = root;

    while(i < word.size() && aux->edgeLabel[(int)word[i] - (int)CASE] != ""){
        int index =(int)word[i] - (int)CASE, j = 0;
        string label = aux->edgeLabel[index];  
        while(j < label.size() && i < word.size() && (int)label[j] == (int)word[i]){
            ++i;
            ++j;
        }
        if(j == label.size()){
            aux = aux->children[index];
        }else{
            if(i == word.size()){
                Node* prt = aux->children[index];
                Node* newChild = new Node(true);

                string remainingLabel = label.substr(j);
                aux->edgeLabel[index] = label.substr(0,j);
                aux->children[index] = newChild;
                newChild->children[(int)remainingLabel[0] - (int)CASE] = prt;
                newChild->edgeLabel[(int)remainingLabel[0] - (int)CASE] = remainingLabel;
                delete prt;
            }else{ // insert partial matching words
                string remainingLabel = label.substr(j);
                Node* newChild = new Node(false);
                string remainingWord =  word.substr(i);
                Node* temp = aux->children[index];
                
                aux->edgeLabel[index] = label.substr(0,j);
                aux->children[index] = newChild;
                newChild->edgeLabel[(int)remainingLabel[0] - (int)CASE] = remainingLabel;
                newChild->children[(int)remainingLabel[0] - (int)CASE] = temp;
                newChild->edgeLabel[(int)remainingWord[0] - (int)CASE] = remainingWord;
                newChild->children[(int)remainingWord[0] - (int)CASE] = new Node(true);

                delete temp;
            }
            return;
        }
    }
    if(i < word.size()){
        aux->edgeLabel[(int)word[i] - (int)CASE] = word.substr(i);
        aux->children[(int)word[i] - (int)CASE] = new Node(true);
    }else{
        aux->isEnd = true;
    }
    
}

void RadixTree::print(){
    string str;
    printUtil(root, str);
}

void RadixTree::printUtil(Node* node, string &str){
    if(node->isEnd){
        cout << str << endl; 
    }
    for (int i = 0; i < 26; ++i) {
        if (node->edgeLabel[i] != "") {
            int length = str.size();

            str = str.append(node->edgeLabel[i]);
            printUtil(node->children[i], str);
            str = str.substr(0,length);

        }
    }
}
