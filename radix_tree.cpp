#include "radix_tree.h"
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>

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
    for (int i = 0; i < 26; i++) {
        if (node->edgeLabel[i] != "") {
            int length = str.size();

            str = str.append(node->edgeLabel[i]);
            printUtil(node->children[i], str);
            str = str.substr(0,length);
        }
    }
}

int RadixTree::startWith(string word){
    int i = 0;
    Node* aux = root;
    string rootPrefix = "";

    while(i < word.size() && aux->edgeLabel[(int)word[i] - (int)CASE] != ""){
        int index =(int)word[i] - (int)CASE, j = 0;
        string label = aux->edgeLabel[index];  
        while(j < label.size() && i < word.size() && (int)label[j] == (int)word[i]){
            ++i;
            ++j;
        }
        if(j == label.size()){
            rootPrefix = rootPrefix.append(aux->edgeLabel[index]);
            aux = aux->children[index];
        }else{
            int change = 0;
            if(i == word.size()){
                rootPrefix = rootPrefix.append(aux->edgeLabel[index]);
                aux = aux->children[index];
                bool isWord = false;
                if(aux->isEnd == true && aux->children[index] == NULL){
                    isWord = true;
                }
                printPrefix(aux, rootPrefix, false, isWord);

            }else{ 

                return 0;
            }
            return 1;
        }
    }
    if(i < word.size()){
        // cout << "prefix not found !!" << endl;
        return 0;
    }else{
        printPrefix(aux, rootPrefix, false, false);
        return 1;
    }
        
}

void RadixTree::insertFile(RadixTree *tree, string path){
    ifstream inFile(path);
    string line;
    if(inFile.is_open()){
        while(getline(inFile,line)){
            if(line != ""){
                tree->insert(line);
            }
        }
        inFile.close();
    }

  else{
    cout << "Unable to open file!!"; 
  }

    
}

void RadixTree::printPrefix(Node* node, string &str, bool firstIteration, bool full){
    if((node->isEnd && firstIteration == false) || (full == true)){
        cout << str <<endl;

    }
    for (int i = 0; i < 26; i++) {
        if (node->edgeLabel[i] != "") {
            int length = str.size();

            str = str.append(node->edgeLabel[i]);
            // cout << i << endl;
            printPrefix(node->children[i], str, false, false);
            str = str.substr(0,length);
        }
    }
}

bool RadixTree::search(string word){
    int i = 0;
    Node* aux = root;

    while(i < word.size() && aux->edgeLabel[(int)word[i] - (int)CASE] != ""){
        int index =(int)word[i] - (int)CASE, j = 0;
        string label = aux->edgeLabel[index];  
        while(j < label.size() && i < word.size()){
            if((int)label[j] != (int)word[i]){
                return false;
            }
            ++i;
            ++j;
        }
        if(j == label.size() && i <= word.size()){
            aux = aux->children[index];
        }else{
            return false;
        }
    }
    
    return i == word.size() && aux->isEnd == true;
}

int RadixTree::printSubString(string word){
    string str;
    int x = 0;
    printUtilSubString(root, str, word, x);
    if(x == 0){
        cout << "NAO EXISTEM PALAVRAS PARA ESSA SUBSTRING!!" << endl;
    }
}

void RadixTree::printUtilSubString(Node* node, string &str,string word, int &x){
    if(node->isEnd == true){
        size_t found = str.find(word);
        if(found != string::npos){
            cout << str << endl;
            x = 1;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (node->edgeLabel[i] != "") {
            int length = str.size();

            str = str.append(node->edgeLabel[i]);
            printUtilSubString(node->children[i], str, word, x);
            str = str.substr(0,length);
        }
    }
}



