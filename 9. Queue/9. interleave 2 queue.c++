#include <bits/stdc++.h>
using namespace std;

//Que.- You are given a queue Q of N integers of even length, rearrange the elements by
//      interleaving the first half of the queue with the second half of the queue.
//      Note : The given queue will always be of even length.

// Time : O(N)
// Space : O(N)

void interLeaveQueue(queue<int> &q) {
    //using stack

    int n = q.size();

    stack<int> s;

    // pushing first half of queue into stack
    for(int i = 0; i < n/2; i++) {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    // pushing all elements of stack into queue
    while(!s.empty()) {
        int num = s.top();
        s.pop();
        q.push(num);
    }

    // pushing first half of the queue into that queue itself
    for(int i = 0; i < n/2; i++) {
        int val = q.front();
        q.pop();
        q.push(val);
    }

    // pushing first half of queue into stack
    for(int i = 0; i < n/2; i++) {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    // interleave the elements of queue and stack
    while(!s.empty()) {
        int num = s.top();
        s.pop();
        q.push(num);

        num = q.front();
        q.pop();
        q.push(num);
    }
}

void interLeaveQueue(queue<int> & q) {
    //using queue
    
    int n = q.size();

    queue<int> newQ;

    for(int i = 0; i < n/2; i++) {
        int val = q.front();
        q.pop();
        newQ.push(val);
    }

    while(!newQ.empty()) {
        int num = newQ.front();
        newQ.pop();
        q.push(num);

        num = q.front();
        q.pop();
        q.push(num);
    }
}