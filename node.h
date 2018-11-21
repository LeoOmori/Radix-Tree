#ifndef NODE_H
#define NODE_H
#include <string.h>
#include <iostream>

using namespace std;

class Node{    

    public:
        Node(bool);
        Node* children[26];
        string edgeLabel[26];
        bool isEnd;
};




#endif // NODE_H