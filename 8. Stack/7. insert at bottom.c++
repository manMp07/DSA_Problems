#include<bits/stdc++.h>
using namespace std;

// For a given stack, insert element 'x' at it's bottom.

void solve(stack<int>& myStack, int x) {
    if(myStack.empty()) {
        myStack.push(x);
        return;
    }

    int element = myStack.top();
    myStack.pop();

    solve(myStack, x);

    myStack.push(element);

}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack, x);

    return myStack;
}