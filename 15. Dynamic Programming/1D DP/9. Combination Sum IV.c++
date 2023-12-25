#include<bits/stdc++.h>
using namespace std;

//Que.- Given an array of distinct integers nums and a target integer 'target',
//      return the number of possible combinations that add up to target.

/*Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)*/

/***Recursion***/
// Time : O(exponential)
// Space : O(X)

int solve(vector<int>& num, int target){
    if(target == 0)
        return 1;
    if(target < 0)
        return 0;

    int count = 0;
    for(int i = 0; i < num.size(); i++)
        count += solve(num, target-num[i]);

    return count;
}

int findWays(vector<int> &num, int target){
    int ans = solve(num, target);

    return ans;
}

/***Top Down Approach(Memoization)***/
// Time : O(N*Target)
// Space : O(Target)

int solve(vector<int>& num, int target, vector<int>& dp){
    if(target == 0)
        return 1;
    if(target < 0)
        return 0;

    if(dp[target] != -1)
        return dp[target];

    int count = 0;
    for(int i = 0; i < num.size(); i++)
        count += solve(num, target-num[i], dp);

    dp[target] = count;
    return dp[target];
}

int findWays(vector<int> &num, int target){
    vector<int> dp(target+1, -1);

    int ans = solve(num, target, dp);

    return ans;
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N*Target)
// Space : O(Target)

int findWays(vector<int> &num, int target){
    vector<int> dp(target+1, 0);
    dp[0] = 1;

    for(int i = 1; i <= target; i++){
        int count = 0;
        for(int j = 0; j < num.size(); j++){
            if(i-num[j] >= 0)
                count += dp[i-num[j]];
        }
        dp[i] = count;
    }

    return dp[target];
}

// Further Space Optimization is Not Possible.