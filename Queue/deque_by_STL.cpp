#include<iostream>
#include<deque>
using namespace std;


int main(){
    deque<int> dq;

    dq.push_back(10);
    dq.push_front(20);
    dq.push_front(30);
    dq.push_front(40);
    dq.push_front(50);
    cout << dq.front()<<endl;
    cout << dq.back()<<endl;
    dq.pop_back();
    cout<<dq.back()<<endl;
    dq.pop_front();
    cout<<dq.front()<<endl;
}