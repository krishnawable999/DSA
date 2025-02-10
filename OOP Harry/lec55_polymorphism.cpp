#include<iostream>
using namespace std;

class Base{
    public:
    int base_var;

    void display(){
        cout<<"the value of base_var is"<<base_var<<endl;
    }
};

class Derived: public Base{
    public:
    int derived_var;

    void display(){
        cout<<"the value of derived_var is "<<derived_var<<endl;
    }
};

int main(){
    Base *base_class_ptr;
    Base base_class_obj;
    Derived derived_class_obj;
    // base_class_ptr = &derived_class_obj; // we can make the pointer of base class  and points it to the object of the derived class
    // base_class_ptr->display(); // It will call to the display() function of the base class it is called as late binding
    
    Derived *derived_class_ptr;
    derived_class_ptr = &derived_class_obj;

    derived_class_ptr->derived_var = 99;
    derived_class_ptr->display();
}