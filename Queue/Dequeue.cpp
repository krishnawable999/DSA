#include<iostream>
using namespace std;

class deque{
    public:
    int *arr;
    int front;
    int rear;
    int size;

    deque(int size){
        arr = new int[size];
        this -> size = size;
        front = -1;
        rear  = -1;
    }

    void pushBack(int val){
        //Queue is empty
        if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[rear] = val;
        }
        //single element
        else if(front == rear){
            rear++;
            arr[rear] = val;
        }
        //Overflow condition
        else if((front == 0 && rear == size-1) || (rear == front-1)){
            cout<<"Circular Queue Overflow"<<endl;
            return;
        }
        //circular conditiion
        else if(rear == size-1 && front !=0){
            rear = 0;
            arr[rear] = val;
        }
        //normal condition
        else{
            rear++;
            arr[rear] = val;
        }

    }
    void pushFront(int val){
        //overflow condition
        if((front == 0 && rear == size-1 ) || (rear == front - 1)){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        //empty queue
        else if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[front] = val;
        }
        else if(front == 0 && rear != size-1){
            
            front = size-1;
            arr[front] = val;
        }
        //normal case
        else{
            front--;
            arr[front] = val;
        }
    }
    void popback(){
        //underflow condition
        if(front == -1 && rear == -1){
            cout<<"Underflow!!!"<<endl;
            return;
        }
        //single element
        else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if(rear == 0){
            arr[rear] = -1;
            rear = size - 1;
        }
        //normal case
        else{
            arr[rear] = -1;
            rear--;
        }
    }
    void popfront(){
        //underflow condition
        if(front == -1 && rear == -1){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        //single element
        else if(front == rear){
            front = -1;
            rear = -1;
            arr[front] = -1;
            return;
        }
        //Circular condition
        else if(front == size-1){
            arr[front] = -1;
            front = 0;
        }
        //normal condition
        else{
            arr[front] = -1;
            front++;
        }
    }

    void print(){
        for(int i=0 ; i<size ; i++){
            cout<<arr[i]<<" "<<endl;
        }
    }
};


int main(){
    deque dq(5);
    // dq.pushBack(10);
    // dq.print();
    // dq.popback();
    // dq.print();
    dq.popback();
}