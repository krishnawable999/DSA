#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};


class queue{

    Node* head;
    Node* front;
    int qsize;
    public:
    queue(){
        head = NULL;
        qsize=0;
        front = NULL;
    }

    void push(int data){
        Node * temp = new Node();
        temp->data = data;
        temp->next = head;
        if(head == NULL){
            head = front = temp;
        }
        head = temp;
        qsize++;
    }

    void pop(){
        if(head == NULL){
            cout<<"Queue Underflow"<<endl;
            return;
        }

        Node * temp = head;
        while(temp->next != front){
            temp = temp->next;
        }
        temp->next = NULL;
        Node* nodetoDelete = front;
        front = temp;
        delete nodetoDelete;
        qsize--;
    }

    int frontVal(){
        if(head == NULL){
            return -1;
        }
        return front->data;
    }

    int size(){
        return qsize;
    }



};

int main(){
    queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout<<q.size()<<endl;
    cout<<q.frontVal()<<endl;
    q.pop();
    q.pop();
    q.pop();
    cout<<q.frontVal()<<endl;
    cout<<q.size()<<endl;
}