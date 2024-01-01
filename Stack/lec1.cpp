#include <iostream>
using namespace std;

/*class Stack
{
public:
    // variables
    int top;
    int size;
    //int data;
    int *arr;

    // constructor
    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
    }
    // functions
    int sttop()
    {
        if(top == -1){
            cout<<"No element in the stack"<<endl;
        }
        else{
            return arr[top];
        }
    }
    void push(int data)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop()
    {
        if(top == -1){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            top--;
        }
    }
    bool isEmpty()
    {
        if(top == -1){
            return true;
        }
        else return false;
    }
    int stsize()
    {
        return top+1;
    }
};*/

class Stack{
    public:
    int size;
    int *arr;
    int top1;
    int top2;

    Stack(int size){
        this -> size = size;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }

    void push1(int data){
        if(top2 - top1 == 1){
            cout<<"Stack1 Overflow"<<endl;
        }
        else{
            top1++;
            arr[top1] = data;
        }
    }
    void push2(int data){
        if(top2 - top1 ==1 ){
            cout<<"Stack2 overflow"<<endl;
        }
        else{
            top2--;
            arr[top2] = data;
        }
    }
    void pop1(){
        if(top1==-1){
            cout<<"Stack1 Underflow"<<endl;
        }
        else{
            top1--;
        }

    }
    void pop2(){
        if(top2 == size){
            cout<<"Stack2 Underflow"<<endl;
        }
        else{
            top2++;
        }
    }

};

int main(){
    Stack st(10);
    st.push1(10);
    st.push1(20);
    st.push1(30);
    st.push2(40);
    st.push2(50);
    st.push2(60);
    st.push1(10);
    st.push1(10);
    st.push1(10);
    st.push1(10);
    st.push1(10);
    st.push2(10);


    // while(!st.isEmpty()){
    //     cout<<st.sttop()<<" ";
    //     st.pop();
    // }
}