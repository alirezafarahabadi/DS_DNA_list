//
// Created by alireza on 12/8/17.
//

#include "MyMap.h"

void MyMap::left_rotate(Node *x) {
        Node* y = x->right;
        if(y) {
            x->right = y->left;
            if( y->left ) y->left->parent = x;
            y->parent = x->parent;
        }

        if( !x->parent ) root = y;
        else if( x == x->parent->left ) x->parent->left = y;
        else x->parent->right = y;
        if(y) y->left = x;
        x->parent = y;
}
void MyMap::right_rotate(Node *x) {
    Node *y = x->left;
    if(y) {
        x->left = y->right;
        if( y->right ) y->right->parent = x;
        y->parent = x->parent;
    }
    if( !x->parent ) root = y;
    else if( x == x->parent->left ) x->parent->left = y;
    else x->parent->right = y;
    if(y) y->right = x;
    x->parent = y;
}
void MyMap::splay(Node *x) {
    while( x->parent ) {
        if( !x->parent->parent ) {
            if( x->parent->left == x ) right_rotate( x->parent );
            else left_rotate( x->parent );
        } else if( x->parent->left == x && x->parent->parent->left == x->parent ) {
            right_rotate( x->parent->parent );
            right_rotate( x->parent );
        } else if( x->parent->right == x && x->parent->parent->right == x->parent ) {
            left_rotate( x->parent->parent );
            left_rotate( x->parent );
        } else if( x->parent->left == x && x->parent->parent->right == x->parent ) {
            right_rotate( x->parent );
            left_rotate( x->parent );
        } else {
            left_rotate( x->parent );
            right_rotate( x->parent );
        }
    }
}

void MyMap::insert(const MyString& key, const Gene& value) {
    Node *z = root;
    Node *p = nullptr;

    while( z ) {
        p = z;
        if( key.comparison_(z->key)) z = z->right;
        else z = z->left;
    }

    z = new Node( key ,value);
    z->parent = p;

    if( !p ) root = z;
    else if(z->key.comparison_(p->key)) p->right = z;
    else p->left = z;

    splay( z );
    p_size++;
}

Node* MyMap::subtree_minimum(Node *u) const{
    while( u->left ) u = u->left;
    return u;
}

Node* MyMap::subtree_maximum(Node *u) const{
    while( u->right ) u = u->right;
    return u;
}

void MyMap::replace( Node *u, Node *v ) {
    if( !u->parent ) root = v;
    else if( u == u->parent->left ) u->parent->left = v;
    else u->parent->right = v;
    if( v ) v->parent = u->parent;
}


Node* MyMap::find(const MyString& key) const{
    Node *z = root;
    while( z ) {
        if( key.comparison_(z->key) ) z = z->right;
        else if(z->key.comparison_(key)) z = z->left;
        else return z;
    }
    return nullptr;
}


void MyMap::erase(const MyString& key ) {
    Node *z = find( key );
    if( !z ) return;

    splay( z );

    if( !z->left ) replace( z, z->right );
    else if( !z->right ) replace( z, z->left );
    else {
        Node *y = subtree_minimum( z->right );
        if( y->parent != z ) {
            replace( y, y->right );
            y->right = z->right;
            y->right->parent = y;
        }
        replace( z, y );
        y->left = z->left;
        y->left->parent = y;
    }

    delete z;
    p_size--;
}


