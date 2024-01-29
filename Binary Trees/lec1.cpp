#include <iostream>
#include <queue>
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

int main()
{
    Node *root = createTree();
    cout << root->data << endl;
    // cout << endl;
    // cout << "Printing preorder traversal" << endl;
    // preOrederTraversal(root);
    // cout << endl;
    // cout << "Printing inorder traversal" << endl;
    // inorderTraversal(root);
    // cout << endl;
    // cout << "Printing postorder traversal" << endl;
    // postOrderTraversal(root);

    cout << endl;
    cout << "Printing level order traversal" << endl;
    levelOrderTraversal(root);
}