#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
            
};
void insertAthead(Node* &head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    temp=head;
}
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main()
{
    Node* node1= new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;
     Node* head=node1;
    print(head);
    insertAthead(head,12);
    print(head);
    insertAthead(head,12);
    print(head);
    return 0;
}