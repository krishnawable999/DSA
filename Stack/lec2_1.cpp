#include<iostream>
using namespace std;

class stack{
    public:
    int *arr;
    int size;
    int top1;
    int top2;

    stack(int size)
    {
        arr = new int[size];
        this -> size = size;
        top1 = -1;
        top2 = size;
    }

    void push1(int data){
        if(top2 - top1 == 1){
            cout<<"overflow !!"<<endl;
        }
        top1++;
        arr[top1] = data;
    }
    void push2(int data){
        if(top2 - top1 == 1){
            cout<<"overflow !!"<<endl;
        }
        top2--;
        arr[top2] = data;
    }

    void pop1(){
        if(top1 == -1){
            cout<<"Underflow"<<endl;
        }
        arr[top1] = 0;
        top1--;
    }
    void pop2(){
        if(top2 == size){
            cout<<"Underflow"<<endl;
        }
        arr[top2] = 0;
        top2++;
    }

    void print(){
        cout<<"Top1: " << top1 <<endl;
        cout<<"Top2: " << top2 <<endl;
        
        for(int i=0 ; i<size ; i++){
            cout<<arr[i] <<" ";
        }
        cout << endl;
    }
};
int main(){
    stack st(6);

    st.push1(10);
    st.print();

    st.push1(20);
    st.print();

    st.push1(30);
    st.print();

    st.push2(100);
    st.print();

    st.push2(200);
    st.print();

    st.push2(300);
    st.print();

    st.push1(10);
    st.pop1();
    st.print();
    st.pop1();
    st.pop1();
    st.print();
    st.pop1();
    st.print();
    st.pop1();
    st.pop2();
    st.pop2();
    st.pop2();
    st.print();
}