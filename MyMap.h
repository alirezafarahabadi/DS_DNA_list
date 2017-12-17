//
// Created by alireza on 12/8/17.
//

#ifndef DS_DNA_LIST_MYMAP_H
#define DS_DNA_LIST_MYMAP_H

#include <iostream>
#include "Gene.h"
#include "MyString.h"

using namespace std;

struct Node{
public:
    Node* parent;
    Node* right;
    Node* left;
    MyString key;
    Gene value;
    Node(MyString key, Gene value){
        this->key = key;
        this->value = value;
    }
    Node(){

    }
};



class MyMap {

public:
    Node* root;
    int p_size;
    void insert(MyString key, Gene value);
    Node* find(MyString key);
    void erase(MyString key);


    MyMap(){
        root = nullptr;
        p_size = 0;
    }

private:
    void left_rotate(Node* x);
    void right_rotate(Node* x);
    void splay(Node* x);
    Node* subtree_minimum( Node* u );
    Node* subtree_maximum( Node* u );
    void replace(Node* u, Node* v);
};


#endif //DS_DNA_LIST_MYMAP_H
