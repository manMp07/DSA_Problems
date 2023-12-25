#include<bits/stdc++.h>
using namespace std;

// Sort a stack as top element will be the largest element

void sortedInsert(stack<int> &stack, int element) {
	if(stack.empty() || stack.top() <= element) {
		stack.push(element);
		return;
	}

	int num = stack.top();
	stack.pop();

	sortedInsert(stack, element);
	stack.push(num);
}

void sortStack(stack<int> &stack){
	//base case
	if(stack.empty()) {
		return;
	}

	int element = stack.top();
	stack.pop();

	//recursive call
	sortStack(stack);

	sortedInsert(stack, element);
}