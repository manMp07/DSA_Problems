#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;

//Que.- Design a data-structure SpecialStack that supports all the stack operations like
//      push(), pop(), isEmpty() and an additional operation getMin() which should return
//      minimum element from the SpecialStack. Your task is to complete all the functions,
//      using stack data-Structure. 
//      Note : Time & Space should be O(1).


class SpecialStack {
	stack<int> s;
    int mini = INT_MAX;
    
    public:
    void push(int data) {
        //for first element
        if(s.empty()) {
            s.push(data);
            mini = data;
        }
        else {
         	if(data < mini) {
                s.push(2*data - mini);
                mini = data;
            }   
            else {
                s.push(data);
            }
        }
    }

    int pop() {
        if(s.empty()) {
            return -1;
        }
        
        int curr = s.top();
        s.pop();
        if(curr > mini) {
            return curr;
        }
        else {
            int prevMin = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top() {
        if(s.empty())
            return -1;
        
        int curr = s.top();
        if(curr < mini) {
            return mini;
        }
        else {
            return curr;
        }
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        if(s.empty())
            return -1;
        
        return mini;
    }
};