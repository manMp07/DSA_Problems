#include <bits/stdc++.h>
using namespace std;

//Que.- https://leetcode.com/problems/pizza-with-3n-slices/description/

/***Recursion***/
// Time : O(2^N)
// Space : O(N)

int solve(int index, int endIndex, vector<int>& slices, int n) {
    if(n == 0 || index > endIndex)
        return 0;

    int take = slices[index] + solve(index+2, endIndex, slices, n-1);
    int notTake = 0 + solve(index+1, endIndex, slices, n);

    return max(take, notTake);
}

int pizzaSharing(int n, vector<int> &slices){
    int case1 = solve(0, n-2, slices, n/3);
    int case2 = solve(1, n-1, slices, n/3);

    return max(case1, case2);
}

/***Top Down Approach(Memoization)***/
// Time : O(N*N)
// Space : O(N*N)

int solve(int index, int endIndex, vector<int>& slices, int n, vector<vector<int>>& dp) {
    if(n == 0 || index > endIndex)
        return 0;

    if(dp[index][n] != -1)
        return dp[index][n];

    int take = slices[index] + solve(index+2, endIndex, slices, n-1, dp);
    int notTake = 0 + solve(index+1, endIndex, slices, n, dp);

    return dp[index][n] = max(take, notTake);
}

int pizzaSharing(int n, vector<int> &slices){
    vector<vector<int>> dp1(n, vector<int>(n/3+1, -1));

    int case1 = solve(0, n-2, slices, n/3, dp1);

    vector<vector<int>> dp2(n, vector<int>(n/3+1, -1));
    int case2 = solve(1, n-1, slices, n/3, dp2);

    return max(case1, case2);
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N*N)
// Space : O(N*N)

int pizzaSharing(int n, vector<int> &slices){
    vector<vector<int>> dp1(n+2, vector<int>(n/3+1, 0));
    vector<vector<int>> dp2(n+2, vector<int>(n/3+1, 0));

    // For case1
    for(int index = n-2; index >= 0; index--){
        for(int k = 1; k <= n/3; k++){
            int take = slices[index] + dp1[index+2][k-1];
            int notTake = 0 + dp1[index+1][k];

            dp1[index][k] = max(take, notTake);
        }
    } int case1 = dp1[0][n/3];

    // For case2
    for(int index = n-1; index >= 1; index--){
        for(int k = 1; k <= n/3; k++){
            int take = slices[index] + dp2[index+2][k-1];
            int notTake = 0 + dp2[index+1][k];

            dp2[index][k] = max(take, notTake);
        }
    } int case2 = dp2[1][n/3];

    return max(case1, case2);
}

/***Space Optimization***/
// Time : O(N*N)
// Space : O(N)

int pizzaSharing(int n, vector<int> &slices){
    // For case1
    vector<int> prev1(n+2, 0);
    vector<int> curr1(n+2, 0);
    vector<int> next1(n+2, 0);

    for(int index = n-2; index >= 0; index--){
        for(int k = 1; k <= n/3; k++){
            int take = slices[index] + next1[k-1];
            int notTake = 0 + curr1[k];

            prev1[k] = max(take, notTake);
        }
        next1 = curr1;
        curr1 = prev1;
    } int case1 = curr1[n/3];
    
    // For case2
    vector<int> prev2(n+2, 0);
    vector<int> curr2(n+2, 0);
    vector<int> next2(n+2, 0);

    for(int index = n-1; index >= 1; index--){
        for(int k = 1; k <= n/3; k++){
            int take = slices[index] + next2[k-1];
            int notTake = 0 + curr2[k];

            prev2[k] = max(take, notTake);
        }
        next2 = curr2;
        curr2 = prev2;
    } int case2 = curr2[n/3];

    return max(case1, case2);
}