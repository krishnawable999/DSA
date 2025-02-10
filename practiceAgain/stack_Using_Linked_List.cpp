#include<iostream>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node* next;
};


class mystack{
    public:
    Node* head;
    int stackSize=0;
    mystack(){
        head = NULL;
        stackSize=0;
    }

    void push(int val){
        Node* temp = new Node();
        temp->data = val;
        temp->next = head;
        head = temp;
        stackSize++;
    }

    void pop(){
        if(head == NULL){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        stackSize--;
        delete temp;
    }

    int size(){
        return stackSize;
    }

    int top(){
        if(head == NULL){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return head->data;
    }

};

int main(){
    mystack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout<<st.top()<<endl;
    // st.pop();
    // st.pop();
    // st.pop();
    // st.pop();
    // st.pop();
    cout<<st.top()<<endl;
    cout<<st.size()<<endl;
}