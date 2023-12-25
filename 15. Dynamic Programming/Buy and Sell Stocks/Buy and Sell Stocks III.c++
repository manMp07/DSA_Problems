#include<bits/stdc++.h>
using namespace std;

//Que.- You are given an array prices where prices[i] is the price of a given stock
//      on the ith day.
//      Find the maximum profit you can achieve. You may complete at most two
//      transactions.
//      Note: You may not engage in multiple transactions simultaneously (i.e., you
//      must sell the stock before you buy again).

/***Recursion***/
// Time : O(Exponential)
// Space : O(N)

int solve(vector<int> price, int index, int buy, int limit) {
    int n = price.size();
    if(index == n || limit == 0)
        return 0;

    int profit = 0;
    if(buy){
        int buyKaro = (-price[index]) + solve(price, index+1, 0, limit);
        int skipKaro = solve(price, index+1, 1, limit);
        profit = max(buyKaro, skipKaro);
    }
    else if(!buy){
        int sellKaro = (+price[index]) + solve(price, index+1, 1, limit-1);
        int skipKaro = solve(price, index+1, 0, limit);
        profit = max(sellKaro, skipKaro);
    }

    return profit;
}

int maxProfit(vector<int>& price){
    return solve(price, 0, 1, 2);
}

/***Top Down Approach(Memoization)***/
// Time : O(N)
// Space : O(N)

int solve(vector<int> price, int index, int buy, int limit, vector<vector<vector<int>>>& dp) {
    int n = price.size();
    if(index == n || limit == 0)
        return 0;

    if(dp[index][buy][limit] != -1)
        return dp[index][buy][limit];

    int profit = 0;
    if(buy){
        int buyKaro = (-price[index]) + solve(price, index+1, 0, limit, dp);
        int skipKaro = solve(price, index+1, 1, limit, dp);
        profit = max(buyKaro, skipKaro);
    }
    else{
        int sellKaro = (+price[index]) + solve(price, index+1, 1, limit-1, dp);
        int skipKaro = solve(price, index+1, 0, limit, dp);
        profit = max(sellKaro, skipKaro);
    }

    return dp[index][buy][limit] = profit;
}

int maxProfit(vector<int>& price){
    int n = price.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

    return solve(price, 0, 1, 2, dp);
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N)
// Space : O(N)

int maxProfit(vector<int>& price){
    int n = price.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

    for(int index = n-1; index >= 0; index--) {
        for(int buy = 0; buy <= 1; buy++) {
            for(int limit = 1; limit <= 2; limit++) {
                int profit = 0;
                if(buy){
                    int buyKaro = (-price[index]) + dp[index+1][0][limit];
                    int skipKaro = dp[index+1][1][limit];
                    profit = max(buyKaro, skipKaro);
                }
                else{
                    int sellKaro = (+price[index]) + dp[index+1][1][limit-1];
                    int skipKaro = dp[index+1][0][limit];
                    profit = max(sellKaro, skipKaro);
                }

                dp[index][buy][limit] = profit;
            }
        }
    }

    return dp[0][1][2];
}

/***Space Optimization***/
// Time : O(N)
// Space : O(1)

int maxProfit(vector<int>& price){
    int n = price.size();
    vector<vector<int>> next(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    for(int index = n-1; index >= 0; index--) {
        for(int buy = 0; buy <= 1; buy++) {
            for(int limit = 1; limit <= 2; limit++) {
                int profit = 0;
                if(buy){
                    int buyKaro = (-price[index]) + next[0][limit];
                    int skipKaro = next[1][limit];
                    profit = max(buyKaro, skipKaro);
                }
                else{
                    int sellKaro = (+price[index]) + next[1][limit-1];
                    int skipKaro = next[0][limit];
                    profit = max(sellKaro, skipKaro);
                }

                curr[buy][limit] = profit;
            }
        }
        next = curr;
    }

    return next[1][2];
}