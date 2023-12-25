#include<bits/stdc++.h>
using namespace std;

//Que.- Given an integer n, return the number of structurally unique BST's (binary
//		search trees) which has exactly n nodes of unique values from 1 to n.

/***Merge Interval Pattern***/

/***Recursion***/
//Time : O(Exponential)
//Space : O(N)

long long solve(int n){
	if(n == 0 || n == 1)
		return 1;

	long long ans = 0;
	for(int i = 1; i <= n; i++)
		ans += solve(i-1)*solve(n-i);

	return ans;
}

long long int numTrees(int n) {
	return solve(n);
}

/***Top Down Approach(Memoization)***/
// Time : O(N*N)
// Space : O(N)

long long solve(int n, vector<int> dp){
	if(n == 0 || n == 1)
		return 1;

	if(dp[n] != -1)
		return dp[n];

	long long ans = 0;
	for(int i = 1; i <= n; i++)
		ans += solve(i-1, dp)*solve(n-i, dp);

	return dp[n] = ans;
}

long long int numTrees(int n) {
	vector<int> dp(n+1, -1);
	return solve(n, dp);
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N*N)
// Space : O(N)

long long int numTrees(int n) {
	vector<int> dp(n+1, 0);

	dp[0] = 1;
	dp[1] = 1;

	for(int j = 2; j <= n; j++){
		for(int i = 1; i <= j; i++)
			dp[j] += dp[i-1]*dp[j-i];
	}

	return dp[n];
}

/***Catalan Number***/
//Time : O(N)
//Space : O(1)

long long fact(int n) {
    int ans = 1;
    for(int i = 1; i <= n; i++)
        ans *= i;

    return ans;
}

long long int numTrees(int n) {
	return fact(2*n) / (fact(n+1)*fact(n));
}