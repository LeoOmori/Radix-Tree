#include "radix_tree.h"
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    RadixTree* tree = new RadixTree();
    string word;
    tree->insertFile(tree,"bancoNome.txt");
    while(word != "SAIR"){
        cout << "------------DIGITE ///SAIR/// PARA SAIR DO PROGRAMA(LETRA MAISCULA)------------"<< endl;
        cout << "------------PROCURE UMA SUBSTRING NO BANCO DE PALAVRAS(LETRA MINUSCULA)------------" << endl;
        cin >> word;
        if(word  ==  "SAIR"){
            return 0;
        }
        cout << "------------RESULTADO:------------:" << endl;
        tree->printSubString(word);    
    }

}