#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H

#include <iostream>
using namespace std;

template <typename T>
class stackinterface{
    public:
    virtual ~stackinterface(){}
    virtual void push(const T& element) = 0;
    virtual void pop() = 0;
    virtual T peek() const = 0;
    virtual bool isempty() const=0;
    virtual int size() const = 0;
};

#endif