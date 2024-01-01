#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;

    //constructor
    Node(int d){
        this->data=d;
        this->next=NULL;
    }
    ~Node(){
        int val=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }

        cout<<"Deleted Value is"<<val<<endl;

    }
};
void insertNode(Node * &tail,int element, int d)
{
    if(tail==NULL){
        Node* newnode=new Node(d);
        tail=newnode;
        newnode->next=newnode;
    }
    else{
        Node * curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        Node* temp=new Node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}
void print(Node * tail){
    Node* temp=tail;
    do{
        cout<<temp->data;
        temp=temp->next;
    }while(tail!=temp);

}
bool isCirc(Node* head){
    Node* temp=head->next;

    if(head==NULL){
        return false;
    }
    while(temp!=NULL && temp != head){
        temp=temp->next;
    }
    if(temp==NULL){
        return false;
    }
    else
    return true;
}
int main()
{
    Node* tail=NULL;
    insertNode(tail,5,1);
    print(tail);
    insertNode(tail,2,10);
    print(tail);

    if(isCirc(tail)){
cout<<"List is circ"<<endl;
    }
    else
    cout<<"Not circ"<<endl;

}