#include<bits/stdc++.h>
using namespace std;

/*Que.- We are playing the Guessing Game. The game will work as follows:

I pick a number between 1 and n.
You guess a number.
If you guess the right number, you win the game.
If you guess the wrong number, then I will tell you whether the number I picked is
higher or lower, and you will continue guessing.
Every time you guess a wrong number x, you will pay x dollars. If you run out of 
money, you lose the game.
Given a particular n, return the minimum amount of money you need to guarantee a
win regardless of what number I pick.*/

/***Merge Interval Pattern*/

/***Recursion***/
// Time : O(Exponential)
// Space : O(N)

int solve(int start, int end){
    if(start >= end)
        return 0;

    int ans = INT_MAX;
    for(int i = start; i <= end; i++)
        ans = min(ans, i + max(solve(start,i-1), solve(i+1, end)));

    return ans;
}

int getMoneyAmount(int n) {
    return solve(1, n);
}

/***Top Down Approach(Memoization)***/
// Time : O(N*N*N)
// Space : O(N*N)

int solve(int start, int end, vector<vector<int>>& dp){
    if(start >= end)
        return 0;

    if(dp[start][end] != -1)
        return dp[start][end];

    int ans = INT_MAX;
    for(int i = start; i <= end; i++)
        ans = min(ans, i + max(solve(start, i-1, dp), solve(i+1, end, dp)));

    return dp[start][end] = ans;
}

int getMoneyAmount(int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return solve(1, n, dp);
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N*N*N)
// Space : O(N*N)

int getMoneyAmount(int n) {
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

    for(int start = n; start >= 1; start--){
        for(int end = start+1; end <= n; end++){
            int ans = INT_MAX;
            for(int i = start; i <= end; i++)
                ans = min(ans, i + max(dp[start][i-1], dp[i+1][end]));

            dp[start][end] = ans;
        }
    }

    return dp[1][n];
}

/***Space Optimization***/
// Time : O(N*N)
// Space : O(N)