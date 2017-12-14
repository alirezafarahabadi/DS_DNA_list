//
// Created by alireza on 12/7/17.
//

#ifndef DS_DNA_LIST_MYSTRING_H
#define DS_DNA_LIST_MYSTRING_H

#include <iostream>

using namespace std;

class MyString {
public:
    char* data;
    int size;
    bool comparison_(MyString str);
    int length(char* str);

    explicit MyString(char* data1){
        this->data = data1;
        size = sizeof(data)/ sizeof(char);
    }
    MyString(){

    }

};


#endif //DS_DNA_LIST_MYSTRING_H
