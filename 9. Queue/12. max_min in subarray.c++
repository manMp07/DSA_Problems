#include<bits/stdc++.h>
using namespace std;

//Que.- Given an array of both positive and negative integers, the task is to
//      compute sum of minimum and maximum elements of all sub-array of size k.

// Time : O(N)
// Space : O(K)

long long sumOfMaxAndMin(vector<int> &arr, int n, int k) {

	deque<int> maxi(k);
	deque<int> mini(k);

	//Addition of first k sized window
	for(int i = 0; i < k; i++) {
		while(!maxi.empty() && arr[maxi.back()] <= arr[i]) {
			maxi.pop_back();
		}
		while(!mini.empty() && arr[mini.back()] >= arr[i]) {
			mini.pop_back();
		}

		mini.push_back(i);
		maxi.push_back(i);
	}

	long long sum = 0;

	for(int i = k; i < n; i++) {
		sum += arr[maxi.front()] + arr[mini.front()];

		//for next window

		//removal
		while(!maxi.empty() && i-maxi.front() >= k) {
			maxi.pop_front();
		}
		while(!mini.empty() && i-mini.front() >= k) {
			mini.pop_front();
		}

		//addition
		while(!maxi.empty() && arr[maxi.back()] < arr[i]) {
			maxi.pop_back();
		}
		while(!mini.empty() && arr[mini.back()] > arr[i]) {
			mini.pop_back();
		}

		mini.push_back(i);
		maxi.push_back(i);
	}

	//Make sure to consider last window
	sum += arr[maxi.front()] + arr[mini.front()];
	
	return sum;
}