#ifndef STACKOP_H
#define STACKOP_H

#include <iostream>
using namespace std;

template <typename T>
void stackop(stackinterface<T> *astack){
    int op;
    do{
        cout<<"choose operation push(1) pop(2) peek(3) check_if_empty(4) size(5) exit(9) ";
        
        cin>>op;
        switch (op)
        {
        case 1:
            T pele;
            cout<<"enter element "<< endl;
            cin>>pele;
            astack->push(pele);
            break;
        case 2:
            astack->pop();
            break;
        case 3:
            cout<<astack->peek()<< endl;
            break;
        case 4:
            if(astack->isempty()){
                cout<<"stack empty"<< endl;
            }else{
                cout<<"stack not empty"<< endl;
            }
            break;
        case 5:
            cout<<astack->size()<< endl;
            break;
        case 9:
            cout<<"exit "<< endl;
            break;
        default:
            cout<<"Invalid"<< endl;
            break;
        }
    }while(op !=9);
}

#endif