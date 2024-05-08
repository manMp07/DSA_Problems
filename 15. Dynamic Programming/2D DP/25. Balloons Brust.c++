#include<bits/stdc++.h>
using namespace std;

//Que.- You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a
//      number on it represented by an array. You are asked to burst all the balloons.
//      If you burst the ith balloon, you will get arr[i - 1] * arr[i] * arr[i + 1] coins.
//      If i - 1 or i + 1 goes out of the array's bounds, then treat it as if there is a
//      balloon with a 1 painted on it.
//      Return the maximum coins you can collect by bursting the balloons wisely.

//Hint1 : Try dividing this problem into independent subproblems.
//Hint2 : Think about brusting last balloon, then 2nd last balloon and so on...

/***Top Down Approach(Memoization)***/
// Time : O(N*N*N)
// Space : O(N*N) + O(N)

int solve(vector<int>& arr, int i, int j, vector<vector<int>>& dp){
    if(i > j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MIN;
    for(int k = i; k <= j; k++){
        int coins = arr[i-1]*arr[k]*arr[j+1];
        int remainingCoins = solve(arr, i, k-1, dp) + solve(arr, k+1, j, dp);

        ans = max(ans, coins + remainingCoins);
    }

    return dp[i][j] = ans;
}

int burstBalloons(vector<int> &arr){
    int n = arr.size();

    arr.insert(arr.begin(), 1);
    arr.push_back(1);

    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    // here need not to assign size = dp[n+2][n+1] bcoz, solve(k+1, j) will handle by base case

    return solve(arr, 1, n, dp);
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N*N*N)
// Space : O(N)

int burstBalloons(vector<int> &arr){
    int n = arr.size();

    arr.insert(arr.begin(), 1);
    arr.push_back(1);

    vector<vector<int>> dp(n+2, vector<int>(n+1, 0));

    for(int i = n; i >= 1; i--){
        for(int j = i; j <= n; j++){
            int ans = INT_MIN;
            for(int k = i; k <= j; k++){
                int coins = arr[i-1]*arr[k]*arr[j+1];
                int remainingCoins = dp[i][k-1] + dp[k+1][j]; //dp[k+1] can go out ou bound when j == n, that's why size = dp[n+2][n+1]

                ans = max(ans, coins + remainingCoins);
            }

            dp[i][j] = ans;
        }
    }

    return dp[1][n];
}