#include <iostream>
using namespace std;

class Stack {
public:
    Stack(int capacity) {
        top = -1;
        size = capacity;
        arr[size];
    }

    void push(int value) {
        if (top == size - 1)
            cout << "Stack Overflow";
        else
            arr[++top] = value;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow";
            return -1;
        }
        return arr[top--];
    }

private:
    int top;
    int size;
    int arr[];
};

int main() {
    Stack myStack(5);
    myStack.push(1);
    myStack.push(2);
    myStack.pop();
    return 0;
}