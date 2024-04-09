#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void sound()
    {
        cout << "Animal is making a sound" << endl;
    }
    // virtual ~Animal(){
    //     cout<<"Animal Dtor"<<endl;
    // }
};

class Dog : public Animal
{
public:
    void sound() override
    {
        cout << "Dog is Barking" << endl;
    }

    ~Dog()
    {
        cout << "Dog Dtor" << endl;
    }
};

class Cat : public Animal
{
public:
    void sound() override
    {
        cout << "Cat Meow Meow" << endl;
    }

    ~Cat()
    {
        cout << "Cat Dtor" << endl;
    }
};

class Parrot : public Animal
{
public:
    void sound() override
    {
        cout << "Parrot Speaking" << endl;
    }

    ~Parrot()
    {
        cout << "Parrot Dtor" << endl;
    }
};

void sound(Animal *animal)
{
    // here this line is polymorphic
    animal->sound(); // this line is behaving as per the reqired object allocated to it.
}

int main()
{
    // Animal *animal = new Dog();
    // //    sound(animal);
    // animal = new Dog();
    // sound(animal);

    // animal = new Parrot();
    // sound(animal);
    // delete animal;
    Dog * animal = new Animal();
    sound(animal);
}