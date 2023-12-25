#include<bits/stdc++.h>
using namespace std;

//Que.- You have a convex n-sided polygon where each vertex has an integer value.
//		You are given an integer array values where values[i] is the value of the
//		ith vertex (i.e., clockwise order).
//		You will triangulate the polygon into n - 2 triangles. For each triangle,
//		the value of that triangle is the product of the values of its vertices,
//		and the total score of the triangulation is the sum of these values over all
//		n - 2 triangles in the triangulation.
//		Return the smallest possible total score that you can achieve with some
//		triangulation of the polygon.

/***Recursion***/
// Time : O(N^(N-3))
// Space : O(N)

int solve(vector<int> &arr, int i, int j){
	// base case (triangle using only 2 vertices is not possible)
	if(i+1 == j)
		return 0;

	int ans = INT_MAX;
	for(int k = i+1; k < j; k++) {
		int curr = arr[i]*arr[k]*arr[j] + solve(arr, i, k) + solve(arr, k, j);

		ans = min(ans, curr);
	}

	return ans;
}

int minimumTriangleScore(vector<int> &arr, int n){
	return solve(arr, 0, n-1);
}

/***Top Down Approach(Memoization)***/
// Time : O(N^3)
// Space : O(N^2) + O(N) ~ O(N^2)

int solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp){
	if(i+1 == j)
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	int ans = INT_MAX;
	for(int k = i+1; k < j; k++) {
		int curr = arr[i]*arr[k]*arr[j] + solve(arr, i, k, dp) + solve(arr, k, j, dp);

		ans = min(ans, curr);
	}

	dp[i][j] = ans;
	return dp[i][j];
}

int minimumTriangleScore(vector<int> &arr, int n){
	vector<vector<int>> dp(n, vector<int>(n, -1));
	return solve(arr, 0, n-1, dp);
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N^3)
// Space : O(N^2)

int minimumTriangleScore(vector<int> &arr, int n){
	vector<vector<int>> dp(n, vector<int>(n, 0));

    // In memoization starting : i = 0 & j = n-1
    // In Tabulation starting : i = n-1 & j = i+2 (taken minimum 3 points)

	for(int i = n-1; i >= 0; i--){
		for(int j = i+2; j < n; j++){
			int ans = INT_MAX;
			for(int k = i+1; k < j; k++) {
				int curr = arr[i]*arr[k]*arr[j] + dp[i][k] + dp[k][j];
				ans = min(ans, curr);
			}
			dp[i][j] = ans;
		}
	}

	return dp[0][n-1];
}

// No further optimization possible