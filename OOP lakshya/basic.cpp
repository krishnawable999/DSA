#include<iostream>
using namespace std;


int main(){
    // int *a = new int;
    // *a = 2;
    // cout<<*a<<endl;
    // delete a;
    // int b = 5;
    // a = &b;
    // cout<<*a<<endl;

    // 2. const with pointers
    // const int *a = new int(2); // const value, non-const pointer
    // cout<< *a<<endl;
    // //  *a = 20; -> value cannot be re-assign
    // int b = 20;
    // a = &b;
    // cout<<*a<<endl; // Pointer can be re-assigned/

    // // 3. const pointer, non-const data
    // int *const a = new int(2);
    // cout<<*a<<endl;
    // *a = 20;
    // cout<<*a<<endl;
    // int b = 50;
    // // a = &b; -> we cannot modify the poiner bcz it is const.
    // // cout<<*a<<endl;

    // 4. Const pointer const data

    const int *const a = new int(10);
    cout<<*a<<endl;
    int b = 10;
    a = &b;
    cout<<*a;


}