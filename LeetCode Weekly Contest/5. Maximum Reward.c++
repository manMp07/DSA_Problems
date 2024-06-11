#include<bits/stdc++.h>
using namespace std;

// Weekly Contest 401 (Que.3)
// DATE : 09 June 2024

//Que.- You are given an integer array rewardValues of length n, representing the values
//      of rewards.
//      Initially, your total reward x is 0, and all indices are unmarked. You are allowed
//      to perform the following operation any number of times:
//      Choose an unmarked index i from the range [0, n - 1].
//      If rewardValues[i] is greater than your current total reward x, then add rewardValues[i]
//      to x (i.e., x = x + rewardValues[i]), and mark the index i.
//      Return an integer denoting the maximum total reward you can collect by performing
//      the operations optimally.

/*
Constraints:
1 <= rewardValues.length <= 2000
1 <= rewardValues[i] <= 2000
*/

// Time : O(N*N)
// Space : O(N*N)

int solve(vector<int> &arr, int i, int x, vector<vector<int>>& dp){
    // When x > 2000, it means we can't find any arr[i] > x, because 1 <= arr[i] <= 2000
    if(i == arr.size() || x >= 2001)
        return x;

    if(dp[i][x] != -1)
        return dp[i][x];

    int take = 0;
    if(arr[i] > x)
        take = solve(arr, i+1, x + arr[i], dp);       
    
    int noTake = solve(arr, i+1, x, dp);
    
    return dp[i][x] = max(take, noTake);
}

int maxTotalReward(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    
    vector<vector<int>> dp(2001, vector<int>(2001, -1));
    return solve(arr, 0, 0, dp);
}