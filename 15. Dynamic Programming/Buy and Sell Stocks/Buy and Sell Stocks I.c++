#include<bits/stdc++.h>
using namespace std;

//Que.- You are given an array prices where prices[i] is the price of a given stock
//      on the ith day.
//      You want to maximize your profit by choosing a single day to buy one stock
//      and choosing a different day in the future to sell that stock.
//      Return the maximum profit you can achieve from this transaction. If you
//      cannot achieve any profit, return 0.

//Time : O(N)
//Space : O(1)

int maximumProfit(vector<int> &prices){
    int mini = prices[0];
    int profit = 0;

    for(int sell = 1; sell < prices.size(); sell++){
        int diff = prices[sell] - mini;
        profit = max(profit, diff);

        mini = min(mini, prices[sell]);
    }

    return profit;
}