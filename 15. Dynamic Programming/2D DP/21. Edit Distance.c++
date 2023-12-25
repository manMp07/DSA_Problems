#include<bits/stdc++.h>
using namespace std;

//Que.- Given two strings word1 and word2, return the minimum number of operations
//      required to convert word1 to word2.
//      You have the following three operations permitted on a word:
//      1. Insert a character
//      2. Delete a character
//      3. Replace a character

/*DP on Strings Pattern*/

/***Recursion***/
// Time : O(Exponential)
// Space : O(N)

int solve(string& a, string& b, int i, int j) {
    if(i == a.length())
        return b.length()-j;
    if(j == b.length())
        return a.length()-i;

    int ans = 0;
    if(a[i] == b[j])
        ans = solve(a, b, i+1, j+1);
    else {
        int insertAns = solve(a, b, i, j+1); // +1
        int deleteAns = solve(a, b, i+1, j);// +1
        int replaceAns = solve(a, b, i+1, j+1);// +1

        ans = min(insertAns, min(deleteAns, replaceAns)) + 1;
    }

    return ans;
}

int editDistance(string str1, string str2){
    return solve(str1, str2, 0, 0);
}

/***Top Down Approach(Memoization)***/
// Time : O(N*M)
// Space : O(N*M)

int solve(string& a, string& b, int i, int j, vector<vector<int>>& dp) {
    if(i == a.length())
        return b.length()-j;
    if(j == b.length())
        return a.length()-i;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if(a[i] == b[j])
        ans = solve(a, b, i+1, j+1, dp);
    else {
        int insertAns = solve(a, b, i, j+1, dp); // +1
        int deleteAns = solve(a, b, i+1, j, dp);// +1
        int replaceAns = solve(a, b, i+1, j+1, dp);// +1

        ans = min(insertAns, min(deleteAns, replaceAns)) + 1;
    }
    return dp[i][j] = ans;
}

int editDistance(string str1, string str2){
    vector<vector<int>> dp(str1.length(), vector<int>(str2.length(), -1));
    return solve(str1, str2, 0, 0, dp);
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N*M)
// Space : O(N*M)

int editDistance(string str1, string str2){
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // base case analyze
    for(int j = 0; j < m; j++)
        dp[n][j] = m-j;
    for(int i = 0; i < n; i++)
        dp[i][m] = n-i;

    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            int ans = 0;
            if(str1[i] == str2[j])
                ans = dp[i+1][j+1];
            else {
                int insertAns = dp[i][j+1]; // +1
                int deleteAns = dp[i+1][j];// +1
                int replaceAns = dp[i+1][j+1];// +1

                ans = min(insertAns, min(deleteAns, replaceAns)) + 1;
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

/***Space Optimization***/
// Time : O(N*M)
// Space : O(min(N,M))

int editDistance(string str1, string str2){
    int n = str1.length();
    int m = str2.length();
    
    if(n == 0)
        return m;
    if(m == 0)
        return n;

    vector<int> next(m+1, 0);
    vector<int> curr(m+1, 0);

    // base case analyze
    for(int j = 0; j < m; j++)
        next[j] = m-j;

    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            // catch -> base case se mila he
            curr[m] = n-i;

            int ans = 0;
            if(str1[i] == str2[j])
                ans = next[j+1];
            else {
                int insertAns = curr[j+1]; // +1

                int deleteAns = next[j];// +1
                
                int replaceAns = next[j+1];// +1

                ans = min(insertAns, min(deleteAns, replaceAns)) + 1;
            }
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}