#include<iostream>
using namespace std;

class base1{
    public:
    void greet(){
        cout<<"Hii how are you"<<endl;
    }
};

class base2{
    public:
    void greet(){
        cout<<"Kaise hoo Bhaii"<<endl;
    }
};

class Derived:public base1, public base2{
    public:

    // void greet(){
    //     base2::greet();
    // }
};

class B{
    public:
    void say(){
        cout<<"Hello world"<<endl;
    }
};

class D: public B{
    public:
    void say(){
        cout<<"Namaste Dduniya"<<endl;
    }
};

int main(){
    // Ambiguity 1
    /*Derived d;
    // d.greet();
    d.greet();*/

    // Solution to Ambiguity ---> object_name.className :: function();

    // Ambiguity 2

    D d;
    d.say();
}