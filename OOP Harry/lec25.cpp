#include<iostream>
using namespace std;

class Emp{
    int id;
    int sal;
    public:

    void setVal(){
        sal = 123;
        cout<<"Enter the value of id"<<endl;
        cin>>id;
    }

    void getVal(){
        cout<<"The val of id is "<<id<<"and salary is "<<sal<<endl;
    }

};

int main(){
    Emp e[4];
    for (int i = 0; i < 4; i++)
    {
        e[i].setVal();
        e[i].getVal();
    }
    
}