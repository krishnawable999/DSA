#include<iostream>
using namespace std;

int main(){
    int n=7;
    int arr[n] = {66, 11, 22, 27, 1,2,3};

    for(int i=0 ; i<n-1 ; i++){
        int minIndex=i;
        for(int j=i+1 ; j<n ; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }

    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
}