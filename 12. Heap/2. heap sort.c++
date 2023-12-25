#include<bits/stdc++.h>
using namespace std;

//Que.- For given an array Sort in non-decreasing order using Heap Sort algorithm.

// Time : O(NlogN)
// Space : O(?)

void heapify(vector<int> &arr, int n, int i){
	int largest = i;
	int left = i*2 + 1;
	int right = i*2 + 2;

	if(left < n && arr[largest] < arr[left])
		largest = left;
	if(right < n && arr[largest] < arr[right])
		largest = right;

	if(largest != i){
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void solveHeapSort(vector<int> &arr, int n){
	int size = n;

	while(size > 1) {
		//step1
		swap(arr[0], arr[size-1]);
		size--;
		//step2
		heapify(arr, size, 0);
	}	
}

vector<int> heapSort(vector<int>& arr, int n) {
	for(int i = n/2-1; i >= 0; i--){
		heapify(arr, n, i);
	}

	solveHeapSort(arr, n);

	return arr;
}