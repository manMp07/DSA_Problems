#include<bits/stdc++.h>
using namespace std;

//Que.- Given an input string (s) and a pattern (p), implement wildcard pattern matching
//      with support for '?' and '*' where:
//      '?' Matches any single character.
//      '*' Matches any sequence of characters (including the empty sequence).
//      The matching should cover the entire input string (not partial).

/*DP on Strings Pattern*/

/***Recursion***/
// Time : O(Exponential)
// Space : O(N)

bool solve(string& text, string& pattern, int i, int j) {
    // base cases
    if(i < 0 && j < 0)
        return true;

    if(i >= 0 && j < 0)
        return false;

    if(i < 0 && j >= 0){
        for(int k = 0; k <= j; k++)
            if(pattern[k] != '*')
                return false;
        return true;
    }

    // pattern matched
    if(text[i] == pattern[j] || pattern[j] == '?')
        return solve(text, pattern, i-1, j-1);

    else if(pattern[j] == '*')
        //empty string se replace krvao || current char se replace krvao
        return solve(text, pattern, i, j-1) || solve(text, pattern, i-1, j);

    // text[i] != pattern[j]
    else
        return false;
}

bool wildcardMatching(string pattern, string text){
   return solve(text, pattern, text.length()-1, pattern.length()-1);
}

/***Top Down Approach(Memoization)***/
// Time : O(N*M)
// Space : O(N*M)

//Used 1-based Indexing

bool solve(string& text, string& pattern, int i, int j, vector<vector<int>>& dp) {
    if(i == 0 && j == 0)
        return true;

    if(i > 0 && j == 0)
        return false;

    if(i == 0 && j > 0){
        for(int k = 1; k <= j; k++)
            if(pattern[k-1] != '*')
                return false;
        return true;
    }

    if(dp[i][j] != -1)
        return dp[i][j];

    // pattern matched
    if(text[i-1] == pattern[j-1] || pattern[j-1] == '?')
        return dp[i][j] = solve(text, pattern, i-1, j-1, dp);

    else if(pattern[j-1] == '*')
        //empty string se replace krvao || current char se replace krvao
        return dp[i][j] = solve(text, pattern, i, j-1, dp) || solve(text, pattern, i-1, j, dp);

    // text[i] != pattern[j]
    else
        return dp[i][j] = false;
}

bool wildcardMatching(string pattern, string text){
   int n = text.length();
   int m = pattern.length();

   vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
   return solve(text, pattern, n, m, dp);
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N*M)
// Space : O(N*M)

bool wildcardMatching(string pattern, string text){
    int n = text.length();
    int m = pattern.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    dp[0][0] = true;

    for(int j = 1; j <= m; j++){
        bool flag = true;
        for(int k = 1; k <= j; k++){
            if(pattern[k-1] != '*'){
                flag = false;
                break;
            }
        }
        dp[0][j] = flag;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(text[i-1] == pattern[j-1] || pattern[j-1] == '?')
                dp[i][j] = dp[i-1][j-1];

            else if(pattern[j-1] == '*')
                dp[i][j] = dp[i-1][j] || dp[i][j-1];

            else
                dp[i][j] = false;
        }
    }

    return dp[n][m];
}

/***Space Optimization***/
// Time : O(N*M)
// Space : O(min(N,M))

bool wildcardMatching(string pattern, string text){
    int n = text.length();
    int m = pattern.length();
    
    vector<int> prev(m+1, 0);
    vector<int> curr(m+1, 0);

    prev[0] = true;

    for(int j = 1; j <= m; j++){
        bool flag = true;
        for(int k = 1; k <= j; k++){
            if(pattern[k-1] != '*'){
                flag = false;
                break;
            }
        }
        prev[j] = flag;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(text[i-1] == pattern[j-1] || pattern[j-1] == '?')
                curr[j] = prev[j-1];

            else if(pattern[j-1] == '*')
                curr[j] = prev[j] || curr[j-1];

            else
                curr[j] = false;
        }
        prev = curr;
    }

    return prev[m];
}