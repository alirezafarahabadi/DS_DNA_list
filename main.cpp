#include <iostream>
#include <algorithm>
#include "MyString.h"
#include "MyMap.h"
#include "Gene.h"

using namespace std;

bool available_neighbors(Node* source,Node* distination);

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

        if (order.contain(order.data,"AddGene")) {
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

        if (order.contain(order.data,"PrintGeneInfo")) {
            order.data = order.erase(order.data);
            name1.data = order.substr(order.data);
            Node *node = myMap.find(name1);
            if (node == nullptr) {
                cout << "**Error : there is no gene by this name" << endl;
            }
            else {
                cout << node->key.data << endl;
                cout << node->value.x1 << endl;
                cout << node->value.x2 << endl;
                cout<<"list of names"<<endl;
                for(auto v:node->value.names){
                    cout<<v.data<<endl;
                }
                cout<<"list of neighbors"<<endl;
                for(auto v:node->value.neighbors){
                    cout<<v.names.back().data<<endl;
                }
            }
        }

        if (order.contain(order.data,"Add_GeneAlias")) {
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

        if (order.contain(order.data,"Regulates")){
            order.data = order.erase(order.data);
            name.data = order.substr(order.data);
            order.data = order.erase(order.data);
            name1.data = order.substr(order.data);
            if (myMap.find(name) == nullptr || myMap.find(name1) == nullptr)
                cout<<"**Error : names are not available"<<endl;
            else{
                Node *node = myMap.find(name);
                Node *node1 = myMap.find(name1);
                if(available_neighbors(node,node1)){
                    //NOTHING
                }

                else {
                    node->value.neighbors.push_back(node1->value);
                }
            }

        }

        if (order.contain(order.data, "exit"))
            break;
    }

    return 0;
}

bool available_neighbors(Node* source,Node* distination){
    for (auto v:source->value.neighbors){
        if(v.names.back().data == distination->value.names.back().data && v.x1 == distination->value.x1 && v.x2 == distination->value.x2)
            return true;
    }
    return false;
}