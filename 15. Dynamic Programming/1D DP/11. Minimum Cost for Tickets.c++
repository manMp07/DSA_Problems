#include<bits/stdc++.h>
using namespace std;

/*Que.- You have planned some train traveling one year in advance. The days of the
        year in which you will travel are given as an integer array days. Each day
        is an integer from 1 to 365.

        Train tickets are sold in three different ways:
        a 1-day pass is sold for costs[0] dollars,
        a 7-day pass is sold for costs[1] dollars, and
        a 30-day pass is sold for costs[2] dollars.
        The passes allow that many days of consecutive travel.

        For example, if we get a 7-day pass on day 2, then we can travel for 7 days:
        2, 3, 4, 5, 6, 7, and 8.
        Return the minimum number of dollars you need to travel every day in the
        given list of days.
*/

/***Recursion***/
// Time : O(Exponential)
// Space : O(N)

int solve(int n, int idx, vector<int>& days, vector<int>& cost){
    if(idx >= n)
        return 0;

    // 1 day pass
    int option1 = cost[0] + solve(n, idx+1, days, cost);

    // 7 day pass
    int next;
    for(next = idx+1; next < n && days[next] < days[idx]+7; next++);
    int option2 = cost[1] + solve(n, next, days, cost);

    // 30 day pass
    for(next = idx+1; next < n && days[next] < days[idx]+30; next++);
    int option3 = cost[2] + solve(n, next, days, cost);

    // minimum of all three options
    return min(option1, min(option2, option3));
}

int minimumCoins(int n, vector<int> days, vector<int> cost){
    int ans = solve(n, 0, days, cost);

    return ans;
}

/***Top Down Approach(Memoization)***/
// Time : O(N)
// Space : O(N) + O(N) ~ O(N)

int solve(int n, int idx, vector<int>& days, vector<int>& cost, vector<int>& dp){
    if(idx >= n)
        return 0;

    if(dp[idx] != -1)
        return dp[idx];

    // 1 day pass
    int option1 = cost[0] + solve(n, idx+1, days, cost, dp);

    // 7 day pass
    int next = idx+1;
    while(next < n && days[next] < days[idx]+7)
        next++;
    int option2 = cost[1] + solve(n, next, days, cost, dp);

    // 30 day pass
    next = idx+1;
    while(next < n && days[next] < days[idx]+30)
        next++;
    int option3 = cost[2] + solve(n, next, days, cost, dp);

    // minimum of all three options
    dp[idx] = min(option1, min(option2, option3));
    return dp[idx];
}

int minimumCoins(int n, vector<int> days, vector<int> cost){
    vector<int> dp(n+1, -1);
    int ans = solve(n, 0, days, cost, dp);

    return ans;
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N)
// Space : O(N)

int minimumCoins(int n, vector<int> days, vector<int> cost){
    vector<int> dp(n+1, INT_MAX);
    dp[n] = 0;

    for(int k = n-1; k >= 0; k--){
        // 1 day pass
        int option1 = cost[0] + dp[k+1];

        // 7 day pass
        int next = k+1;
        while(next < n && days[next] < days[k]+7)
            next++;
        int option2 = cost[1] + dp[next];

        // 30 day pass
        next = k+1;
        while(next < n && days[next] < days[k]+30)
            next++;
        int option3 = cost[2] + dp[next];

        // minimum of all three options
        dp[k] = min(option1, min(option2, option3));
    }

    return dp[0];
}

/***Space Optimization***/
// Time : O(N)
// Space : O(1)

int minimumCoins(int n, vector<int> days, vector<int> cost){
    int ans = 0;
    queue<pair<int, int>> month;
    queue<pair<int, int>> week;

    for(int day : days) {
        //step1 : remove expired days
        while(!month.empty() && month.front().first + 30 <= day)
            month.pop();

        while(!week.empty() && week.front().first + 7 <= day)
            week.pop();

        //step2 : add cost for currnt day
        week.push({day, ans + cost[1]});
        month.push({day, ans + cost[2]});

        //step3 : ans update
        ans = min(ans+cost[0], min(week.front().second, month.front().second));
    }

    return ans;
}