//
// Created by alireza on 12/7/17.
//

#include "MyString.h"
#include <iostream>

using namespace std;

bool MyString::comparison_(MyString str) {
    int min = size;
    if(str.size < min)
        min = str.size;

    for (int i = 0; i < min; i++) {
        if (data[i] > str.data[i])
            return true;
        else if(data[i] < str.data[i])
            return false;
    }
    return false;
}

int MyString::length(char *str) {
    int length = 0;
    while (str[length] != '\0'){
        length++;
    }
    return length;
}
