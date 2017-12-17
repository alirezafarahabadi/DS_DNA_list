#include <iostream>
#include <algorithm>
#include "MyString.h"
#include "MyMap.h"
#include "Gene.h"

using namespace std;

int main() {
    MyMap myMap;
    MyString order;
    MyString order1;
    MyString name;
    MyString name1;
    MyString x1;
    MyString x2;
    while (true) {
        order.data = order.get_line();
        cout << order.data << endl;

        if (order1.contain(order.data,"AddGene")) {
            order.data = order.erase(order.data);
            name.data = order.substr(order.data);
            order.data = order.erase(order.data);
            x1.data = order.substr(order.data);
            order.data = order.erase(order.data);
            x2.data = order.substr(order.data);
            Node *node = myMap.find(name);
            if (node != nullptr) {
                cout << "**Error : A gene by this name is available" << endl;
            } else {
                Gene gene;
                gene.names.push_back(name);
                gene.x1 = atoi(x1.data);
                gene.x2 = atoi(x2.data);
                myMap.insert(name, gene);
            }
        }

        if (order1.contain(order.data,"PrintGeneInfo")) {
            order.data = order.erase(order.data);
            name1.data = order.substr(order.data);
            Node *node = myMap.find(name1);
            if (node == nullptr) {
                cout << "**Error : there is no gene by this name" << endl;
            } else {
                cout << node->key.data << endl;
                cout << node->value.x1 << endl;
                cout << node->value.x2 << endl;
                cout<<"in list"<<endl;
                for(auto v:node->value.names){
                    cout<<v.data<<endl;
                }
            }
        }

        if (order1.contain(order.data,"Add_GeneAlias")) {
            cout << "print1" << endl;
            order.data = order.erase(order.data);
            name.data = order.substr(order.data);
            order.data = order.erase(order.data);
            name1.data = order.substr(order.data);
            if (myMap.find(name) == nullptr)
                cout << "**Error : there is no gene by first name" << endl;
            else if (myMap.find(name1) != nullptr)
                cout << "**Error : A gene by second name is available" << endl;
            else {
                cout << "print2" << endl;
                Node *node = myMap.find(name);
                cout << "print3" << endl;
                node->value.names.push_back(name1);
                cout << "print4" << endl;
                myMap.insert(name1, node->value);
                cout << "print5" << endl;
            }
        }

        if (order.contain(order.data, "exit"))
            break;
    }

    return 0;
}