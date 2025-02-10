#include<iostream>
using namespace std;

int count=0;
class Num{
    public:
    Num(){
        count++;
        cout<<"Ctor Called for object"<<count<<endl;
    }

    ~Num(){
        count--;
        cout<<"Dtor called for block"<<count<<endl;
    }
};

int main(){

    Num n1;
    {
        cout<<"Entering main Block"<<endl;
        Num n2,n3;
        cout<<"Exit from main block"<<endl;
    }

    cout<<"Out of main block"<<endl;

}