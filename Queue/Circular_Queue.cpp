#include<iostream>

using namespace std;

class Cqueue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Cqueue(int size){
        arr = new int[size];
        this -> size = size;
        front = -1;
        rear = -1;
    }

    void push(int val){
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
    void pop(){
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
        cout<<"Front :" <<front <<" Rear :" <<rear<<endl; 
        for(int i=0 ; i<size ; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};




int main(){
    Cqueue cq(5);
    cq.push(10);
    cq.push(20);
    cq.push(30);
    cq.push(40);
    cq.push(50);
    //cq.push(60);
    //cq.pop();
    cq.pop();
    cq.pop();
    // cq.pop();
    // cq.pop();
    // cq.pop();
    // cq.print();
    // cq.pop();
    // cq.pop();
    // cq.print();
    cq.push(100);
    cq.push(200);
    cq.push(300);
    cq.print();

}