#include<bits/stdc++.h>
using namespace std;

/*Que.- A chef has collected data on the satisfaction level of his n dishes. Chef
        can cook any dish in 1 unit of time.

        Like-time coefficient of a dish is defined as the time taken to cook that
        dish including previous dishes multiplied by its satisfaction level i.e.
        time[i] * satisfaction[i].

        Return the maximum sum of like-time coefficient that the chef can obtain
        after preparing some amount of dishes.

        Dishes can be prepared in any order and the chef can discard some dishes to
        get this maximum value.
*/

/***Recursion***/
// Time : O(2^N)
// Space : O(N)

int solve(vector<int>& satisfaction, int i, int time) {
    int n = satisfaction.size();
    if(i == n)
        return 0;

    int include = (time+1)*satisfaction[i] + solve(satisfaction, i+1, time+1);
    int exclude = solve(satisfaction, i+1, time);

    return max(include, exclude);
}

int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());
    return solve(satisfaction, 0, 0);
}

/***Top Down Approach(Memoization)***/
// Time : O(N*N)
// Space : O(N*N)

int solve(vector<int>& satisfaction, int i, int time, vector<vector<int>>& dp) {
    int n = satisfaction.size();
    if(i == n)
        return 0;

    if(dp[i][time] != -1)
        return dp[i][time];

    int include = (time+1)*satisfaction[i] + solve(satisfaction, i+1, time+1, dp);
    int exclude = solve(satisfaction, i+1, time, dp);

    dp[i][time] = max(include, exclude);
    return dp[i][time];
}

int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());

    int n = satisfaction.size();
    vector<vector<int>> dp(n, vector<int>(n+1, -1));

    return solve(satisfaction, 0, 0, dp);
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N*N)
// Space : O(N*N)

int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());

    int n = satisfaction.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int i = n-1; i >= 0; i--) {
        for(int time = i; time >= 0; time--) {
            int include = (time+1)*satisfaction[i] + dp[i+1][time+1];
            int exclude = dp[i+1][time];

            dp[i][time] = max(include, exclude);
        }
    }

    return dp[0][0];
}

/***Space Optimization***/
// Time : O(N*N)
// Space : O(N)

int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());
    int n = satisfaction.size();

    vector<int> next(n+1, 0);
    vector<int> curr(n+1, 0);

    for(int i = n-1; i >= 0; i--) {
        for(int time = i; time >= 0; time--) {
            int include = (time+1)*satisfaction[i] + next[time+1];
            int exclude = next[time];

            curr[time] = max(include, exclude);
        }
        next = curr;
    }

    return next[0];
}

// Do further optimization of Space = O(1)