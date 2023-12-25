#include<bits/stdc++.h>
using namespace std;

//Que.- Given a number N. Find the minimum number of squares of any number that sums
//      to N. For Example: If N = 100 , N can be expressed as (10*10) and also as
//      (5*5 + 5*5 + 5*5 + 5*5) but the output will be 1 as minimum number of square
//      is 1, i.e (10*10).

/***Recursion***/
//Time : O(Exponential)
//Space : O(N)

int solve(int n) {
	if(n == 0)
		return 0;

	int ans = n;
	for(int i = 1; i*i <= n; i++){
		int count = solve(n-(i*i)) + 1;
		ans = min(ans, count);
	}

	return ans;
}

int minCount(int n){
	int ans = solve(n);
	return ans;
}

/***Top Down Approach(Memoization)***/
// Time : O(N*Sqrt(N))
// Space : O(N)+O(N) ~ O(N)

int solve(int n, vector<int> &dp) {
	if(n == 0)
		return 0;

	if(dp[n] != -1)
		return dp[n];

	int ans = n;
	for(int i = 1; i*i <= n; i++){
		int count = solve(n-(i*i), dp) + 1;
		ans = min(ans, count);
	}

	dp[n] = ans;
	return dp[n];
}

int minCount(int n){
	vector<int> dp(n+1, -1);

	int ans = solve(n, dp);
	return ans;
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N*Sqrt(N))
// Space : O(N)

int minCount(int n){
	vector<int> dp(n+1, INT_MAX);
	dp[0] = 0;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j*j <= i; j++){
			int count = dp[i-(j*j)] + 1;
			
			dp[i] = min(dp[i], count);
		}
	}

	return dp[n];
}