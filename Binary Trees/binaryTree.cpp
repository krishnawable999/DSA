#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->left=NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    int data;
    cout<<"Enter data: "<<endl;
    cin>>data;

    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data to insert to the left of:" <<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data to insert to the right of: "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrederTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* front = q.front();
        q.pop();

        if(front == NULL){
            if(!q.empty()){
                q.push(NULL);
                cout<<endl;
            }
        }else{
            cout<<front->data<<" ";
            
            if(front->left != NULL){
                q.push(front->left);
            }

            if(front->right != NULL){
                q.push(front->right);
            }
        }
    }
}


void buildFromlevelorder(node* &root){
    queue<node*> q;
    cout<<"Enter the root of tree: "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter data to insert to left of: "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter data to insert to right of: "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata != -1){
            temp->right= new node(rightdata);
            q.push(temp->right);
        }
    }
}

int main(){
    node* root = NULL;
    // root = buildTree(root);
    // levelOrederTraversal(root);
    buildFromlevelorder(root);
    levelOrederTraversal(root);
}