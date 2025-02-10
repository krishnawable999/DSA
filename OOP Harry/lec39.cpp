#include<iostream>
using namespace std;

class Base{
    protected:
    int a;
    public:
    int b;
};

class Derived:protected Base{
    public:
    void print(){
        cout<<a<<" "<<b<<endl;
    }
};

int main(){
    Derived d1;
    // cout<<d1.a<<endl; This will not work bcz, a is protected
    d1.print();
}