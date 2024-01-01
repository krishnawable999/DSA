#include<iostream>
#include<string>

bool palindrome(string str)
{
    int len = str.length();
    int s=0;
    int e=len-1;

    while(s < e)
    {
        if(str[s++] != str[e--]){
            return 0;
        }
        else{
            s++;
            e--;
            return 1;
        }
    }
}
using namespace std;
int main()
{
    string str;
    cout<<"Enter a string"<<endl;
    cin>>str;
    cout<<"String is palindrome or Not:  "<< palindrome(str);
}
    //check for palindrome
   