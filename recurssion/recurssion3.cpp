#include<iostream>
using namespace std;

void printSubstring(string str , string op , int i)
{
    if(i >= str.length())
    {
        cout<<op<<endl;
        return;
    }

    //exclude
    printSubstring(str , op ,i+1);

    //include
    op.push_back(str[i]);
    printSubstring(str , op , i+1);
}

int main()
{
    string str = "abc";
    string op = "";
    int i=0;
    printSubstring(str, op ,i);
}