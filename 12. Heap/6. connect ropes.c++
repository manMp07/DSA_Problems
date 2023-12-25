#include<bits/stdc++.h>
using namespace std;

//Que.- There are given N ropes of different lengths, we need to connect these
//      ropes into one rope. The cost to connect two ropes is equal to sum of their
//      lengths. The task is to connect the ropes with minimum cost. Given N size
//      array arr[] contains the lengths of the ropes.

// Time : O(NlogN) why?
// Space : O(N)

int minCost(int arr[], int n){
	priority_queue<int, vector<int>, greater<int>> minHeap;
	for(int i = 0; i < n; i++) {
		minHeap.push(arr[i]);
	}

	int totalCost = 0;

	while(minHeap.size() > 1) {
		int first = minHeap.top(); minHeap.pop();
		int second = minHeap.top(); minHeap.pop();

		int currCost = first + second;
		totalCost += currCost;
		
		minHeap.push(currCost);
	}

	return totalCost;
}