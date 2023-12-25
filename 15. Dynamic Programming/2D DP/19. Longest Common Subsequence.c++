#include<bits/stdc++.h>
using namespace std;

//Que.- Given two strings text1 and text2, return the length of their longest
//      common subsequence. If there is no common subsequence, return 0.

/*DP on Strings Pattern*/

/***Recursion***/
// Time : O(Exponential)
// Space : O(min(N,M))

int solve(string& s, string& t, int i, int j){
    if(i == s.size() || j == t.size())
        return 0;

    int ans = 0;
    if(s[i] == t[j])
        ans = 1 + solve(s, t, i+1, j+1);
    else
        ans = max(solve(s, t, i+1, j), solve(s, t, i, j+1));

    return ans;
}

int lcs(string s, string t){
	return solve(s, t, 0, 0);
}

/***Top Down Approach(Memoization)***/
// Time : O(N*M)
// Space : O(N*M)

int solve(string& s, string& t, int i, int j, vector<vector<int>>& dp){
    if(i == s.size() || j == t.size())
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if(s[i] == t[j])
        ans = 1 + solve(s, t, i+1, j+1, dp);
    else
        ans = max(solve(s, t, i+1, j, dp), solve(s, t, i, j+1, dp));

    return dp[i][j] = ans;
}

int lcs(string s, string t){
    int m = s.size();
    int n = t.size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

	return solve(s, t, 0, 0, dp);
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N*M)
// Space : O(N*M)

int lcs(string s, string t){
    int m = s.size();
    int n = t.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for(int i = m-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            int ans = 0;
            if(s[i] == t[j])
                ans = 1 + dp[i+1][j+1];
            else
                ans = max(dp[i+1][j], dp[i][j+1]);

            dp[i][j] = ans;
        }
    }

	return dp[0][0];
}

/***Space Optimization***/
// Time : O(N*M)
// Space : O(min(N,M))

int lcs(string s, string t){
    int m = s.size();
    int n = t.size();
    
    vector<int> next(n+1, 0);
    vector<int> curr(n+1, 0);

    for(int i = m-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            int ans = 0;
            if(s[i] == t[j])
                ans = 1 + next[j+1];
            else
                ans = max(next[j], curr[j+1]);

            curr[j] = ans;
        }
        next = curr;
    }

	return next[0];
}