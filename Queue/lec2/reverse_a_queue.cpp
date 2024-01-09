#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQueue(queue<int> &q){
    stack<int> st;

    while(!q.empty()){
        int ele = q.front();
        q.pop();
       // reverseQueue(q);
        st.push(ele);
    } 

    while(!st.empty()){
        int ele = st.top();
        st.pop();
        q.push(ele);
    }

}

//reverse using recurssion

void reverse(queue<int> &q){
    if(q.empty()) return;

    int ele = q.front();
    q.pop();
    reverse(q);
    q.push(ele);
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    // reverseQueue(q);
    reverse(q);

    while(!q.empty()){
        cout << q.front()<<" ";
        q.pop();
    } cout<<endl;

}