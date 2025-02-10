#include<iostream>
using namespace std;

class base1{
    protected:
    int val1;
    public:
    void setVal(int val1){
        this->val1 = val1;
    }

};


class base2{
    protected:
    int val2;
    public:
    void setVal(int val2){
        this->val2 = val2;
    }
};

class base3{
    protected:
    int val3;
    public:
    void setVal3(int val3){
        this->val3 = val3;
    }
};

class Derived: public base1, public base2, protected base3
{
    public:
    void result(){
        cout<<"The val1 : "<<val1<<endl;
        cout<<"The val2: "<<val2<<endl;
        setVal3(10);
        cout<<"The val3: "<<val3<<endl;
        cout<<"The sum is: "<<val1 + val2 + val3<<endl;
    }
};
int main(){
    Derived d;
    d.base1 ::setVal(10);
    d.base2::setVal(20);
    d.result();
}