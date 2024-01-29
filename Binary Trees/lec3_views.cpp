#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }

};

Node *createTree(){
    int data;
    cout<<"Enter Value to Be insertd in the Tree"<<endl;
    cin>>data;

    if(data == -1){
        return NULL;
    }
    Node *root = new Node(data);
    cout <<"Node"<<root->data<<endl;

    cout<<"Node left->"<<root->data<<endl;
    root -> left = createTree();
    cout<<"Right Node"<<root->data<<endl;
    root -> right = createTree();

    return root;
}

void preOreder(Node *root){
    if(root == NULL){
        return ;
    }
    cout<<root->data<<" ";

    preOreder(root -> left);
    preOreder(root -> right);
}

void inOreder(Node *root){
    if(root == NULL){
        return ;
    }
    

    inOreder(root -> left);
    cout<<root->data<<" ";
    inOreder(root -> right);
}

void postOreder(Node *root){
    if(root == NULL){
        return ;
    }

    postOreder(root -> left);
    postOreder(root -> right);
    cout<<root->data<<" ";
}

void levelOrderTraversal(Node *root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
         else{
            cout<<temp->data<<" ";
            if(temp->left != NULL){
                q.push(temp -> left);
            }
            if(temp -> right != NULL){
                q.push(temp->right);
            }
        }
    }
}

void printleftView(Node *root, int level, vector<int> &leftview){
    if(root == NULL){
        return;
    }

    if(level == leftview.size()){
        leftview.push_back(root->data);
    }

    printleftView(root -> left, level+1, leftview);
    printleftView(root -> right, level+1, leftview);
}

void printrightView(Node *root, int level, vector<int> &rightview){
    if(root == NULL){
        return;
    }

    if(level == rightview.size()){
        rightview.push_back(root->data);
    }

    printrightView(root -> right, level+1, rightview);
    printrightView(root -> left, level+1, rightview);
}



void printLeftboundry(Node *root){
    if(root  == NULL){
        return;
    }
    if(root -> left == NULL && root -> right == NULL){
        return;
    }

    cout<<root -> data<<" ";
    if(root -> left != NULL){
        printLeftboundry(root -> left);
    }else{
        printLeftboundry(root -> right);
    }
}

void printLeafBoundry(Node *root){
    if(root == NULL){
        return;
    }
    if(root -> left == NULL && root -> right == NULL){
        cout<<root -> data<<" ";
    }

    printLeafBoundry(root -> left);
    printLeafBoundry(root -> right);
}

void printRightboundry(Node *root){
    if(root == NULL){
        return;
    }
    if(root -> left == NULL && root -> right == NULL){
        return;
    }

    if(root -> right != NULL){
        printRightboundry(root -> right);
    }
    else{
        printRightboundry(root -> left);
    }
    cout<<root -> data <<" ";
}

void printBoundryTraversal(Node *root){
    if(root == NULL){
        return;
    }
    printLeftboundry(root);
    printLeafBoundry(root);
    if(root -> right != NULL){
        printRightboundry(root -> right);
    }else{
        printRightboundry(root);
    }
}


int main(){
    Node *root = createTree();
    cout<<root->data<<" ";
    // preOreder(root);
    // cout<<endl;
    // cout<<endl;
    // inOreder(root);
    // cout<<endl;
    // cout<<endl;
    // postOreder(root);
    //10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
    levelOrderTraversal(root);
    // vector<int> leftview;
    // vector<int> rightview;
    // printleftView(root,0,leftview);
    // cout<<"Printing left View"<<endl;
    // for(int i=0 ; i<leftview.size() ; i++){
    //     cout<<leftview[i]<<" "; 
    // }
    // cout<<endl;
    // printrightView(root,0,rightview);
    // cout<<"Printing Right View"<<endl;
    // for(int i=0 ; i<rightview.size() ; i++){
    //     cout<<rightview[i]<<" "; 
    // }

    //***** Printting Boundry Traversal
    cout<<"Printing Boundry Traverdsal"<<endl;
    printBoundryTraversal(root);
}