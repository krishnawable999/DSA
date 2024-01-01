//Insert Element at the bottom of stack

#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &st,int target){
    //base Case
    if(st.empty()){
        st.push(target);
        return;
    }
    
    // Find top element
    int topele = st.top();
    //pop the top element
    st.pop();
    //RE Call
    solve(st,target);
    //Backtracking
    st.push(topele);
}

void pushAtbottom(stack<int> &st){
    if(st.empty()){
        cout<<"Stack is empty nothing to push"<<endl;
        return;
    }
   
        int target = st.top();
        st.pop();
        solve(st,target);
    
}

void print(stack<int> &st){
    if(st.empty()){
        cout<<"Stack UNderflow"<<endl;
        return;
    } 

    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    pushAtbottom(st);
    print(st);
}