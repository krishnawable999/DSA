#include<iostream>
using namespace std;


int main(){
    int a = 16;
    int *ptr = &a;
    cout<<*(ptr)<<endl;

    float b = 60.77;
    float *p = &b;
    cout<<*p<<endl;

    int *arr = new int[3];
    arr[0] = 10;
    // arr[1] = 20;
    *(arr+1) = 20;
    arr[2] = 30;
    // delete []arr; to delete the allocation inside the heap memory
    cout<<"Value at arr[0]: "<<arr[0]<<endl;
    cout<<"Value at arr[1]: "<<arr[1]<<endl;
    cout<<"Value at arr[2]: "<<arr[2]<<endl;
}