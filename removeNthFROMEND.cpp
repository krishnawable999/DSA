#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
     Node(int d){
        this->data=d;
        this->next=NULL;
       
    }

};
void insertHead( Node* &head, int d){
    Node* temp=new Node(d);
    temp -> next= head;
    head = temp;
}
void insertEnd(Node* &tail, int d){
    Node* temp= new Node(d);
    tail -> next= temp;
    tail=temp;
    // temp->next=NULL;
}

void print(Node* &head){
    Node* temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
// void reverse(Node* head, Node* curr, Node* prev){
//     if(curr == NULL){
//         head=prev;
//         return ;
//     }

//     Node* forward= curr -> next;
//     reverse(head, curr, prev);
//     curr -> next = prev;
// }

// Node* reversell(Node* head){
//     Node* curr = head;
//     Node* prev = NULL;
//     reverse(head, curr, prev);
//     return head;
// }

Node* reverse(Node* head){
    if(head == NULL || head -> next==NULL){
        return head;
    }
    Node* prev= NULL;
    Node* curr=head;
    Node* forward=NULL;
    while(curr != NULL){
        forward= curr -> next;
        curr -> next = prev;
        prev= curr;
        curr = forward;
    }
    return prev;

}

int main(){
    Node* newnode1=new Node(10);
   Node* head=newnode1;
    Node* tail=newnode1;
    // insertHead(head, 9);
    // print(head);
    insertEnd(tail , 12);
    print(head);
    insertEnd(tail , 13);
    print(head);
    insertEnd(tail , 14);
    print(head);
    // reverse(head);
    // print(head);

}