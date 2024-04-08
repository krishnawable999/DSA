#include <iostream>
#include <string>
using namespace std;

// int add(int a, int b){
//     return a+b;
// }

// double add(double a, double b){
//     return a+b;
// }

// int add(int a, int b, int c){
//     return a+b+c;
// }

//  Function Overloading

class Vector
{
private:
    int x, y, z;

public:
    // Vector(int x, int y){
    //     this->x = x;
    //     this->y = y;
    // }

    // Init list
    Vector(int x, int y, int z) : x(x), y(y), z(z) {}

    // operator overloading
    Vector& operator+(const Vector &src)
    {
        // this would be point to v1
        // src would be ref to v2
        this->x = this->x + src.x;
        this->y = this->y + src.y;
        this->z = this->z + src.z;
        return *this;
    }

    // void operator++()
    // {
    //     this->x++;
    //     this->y++;
    // }

    void display()
    {
        cout << "X: " << x << " "<< "y: " << y <<" "<< "z: " << z << endl;
    }
};

int main()
{
    // cout<<add(2,6)<<endl;
    // cout<<add(5.6,8.9)<<endl;
    // cout<<add(4,6,7)<<endl;

    Vector v1(2, 5, 7);
    Vector v2(5, 6, 7);
    Vector v3(4, 5, 6);
    (v1 + v2) + v3;
    // v1.display();

    // ++v1;
    v1.display();
}