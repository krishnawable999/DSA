#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseKele(queue<int> &q,int k, int n){
    stack<int> st;
    for(int i=0 ; i<k ; i++){
        int ele = q.front();
        q.pop();
        st.push(ele);
    }
    while(!st.empty()){
        int top = st.top();
        st.pop();
        q.push(top);
    }

    for(int i=0 ; i<n-k ; i++){
        int ele=q.front();
        q.pop();
        q.push(ele);
    }

    

}


int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    int k=3;
    int n = 5;

    reverseKele(q,k,n);
     while(!q.empty()){
        cout << q.front()<<" ";
        q.pop();
    } cout<<endl;
}