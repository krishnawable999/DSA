#include<iostream>
using namespace std;

class Heap{
    public:
    int capacity;
    int size;
    int *arr;

    Heap(int capacity){
        this->size = 0;
        this->capacity = capacity;
        this->arr = new int[capacity];
    }

    void insert(int val){
        // Overflow Condition 
        if(size == capacity){
            cout<<"Heap Overflow"<<endl;
            return;
        }
        size++;
        int index = size;
        arr[index] = val;
        while(size > 1){
            int parentIndex = size/2;
            if(arr[index] > arr[parentIndex]){
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }else{
                break;
            }
        }
    }

    void printHeap(){
        for(int i=1; i<=size ; i++){
            cout<<arr[i] <<" ";
        }
        cout<<endl;
    }

    int delet(){
        // Storing the answer
        int ans = arr[1];
        // Repalcement
        arr[1] = arr[size];
        // Decreasing the size
        size--;
        int index = 1;
        while(index < size){
            int leftIndex = 2*index;
            int rightIndex = 2*index + 1;

            // Finding the largest;
            int largestIndex = index;

            // 
            if(leftIndex <= size && arr[largestIndex] < arr[leftIndex]){
                largestIndex = leftIndex;
            }

            if(rightIndex <= size && arr[largestIndex] < arr[rightIndex]){
                largestIndex = rightIndex;
            }

            // no change
            if(index == largestIndex){
                break;
            }
            else{
                swap(arr[index], arr[largestIndex]);
                largestIndex = index;
            }
        }

        return ans;
    }

    
};

void heapify(int *arr, int n , int index){
        int leftIndex = 2*index;
        int rightIndex = 2*index + 1;
        int largestIndex = index;

        // teno main se max find karo

        if(leftIndex < n && arr[leftIndex] > arr[largestIndex]){
            largestIndex = leftIndex;
        }
        if(rightIndex < n && arr[rightIndex] > arr[largestIndex]){
            largestIndex = rightIndex;
        }

        if(index != largestIndex){
            swap(arr[index], arr[largestIndex]);
            index = largestIndex;
            heapify(arr,n,index);
        }
    }

    void buildHeap(int *arr, int n){
        for(int i=n/2 ; i>0 ; i--){
            heapify(arr,n,i);
        }
    }

    void heapSort(int *arr, int n){
        while (n != 1)
        {
            swap(arr[1],arr[n]);
            n--;
            heapify(arr,n,1);
        }
        
    }
int main(){

    int arr[] = {-1,5,10,15,20,25,12};
    buildHeap(arr,6);
    cout<<"Printing the heap"<<endl;
    for(int i=1 ; i<=6 ; i++){
        cout<<arr[i] <<" ";
    }
    cout << endl;

    heapSort(arr,6);
    cout<<"Printing the heapSort"<<endl;
    for(int i=1 ; i<=6 ; i++){
        cout<<arr[i] <<" ";
    }
    cout<<endl;
    // Heap h(10);

    // h.insert(10);
    // h.insert(20);
    // h.insert(30);
    // h.insert(5);
    // h.insert(6);
    // h.insert(8);

    // cout<<"Printing the heap"<<endl;
    // h.printHeap();

    // int ans = h.delet();
    // cout<<"Answer: "<<ans<<endl;
    // h.printHeap();

}