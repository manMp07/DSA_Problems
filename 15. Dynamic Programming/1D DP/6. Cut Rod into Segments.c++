#include<bits/stdc++.h>
using namespace std;

//Que.- Given a rod of length N, the task is to cut the rod in such a way that the
//		total number of segments of length x, y, and z is maximized. The segments
//		can only be of length x, y, and z. 

/*Input: n = 11, x = 2, y = 3, z = 5 
Output: 5
Explanation: Segments of 2, 2, 2, 2 and 3 */

/***Recursion***/
//Time: O(3^N)
//Space : O(N)

int solve(int n, int x, int y, int z){
	if(n == 0)
		return 0;
	if(n < 0)
		return INT_MIN;

	int a = solve(n-x, x, y, z) + 1;
    int b = solve(n-y, x, y, z) + 1;
    int c = solve(n-z, x, y, z) + 1;

    int ans = max(a, max(b, c));
	return ans;
}

int cutSegments(int n, int x, int y, int z) {
	int ans = solve(n, x, y, z);
	
	if(ans < 0)
		return 0;

	return ans;
}

/***Top Down Approach(Memoization)***/
// Time : O(N)
// Space : O(2N) ~ O(N)

int solve(int n, int x, int y, int z, vector<int> &dp){
	if(n == 0)
		return 0;
	if(n < 0)
		return INT_MIN;

	if(dp[n] != -1)
		return dp[n];

	int a = solve(n-x, x, y, z, dp) + 1;
    int b = solve(n-y, x, y, z, dp) + 1;
    int c = solve(n-z, x, y, z, dp) + 1;

    dp[n] = max(a, max(b, c));
	return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
	vector<int> dp(n+1, -1);
	dp[0] = 0;

	int ans = solve(n, x, y, z, dp);
	
	if(ans < 0)
		return 0;

	return ans;
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N)
// Space : O(N)

int cutSegments(int n, int x, int y, int z) {
	vector<int> dp(n+1, -1);
	dp[0] = 0;

	for(int i = 1; i <= n; i++) {
		if(i-x >= 0 && dp[i-x] != -1)
			dp[i] = max(dp[i], dp[i-x] + 1);

		if(i-y >= 0 && dp[i-y] != -1)
			dp[i] = max(dp[i], dp[i-y] + 1);

		if(i-z >= 0 && dp[i-z] != -1)
			dp[i] = max(dp[i], dp[i-z] + 1);
	}

	if(dp[n] < 0)
		return 0;
		
	return dp[n];
}

// Further Space Optimization is Not Possible