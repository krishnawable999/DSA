#include<iostream>
using namespace std;

class Base1{
    int data1;
    public:
    Base1(int data){
        data1 = data;
        cout<<"Base1 Ctor Called"<<endl;
    }

    void printData(){
        cout<<"Data1 : "<<data1<<endl;
    }
};

class Base2{
    int data2;
    public:
    Base2(int data){
        data2 = data;
        cout<<"Base2 Ctor Called"<<endl;
    }

    void printData(){
        cout<<"Data2 : "<<data2<<endl;
    }
};

class Derived:public Base1, public Base2
{   int d1,d2;
    public:
    Derived(int d1, int d2 ,int data1,int data2):Base1(data1), Base2(data2){
        this->d1 = d1;
        this->d2 = d2;
        cout<<"Derived Ctor Called"<<endl;
    }

    void printData(){
        cout<<"Derived 1 : "<<d1<<endl;
        cout<<"Derived 2 : "<<d2<<endl;
    }

};

/*

priority depends upon the sequence which we provide from the derived ctor to the its base class ctor
 *** The virtual has the special priority it callls before then any class
 e.g. class D: public A, virtual public D{
        In this case the class D will call firstly after this the A will call
 };
 */

int main(){
    Derived d(10,20, 30, 40);
    d.Base1::printData();
    d.Base2::printData();
    d.Derived::printData();
}