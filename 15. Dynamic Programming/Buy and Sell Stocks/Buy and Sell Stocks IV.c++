#include<bits/stdc++.h>
using namespace std;

//Que.- You are given an integer array prices where prices[i] is the price of a
//      given stock on the ith day, and an integer k.
//      Find the maximum profit you can achieve. You may complete at most k
//      transactions: i.e. you may buy at most k times and sell at most k times.
//      Note: You may not engage in multiple transactions simultaneously (i.e., you
//      must sell the stock before you buy again).

/***Recursion***/
// Time : O(Exponential)
// Space : O(N)

/*Note: This Can be also done using same-ditto method of previous question, and
        Complexity will remain same.(Just write K inseated of 2)*/

int solve(vector<int>& prices, int index, int operation, int k){
    int n = prices.size();
    if(index == n || operation == 2*k)
        return 0;

    int profit = 0;

    // buy allowed
    if(operation % 2 == 0){
        int buyKaro = -prices[index] + solve(prices, index+1, operation+1, k);
        int skipKaro = solve(prices, index+1, operation, k);
        profit = max(buyKaro, skipKaro);
    }
    else { // buy not allowed
        int sellKaro = prices[index] + solve(prices, index+1, operation+1, k);
        int skipKaro = solve(prices, index+1, operation, k);
        profit = max(sellKaro, skipKaro);
    }

    return profit;
}

int maximumProfit(vector<int> &prices, int n, int k){
    return solve(prices, 0, 0, k);
}

/***Top Down Approach(Memoization)***/
// Time : O(N*K)
// Space : O(N*K)

int solve(vector<int>& prices, int index, int operation, int k, vector<vector<int>>& dp){
    int n = prices.size();
    if(index == n || operation == 2*k)
        return 0;

    if(dp[index][operation] != -1)
        return dp[index][operation];

    int profit = 0;

    // buy allowed
    if(operation % 2 == 0){
        int buyKaro = -prices[index] + solve(prices, index+1, operation+1, k, dp);
        int skipKaro = solve(prices, index+1, operation, k, dp);
        profit = max(buyKaro, skipKaro);
    }
    else { // buy not allowed
        int sellKaro = prices[index] + solve(prices, index+1, operation+1, k, dp);
        int skipKaro = solve(prices, index+1, operation, k, dp);
        profit = max(sellKaro, skipKaro);
    }

    return dp[index][operation] = profit;
}

int maximumProfit(vector<int> &prices, int n, int k){
    vector<vector<int>> dp(n, vector<int>(2*k, -1));
    return solve(prices, 0, 0, k, dp);
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N*K)
// Space : O(N*K)

int maximumProfit(vector<int> &prices, int n, int k){
    vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));

    for(int index = n-1; index >= 0; index--){
        for(int operation = 2*k-1; operation >= 0; operation--){
            int profit = 0;

            // buy allowed
            if(operation % 2 == 0){
                int buyKaro = -prices[index] + dp[index+1][operation+1];
                int skipKaro = dp[index+1][operation];
                profit = max(buyKaro, skipKaro);
            }
            else { // buy not allowed
                int sellKaro = prices[index] + dp[index+1][operation+1];
                int skipKaro = dp[index+1][operation];
                profit = max(sellKaro, skipKaro);
            }

            dp[index][operation] = profit;
        }
    }

    return dp[0][0];
}

/***Space Optimization***/
// Time : O(N)
// Space : O(K)

int maximumProfit(vector<int> &prices, int n, int k){
    vector<int> next(2*k+1, 0);
    vector<int> curr(2*k+1, 0);

    for(int index = n-1; index >= 0; index--){
        for(int operation = 2*k-1; operation >= 0; operation--){
            int profit = 0;

            // buy allowed
            if(operation % 2 == 0){
                int buyKaro = -prices[index] + next[operation+1];
                int skipKaro = next[operation];
                profit = max(buyKaro, skipKaro);
            }
            else { // buy not allowed
                int sellKaro = prices[index] + next[operation+1];
                int skipKaro = next[operation];
                profit = max(sellKaro, skipKaro);
            }

            curr[operation] = profit;
        }
        next = curr;
    }

    return next[0];
}