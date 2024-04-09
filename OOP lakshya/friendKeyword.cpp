#include<iostream>
using namespace std;

class A{
    int x;
    public:
    A(int val):x(val){}

    int getX() const {
        return x;
    }

    void setX(int val){
        x = val;
    }

    friend class B;
    friend void print(const A&);
};

class B{
    public:
    void print(const A&a){
        // cout<<a.getX()<<endl;
        cout<<a.x<<endl; // this is possible due to friend keyword, you can access private members of a friend class also
    }
};

void print(const A&a){
    cout<<a.x<<endl;
    cout<<a.getX()<<endl;
}

int main(){
    A a(20);
    print(a);
    // B b;
    // b.print(a);
}