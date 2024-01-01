#include<iostream>
using namespace std;

int binarySearch(int arr[], int size,int key){
    int start=0;
    int end=size-1;

    int mid;
    mid=(start+end) / 2;

    while(start<= end){
        if(arr[mid] == key){
            return mid;
        }
        // goto right part
        if(key > arr[mid]){
            start=mid+1;

        }
        else{
            end=mid-1;
        }
        mid = (start+end) / 2;
    }
    return -1;
}

int main(){
    int even[4]={1,2,3,4};
    int odd[5]={1,2,3,4,5};

    int index = binarySearch(odd, 5 , 5);

    cout<<"present at index"<<index<<endl;
}