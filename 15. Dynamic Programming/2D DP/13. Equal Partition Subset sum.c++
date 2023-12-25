#include<bits/stdc++.h>
using namespace std;

//Que.- Given an array arr[] of size N, check if it can be partitioned into two
//      parts such that the sum of elements in both parts is the same.

/***Recursion***/
// Time : O(Exponential), but it passes all the gfg test cases
// Space : O(N)

bool solve(int arr[], int n, int i, int target) {
    if(target == 0)
        return true;
    if(i >= n || target < 0)
        return false;
        
    bool take = solve(arr, n, i+1, target-arr[i]);
        
    if(take)
        return true;
        
    bool notTake = solve(arr, n, i+1, target);
    
    return notTake;
}

int equalPartition(int N, int arr[]){
    int sum = 0;
    for(int i = 0; i < N; i++)
        sum += arr[i];
        
    if(sum % 2 == 1)
        return 0;
    else
        return solve(arr, N, 0, sum/2);
}

/***Top Down Approach(Memoization)***/
// Time : O(N * sum of elements)
// Space : O(N * sum of elements)

bool solve(int arr[], int n, int i, int target, vector<vector<int>>& dp) {
    if(target == 0)
        return true;
    if(i >= n || target < 0)
        return false;
        
    if(dp[i][target] != -1)
        return dp[i][target];
        
    bool take = solve(arr, n, i+1, target-arr[i], dp);
    bool notTake = solve(arr, n, i+1, target, dp);
    
    return dp[i][target] = take or notTake;
}

int equalPartition(int N, int arr[]){
    int sum = 0;
    for(int i = 0; i < N; i++)
        sum += arr[i];
        
    if(sum % 2 == 1)
        return 0;
    else{
        int target = sum/2;
        vector<vector<int>> dp(N, vector<int>(target+1, -1));
        return solve(arr, N, 0, target, dp);
    }
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N * sum of elements)
// Space : O(N * sum of elements)

int equalPartition(int N, int arr[]){
    int sum = 0;
    for(int i = 0; i < N; i++)
        sum += arr[i];
        
    if(sum % 2 == 1)
        return 0;
    else{
        int t = sum/2;
        vector<vector<int>> dp(N+1, vector<int>(t+1, 0));
        
        for(int i = 0; i <= N; i++)
            dp[i][0] = 1;

        for(int i = N-1; i >= 0; i--){
            for(int target = 1; target <= t; target++) {
                bool take = 0;
                if(target - arr[i] >= 0)
                    take = dp[i+1][target-arr[i]];
                bool notTake = dp[i+1][target];
    
                dp[i][target] = take or notTake;
            }
        }
        
        return dp[0][t];
    }
}

/***Space Optimization***/
// Time : O(N * sum of elements)
// Space : O(sum of elements)

int equalPartition(int N, int arr[]){
    int sum = 0;
    for(int i = 0; i < N; i++)
        sum += arr[i];
        
    if(sum % 2 == 1)
        return 0;
    else{
        int t = sum/2;
        
        vector<int> next(t+1, 0);
        vector<int> curr(t+1, 0);
    
        next[0] = 1;
            
        for(int i = N-1; i >= 0; i--){
            for(int target = 1; target <= t; target++) {
                bool take = 0;
                if(target - arr[i] >= 0)
                    take = next[target-arr[i]];
                    
                bool notTake = next[target];
    
                curr[target] = take or notTake;
            }
            next = curr;
        }
        
        return next[t];
    }
}