#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:
    int *arr;
    int front;
    int rear;
    int size;

    Queue(int size){
        arr = new int[size];
        this-> size = size;
        front = -1;
        rear  = -1;
    }

    void push(int val){
        //check for size full
        if(rear == size-1){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        //if Queue is empty
        else if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[rear] = val;
        }
        //if quque is not empty
        else{
            rear++;
            arr[rear] = val;
        }
    }

    void pop(){
        //Queue is empty
        if(front == -1 && rear == -1){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        //single element
        else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        //simple case
        else{
            arr[front] = -1;
            front++;
        }
    }
    bool isEmpty(){
        //is Empty
        if(front == -1 && rear == -1){
            return true;
        }
        else{
            return false;
        }
    }
    int getSize(){
            return (rear - front + 1);
    }

    //getFront element
    int getFront(){
        //check for valid index
        if(front == -1){
            cout <<"Invalid Index"<<endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

    void print()
    {
        for(int i=0 ; i<size ; i++){
            cout << arr[i]<<" ";
        } cout << endl;
    }
};

int main(){
        Queue q(3);
        q.push(10);
        q.push(20);
        q.push(30);
        // q.pop();
        // q.pop();
        // q.pop();
        cout <<"Size of Queue is :"<<q.getSize() <<endl;
        q.print();
        cout<<"Queue is empty or not :"<<q.isEmpty()<<endl;
}