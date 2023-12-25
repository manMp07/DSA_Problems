#include<bits/stdc++.h>
using namespace std;

//Que.- Given N dice each with M faces, numbered from 1 to M, find the number of
//      ways to get sum X. X is the summation of values on each face when all the
//      dice are thrown.

/***Recursion***/
// Time : O(Exponential)
// Space : O(N)

long long solve(int dice, int faces, int target) {
    if(target < 0)
        return 0;
    if(dice == 0 && target != 0)
        return 0;
    if(dice != 0 && target == 0)
        return 0;
    if(dice == 0 && target == 0)
        return 1;

    long long ans = 0;
    for(int i = 1; i <= faces; i++)
        ans = ans + solve(dice-1, faces, target-i);

    return ans;
}

long long noOfWays(int M , int N , int X) {
    return solve(N, M, X);
}

/***Top Down Approach(Memoization)***/
// Time : O(N*X*M)
// Space : O(N*X)

long long solve(int dice, int faces, int target, vector<vector<long long>>& dp) {
    if(target < 0)
        return 0;
    if(dice == 0 && target != 0)
        return 0;
    if(dice != 0 && target == 0)
        return 0;
    if(dice == 0 && target == 0)
        return 1;

    if(dp[dice][target] != -1)
        return dp[dice][target];

    long long ans = 0;
    for(int i = 1; i <= faces; i++)
        ans = ans + solve(dice-1, faces, target-i, dp);

    dp[dice][target] = ans;
    return dp[dice][target];
}

long long noOfWays(int M , int N , int X) {
    vector<vector<long long>> dp(N+1, vector<long long>(X+1, -1));

    return solve(N, M, X, dp);
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N*X*M)
// Space : O(N*X)

long long noOfWays(int M , int N , int X) {
    vector<vector<long long>> dp(N+1, vector<long long>(X+1, 0));
    
    dp[0][0] = 1; // analyzing base case
    
    for(int dice = 1; dice <= N; dice++) {
        for(int target = 1; target <= X; target++){
            long long ans = 0;
            for(int i = 1; i <= M; i++)
                if(target - i >= 0)
                    ans = ans + dp[dice-1][target-i];
        
            dp[dice][target] = ans;
        }
    }
    
    return dp[N][X];
}

/***Space Optimization***/
// Time : O(N*X*M)
// Space : O(X)

long long noOfWays(int M , int N , int X) {
    vector<long long> prev(X+1, 0);
    vector<long long> curr(X+1, 0);
    
    prev[0] = 1; // analyzing base case
    
    for(int dice = 1; dice <= N; dice++) {
        for(int target = 1; target <= X; target++){
            long long ans = 0;
            for(int i = 1; i <= M; i++)
                if(target - i >= 0)
                    ans = ans + prev[target-i];
        
            curr[target] = ans;
        }
        prev = curr;
    }
    
    return prev[X];
}