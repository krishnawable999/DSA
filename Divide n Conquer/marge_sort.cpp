#include<iostream>
using namespace std;

void merge(int * arr,int s,int e){
    int mid = (s+e) / 2;
    int l1 = mid - s +1;
    int* left = new int[l1];
    int l2 = e - mid;
    int * right = new int[l2];

    int leftindex = 0;
    int rightindex = 0;
    int arrindex = s;

   
    int k = s;
    for(int i = 0 ; i < l1 ; i++)
    {
        left[i] = arr[k];
        k++;

    }
    k = mid+1;
    for(int i = 0 ; i < l2 ; i++)
    {
        right[i] = arr[k];
        k++;

    }

    while(leftindex < l1 && rightindex < l2){
        if(left[leftindex++] < right[rightindex++]){
            arr[arrindex++] = left[leftindex++] ;
        }
        else{
            arr[arrindex++] = right[rightindex++];
        }
    }
//left arrey becomes end
    while(leftindex < l1){
        arr[arrindex++] = left[leftindex++];
    }
//right array ends
    while(rightindex < l2){
        arr[arrindex++] = right[rightindex++];
    }
}

void mergeSort(int* arr ,int s, int e){
    

    //base case
    if(s >= e)
    return;

    int mid = (s+e) / 2;
    //1st case
    mergeSort(arr,s,mid);
    //2nd case
    mergeSort(arr,mid+1,e);


    merge(arr,s,e);
}

int main(){

    int arr[] = {5,4,3,2,1};

    int n=5;

    int s = 0;
    int e = n-1;

    mergeSort(arr,s,e);

    for(int i =0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}