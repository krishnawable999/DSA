#include<iostream>
using namespace std;

class Base{
    int data1;
    public:
    int data2;

    void setData();
    int getdata1();
    int getdata2();
};

void Base ::setData(){
    data1 = 10;
    data2 = 20;
}

int Base::getdata1(){
    return data1;
}

int Base::getdata2(){
    return data2;
}

class Derived : public Base{
    int data3;
    public:

    void process();
    void display();
};

void Derived::process(){
    int val = getdata1();
    data3 = data2*val;
}

void Derived::display(){
    cout<<"Data 1: "<<getdata1()<<endl;
    cout<<"Data 2: "<<data2<<endl;
    cout<<"Data 3: "<<data3<<endl;
}

int main(){
    Derived d;
    d.setData();
    d.process();
    d.display();
}