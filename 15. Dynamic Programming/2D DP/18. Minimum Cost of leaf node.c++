#include<bits/stdc++.h>
using namespace std;

/*Que.- Given an array arr of positive integers, consider all binary trees such that:
Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.
A node is a leaf if and only if it has zero children.*/

/***Merge Interval Pattern*/

/***Recursion***/
// Time : O(Exponential)
// Space : O(N)

int solve(vector<int> &arr, map<pair<int,int>, int> &maxi, int left, int right){
    // leaf node
    if(left == right)
        return 0;

    int ans = INT_MAX;
    for(int k = left; k < right; k++)
        ans = min(ans, maxi[{left, k}]*maxi[{k+1, right}] + solve(arr, maxi, left, k) + solve(arr, maxi, k+1, right));

    return ans; 
}

int mctFromLeafValues(vector<int>& arr) {
    int n = arr.size();

    // storing maximum of all range
    map<pair<int,int>, int> maxi;
    for(int i = 0; i < n; i++){
        maxi[{i,i}] = arr[i];
        for(int j = i+1; j < arr.size(); j++){
            maxi[{i,j}] = max(arr[j], maxi[{i, j-1}]);
        }
    }

    return solve(arr, maxi, 0, n-1);
}

/***Top Down Approach(Memoization)***/
// Time : O(N*N*N)
// Space : O(N*N)

int solve(vector<int> &arr, map<pair<int,int>, int> &maxi, int left, int right, vector<vector<int>>& dp){
    // leaf node
    if(left == right)
        return 0;

	if(dp[left][right] != -1)
		return dp[left][right];

    int ans = INT_MAX;
    for(int k = left; k < right; k++)
        ans = min(ans, maxi[{left, k}]*maxi[{k+1, right}] + solve(arr, maxi, left, k, dp) + solve(arr, maxi, k+1, right, dp));

    return dp[left][right] = ans; 
}

int mctFromLeafValues(vector<int>& arr) {
    int n = arr.size();

	// storing maximum of all range
    map<pair<int,int>, int> maxi;
    for(int i = 0; i < n; i++){
        maxi[{i,i}] = arr[i];
        for(int j = i+1; j < arr.size(); j++){
            maxi[{i,j}] = max(arr[j], maxi[{i, j-1}]);
        }
    }

	vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    return solve(arr, maxi, 0, n-1, dp);
}