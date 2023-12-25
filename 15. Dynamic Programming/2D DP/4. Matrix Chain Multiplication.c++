#include<bits/stdc++.h>
using namespace std;

//Que.- Given the dimension of a sequence of matrices in an array arr[], where the
//      dimension of the ith matrix is (arr[i-1] * arr[i]), the task is to find the
//      most efficient way to multiply these matrices together such that the total
//      number of element multiplications is minimum.

/***Recursion***/
// Time : O(Exponential)
// Space : O(N)

int solve(vector<int> &arr, int i, int j) {
    if(i == j)
        return 0;

    int ans = INT_MAX;
    for(int k = i; k < j; k++){
        int curr = arr[i-1]*arr[k]*arr[j] + solve(arr, i, k) + solve(arr, k+1, j);
        ans = min(ans, curr);
    }

    return ans;
}

int matrixMultiplication(vector<int> &arr, int n){
    return solve(arr, 1, n-1);
}

/***Top Down Approach(Memoization)***/
// Time : O(N^3)
// Space : O(N^2) + O(N) ~ O(N^2)

int solve(vector<int> &arr, int i, int j, vector<vector<int>>& dp) {
    if(i == j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for(int k = i; k < j; k++){
        int curr = arr[i-1]*arr[k]*arr[j] + solve(arr, i, k, dp) + solve(arr, k+1, j, dp);
        ans = min(ans, curr);
    }

    dp[i][j] = ans;
    return dp[i][j];
}

int matrixMultiplication(vector<int> &arr, int n){
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return solve(arr, 1, n-1, dp);
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N^3)
// Space : O(N^2)

int matrixMultiplication(vector<int> &arr, int n){
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i = n-1; i >= 0; i--) {
        // In this case, i should be always left of the j, so j=i+1 is taken.
        for(int j = i+1; j < n ;j++){
            int ans = INT_MAX;
            for(int k = i; k < j; k++){
                int curr = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                ans = min(ans, curr);
            }

            dp[i][j] = ans;
        }
    }

    return dp[1][n-1];
}

// No further optimization possible