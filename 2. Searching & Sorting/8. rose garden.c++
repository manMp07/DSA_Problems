#include<bits/stdc++.h>
using namespace std;

//Que.- You are given an integer array 'Arr', an integer m and an integer k.
//      You want to make m bouquets. To make a bouquet, you need to use k adjacent
//      flowers from the garden. The garden consists of n flowers, the ith flower
//      will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
//      Return the minimum number of days you need to wait to be able to make m
//      bouquets from the garden. If it is impossible to make m bouquets return -1.

// Time : O(NlogN)
// Space : O(1)

bool isPossible(vector<int> arr, int k, int m, int day) {
	int bouquets = 0;
	int currFlowers = 0;

	for(int i = 0; i < arr.size(); i++) {
		if(arr[i] <= day)
			currFlowers++;
		else{
			bouquets += currFlowers/k;
			currFlowers = 0;
		}
	}
	bouquets += currFlowers/k;

	if(bouquets >= m)
		return true;

	return false;
}

int roseGarden(vector<int> arr, int k, int m){
	long long val = k * 1LL * m * 1LL;
	if(val > arr.size())
		return -1;

	int maxi = INT_MIN, mini = INT_MAX;
	for(int i = 0; i < arr.size(); i++) {
		maxi = max(maxi, arr[i]);
		mini = min(mini, arr[i]);
	}

	int lo = mini;
	int hi = maxi;
	int mid;

	while(lo <= hi) {
		mid = (lo+hi)/2;
		if(isPossible(arr, k, m, mid))
			hi = mid - 1;
		else
			lo = mid + 1;
	}

	// Because of opposite polarity concept :
	// hi will always end up with possible polarity to not possible polarity.
	// lo will always end up with not possible polarity to possible polarity.
	return lo;
}