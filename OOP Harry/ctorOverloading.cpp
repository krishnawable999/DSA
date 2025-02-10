#include<iostream>
using namespace std;

class Com{
    int a, b, c;
   
    public:
     Com(){
        a = 0;
        b = 0;
    }

    Com(int a, int b, int c=3){
        this->a = a;
        this->b = b;
        this->c = c;
    }

    void print(){
        cout<<"The comlpex numbers are "<<a<<" + "<<b<<"i"<<endl;
        cout<<"The value of c is: "<<c<<endl;
    }
};



int main(){
    Com c1;
    c1.print();
    Com c2(1,2);
    c2.print();
    
}