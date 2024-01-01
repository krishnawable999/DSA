#include<iostream>
#include<limits.h>
using namespace std;

int solve(int n, int x, int y, int z)
{
    if(n == 0)
    return 0;

    int ans1 = solve(n-x, x,y,z);
    int ans2 = solve(n-y, x,y,z); 
    int ans3 = solve(n-z, x,y,z);

    int ans = max(ans1,max(ans2,ans3));

    return ans;

}

int main()
{
    int n = 9;
    int x = 4;
    int y = 3;
    int z = 2;

    int ans = solve(n,x,y,z);

    if(ans < 0){
        ans = 0;
    }
   
    cout<<"Anawer is"<<endl;

}
