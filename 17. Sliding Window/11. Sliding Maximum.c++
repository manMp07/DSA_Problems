#include<bits/stdc++.h>
using namespace std;

//Que.- Given an array arr[] of size N and an integer K. Find the maximum for each
//      and every contiguous subarray of size K.

/***Using Dequeue***/
//Time : O(N + N)
//Space : O(K)

vector<int> maxSlidingWindow(vector<int> &arr, int n, int k){
    deque<int> dq;
    vector<int> ans;

    for(int i = 0; i < n; i++){
        // removing out of bound index
        if(!dq.empty() && dq.front() == i-k)
            dq.pop_front();

        // removing smaller elements
        while(!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();
        
        dq.push_back(i);
        // storing answer for all windows
        if(i >= k-1)
            ans.push_back(arr[dq.front()]);
    }

    return ans;
}