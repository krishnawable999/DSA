#include<iostream>
using namespace std;

void sol(int arr[], int n)
{
    for(int i=0 ; i < n-1 ;i++){
        int temp = arr[i];
        int j=i-1;

        for(; j>=0 ; j--)
        {
            if(arr[j] > temp){
                arr[j+1] = arr[i];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }

    for(int i=0 ;i < n ;i++){
        cout<<arr[i];
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i < n ; i++)
    {
        cin>>arr[i];
    }
    sol(arr, n);
}