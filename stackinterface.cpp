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
        temp->next = nullptrptr;
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