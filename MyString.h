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
    int get_size(char* str);
    char* get_line();
    bool contain(char* source, char* sub);
    char* erase(char* source);
    char *substr(const char *source);

    MyString(char* data1){
        this->data = data1;
        size = get_size(data);
    }

    MyString(){

    }
};


#endif //DS_DNA_LIST_MYSTRING_H
