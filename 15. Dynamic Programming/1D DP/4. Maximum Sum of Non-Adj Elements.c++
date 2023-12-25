#include <bits/stdc++.h>
using namespace std;

//Que.- Given an array arr[] of positive numbers, The task is to find the maximum
//      sum of a subsequence such that 2 numbers in the sequence should not be
//      adjacent in the array.

/***Recursion***/
// Time : O(2^N)
// Space : O(N)

int solve(vector<int> &num, int i) {
    if(i < 0)
        return 0;
    if(i == 0)
        return num[0];

    // inclusion of i
    int incl = solve(num, i-2) + num[i];

    //exclusion of i
    int excl = solve(num, i-1) + 0;

    return max(incl, excl);
}

int maximumNonAdjacentSum(vector<int> &num){
    int n = num.size();

    int ans = solve(num, n-1);
    // it can be done in left to right manner also(start from 0th index instead of n-1)

    return ans;
}

/***Top Down Approach(Memoization)***/
// Time : O(N)
// Space : O(N) + O(N) ~ O(N)

int solve(vector<int> &num, int i, vector<int> &dp) {
    if(i < 0)
        return 0;
    if(i == 0)
        return num[0];

    if(dp[i] != -1)
        return dp[i];

    // inclusion of i
    int incl = solve(num, i-2, dp) + num[i];

    //exclusion of i
    int excl = solve(num, i-1, dp) + 0;

    dp[i] = max(incl, excl);
    return dp[i];
}

int maximumNonAdjacentSum(vector<int> &num){
    int n = num.size();
    vector<int> dp(n, -1);
    dp[0] = num[0];

    int ans = solve(num, n-1, dp);
    // traversing right to left bcoz, we want to store dp from 0 to nth index

    // it can be done in left to right manner.
    return ans;
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N)
// Space : O(N)

int maximumNonAdjacentSum(vector<int> &num){
    int n = num.size();
    vector<int> dp(n);
    dp[0] = num[0];

    for(int i = 1; i < n; i++) {
        int incl = dp[i-2] + num[i];
        int excl = dp[i-1] + 0;

        dp[i] = max(incl, excl);
    }

    return dp[n-1];
}

/***Space Optimization***/
// Time : O(N)
// Space : O(1)

int maximumNonAdjacentSum(vector<int> &num){
    int n = num.size();
    int prev1 = num[0];
    int prev2 = 0;

    for(int i = 1; i < n; i++) {
        int curr = max(prev2 + num[i], prev1);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}