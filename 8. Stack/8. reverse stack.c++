#include<bits/stdc++.h>
using namespace std;

// Reverse stack using recursion

void insertAtBottom(stack<int> &stack, int element) {
    if(stack.empty()) {
        stack.push(element);
        return;
    }

    int num = stack.top();

    stack.pop();
    insertAtBottom(stack, element);

    stack.push(num);
}

void reverseStack(stack<int> &stack) {
    if(stack.empty()) {
        return;
    }

    int element = stack.top();
    stack.pop();
    
    reverseStack(stack);

    insertAtBottom(stack, element);
}