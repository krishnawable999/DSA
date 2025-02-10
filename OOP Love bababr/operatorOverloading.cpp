#include<iostream>
using namespace std;

class A{
    public:
    int a;
    int b;

    void operator+(A &obj){
        int val1 = this->a;
        int val2 = obj.a;

        cout<<"Answer : "<<val2-val1<<endl;
    }

    void operator() (){
        cout<<"I am Bracket"<<endl;
    }
};

int main(){
    A obj1, obj2;
    obj1.a = 5;
    obj2.a = 7;

    obj1+obj2;
    obj1();
}