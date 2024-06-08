#include<bits/stdc++.h>
using namespace std;

//Que.- In the "Arcade" mall of Berland, Bob and his wife start at shop 0 and N-1 respectively.
//      Bob can jump from shop i to any shop between (i) and (i + Arr[i]). Determine the
//      minimum number of jumps Bob needs to make from shop 0 to reach his wife at shop N-1.
//      If it's impossible, return -1.

/***Recursion***/
//Time: O(Exponential)
//Space : O(N)

int solve(vector<int> arr, int i, int n){
    if(i >= n-1)
        return 0;

    int ans = INT_MAX;
    for(int jump = 1; jump <= arr[i]; jump++){
        int curr = solve(arr, i+jump, n);
        if(curr != -1)
            ans = min(ans, curr + 1);
    }

    if(ans == INT_MAX)
        return -1;

    return ans;
}

int minimumJumps(vector<int> &arr, int n){
    return solve(arr, 0, n);
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N*N)
// Space : O(N)

int minimumJumps(vector<int> &arr, int n){
    vector<int> dp(n, 0);

    for(int i = n-2; i >= 0; i--){
        int ans = INT_MAX;
        for(int jump = 1; jump <= arr[i]; jump++){
            int next = -1;
            if(i+jump < n)
                next = dp[i+jump];

            if(next != -1)
                ans = min(ans, next + 1);
        }

        if(ans == INT_MAX)
            dp[i] = -1;
        else
            dp[i] = ans;
    }

    return dp[0];;
}

// Greedy Approach is in "16.Greedy" folder "Que.10"