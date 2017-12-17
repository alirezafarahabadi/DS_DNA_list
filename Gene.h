//
// Created by alireza on 12/8/17.
//

#ifndef DS_DNA_LIST_GENE_H
#define DS_DNA_LIST_GENE_H

#include <iostream>
#include <list>
#include "MyString.h"

using namespace std;

class Gene {
public:
    int x1,x2;
    list <MyString> names;
    list <Gene> neighbors;
    Gene();

};


#endif //DS_DNA_LIST_GENE_H