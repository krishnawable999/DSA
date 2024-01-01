#include<iostream>
using namespace std;

int main()
{
    int ch = 5;
    int * chr = &ch;

    chr=chr+1;
    cout<<ch<<" "<<*chr;
}