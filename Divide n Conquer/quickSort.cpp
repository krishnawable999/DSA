#include<iostream>
using namespace std;
int partition(int arr[],int s, int e)
{
    
    int pivotIndex = s;
    int pivotelement = arr[s];
    int count = 0;
    for(int i=s+1 ; i <= e ; i++){
        if(arr[i] <= pivotelement){
            count++;
        }
    }
    int rightIndex = s + count;
    swap(arr[pivotIndex] , arr[rightIndex]);
    pivotIndex = rightIndex;

    int  i = s;
    int j = e;

    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivotelement){
            i++;
        }
        while(arr[j] >= pivotelement){
            j--;
        }


        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i], arr[j]);
        }

    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e){

    //base case
    if(s >= e){
        return;
    }

    int p = partition(arr,s,e);

    //left half

    quickSort(arr,s,p-1);

    //right half

    quickSort(arr,p+1,e);

}

int main(){
    int arr[] = {5,4,12,8,7,9};

    int n = 6;
    int s = 0;
    int e = n-1;

    quickSort(arr,s,e);

    for(int i=0 ;i < n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}