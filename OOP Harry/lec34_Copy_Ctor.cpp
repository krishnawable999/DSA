#include<iostream>
using namespace std;

class Number{
    int num;
    public:
    Number(){}

    Number(int num){
        this->num = num;
    }

    // copy ctor
    // when we do not make copy cotr manually then the compiler automatically makes their own copy ctor
    Number(Number &obj){
        cout<<"Copy Ctor Called"<<endl;
        num = obj.num;
    }

    void show(){
        cout<<"The number is :"<<num<<endl;
    }
};

int main(){

    Number x,y(21),z,z2;
    z = Number(11);
    z.show();
    y.show();
    Number a(y);
    a.show();

    z2 = z; // Cpoy ctor will not called
    Number z3 = z ;// copy Ctor WILL called
    z3.show();

}