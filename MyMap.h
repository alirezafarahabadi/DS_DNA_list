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
    Node(const MyString& key, const Gene& value){
        this->key = key;
        this->value = value;
    }
    Node(){

    }
private:

};



class MyMap {

public:
    void insert(const MyString& key, const Gene& value);
    Node* find(const MyString& key) const;
    void erase(const MyString& key);


    MyMap(){
        root = nullptr;
        p_size = 0;
    }

private:
    void left_rotate(Node* x);
    void right_rotate(Node* x);
    void splay(Node* x);
    Node* subtree_minimum( Node* u ) const;
    Node* subtree_maximum( Node* u ) const;
    void replace(Node* u, Node* v);

    Node* root;
    int p_size;
};


#endif //DS_DNA_LIST_MYMAP_H
