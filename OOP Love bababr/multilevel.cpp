#include<iostream>
using namespace std;

class Animal{
    public:
    int age;
    int weight;

    void sound(){
        cout<<"Speaking, Inside Animal Class"<<endl;
    }
};

class Human{
    public:

    void speak(){
        cout<<"Speaking, Inside Human Class"<<endl;
    }
};

class Hybrid: public Animal, public Human{
    public:

    void Hbd(){
        cout<<"Inside Hybrid Class"<<endl;
    }
};


int main(){
    Hybrid h;
    h.sound();
    h.speak();
    h.Hbd();

    
}