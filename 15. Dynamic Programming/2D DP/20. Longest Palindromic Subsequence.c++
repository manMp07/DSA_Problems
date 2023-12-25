#include<bits/stdc++.h>
using namespace std;

//Que.- Given a string s, find the longest palindromic subsequence's length in s.

/*DP on Strings Pattern*/

/***Recursion***/
// Time : O(Exponential)
// Space : O(N)

int solve(string& s, int i, int j) {
    if(i == j)
        return 1;
    if(i > j)
        return 0;

    int ans = 0;
    if(s[i] == s[j])
        ans = 2 + solve(s, i+1, j-1);
    else
        ans = max(solve(s, i+1, j), solve(s, i, j-1));

    return ans;
}

int longestPalindromeSubsequence(string s){
    int n = s.size();
    return solve(s, 0, n-1);
}

/***Top Down Approach(Memoization)***/
// Time : O(N*N)
// Space : O(N*N)

int solve(string& s, int i, int j, vector<vector<int>>& dp) {
    if(i == j)
        return 1;
    if(i > j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];
    
    int ans = 0;
    if(s[i] == s[j])
        ans = 2 + solve(s, i+1, j-1, dp);
    else
        ans = max(solve(s, i+1, j, dp), solve(s, i, j-1, dp));

    return dp[i][j] = ans;
}

int longestPalindromeSubsequence(string s){
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return solve(s, 0, n-1, dp);
}

/***Using LCS Logic***/

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

int longestPalindromeSubsequence(string str){
    string revStr = str;
    reverse(revStr.begin(), revStr.end());
    return lcs(str, revStr);
}