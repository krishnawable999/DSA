#include<iostream>
#include<queue>
using namespace std;

class Info{
    private:
    int maxVal;
    bool isheap;

    Info(int a, bool b){
        this->maxVal = a;
        this->isheap = b;
    }
};

Info checkmaxHeap(Node *root){
    if(root == NULL){
        Info temp;
        temp.maxVal = INT_MIN;
        temp.isheap = true;
        return temp; 
    }

    if(root->left == NULL && root->right == NULL){
        Info temp;
        temp.maxVal = temp->data;
        temp.isheap = true;
        return temp;
    }

    Info leftans = checkmaxHeap(root -> left);
    Info rightans = checkmaxHeap(root -> right);

    // ek case solve krdo baki recurssion dekh lega
    if(root->data > leftans.maxVal && root->data > rightans.maxVal && leftans.isheap && rightans.isheap){
        Info ans;
        ans.maxVal = root->data;
        ans.isheap = true;
        return ans;
    }else{
        Info ans;
        ans.maxVal = max(root>data, max(leftans.maxVal, rightans.maxVal));
        ans.isheap = false;
        return ans;
    }

    
}


int main(){

}