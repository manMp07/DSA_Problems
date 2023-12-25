#include<bits/stdc++.h>
#include<queue>
using namespace std;

//Que.- Given an input stream of N integers. The task is to insert these numbers
//      into a new stream and find the median of the stream formed by each insertion
//      of X to the new stream.

// Practice This Question : Rearrange String

// Time : O(N*logN)
// Space : O(N)

int signum(int first, int second) {
	if(first == second)
		return 0;
	if(first > second)
		return 1;
	if(first < second)
		return -1;
}

void getMedian(int element, priority_queue<int> &maxHeap, 
	priority_queue<int, vector<int>, greater<int>> &minHeap, int &median) {

		switch( signum(maxHeap.size(), minHeap.size()) ){
			case 0: if(element > median){
						minHeap.push(element);
						median = minHeap.top();
					}
					else{
						maxHeap.push(element);
						median = maxHeap.top();
					}
                    break;
			
			case 1: if(element > median){
						minHeap.push(element);
					}
					else {
						minHeap.push(maxHeap.top());
						maxHeap.pop();
						maxHeap.push(element);
					}
					median = (minHeap.top() + maxHeap.top())/2;
					break;

			case -1: if(element > median){
						maxHeap.push(minHeap.top());
						minHeap.pop();
						minHeap.push(element);
					}
					else {
						maxHeap.push(element);
					}
					median = (minHeap.top() + maxHeap.top())/2;
					break;
		}
	}

vector<int> findMedian(vector<int> &arr, int n){
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;

	vector<int> ans;
	int median = 0;
	for(int i = 0; i < arr.size(); i++) {
		getMedian(arr[i], maxHeap, minHeap, median);
		ans.push_back(median);
	}

	return ans;
}