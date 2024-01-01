#include<iostream>
using namespace std;

void update(int **p2)
{
    // p2 = p2+1;
    // *p2 =  *p2 +1;
    **p2 = **p2 +1;
}

int main()
{
    int i=5;
    int *p=&i;
    int **p2 = &p;


    cout<<"Before"<<endl;

    cout<< p <<endl;
    cout<< *p<<endl;
    cout<<**p2<<endl;

    update(p2);
    cout<<"After"<<endl;
    cout<< p <<endl;
    cout<< *p<<endl;
    cout<<**p2<<endl;


}