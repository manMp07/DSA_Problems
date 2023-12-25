#include<bits/stdc++.h>
using namespace std;

//Que.- https://leetcode.com/problems/minimum-sideway-jumps/description/

/***Recursion***/
// Time : O()
// Space : O()

int solve(vector<int> obs, int currLane, int pos) {
    int n = obs.size()-1;
    if(pos == n)
        return 0;
        
    // jump not required
    if(obs[pos+1] != currLane)
        return solve(obs, currLane, pos+1);

    // jump required
    else{
        int ans = INT_MAX;
        for(int i = 1; i <= 3; i++){
            if(i != currLane && obs[pos] != i)
                ans = min(ans, 1 + solve(obs, i, pos));
        }
        return ans;
    }
}

int minSideJumps(vector<int>& obstacles) {
    return solve(obstacles, 2, 0);
}

/***Top Down Approach(Memoization)***/
// Time : O()
// Space : O(4*N) + O(N)

int solve(vector<int>& obs, int currLane, int pos, vector<vector<int>>& dp) {
    int n = obs.size()-1;
    if(pos == n)
        return 0;
        
    if(dp[currLane][pos] != -1)
        return dp[currLane][pos];

    // jump not required
    if(obs[pos+1] != currLane){
        dp[currLane][pos] = solve(obs, currLane, pos+1, dp);
        return dp[currLane][pos];
    }

    // jump required
    else{
        int ans = INT_MAX;
        for(int i = 1; i <= 3; i++){
            if(i != currLane && obs[pos] != i)
                ans = min(ans, 1 + solve(obs, i, pos, dp));
        }
        dp[currLane][pos] = ans;
        return dp[currLane][pos];
    }
}

int minSideJumps(vector<int>& obstacles) {
    int n = obstacles.size();
    vector<vector<int>> dp(4, vector<int>(n, -1));

    return solve(obstacles, 2, 0, dp);
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(9*N)
// Space : O(4*N)

// This is absolute JAFFA :)

int minSideJumps(vector<int>& obs) {
    int n = obs.size();
    vector<vector<int>> dp(4, vector<int>(n, 1e9));

    dp[0][n] = 0;
    dp[1][n] = 0;
    dp[2][n] = 0;
    dp[3][n] = 0;

    for(int pos = n-1; pos >= 0; pos--){
        for(int currLane = 1; currLane <= 3; currLane++){
            // jump not required
            if(obs[pos+1] != currLane){
                dp[currLane][pos] = dp[currLane][pos+1];
            }       

            // jump required
            else{
                int ans = 1e9;
                for(int i = 1; i <= 3; i++){
                    if(i != currLane && obs[pos] != i)
                        ans = min(ans, 1 + dp[i][pos+1]); // This pos+1 is very imp
                }
                dp[currLane][pos] = ans;
            }
        }
    }
    //dp[i][j] = i-lane & j-pos thi destination sudhi pochta minimum lagta jumps
    return min(dp[2][0], min(1+dp[1][0], 1+dp[3][0])); 
}

/***Space Optimization***/
// Time : O(9*N)
// Space : O(1)

int minSideJumps(vector<int>& obstacles) {
    int n = obstacles.size()-1;
    vector<int> curr(4, 1e9);
    vector<int> next(4, 1e9);

    next[0] = 0;
    next[1] = 0;
    next[2] = 0;
    next[3] = 0;

    for(int pos = n-1; pos >= 0; pos--){
        for(int lane = 1; lane <= 3; lane++) {
            // no jump required
            if(obstacles[pos+1] != lane){
                curr[lane] = next[lane];
            }

            //jump required
            else{
                int mini = 1e9;
                for(int i = 1; i <= 3; i++){
                    if(i != lane && obstacles[pos] != i)
                        mini = min(mini, 1 + next[i]);
                }
                curr[lane] = mini;
            }
        }
        next = curr;
    }

    return min(next[2], min(next[1]+1, next[3]+1));
}