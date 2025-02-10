#include<iostream>
using namespace std;

void merge(int *arr, int s, int e){
    int mid = (s+e)/2;
    int lenLeft = mid-s+1;
    int lenright = e-mid;

    int *left = new int[lenLeft];
    int *right = new int[lenright];

    int k = s;

    // copying elements from the left array
    for(int i=0 ; i<lenLeft ; i++){
        left[i] = arr[k];
        k++;
    }

    // copying elements form the right array
    k = mid+1;
    for(int i=0 ; i<lenright ; i++){
        right[i] = arr[k];
        k++;
    }

    int leftIndex=0;
    int rightIndex=0;
    int mainIndex = s;


    // actual logic of merge sorting array
    while(leftIndex < lenLeft && rightIndex < lenright){
        if(left[leftIndex] < right[rightIndex]){
            arr[mainIndex] = left[leftIndex];
            // mainIndex++;
            leftIndex++;
        }
        else{
            arr[mainIndex] = right[rightIndex];
            // mainIndex++;
            rightIndex++;
        }
        mainIndex++;
    }

    // 2 extra cases in case if one of the array is over and another array is left
    // 1 when rightarray is remainin and left is over
    while(rightIndex < lenright){
            arr[mainIndex] = right[rightIndex];
            mainIndex++;
            rightIndex++;
    }

    // 2 when left is remaining and right is over
    while(leftIndex < lenLeft){
            arr[mainIndex] = left[leftIndex];
            mainIndex++;
            leftIndex++;
    }

    // deallocate the dynamic allocation
    delete [] left;
    delete [] right;
}


void mergeSort(int *arr, int s, int e){
    if(s >= e) return;

    int mid = (s+e)/2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);

    // call to merge the sorted array;
    merge(arr, s, e);
}

int main(){
    int n = 6;
    int arr[n] = {2,1,9,7,4,6};

    mergeSort(arr, 0, n-1);

    cout<<"Araray after sorting"<<endl;

    for(int i=0;  i<n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}