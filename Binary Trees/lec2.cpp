#include <iostream>
#include<map>
#include<queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree()
{
    int data;
    cout << "Enter values to the node :" << endl;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }
    // step 1
    Node *root = new Node(data);
    cout << "Node" << root->data << endl;
    // step2 :create left subtree
    cout << "Left Node" << root->data << endl;
    root->left = createTree();

    // step3 : create rigth subtree
    cout << "Right Node" << root->data << endl;
    root->right = createTree();

    return root;
}

void preOrederTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // N L R
    cout << root->data << " ";
    // L
    preOrederTraversal(root->left);
    // R
    preOrederTraversal(root->right);
}

void inorderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    // L N R
    // L
    inorderTraversal(root->left);
    // N
    cout << root->data << " ";
    // R
    inorderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    // L R N
    //  L
    postOrderTraversal(root->left);
    // R
    postOrderTraversal(root->right);
    // N
    cout << root->data << " ";
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else
        {
            // valid case
            cout << front->data << " ";

            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}

int searchInoder(int inorder[],int size, int element){
    for(int i=0 ; i<size ; i++){
        if(element == inorder[i]){
            return i;
        }
    }
    return -1;
}

void createMapping(int inorder[],int size, map<int,int> &valueToindexMap){
    for(int i=0 ; i<size ; i++){
        int element = inorder[i];
        int index = i;
        valueToindexMap[element] = index;
    }
}

/* preorderIndex la by reference pass karav lagel karan tyachi value apan increament tr kartoy 
pn jevha function call jate tevha toh punha zero hotoy tyamule ans multiple times print hotay*/

Node* constructTreeFromPreAndInorderTravrersal(map<int,int> &valueToindexMap, int preorder[],int inorder[], int inorderstart,int &preorderIndex, int inorderend, int size){
    // base case
    if(preorderIndex >= size || inorderstart > inorderend){
        return NULL;
    }


    // Ek case him sambhal lenge
    int element = preorder[preorderIndex];
    preorderIndex++;

    Node *root = new Node(element);
    // int position = searchInoder(inorder,size,element);
    /* map use keley karan ki element search operation pratyek time la O(n) time ghetay
    on map fakt ekda traversal kartay ani O(1) madhe elemnt search karun return kartay*/
    int position = valueToindexMap[element];

    // baki recursssion sambhal lega

    root -> left = constructTreeFromPreAndInorderTravrersal(valueToindexMap,preorder,inorder,inorderstart,preorderIndex,position-1,size);
    root -> right = constructTreeFromPreAndInorderTravrersal(valueToindexMap,preorder,inorder,position+1,preorderIndex,inorderend,size);
    return root;
}

int main()
{
    // int preorder[] = {2, 8, 10, 6, 4, 12};
    // int inorder[] = {10, 8, 6, 2, 4, 12};
    // int inorderstart = 0;
    // int preorderIndex = 0;
    // int inorderend = 5;
    // int size = 6;

    // map<int,int> valueToindexMap;
    // createMapping(inorder,size,valueToindexMap);
    // Node *root = constructTreeFromPreAndInorderTravrersal(valueToindexMap,preorder,inorder,inorderstart,preorderIndex,inorderend,size);

    int inorder[] = {8,14,6,2,10,4};
    int postorder[] = {8,6,14,4,10,2};
    int size = 6;
    int inorderstart = 0;
    int postorderindex = size-1;
    int inorderend = size-1;
    map<int,int> valueToindexMap;
    createMapping(inorder,size,valueToindexMap);

    Node *root = constructTreeFromPreAndInorderTravrersal();
    cout<<"Printing Level order" <<endl;
    levelOrderTraversal(root);
}