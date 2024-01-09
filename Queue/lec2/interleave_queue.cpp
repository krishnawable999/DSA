#include<iostream>
#include<queue>
using namespace std;

void interleave(queue<int> &q, int n){
    int x = n/2;
    queue<int> q1;
    for(int i=0 ; i<x ; i++){
        int ele = q.front();
        q.pop();
        q1.push(ele);
    }

    while(!q1.empty() && !q.empty()){
        int e1 = q1.front();
        int q2 = q.front();
        q1.pop();
        q.pop();
        q.push(e1);
        q.push(q2);
    }

}

int main(){
    int n=8;
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);

    interleave(q,n);
    while(!q.empty()){
        cout << q.front()<<" ";
        q.pop();
    } cout<<endl;
}