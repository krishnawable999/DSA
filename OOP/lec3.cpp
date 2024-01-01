#include <iostream>
using namespace std;

class Animal
{
public:
    void speak()
    {
        cout << "speaking" << endl;
    }
};

class dog : public Animal
{
public:
    // override
    void speak()
    {
        cout << "Barking" << endl;
    }
};

int main()
{
    // dog a;
    // a.speak();
    // dynamic Pointer
    // Animal* a = new Animal();
    // a->speak();

    // dog *d = new dog();
    // d->speak();

    // upcasting
    //  Animal* a = new dog();
    //  a->speak();

    // downcasting//working depends on compiler to compiler
     dog* d = (dog*)new Animal();
     d->speak();
}