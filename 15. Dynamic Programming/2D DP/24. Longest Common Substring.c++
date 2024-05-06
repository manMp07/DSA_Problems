#include<bits/stdc++.h>
using namespace std;

//Que.- You are given two strings, 'str1' and 'str2'. You have to find the length of the
//      longest common substring.

/***Bottom Up Approach(Tabulation)***/
// Time : O(N*M)
// Space : O(N*M)

int longestCommonSubstring(string &str1, string &str2){
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(str1[i-1] == str2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = 0;

            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}

/***Space Optimization***/
// Time : O(N*N)
// Space : O(N)

int longestCommonSubstring(string &str1, string &str2){
    int n = str1.size();
    int m = str2.size();
    vector<int> prev(m+1, 0), curr(m+1, 0);

    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(str1[i-1] == str2[j-1])
                curr[j] = 1 + prev[j-1];
            else
                curr[j] = 0;

            ans = max(ans, curr[j]);
        }

        prev = curr;
    }

    return ans;
}