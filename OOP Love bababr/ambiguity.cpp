#include<iostream>
using namespace std;

class A{
    public:
    void fun(){
        cout<<"Inside A"<<endl;
    }
};

class B{
    public:
    void fun(){
        cout<<"Inside B"<<endl;
    }
};

class C: public A, public B{

};

int main(){
    C c;
    c.A ::fun();
}