#include<bits/stdc++.h>
using namespace std;

//Que.- You are given an integer array prices where prices[i] is the price of a
//      given stock on the ith day.
//      On each day, you may decide to buy and/or sell the stock. You can only hold
//      at most one share of the stock at any time. However, you can buy it then
//      immediately sell it on the same day.
//      Find and return the maximum profit you can achieve.

/***Recursion***/
// Time : O(Exponential)
// Space : O(N)

long solve(long* price, int index, int n, int buy) {
    if(index == n)
        return 0;

    long profit = 0;
    if(buy){
        long buyKaro = (-price[index]) + solve(price, index+1, n, 0);
        long skipKaro = solve(price, index+1, n, 1);
        profit = max(buyKaro, skipKaro);
    }
    else {
        long sellKaro = (+price[index]) + solve(price, index+1, n, 1);
        long skipKaro = solve(price, index+1, n, 0);
        profit = max(sellKaro, skipKaro);
    }

    return profit;
}

long getMaximumProfit(long *price, int n){
    return solve(price, 0, n, 1);
}

/***Top Down Approach(Memoization)***/
// Time : O(N)
// Space : O(N)

long solve(long* price, int index, int n, int buy, vector<vector<long>> &dp) {
    if(index == n)
        return 0;

    if(dp[index][buy] != -1)
        return dp[index][buy];

    long profit = 0;
    if(buy){
        long buyKaro = (-price[index]) + solve(price, index+1, n, 0, dp);
        long skipKaro = solve(price, index+1, n, 1, dp);
        profit = max(buyKaro, skipKaro);
    }
    else {
        long sellKaro = (+price[index]) + solve(price, index+1, n, 1, dp);
        long skipKaro = solve(price, index+1, n, 0, dp);
        profit = max(sellKaro, skipKaro);
    }

    dp[index][buy] = profit;
    return dp[index][buy];
}

long getMaximumProfit(long *price, int n){
    vector<vector<long>> dp(n, vector<long>(2, -1));
    return solve(price, 0, n, 1, dp);
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N)
// Space : O(N)

long getMaximumProfit(long *price, int n){
    vector<vector<long>> dp(n+1, vector<long>(2, 0));

    for(int index = n-1; index >= 0; index--){
        for(int buy = 0; buy <= 1; buy++){
            long profit = 0;
            if(buy){
                long buyKaro = (-price[index]) + dp[index+1][0];
                long skipKaro = dp[index+1][1];
                profit = max(buyKaro, skipKaro);
            }
            else {
                long sellKaro = (+price[index]) + dp[index+1][1];
                long skipKaro = dp[index+1][0];
                profit = max(sellKaro, skipKaro);
            }

            dp[index][buy] = profit;
        }
    }

    return dp[0][1];
}

/***Space Optimization***/
// Time : O(N)
// Space : O(1)

long getMaximumProfit(long *price, int n){
    vector<long> next(2, 0);
    vector<long> curr(2, 0);

    for(int index = n-1; index >= 0; index--){
        for(int buy = 0; buy <= 1; buy++){
            long profit = 0;
            if(buy){
                long buyKaro = (-price[index]) + next[0];
                long skipKaro = next[1];
                profit = max(buyKaro, skipKaro);
            }
            else {
                long sellKaro = (+price[index]) + next[1];
                long skipKaro = next[0];
                profit = max(sellKaro, skipKaro);
            }

            curr[buy] = profit;
        }
        next = curr;
    }

    return next[1];
}