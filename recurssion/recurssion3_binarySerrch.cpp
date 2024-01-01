#include<iostream>
using namespace std;

int binarySearch(int arr[],int s,int e ,int target)
{
   
   
    int mid = (s+e)/2;
    if(s > e)
        return -1;

    if(arr[mid] == target)
    {
        return mid;
    }
    if(arr[mid] < target)
    {
        e=mid-1;
      return  binarySearch(arr,s,e,target);
    }
    else if(arr[mid] > target)
    {
        s=mid+1;
       return binarySearch(arr,s,e,target);   
    }
}

int main()
{
    int arr[]={10,11,55,56,65,78,87};
    int n=7;
    int s=0;
    int e=n-1;
    //int i=0;
    //int s=0;
    int target = 65;
    //int e=n-1;
   // int mid=(s+e)/2;
   
    
    int ans =binarySearch(arr, s,e,target);
    cout<<"Ans is:"<<ans<<endl;
}