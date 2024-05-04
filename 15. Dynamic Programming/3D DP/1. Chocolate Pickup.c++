#include <bits/stdc++.h>
using namespace std;

//Que.- We are given an ‘N*M’ matrix. Every cell of the matrix has some chocolates on it,
//      mat[i][j] gives us the number of chocolates. We have two friends ‘Alice’ and ‘Bob’.
//      initially, Alice is standing on the cell(0,0) and Bob is standing on the cell(0, M-1).
//      Both of them can move only to the cells below them in these three directions: to the
//      bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙).
//      When Alica and Bob visit a cell, they take all the chocolates from that cell with them.
//      It can happen that they visit the same cell, in that case, the chocolates need to be
//      considered only once.
//      We need to return the maximum number of chocolates that Bob and Alice can together
//      collect.

/***Memoization***/
//Time : O(N*M*M)*9
//Space : O(N) + O(N*M*M)

int maxChocoUtil(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
    // Check if the positions (j1, j2) are valid
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e9; // A very large negative value to represent an invalid position

    // Base case: If we are at the last row, return the chocolate at the positions (j1, j2)
    if (i == n - 1) {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    // If the result for this state is already computed, return it
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxi = INT_MIN;
    
    // Try all possible moves (down, left, right) for both positions (j1, j2)
    for (int alice = -1; alice <= 1; alice++) {
        for (int bob = -1; bob <= 1; bob++) {
            int ans;
            
            if (j1 == j2)
                ans = grid[i][j1] + maxChocoUtil(i + 1, j1 + alice, j2 + bob, n, m, grid, dp);
            else
                ans = grid[i][j1] + grid[i][j2] + maxChocoUtil(i + 1, j1 + alice, j2 + bob, n, m, grid, dp);
            
            // Update the maximum result
            maxi = max(maxi, ans);
        }
    }
    
    // Store the maximum result for this state in dp
    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    // Create a 3D DP array to store computed results
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    // Call the recursive utility function to find the maximum chocolates starting from the first row
    return maxChocoUtil(0, 0, m - 1, n, m, grid, dp);
}