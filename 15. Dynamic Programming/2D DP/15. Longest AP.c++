#include<bits/stdc++.h>
using namespace std;

//Que.- Given an array called A[] of sorted integers having no duplicates,
//      find the length of the Longest Arithmetic Progression in it.

/***Recursion***/
// Time : O(Exponential)
// Space : O(N)

int solve(int arr[], int diff, int index) {
	if(index < 0)
		return 0;

	int count = 0;
	for(int j = index-1; j >= 0; j--){
		if(arr[index] - arr[j] > diff)
			break;
		if(arr[index] - arr[j] == diff)
			count = max(count, 1 + solve(arr, diff, j));
	}
	return count;
}

int lengthOfLongestAP(int arr[], int n) {
	if(n <= 2)
		return n;

	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			ans = max(ans, 2 + solve(arr, arr[j]-arr[i], i));
		}
	}
	return ans;
}

/***Top Down Approach(Memoization)***/
// Time : O(N*N)
// Space : O(N*N)

int solve(int arr[], int diff, int index, unordered_map<int, int> dp[]) {
	if(index < 0)
		return 0;
		
	if(dp[index].count(diff))
	    return dp[index][diff];

	int count = 0;
	for(int j = index-1; j >= 0; j--){
		if(arr[index] - arr[j] > diff)
			break;
		if(arr[index] - arr[j] == diff)
			count = max(count, 1 + solve(arr, diff, j, dp));
	}
	return dp[index][diff] = count;
}

int lengthOfLongestAP(int arr[], int n) {
	if(n <= 2)
		return n;

    unordered_map<int, int> dp[n+1];
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			ans = max(ans, 2 + solve(arr, arr[j]-arr[i], i, dp));
		}
	}
	return ans;
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N*N)
// Space : O(N*N)

int lengthOfLongestAP(int arr[], int n) {
	if(n <= 2)
		return n;

	int ans = 0;
    unordered_map<int, int> dp[n+1];
	
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
		    int diff = arr[i] - arr[j];
		    int count = 1;
		    
		    //check if ans already present
		    if(dp[j].count(diff))
		        count = dp[j][diff];
		    
			dp[i][diff] = 1 + count;
			
			ans = max(ans, dp[i][diff]);
		}
	}
	return ans;
}

// Further Space Optimization is possible to O(N).