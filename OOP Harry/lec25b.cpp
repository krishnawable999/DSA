#include<iostream>
using namespace std;

class com{
    int a;
    int b;

    public:

    void setVal(int a, int b){
        this->a = a;
        this->b = b;
    }

    void complex(com c1, com c2){
        a = c1.a + c2.a;
        b = c1.b + c2.b;

    }

    void print(){
        cout<<"The complex number is"<<a<<" + "<<b<<"i"<<endl;
    }
};

int main(){
    com c1, c2, c3;
    c1.setVal(1,2);
    c2.setVal(3,4);
    c1.print();
    // c3.setVal(c1,c2);
    c3.complex(c1,c2);
    c3.print();
}