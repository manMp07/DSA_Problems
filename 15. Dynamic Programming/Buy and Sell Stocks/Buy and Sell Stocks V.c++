#include<bits/stdc++.h>
using namespace std;

//Que.- You are given an array prices where prices[i] is the price of a given stock
//      on the ith day, and an integer fee representing a transaction fee.
//      Find the maximum profit you can achieve. You may complete as many
//      transactions as you like, but you need to pay the transaction fee for each transaction.
//      Note: You may not engage in multiple transactions simultaneously (i.e., you
//      must sell the stock before you buy again).

/***Recursion***/
// Time : O(Exponential)
// Space : O(N)

int solve(vector<int>& price, int index, int buy, int fee) {
	int n = price.size();
    if(index == n)
        return 0;

    int profit = 0;
    if(buy){
        int buyKaro = (-price[index]) + solve(price, index+1, 0, fee);
        int skipKaro = solve(price, index+1, 1, fee);
        profit = max(buyKaro, skipKaro);
    }
    else {
        int sellKaro = price[index] + solve(price, index+1, 1, fee) - fee;
        int skipKaro = solve(price, index+1, 0, fee);
        profit = max(sellKaro, skipKaro);
    }

    return profit;
}

int maximumProfit(vector<int> &prices, int n, int fee){
	return solve(prices, 0, 1, fee);
}

/***Space Optimization***/
// Time : O(N)
// Space : O(1)

int maximumProfit(vector<int> &prices, int n, int fee){
    vector<int> next(2, 0);
    vector<int> curr(2, 0);

    for(int index = n-1; index >= 0; index--){
        for(int buy = 0; buy <= 1; buy++){
            int profit = 0;
            if(buy){
                int buyKaro = (-prices[index]) + next[0];
                int skipKaro = next[1];
                profit = max(buyKaro, skipKaro);
            }
            else {
                int sellKaro = prices[index] + next[1] - fee;
                int skipKaro = next[0];
                profit = max(sellKaro, skipKaro);
            }

            curr[buy] = profit;
        }
        next = curr;
    }

    return next[1];
}