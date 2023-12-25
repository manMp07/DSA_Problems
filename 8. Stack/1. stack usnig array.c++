#include<iostream>
using namespace std;

// Stack implementation using array

class Stack {
    public:
    //properties
    int *arr; // pointer
    int top;
    int size;

    //behaviour
    Stack(int size) {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data) {
        if(size - top > 1) {
            top++;
            arr[top] = data;
        }
        else {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop() {
        if(top >= 0) {
            top--;
        }
        else {
            cout << "Stack Underflow" << endl;
        }
    }

    int peek() {
        if(top >= 0) {
            return arr[top];
        }
        else {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        if(top == -1) {
            return true;
        }
        else {
            return false;
        }
    } 
};

int main() {
    Stack st(5);

    st.push(7);
    st.push(11);
    st.push(22);
    st.push(15);
    st.push(30);
    st.push(44);

    cout << st.peek() << endl;

    st.pop();
    cout << st.peek() << endl;

    st.pop();
    cout << st.peek() << endl;

    st.pop();
    cout << st.peek() << endl;

    if(st.isEmpty()) {
        cout << "Stack is empty mere dost" << endl;
    }
    else{
        cout << "Stack is not empty mere dost" << endl;
    }
}