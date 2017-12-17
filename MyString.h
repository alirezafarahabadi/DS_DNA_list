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
    bool comparison_(const MyString& str) const;
    int length(const char* str) const;
    int get_size(const char* str) const;
    char* get_line() const;
    bool contain(const char* source, const char* sub) const;
    char* erase(const char* source) const;
    char *substr(const char *source) const;

    MyString(char* data1){
        this->data = data1;
        size = get_size(data);
    }

    MyString(){

    }
};


#endif //DS_DNA_LIST_MYSTRING_H
