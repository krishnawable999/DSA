#include<iostream>
using namespace std;

class Complex{
    int a,b;
    public:
    void setData(int a, int b){
        this->a = a;
        this->b = b;
    }

    void getData(){
        cout<<"Real part "<<a<<endl;
        cout<<"Imaginary part "<<b<<"i"<<endl;
    }
};

int main(){
    // Complex c;
    // c.setData(1,12);
    // c.getData();
    // Complex *ptr = &c;
    // (*ptr).setData(12,21);
    // (*ptr).getData();

    // Complex *ptr = new Complex;
    // // (*ptr).setData(10,20); Exactly same as
    // ptr->setData(10,25);
    // (*ptr).getData();

    // Array of Objects.
    // Complex *arr = new Complex[2];
    // arr[0].setData(44,55);
    // arr[0].getData();

    // arr[1].setData(49,34);
    // arr[1].getData();
        int size = 3;
        Complex *arr = new Complex[size];
        Complex *arrTemp = arr;

        for(int i=0 ; i<size ; i++){
            int a,b;
            cout<<"Enter a : && b: "<<endl;
            cin>>a>>b;
            arr->setData(a,b);
            arr++;
        }

        for(int i=0 ; i<size ; i++){
            arrTemp->getData();
            arrTemp++;
        }
}