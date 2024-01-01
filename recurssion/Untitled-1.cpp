#include<iostream>
using namespace std;



int binarySearch(int arr[] , int left , int right, int target)
{ 
    int mid = (left + right)/ 2;
    
    if(left > right)
    {
        return -1;
        
    }

    if(arr[mid] == target)
    return mid;
    
    if(target < arr[mid])
    {
        right = mid -1;
        return binarySearch(arr, left,right,target);
    }
    else
        left = mid +1;
        return binarySearch(arr, left,right,target);
    
    
}

int main(){
    
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int left = 0;
    int right =n-1;
    int target;
  
    cin>>target;


    int ans = binarySearch(arr, left, target, target);

    
    cout<<ans;




    return 0;
}