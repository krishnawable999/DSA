#include<iostream>
using namespace std;

void reverse(int n)
{
    if(n==0) return; //base case is must
    cout<<n<<" ";
   return  reverse(n-1);
}
int main()
{
    int n;
    cin>>n;
    reverse(n);
}