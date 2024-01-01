#include<iostream>
using namespace std;

// int stairs(int n)
// {
//     if(n == 0) return 0;
//     if(n == 1) return 1;

//     int ans = stairs(n-1) + stairs(n-2); 
//     return ans;
// }

/*void findmax(int arr[] ,int& maxi, int n , int i)
{
    if(i>=n)
    return;

    if(arr[i] > maxi)
    maxi = arr[i];
  

    return findmax(arr, maxi ,n , i+1);
}*/

void findmin(int arr[], int& mini, int n,int i)
{
    if(i>= n)
    return;

    if(arr[i] < mini)
    {
        mini = arr[i];
    }

  return  findmin(arr, mini, n, i+1);
}

int main()
{
    // int n;
    // cin>>n;

    // int ans = stairs(n);
    // cout << ans<<endl;

    int arr[] = {20 ,30,40,50,60};
    int n=5;

   // int maxi=INT_MIN;

    int mini = INT_MAX;
    int i=0;
   // findmax(arr,maxi,n,i);
    findmin(arr, mini, n,i);
    cout<<mini<<endl;
}