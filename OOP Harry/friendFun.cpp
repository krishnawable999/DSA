#include<iostream>
using namespace std;

class Complex{
    int a;
    int b;

    public:
    void setval(int a, int b){
        this->a = a;
        this->b = b;
    }

    void print(){
        cout<<"The complex number is "<<a<<" + "<<b<<"i"<<endl;
    }
    friend Complex sumComplex(Complex c1, Complex c2);
};

Complex sumComplex(Complex c1, Complex c2){
    Complex c3;
    c3.setval((c1.a+c2.a), (c1.b+c2.b));
    return c3;
}

int main(){

    Complex c1, c2, sum;
    c1.setval(1,2);
    c1.print();

    c2.setval(3,4);
    c2.print();

    sum = sumComplex(c1,c2);
    sum.print();

}