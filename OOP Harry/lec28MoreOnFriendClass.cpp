#include<iostream>
using namespace std;

// in a case when we are using another class which is not declared in the above we have to use the forword declaration

class Y;
class X{
    int data;
    public:
    void setVal(int data){
        this->data = data;
    }
    friend void add(X,Y);
};

class Y{
    int num;
    public:
    void setVal(int data){
        num = data;
    }
    friend void add(X,Y);
};

void add(X o1, Y o2){
    cout<<"Result after the sum is: "<<o1.data+o2.num<<endl;
}

int main(){
    X o1;
    o1.setVal(2);
    Y o2;
    o2.setVal(4);
    add(o1, o2);
}