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

Node *insertintoBST(Node *root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        root -> right = insertintoBST(root->right,data);
    }
    else{
       root -> left = insertintoBST(root->left,data);
    }
    return root;
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
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
}

void createBST(Node *&root){
    cout<<"Enter Values to be inserted :"<<endl;
    int data;
    cin>>data;

    while(data != -1){
        root = insertintoBST(root,data);
        cout<<"Enter Data: ";
        cin>>data;
    }
}

void preOrder(Node *root){
    if(root == nullptr){
        return;
    }

    cout<<root->data<<" ";
    preOrder(root -> left);
    preOrder(root -> right);
}

/*Note: The inorder of BST is always a SORTED*/
void inOrder(Node *root){
    if(root == nullptr){
        return;
    }

    
    inOrder(root -> left);
    cout<<root->data<<" ";
    inOrder(root -> right);
}

void postOrder(Node *root){
    if(root == nullptr){
        return;
    }

    
    postOrder(root -> left);
    postOrder(root -> right);
    cout<<root->data<<" ";
}


void minValue(Node *root){
    if(root == NULL){
        cout<<"NO MIN VALUE"<<endl;
        return;
    }
    Node *temp = root;
    int mini = -1;
    while(temp->left != NULL){
        temp = temp -> left;
        mini = temp -> data;
    }

    cout<<"Minimum Value is: "<<mini<<endl;
}

Node* maxValue(Node *root){
    if(root == NULL){
        cout<<"NO MAX VALUE"<<endl;
        return NULL;
    }

    Node *temp = root;
    // int maxi = -1;
    while(temp -> right != NULL){
        temp = temp -> right;
        // maxi = temp -> data;
    }

    return temp;

}

bool searchBST(Node *root, int target){
    if(root == NULL){
        return 0;
    }

    if(root->data == target){
        return true;
    }
    bool leftans = false;
    bool rightans = false;
    if(root->data > target){
       leftans = searchBST(root->left,target);
    }else{
       rightans =  searchBST(root->right, target);
    }
    return leftans || rightans;
}

//Delete from BST
Node *deleteBST(Node *root, int target){
    if(root == NULL){
        return NULL;
    }

    if(root -> data == target){
        // 4 caese to delete
        // 1 case -> both null
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }

        else if(root -> left != NULL && root -> right == NULL){
            Node *childsubtree = root->left;
            delete root;
            return childsubtree;
        }
        else if(root -> left == NULL && root -> right != NULL){
            Node *childsubtree = root->right;
            delete root;
            return childsubtree;
        }
        else{
            //left subtree ki max value nikalo
            Node *maxi = maxValue(root->left);
            //Replacement
            root->data = maxi -> data;
            //delete actual node
            root -> left = deleteBST(root -> left,maxi->data);

            return root;
        }
    }

    else if(root -> data > target){
        root -> left = deleteBST(root -> left, target);
    }
    else{
        root -> right = deleteBST(root -> right, target);
    }

    return root;
}

Node *bstFromInorder(int inorder[], int s, int e){
    if(s > e){
        return NULL;
    }

    int mid = (s+e)/2;
    int ele = inorder[mid];
    Node *root = new Node(ele);

    root -> left = bstFromInorder(inorder,s,mid-1);
    root -> right = bstFromInorder(inorder,mid+1, e);
    return root;
}

int main(){
//     Node *root = NULL;
//     createBST(root);
//     cout<<endl;
//     levelOrderTraversal(root);
//     cout<<endl;
//     cout<<endl;
//     cout<<"Printing ans"<<endl;
//     // preOrder(root);
//     // cout<<endl;
//     // inOrder(root);
//     // cout<<endl;
//     // postOrder(root);
//     // cout<<endl;
//     //50 30 40 20 60 55 70 80 -1
//     // minValue(root);
//     // maxValue(root);
//     // cout<<"Target is present or not: "<<searchBST(root,55);
//     int key;
//     cout<<"Enter node to delete";
//     cin>>key;
//     deleteBST(root,70);
//     levelOrderTraversal(root);
    int inorder[] = {10,20,30,40,50,60,70};
    int size = 7;
    int s=0;
    int e=size-1;
    Node *root = bstFromInorder(inorder,s,e);
    levelOrderTraversal(root);
}