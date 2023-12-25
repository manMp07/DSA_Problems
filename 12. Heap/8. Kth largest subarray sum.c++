#include<bits/stdc++.h>
using namespace std;

//Que.- Given an array of integers. Find the K-th largest sum of subarray.

// Time : O(N*N*logN)
// Space : O(K)

int getKthLargest(vector<int> &arr, int k){
	priority_queue<int, vector<int>, greater<int>> minHeap;

	for(int i = 0; i < arr.size(); i++) {
		int sum = 0;

		for(int j = i; j < arr.size(); j++){
			sum += arr[j];

			minHeap.push(sum);
			if(minHeap.size() > k)
				minHeap.pop();
		}
	}

	return minHeap.top();
}