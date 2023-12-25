#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// Time : O(N)
// Space :

void helper(queue<int> &q) {
    if (q.empty())
    {
        return;
    }
	
    int element = q.front();
    q.pop();

    helper(q);
	
    q.push(element);
}

queue<int> reverseQueueRecursion(queue<int> q){
    helper(q);

    return q;
}

// Time : O(N)
// Space : O(N)
queue<int> reverseQueue(queue<int> q){
    queue<int> rq;
    stack<int> s;

    while(!q.empty()) {
        int num = q.front();
        s.push(num);
        q.pop();
    }

    while(!s.empty()) {
        int num = s.top();
        rq.push(num);
        s.pop();
    }

    return rq;
}