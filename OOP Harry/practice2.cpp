#include<iostream>
using namespace std;

class A{
    public:
    A(){
        cout<<"Ctor A called"<<endl;
    }
};

class B: public A{
    public:
    B(){
        cout<<"Ctor B called"<<endl;
    }
};

int main(){
    A a;
}