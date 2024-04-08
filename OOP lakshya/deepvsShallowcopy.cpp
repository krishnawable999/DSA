#include <iostream>
// #include <cstdlib>
using namespace std;

class abc
{
public:
    int x;
    int *y;

    abc(int _x, int _y) : x(_x), y(new int(_y)) {}
    //  Compiler introduces by default dumb constructor
    // cpp by default introduces shallow copy
    // abc(const abc&obj){
    //     x = obj.x;
    //     y = obj.y;
    // }


    //  Deep copy
    // abc(const abc&obj){
    //     x = obj.x;
    //     y = new int(*obj.y);
    // }


    void print() const
    {
        printf("X: %d \nY: %p\n Y: %d", x, y, *y);
    }

    ~abc(){
        delete y;
    }
};

int main()
{
    // abc a(4, 5);
    // cout << "Printing a" << endl;
    // a.print();
    // cout << endl;
    // cout << "Printing b" << endl;

    // abc b(a);
    // b.print();
    // *b.y = 20;
    // cout<<"Printing y"<<endl;
    // b.print();
    // cout<<endl;
    // cout<<"Printing a"<<endl;
    // a.print();
    
    abc *a = new abc(4,5);
    abc b = *a;
    delete a;
    b.print();
    return 0;
}