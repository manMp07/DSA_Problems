#include<bits/stdc++.h>
using namespace std;

//Que.- Given a value V and array coins[] of size M, the task is to make the change
//      for V cents, given that you have an infinite supply of each of coins{coins1,
//      coins2, ..., coinsm} valued coins. Find the minimum number of coins to make
//      the change. If not possible to make change then return -1.

/***Recursion***/
// Time : O(Exponential)
// Space : O(X)

int solve(vector<int> &num, int x){
    if(x == 0)
        return 0;
    if(x < 0)
        return INT_MAX;

    int mini = INT_MAX;
    for(int i = 0; i < num.size(); i++){
        int ans = solve(num, x-num[i]);

        // valid case
        if(ans != INT_MAX)
            mini = min(mini, ans+1); // ans+1 bcoz, add current coin to count
    }
    return mini;
}

int minimumElements(vector<int> &num, int x){
    int ans = solve(num, x);

    // Not possible
    if(ans == INT_MAX)
        return -1;

    return ans;
}

/***Top Down Approach(Memoization)***/
// Time : O(N*X)
// Space : O(X) + O(X) ~ O(X)

int solve(vector<int> &num, vector<int> &dp, int x){
    if(x == 0)
        return 0;
    if(x < 0)
        return INT_MAX;

    //step3 : This should be just after the base case
    if(dp[x] != -1)
        return dp[x];

    int mini = INT_MAX;
    for(int i = 0; i < num.size(); i++){
        int ans = solve(num, dp, x-num[i]);

        if(ans != INT_MAX)
            mini = min(mini, ans+1);
    }

    //step2
    dp[x] = mini;
    return dp[x];
}

int minimumElements(vector<int> &num, int x){
    //step1
    vector<int> dp(x+1, -1);

    int ans = solve(num, dp, x);

    if(ans == INT_MAX)
        return -1;

    return ans;
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N*X)
// Space : O(X)

int minimumElements(vector<int> &num, int x){
    vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= x; i++){
        for(int j = 0; j < num.size(); j++){
            if(i-num[j] >= 0 && dp[i-num[j]] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i-num[j]]);
        }
    }

    if(dp[x] == INT_MAX)
        return -1;

    return dp[x];
}

// Further Space Optimization is Not Possible.