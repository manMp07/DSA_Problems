#include<bits/stdc++.h>
using namespace std;

//Que.- Given a set of N items numbered from 0 to N-1, each with a weight Wi and a 
//      value Vi, along with a maximum weight capacity W, maximize the sum of the
//      values of the items in the knapsack so that the sum of the weights is less
//      than or equal to the knapsack's capacity.

/***Recursion***/
// Time : O(2^N)
// Space : O(N)

int solve(vector<int> &values, vector<int> &weights, int idx, int w) {
	//base case
	if(idx == 0){
		if(weights[0] <= w)
			return values[0];
		else
			return 0;
	}

	// inclusion
	int inc = 0;
	if((w - weights[idx]) >= 0)
		inc = values[idx] + solve(values, weights, idx-1, w-weights[idx]);

	// exclusion
	int exc = solve(values, weights, idx-1, w);

	return max(inc, exc);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w){
	int ans = solve(values, weights, n-1, w);

	return ans;
}

/***Top Down Approach(Memoization)***/
// Time : O(N*W)
// Space : O(N*W) + O(N) ~ O(N*W)

int solve(vector<int> &values, vector<int> &weights, int idx, int w, vector<vector<int>>& dp) {
	//base case
	if(idx == 0){
		if(weights[0] <= w)
			return values[0];
		else
			return 0;
	}

	if(dp[idx][w] != -1)
		return dp[idx][w];

	// inclusion
	int inc = 0;
	if((w - weights[idx]) >= 0)
		inc = values[idx] + solve(values, weights, idx-1, w-weights[idx], dp);

	// exclusion
	int exc = solve(values, weights, idx-1, w, dp);

	dp[idx][w] = max(inc, exc);
	return dp[idx][w];
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w){
	// Why 2D?- In every recursive function, at max 2 states are changing.
	vector<vector<int>> dp(n, vector<int>(w+1, -1));

	int ans = solve(values, weights, n-1, w, dp);

	return ans;
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N*W)
// Space : O(N*W)

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w){
	// Why 2D?- In every recursive function, at max 2 states are changing.
	vector<vector<int>> dp(n, vector<int>(w+1, 0));

	for(int i = weights[0]; i <= w; i++)
		dp[0][i] = values[0];

	for(int i = 1; i < n; i++) {
		for(int j = 0; j <= w; j++) {
			int inc = 0;
			if(j-weights[i] >= 0)
				inc = values[i] + dp[i-1][j-weights[i]];

			int exc = dp[i-1][j];

			dp[i][j] = max(inc, exc);
		}
	}
	
	return dp[n-1][w];
}

/***Space Optimization***/
// Time : O(N*W)
// Space : O(2W)

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w){
	vector<int> prev(w+1, 0);
	vector<int> curr(w+1, 0);

	for(int i = weights[0]; i <= w; i++)
		prev[i] = values[0];

	for(int i = 1; i < n; i++) {
		for(int j = 0; j <= w; j++) {
			int inc = 0;
			if(j-weights[i] >= 0)
				inc = values[i] + prev[j-weights[i]];

			int exc = prev[j];

			curr[j] = max(inc, exc);
		}
		prev = curr;
	}

	return prev[w];
}

/***Further Space Optimization***/
// Time : O(N*W)
// Space : O(W)

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w){
	vector<int> curr(w+1, 0);

	for(int i = weights[0]; i <= w; i++)
		curr[i] = values[0];

	for(int i = 1; i < n; i++) {
		for(int j = w; j >= 0; j--) { //Why using reverse loop?
			int inc = 0;
			if(j-weights[i] >= 0)
				inc = values[i] + curr[j-weights[i]];

			int exc = curr[j];

			curr[j] = max(inc, exc);
		}
	}

	return curr[w];
}