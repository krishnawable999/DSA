#include<iostream>
#include<string>
using namespace std;

class Person{
    public:

    void walk(){
        cout<<"Walking"<<endl;
    }
};

class Teacher: virtual public Person{
    public:

    void Teach(){
        cout<<"Teaching"<<endl;
    }
};

class Researcher: virtual public Person{
    public:

    void Research(){
        cout<<"Researching"<<endl;
    }
};

// multiple Inheritance
class Professor:public Teacher, public Researcher{
    public:
    void Bor(){
        cout<<"Boreing"<<endl;
    }
};

int main(){
    Professor p;
    // Diamond Problem
    //  Solution 1 : Scope Resolution
    // p.Teacher::walk();
    // p.Researcher::walk();

    //  Second Method 
    // Virtual Function
    p.walk();
    p.walk();
}
