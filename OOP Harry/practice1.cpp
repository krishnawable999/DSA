#include <iostream>
using namespace std;

class A
{
    protected:
    int d = 10;
public:
    int a, b;
    A(int a)
    {
        this->a = a;
        cout << "inside A" << endl;
    }
    A() {}
};

class B : protected A
{
    // protected:

public:
    int d = 10;
    B(int bb)
    {
        b = bb;
        cout << "inside B" << endl;
    }

    void disp()
    {
        cout << b << endl;
        cout<<"Printing protected "<<d<<endl;
    }
};

int main()
{
    // cout << "Hello world!" << endl;
    A a1(5);
    B b1(10);
    b1.disp();
    cout << b1.d << endl;
    return 0;
}