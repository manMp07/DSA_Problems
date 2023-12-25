#include<bits/stdc++.h>
using namespace std;

//Que.- In a candy store, there are N different types of candies available and the
//      prices of all the N different types of candies are provided to you.
//      For every candy you buy from the store and get at most K other candies for
//      free.
//      You have to find what is the Minimum & Maximum amount of money you have to
//      spend to buy all the N different candies.

//Time : O(N*logN)
//Space : O(1)

int minimumCost(vector<int> &cost, int n, int k){
    sort(cost.begin(), cost.end());

    int buy = 0;
    int free = n-1;

    int minAns = 0;
    while(buy <= free){
        minAns += cost[buy++];
        free = free - k;
    }

    return minAns;
}

int maximumCost(vector<int> &cost, int n, int k){
    sort(cost.begin(), cost.end());

    int free = 0;
    int buy = n-1;

    int maxAns = 0;
    while(free <= buy){
        maxAns += cost[buy--];
        free = free + k;
    }

    return maxAns;
}