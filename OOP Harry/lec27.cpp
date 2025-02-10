#include<iostream>
using namespace std;

// forword declareation
class Complex;

class Calc{
    
};




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
};

int main(){

}