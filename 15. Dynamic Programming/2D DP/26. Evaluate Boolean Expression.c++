#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

//Que.- Given an expression, A, with operands and operators (OR, AND, XOR), return number of
//      ways you can evaluate the expression to be true, by grouping it in different ways?

/***Recursion***/
// Time : O(Exponential)
// Space : O(N)

int solve(string& exp, int i, int j, bool isTrue){
    if(i > j)
        return 0;

    if(i == j){
        if(isTrue) return exp[i] == 'T' ? 1 : 0;
        else return exp[i] == 'F' ? 1 : 0;
    }

    int ways = 0;
    for(int k = i+1; k <= j-1; k += 2){
        int leftTrue = solve(exp, i, k-1, true);
        int leftFalse = solve(exp, i, k-1, false);
        int rightTrue = solve(exp, k+1, j, true);
        int rightFalse = solve(exp, k+1, j, false);

        if(exp[k] == '&'){
            if(isTrue) ways += leftTrue*rightTrue;
            else         ways += leftTrue*rightFalse + leftFalse*rightFalse + leftFalse*rightTrue;
        }

        if(exp[k] == '|'){
            if(isTrue) ways += leftTrue*rightTrue + leftTrue*rightFalse + leftFalse*rightTrue;
            else         ways += leftFalse*rightFalse;
        }

        if(exp[k] == '^'){
            if(isTrue) ways += leftTrue*rightFalse + leftFalse*rightTrue;
            else         ways += leftTrue*rightTrue + leftFalse*rightFalse;
        }
    }

    return ways;
}

int evaluateExp(string & exp) {
    int n = exp.size();
    return solve(exp, 0, n-1, true);
}

/***Top Down Approach(Memoization)***/
// Time : O(N*N*2*N)
// Space : O(N*N*2) + O(N)

int solve(string& exp, int i, int j, bool isTrue, vector<vector<vector<int>>>& dp){
    if(i > j)
        return 0;

    if(i == j){
        if(isTrue) return exp[i] == 'T' ? 1 : 0;
        else return exp[i] == 'F' ? 1 : 0;
    }
    
    if(dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    ll ways = 0;
    for(int k = i+1; k <= j-1; k += 2){
        ll leftTrue = solve(exp, i, k-1, true, dp);
        ll leftFalse = solve(exp, i, k-1, false, dp);
        ll rightTrue = solve(exp, k+1, j, true, dp);
        ll rightFalse = solve(exp, k+1, j, false, dp);

        if(exp[k] == '&'){
            if(isTrue) ways = (ways + (leftTrue*rightTrue)%mod) % mod;
            else         ways = (ways + (leftTrue*rightFalse)%mod + (leftFalse*rightFalse)%mod + (leftFalse*rightTrue)%mod) % mod;
        }

        else if(exp[k] == '|'){
            if(isTrue) ways = (ways + (leftTrue*rightTrue)%mod + (leftTrue*rightFalse)%mod + (leftFalse*rightTrue)%mod) % mod;
            else         ways = (ways + (leftFalse*rightFalse)%mod) % mod;
        }

        else if(exp[k] == '^'){
            if(isTrue) ways = (ways + (leftTrue*rightFalse)%mod + (leftFalse*rightTrue)%mod) % mod;
            else         ways = (ways + (leftTrue*rightTrue)%mod + (leftFalse*rightFalse)%mod) % mod;
        }
    }

    return dp[i][j][isTrue] = ways;
}

int evaluateExp(string & exp) {
    int n = exp.size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));

    return solve(exp, 0, n-1, true, dp);
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N*N*2*N)
// Space : O(N*N*2)

int evaluateExp(string & exp) {
    int n = exp.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

    //basecase
    for(int i = 0; i < n; i++){
        for(int isTrue = 0; isTrue < 2; isTrue++){
            if(isTrue)
                dp[i][i][isTrue] = (exp[i] == 'T' ? 1 : 0);
            else
                dp[i][i][isTrue] = (exp[i] == 'F' ? 1 : 0);
        }
    }

    for(int i = n-1; i >= 0; i--){
        for(int j = i+2; j < n; j++){
            for(int isTrue = 0; isTrue < 2; isTrue++){
                ll ways = 0;
                for(int k = i+1; k <= j-1; k += 2){
                    ll leftTrue = dp[i][k-1][true];
                    ll leftFalse = dp[i][k-1][false];
                    ll rightTrue = dp[k+1][j][true];
                    ll rightFalse = dp[k+1][j][false];

                    if(exp[k] == '&'){
                        if(isTrue) ways = (ways + (leftTrue*rightTrue)%mod) % mod;
                        else         ways = (ways + (leftTrue*rightFalse)%mod + (leftFalse*rightFalse)%mod + (leftFalse*rightTrue)%mod) % mod;
                    }

                    else if(exp[k] == '|'){
                        if(isTrue) ways = (ways + (leftTrue*rightTrue)%mod + (leftTrue*rightFalse)%mod + (leftFalse*rightTrue)%mod) % mod;
                        else         ways = (ways + (leftFalse*rightFalse)%mod) % mod;
                    }

                    else if(exp[k] == '^'){
                        if(isTrue) ways = (ways + (leftTrue*rightFalse)%mod + (leftFalse*rightTrue)%mod) % mod;
                        else         ways = (ways + (leftTrue*rightTrue)%mod + (leftFalse*rightFalse)%mod) % mod;
                    }
                }

                dp[i][j][isTrue] = ways;
            }
        }
    }

    return dp[0][n-1][true];
}