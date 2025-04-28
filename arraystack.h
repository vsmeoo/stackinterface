#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include <iostream>
using namespace std;
#include "stackinterface.h"

template <typename T>
class arraystack: public stackinterface<T>{
    private:
    T* arr;
    int top;
    int capacity;
    
    public:
    arraystack(int cap){
        capacity = cap;
        top = -1;
        arr = new T[capacity];
    }
    
    ~arraystack(){
        delete[] arr;
    }
    
    void push(const T& element) override{
        if(top== capacity-1){
            cout<<"stack full"<< endl;
            return;
        }
        top++;
        arr[top] = element;
    }

    void pop() override{
        if(top==-1){
            cout<<"stack empty"<< endl;
            return;
        }
        top--;
    }

    T peek() const override{
        if(top==-1){
            cout<<"stack empty"<< endl;
            return T();
        }
        return arr[top];
    }

    bool isempty() const override{
        return top==-1;
    }

    int size() const override{
        return top+1;
    }
};

#endif