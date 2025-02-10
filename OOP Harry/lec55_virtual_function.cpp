#include<iostream>
using namespace std;

class Base{
    public:
    int base_var=10;

    virtual void display(){
        cout<<"the value of base_var is"<<base_var<<endl;
    }
};

class Derived: public Base{
    public:
    int derived_var = 20;

    void display(){
        cout<<"the value of derived_var is "<<derived_var<<endl;
    }
};

int main(){
    Base *base_class_ptr;
    Base base_class_obj;

    Derived derived_class_obj;
    base_class_ptr = &derived_class_obj;
    base_class_ptr->display();
}