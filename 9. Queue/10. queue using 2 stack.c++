#include<bits/stdc++.h>
using namespace std;

//Que.- Implement queue using two stacks.

// Making Enqueue operations coastly
class Queue{
    // Stacks to be used in the operations.
    stack<int> stk1, stk2;
    
    public:
    bool push(int X){//enqueue
        while(!stk1.empty()) {
            int num = stk1.top();
            stk1.pop();

            stk2.push(num);
        }

        stk1.push(X);

        while(!stk2.empty()) {
            int num = stk2.top();
            stk2.pop();

            stk1.push(num);
        }

        return true;
    }

    int pop(){//dequeue
        if(stk1.empty())
            return -1;

        int val = stk1.top();
        stk1.pop();

        return val;
    }
};

// Making Dequeue operations coastly
class Queue{
    // Stacks to be used in the operations.
    stack<int> stk1, stk2;
    
    public:
    bool push(int X){ //enqueue
        stk1.push(X);
        return true;
    }

    int pop(){ //dequeue
        if(stk1.empty()) {
            return -1;
        }
        
        while(!stk1.empty()) {
            int num = stk1.top();
            stk1.pop();

            stk2.push(num);
        }

        int val = stk2.top();
        stk2.pop();

        while(!stk2.empty()) {
            int num = stk2.top();
            stk2.pop();

            stk1.push(num);
        }

        return val;
    }
};