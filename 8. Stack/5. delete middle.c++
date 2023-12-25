#include<bits/stdc++.h>
using namespace std;

// For a given stack of size N, delete middle element.

void solve(stack<int> &inputStack, int count, int size) {
    if(count == size/2) {
        inputStack.pop();
        return;
    }

    int element = inputStack.top();
    inputStack.pop();

    solve(inputStack, count+1, size);

    inputStack.push(element);
}

void deleteMiddle(stack<int> &inputStack, int N){
	
    int count = 0;
    solve(inputStack, count, N);
}