#include<iostream>
using namespace std;

class Employee{
    public:
    int id;
    Employee(int id){
        this->id = id;
    }
    Employee(){
        id=1;
    }
};


class Programmer : Employee{
    public:

    Programmer(int id){
        this->id = id;
    }
    Programmer(){}

    void getId(){
        cout<<"The id is "<<id<<endl;
    }
};

int main(){
    Programmer p(10);
    p.getId();
}