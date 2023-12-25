#include <bits/stdc++.h>
using namespace std;

//Que.- Given an array of integers cost[] of length N, where cost[i] is the cost of
//      the ith step on a staircase. Once the cost is paid, you can either climb one
//      or two steps.
//      You can either start from the step with index 0, or the step with index 1.
//      Return the minimum cost to reach the top of the floor.

/***Recursion***/
// Time : O(2^N)
// Space : O(N)

int solve(vector<int>& cost, int n) {
    if(n == 0)
        return cost[0];
    if(n == 1)
        return cost[1];
            
    int ans = cost[n] + min(solve(cost, n-1), solve(cost, n-2));
    return ans;
}

int minCostClimbingStairs(vector<int>&cost ,int n){
    int ans = min(solve(cost, n-1), solve(cost, n-2)); 
    return ans;
}

/***Top Down Approach(Memoization)***/
// Time : O(N)
// Space : O(N) + O(N) ~ O(N)

int solve(vector<int>& cost, vector<int>& dp, int n) {
    if(n == 0)
        return cost[0];
    if(n == 1)
        return cost[1];
        
    //step3
    if(dp[n] != -1)
        return dp[n];
        
    //step2
    dp[n] = cost[n] + min(solve(cost, dp, n-1), solve(cost, dp, n-2));
    return dp[n];
}

int minCostClimbingStairs(vector<int>&cost ,int n) {
    //step1
    vector<int> dp(n, -1);
    dp[0] = cost[0];
    dp[1] = cost[1];
        
    int ans = min(solve(cost, dp, n-1), solve(cost, dp, n-2));
        
    return ans;
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N)
// Space : O(N)

int minCostClimbingStairs(vector<int>&cost ,int n) {
    //step1 : creation
    vector<int> dp(n);

    //ste2 : base case analyze
    dp[0] = cost[0];
    dp[1] = cost[1];
        
    //step3 : cover all cases except base cases
    for(int i = 2; i < n; i++)
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]); // convert recursive calls
        
    return min(dp[n-1], dp[n-2]);
}

/***Space Optimization***/
// Time : O(N)
// Space : O(1)

int minCostClimbingStairs(vector<int>&cost ,int n) {
    int prev1 = cost[1];
    int prev2 = cost[0];
        
    for(int i = 2; i < n; i++){
        int curr = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    
    return min(prev1, prev2);
}