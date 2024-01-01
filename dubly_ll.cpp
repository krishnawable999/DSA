#include<iostream>
using namespace std;
#include<map>
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    //constructor
    Node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
    ~Node(){
        int val=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Deleted value is"<<val<<endl;
    }

};
void print(Node* &head){
    Node* temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int getlen(Node* head){
    Node* temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
       
    }
    return len;
}
void insertAthead(Node* &head, int d)
{
    Node* temp=new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void insertAttail(Node* &tail, int d)
{
    Node* temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
void insertAtpos(Node* &tail,Node* &head, int pos,int d)
{
    if(pos==1)
    {
        insertAthead(head, d);

    }
    Node* temp=head;
    int cnt=1;
    while(cnt!=pos-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertAttail(tail, d);
    }
    Node* nodetoinsert=new Node(d);
    nodetoinsert->next=temp->next;
    temp->next->prev=nodetoinsert;
    temp->next=nodetoinsert;
    nodetoinsert->prev=temp;
}
void deletenode(int pos,Node* &head)
{
    if(pos==1){
    Node* temp=head;
    temp->next->prev=NULL;
    head=temp->next;
    temp->next=NULL;
    }
    else{
        Node* curr=head;
        Node*prev=NULL;

        int cnt=1;
        while(cnt<pos)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
bool detectLoop(Node* head){
    map<Node* , bool> visited;
    Node* temp=head;

    while(temp!=NULL){
        if(visited[temp]==true){
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;

}
int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
   // print(head);
    insertAthead(head,12);
    //print(head);
    insertAthead(head,15);
   // print(head);
    insertAthead(head,22);
    // print(head);
    insertAthead(head,25);
    // print(head);
    insertAthead(head,23);
    print(head);
   // tail->next=head->next;
    cout<<"head "<<head->data<<endl;
    cout<<"Temp "<<tail->data<<endl;

    if(detectLoop(head)){
        cout<<"LOOP detected"<<endl;
    }
    else{
        cout<<"NO LOOP"<<endl;
    }
   // insertAtpos(tail,head,4,22);
    // print(head);
    // deletenode(5,head);
    // print(head);



}