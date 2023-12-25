#include<bits/stdc++.h>
using namespace std;

//Que.- A Derangement is a permutation of n elements, such that no element appears
//      in its original position. For example, a derangement of {0, 1, 2, 3} is
//      {2, 3, 1, 0}.
//      Given a number n, find the total number of Derangements of a set of n
//      elements(0 to n-1).

/***Recursion***/
//Time : O(Exponential)
//Space : O(N)

long long int solve(int n) {
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;

    return (n-1) * (solve(n-1) + solve(n-2));
}

long long int countDerangements(int n) {
    long long int ans = solve(n);

    return ans;
}

/***Top Down Approach(Memoization)***/
// Time : O(N)
// Space : O(N)+O(N) ~ O(N)

long long int solve(int n, vector<long long int> &dp) {
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;

    if(dp[n] != -1)
        return dp[n];

    dp[n] = (n-1) * (solve(n-1, dp) + solve(n-2, dp));

    return dp[n];
}

long long int countDerangements(int n) {
    vector<long long int> dp(n+1, -1);
    dp[1] = 0;
    dp[2] = 1;

    long long int ans = solve(n, dp);
    return ans;
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N)
// Space : O(N)

long long int countDerangements(int n) {
    vector<long long int> dp(n+1, -1);
    dp[1] = 0;
    dp[2] = 1;

    for(int i = 3; i <= n; i++)
        dp[i] = (i-1) * ( dp[i-1] + dp[i-2] );
    
    return dp[n];
}

/***Space Optimization***/
// Time : O(N)
// Space : O(1)

long long int countDerangements(int n) {
    long long int prev1 = 1;
    long long int prev2 = 0;

    for(int i = 3; i <= n; i++) {
        long long int curr = (i-1) * (prev1 + prev2);

        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}