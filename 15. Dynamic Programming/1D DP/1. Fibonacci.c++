#include<bits/stdc++.h>
using namespace std;

//Que.- Find Nth Fibonacci number.

/***Top Down Approach(Memoization)***/
// Time : O(N)
// Space : O(N)+O(N) ~ O(N)

int find(int n, vector<int> &dp){
    //base case
    if(n <= 1)
        return n;

    //step3 : This should be just after the base case
    if(dp[n] != -1)
        return dp[n];

    //step2
    dp[n] = find(n-1, dp) + find(n-2, dp);
    return dp[n];
}

int NthFibonacci(int n){
    //step1
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;

    return find(n, dp);
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N)
// Space : O(N)

int NthFibonacci(int n){
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}

/***Space Optimization***/
// Time : O(N)
// Space : O(1)

int NthFibonacci(int n){
    if(n == 0)
        return 0;

    int prev1 = 1;
    int prev2 = 0;

    for(int i = 2; i <= n; i++){
        int curr = prev1 + prev2;

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
