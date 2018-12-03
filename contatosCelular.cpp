#include "radix_tree.h"
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    RadixTree* tree = new RadixTree();
    string x;
    tree->insertFile(tree,"bancoNome.txt");
    while(x != "SAIR"){
        cout << "------------DIGITE ///SAIR/// PARA SAIR DO PROGRAMA(LETRA MAISCULA)------------"<< endl;
        cout << "------------PROCURE UM CONTATO NO SEU CELULAR(LETRA MINUSCULA)------------" << endl;
        cin >> x;
        if( x == "SAIR"){
            return 0;
        }
        bool y = tree->search(x);
        cout << "------------RESULTADO:------------:" << endl;
        if(y == 1){
            cout << x << endl; 
        }else{
            cout << "SEM RESULTADO!!" << endl;
            cout << "------------VOCE TALVEZ QUERIA PESQUISAR:------------:" << endl; 
            int ex = tree->startWith(x);
            if(ex != 1){ 
                cout << ex << endl;
                cout << "NAO EXISTEM CONTATOS SIMILARES NO SEU CELULAR!!" << endl;

                cout << endl;
            }
        }
    }

}