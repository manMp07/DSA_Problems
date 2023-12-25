#include <bits/stdc++.h>
using namespace std;

//Que.- Given a QUEUE containing 'N' integers and an integer 'K'. You need to reverse
//      first 'K' elements in queue and leaving others as same order.

// Time : O(N)
// Space : O(N)
queue<int> reverseElements(queue<int> q, int k){
    stack<int> s;
    int n = q.size();

    //first K from Q and put in stack.
    for(int i = 0; i < k; i++) {
        int num = q.front();
        q.pop();

        s.push(num);
    }

    //fetch from stack and push into Q.
    while(!s.empty()) {
        int num = s.top();
        s.pop();

        q.push(num);
    }

    //fetch first N-K element from Q and push_back.
    for(int i = 0; i < n-k; i++) {
        int num = q.front();
        q.pop();
        
        q.push(num);
    }

    return q;
}
