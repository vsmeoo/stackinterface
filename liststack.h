#ifndef LISTSTACK_H
#define LISTSTACK_H

#include <iostream>
using namespace std;
#include "stackinterface.h"

template <typename T>
class liststack;
template <typename T>
class node{
    private:
    node<T>* next;
    T data;
    public:
    node(T ele){
        data = ele;
        next = nullptr;
    }

    friend class liststack<T>;
};

template <typename T>
class liststack: public stackinterface<T>{
    private:
    node<T>* top;
    T data;
    int count;

    public:
    liststack(){
        top = nullptr;
        count=0;
    }
    bool isempty() const override{
        return top==nullptr;
    }
    void push(const T& ele) override{
        node<T> *newnode = new node(ele);
        newnode->next = top;
        top = newnode;
        count++;
    }

    void pop() override{
        if(isempty()){
            cout<<"stack empty"<< endl;
            return;
        }
        node<T>* temp = top;
        top = temp->next;
        temp->next = nullptr;
        delete temp;
        count--;
    }

    T peek() const override{
        if(isempty()){
            cout<<"stack empty"<< endl;
            return T();
        }
        return top->data;
    }

    int size() const override{
        return count;
    }
    

};

#endif