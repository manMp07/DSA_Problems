#include<bits/stdc++.h>
using namespace std;

//Que.- We are given an array Arr with N distinct coins and a target. We have an
//      infinite supply of each coin denomination. We need to find the number of
//      ways we sum up the coin values to give us the target.
//      Each coin can be used any number of times.

//Note : One thing to note here is, (1, 1, 2) is same as that of (2, 1, 1) and
//       (1, 2, 1).

/***Recursion***/
// Time : O(Exponential)
// Space : O(Target)

long solve(int coin[], int idx, int T) {
    if(idx == 0)
        return (T % coin[0] == 0);

    // inclusion of i
    long taken = 0;
    if(T-coin[idx] >= 0)
        taken = solve(coin, idx, T-coin[idx]);

    // exclusion of i
    long notTaken = solve(coin, idx-1, T);

    return taken + notTaken;
}

long countWaysToMakeChange(int *coin, int n, int T){
    return solve(coin, n-1, T);
}

/***Top Down Approach(Memoization)***/
// Time : O(N*T)
// Space : O(N*T) + O(N) ~ O(N*T)

long solve(int coin[], int idx, int T, vector<vector<long>>& dp) {
    if(idx == 0)
        return (T % coin[0] == 0);

    if(dp[idx][T] != -1)
        return dp[idx][T];

    // inclusion of i
    long taken = 0;
    if(T-coin[idx] >= 0)
        taken = solve(coin, idx, T-coin[idx]);

    // exclusion of i
    long notTaken = solve(coin, idx-1, T);

    dp[idx][T] = taken + notTaken;
    return dp[idx][T];
}

long countWaysToMakeChange(int *coin, int n, int T){
    vector<vector<long>> dp(n, vector<long>(T+1, -1));

    return solve(coin, n-1, T, dp);
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N*T)
// Space : O(N*T)

long countWaysToMakeChange(int *coin, int n, int T){
    vector<vector<long>> dp(n, vector<long>(T+1, 0));

    // for first row
    for(int i = 0; i <= T; i++){
        if(i % coin[0] == 0)
            dp[0][i] = 1;
    }

    for(int ind = 1; ind < n; ind++) {
        for(int target = 0; target <= T; target++){
            long notTaken = dp[ind-1][target];

            long taken = 0;
            if(target - coin[ind] >= 0)
                taken = dp[ind][target - coin[ind]];

            dp[ind][target] = taken + notTaken;
        }
    }

    return dp[n-1][T];
}

/***Space Optimization***/
// Time : O(N*T)
// Space : O(T)

long countWaysToMakeChange(int *coin, int n, int T){
    vector<long> prev(T+1, 0);

    // for first row
    for(int i = 0; i <= T; i++){
        if(i % coin[0] == 0)
            prev[i] = 1;
    }

    for(int ind = 1; ind < n; ind++) {
        vector<long> curr(T+1, 0);
        for(int target = 0; target <= T; target++){
            long notTaken = prev[target];

            long taken = 0;
            if(target - coin[ind] >= 0)
                taken = curr[target - coin[ind]];

            curr[target] = taken + notTaken;
        }
        prev = curr;
    }

    return prev[T];
}