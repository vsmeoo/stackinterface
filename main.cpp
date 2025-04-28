#include <iostream>
#include "stackinterface.h"
#include "arraystack.h"
#include "liststack.h"
#include "stackop.h"
using namespace std;

int main(){
    int input=0;
    while(input != 1 && input !=2){
        cout<<"Array(1) or List(2) stack? ";
        
        cin>>input;
        if(input==1){
            int adtype;
            cout<<"Datatype? int(1) char(2) double(3) float(4)";
            cin>>adtype;
            int asize;
            cout<<"Enter size of the array stack ";
            cin>>asize;
            switch (adtype)
            {
            case 1:{
                stackinterface<int> *astack = new arraystack<int>(asize);
                stackop(astack);
                delete astack;
                break;
            }
            case 2:{
                stackinterface<char> *astack = new arraystack<char>(asize);
                stackop(astack);
                delete astack;
                break;}
            case 3:{
                stackinterface<double> *astack = new arraystack<double>(asize);
                stackop(astack);
                delete astack;
                break;}
            case 4:{
                stackinterface<float> *astack = new arraystack<float>(asize);
                stackop(astack);
                delete astack;
                break;}
            default:
                break;
            }
            
        }else if(input==2){
            cout<<"Datatype? int(1) char(2) double(3) float(4)";
            int ldtype;
            cin>>ldtype;
            switch (ldtype)
            {
            case 1:{
                stackinterface<int> *lstack = new liststack<int>;
                stackop(lstack);
                delete lstack;
                break;}
            case 2:{
                stackinterface<char> *lstack = new liststack<char>;
                stackop(lstack);
                delete lstack;
                break;}
            case 3:{
                stackinterface<double> *lstack = new liststack<double>;
                stackop(lstack);
                delete lstack;
                break;}
            case 4:{
                stackinterface<float> *lstack = new liststack<float>;
                stackop(lstack);
                delete lstack;
                break;}
            default:
                break;
            }
        }else{
            cout<<"invalid"<< endl;
        }
    }
    return 0;
}