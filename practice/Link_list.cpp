#include<iostream>
using namespace std;


class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};
void insertatHead(Node* head , int d)
{
    Node* temp = new Node(d);

    temp -> next = head;
    head = temp;
}

void print(Node*  &head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout<<temp -> data<<" ";
        temp = temp->next;
    }
}
int main()
{
    Node* newnode1 = new Node(10);
    Node* head = newnode1;
    insertatHead(head , 5);
    insertatHead(head , 6);
    //insertatHead(head , 7);
    print(head);
}