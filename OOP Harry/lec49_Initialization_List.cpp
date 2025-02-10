#include<iostream>
using namespace std;

class Test{
    int a;
    int b;
    public:
    // Test(int i, int j): a(i), b(j)
    // Test(int i, int j): a(i), b(j+a)
    // Test(int i, int j): b(j),a(b+i) --> This is red flag--> This will not work bcz of the dec;aration, we have declered int a before and int b later;
    Test(int i, int j): a(i), b(j)
    {
        cout<<"Ctor called"<<endl;
        cout<<"value of a: "<<a<<endl;
        cout<<"value of b: "<<b<<endl;
    }
};

int main(){
    Test t(11,12);
}