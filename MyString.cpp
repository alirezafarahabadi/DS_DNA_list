//
// Created by alireza on 12/7/17.
//

#include "MyString.h"
#include <iostream>

using namespace std;

bool MyString::comparison_(MyString str) {
    size = get_size(data);
    int min = size;
    if (str.size < min)
        min = str.size;

    for (int i = 0; i < min; i++) {
        if (data[i] > str.data[i])
            return true;
        else if (data[i] < str.data[i])
            return false;
    }
    return false;
}

int MyString::length(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

char *MyString::get_line() {

    char *str = new char[200];
    cin.getline(str, 200);
    return str;

}

bool MyString::contain(char *source, char *sub) {
    int size1 = get_size(source);
    int size2 = get_size(sub);
    int counter = 0;
    for (int i = 0; i < size1; i++) {
        if (source[i] == sub[counter]){
            counter++;
        } else{
            counter = 0;
        }
        if(counter == size2 || counter == size2 - 1)
            return true;
    }
    return false;
}



int MyString::get_size(char *str) {
    int size = 0;
    while (true) {
        if (str[size] != '\0')
            size++;
        else
            break;
    }
    return size + 1;
}

char* MyString::erase(char *source) {

    int counter = 0;
    while (true){
        if (source[counter] != 32){
            counter++;
        }
        else
            break;
    }

    auto * new_char = new char[get_size(source)-counter+1];
    int x = 0;
    for (int i = counter+1; i <= get_size(source); i++,x++) {
        new_char[x] = source[i];
    }
    return new_char;
}

char* MyString::substr(const char *source) {
    int counter = 0;
    while (true){
        if (source[counter] != 32 && source[counter] != '\0' ){
                counter++;
        } else
            break;
    }
    auto* new_char = new char[counter];
    for (int i = 0; i <counter; i++) {
        new_char[i] = source[i];
    }
    return new_char;
}

