#include<bits/stdc++.h>
using namespace std;

//Que.- Given an array of integers, find the length of the longest(strictly)
//      increasing subsequence from the given array.

/***Recursion***/
// Time : O(2^N)
// Space : O(N)

int solve(int arr[], int n, int curr, int prev) {
    if(curr == n)
        return 0;

    // take
    int include = 0;
    if(prev == -1 || arr[prev] < arr[curr])
        include = 1 + solve(arr, n, curr+1, curr);

    // not take
    int exclude = solve(arr, n, curr+1, prev);

    return max(include, exclude);
}

int longestIncreasingSubsequence(int arr[], int n){
    return solve(arr, n, 0, -1);
}

/***Top Down Approach(Memoization)***/
// Time : O(N*N)
// Space : O(N*N)

int solve(int arr[], int n, int curr, int prev, vector<vector<int>>& dp) {
    if(curr == n)
        return 0;

    if(dp[curr][prev+1] != -1)
        return dp[curr][prev+1];

    // take
    int include = 0;
    if(prev == -1 || arr[prev] < arr[curr])
        include = 1 + solve(arr, n, curr+1, curr, dp);

    // not take
    int exclude = solve(arr, n, curr+1, prev, dp);

    dp[curr][prev+1] = max(include, exclude);
    return dp[curr][prev+1];
}

int longestIncreasingSubsequence(int arr[], int n){
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return solve(arr, n, 0, -1, dp);
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N*N)
// Space : O(N*N)

int longestIncreasingSubsequence(int arr[], int n){
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int curr = n-1; curr >= 0; curr--){
        for(int prev = curr-1; prev >= -1; prev--){
            // take
            int include = 0;
            if(prev == -1 || arr[prev] < arr[curr])
                include = 1 + dp[curr+1][curr+1];

            // not take
            int exclude = dp[curr+1][prev+1];

            dp[curr][prev+1] = max(include, exclude);
        }
    }

    return dp[0][-1+1];
}

/***Space Optimization***/
// Time : O(N*N)
// Space : O(2N)

int longestIncreasingSubsequence(int arr[], int n){
    vector<int> currRow(n+1, 0);
    vector<int> nextRow(n+1, 0);
    
    for(int curr = n-1; curr >= 0; curr--){
        for(int prev = curr-1; prev >= -1; prev--){
            // take
            int include = 0;
            if(prev == -1 || arr[prev] < arr[curr])
                include = 1 + nextRow[curr+1];

            // not take
            int exclude = nextRow[prev+1];

            currRow[prev+1] = max(include, exclude);
        }
        nextRow = currRow;
    }

    return nextRow[-1+1];
}

/***DP with Binary Search***/
//Time : O(N*logN)
//Space : O(N)

int longestIncreasingSubsequence(int arr[], int n){
    vector<int> ans;
    ans.push_back(arr[0]);

    for(int i = 1; i < n; i++){
        if(arr[i] > ans.back())
            ans.push_back(arr[i]);
        else {
            int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[index] = arr[i];
        }
    }

    return ans.size();
}