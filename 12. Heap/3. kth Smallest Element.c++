#include<bits/stdc++.h>
using namespace std;

//Que.- For a given array 'arr' of size 'N', find it's Kth element.

// Time : O(K + (N-k)logK)
// Space : O(K)

int kthSmallest(int n, int k, vector<int> arr){
    priority_queue<int> maxHeap;

    // step1 : creating maxHeap for first K elements
    for(int i = 0; i < k; i++) {
        maxHeap.push(arr[i]);
    }

    // step2 : check for remaining elements
    for(int i = k; i < n; i++){
        if(arr[i] < maxHeap.top()){
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }

    return maxHeap.top();
}

int kthSmallest(int n, int k, vector<int> arr){
    priority_queue<int> maxHeap;

    for(int i = 0; i < n; i++){
        maxHeap.push(arr[i]);

        if(maxHeap.size() > k)
            maxHeap.pop();
    }
    return maxHeap.top();
}