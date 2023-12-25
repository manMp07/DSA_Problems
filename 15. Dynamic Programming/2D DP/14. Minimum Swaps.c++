#include<bits/stdc++.h>
using namespace std;

//Que.- You are given two integer arrays of the same length nums1 and nums2. In one
//      operation, you are allowed to swap nums1[i] with nums2[i].
//      For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the
//      element at i = 3 to obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8].
//      Return the minimum number of needed operations to make nums1 and nums2
//      strictly increasing. The test cases are generated so that the given input
//      always makes it possible.

/***Recursion***/
// Time : O(Exponential)
// Space : O(N)

int solve(vector<int>& nums1, vector<int>& nums2, int i, bool swapped) {
    if(i == nums1.size())
        return 0;

    int ans = INT_MAX;

    int prev1 = nums1[i-1];
    int prev2 = nums2[i-1];

    // catch : We're not swapping in original array, so we need to track if the
    //         previous values are swapped or not.
    if(swapped)
        swap(prev1, prev2);

    // no swap
    if(nums1[i] > prev1 && nums2[i] > prev2)
        ans = solve(nums1, nums2, i+1, 0);

    // swap
    if (nums1[i] > prev2 && nums2[i] > prev1)
        ans = min(ans, 1 + solve(nums1, nums2, i+1, 1));

    return ans;
}

int minSwap(vector<int>& nums1, vector<int>& nums2) {
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
        
    bool swapped = false;
    return solve(nums1, nums2, 1, swapped);
}

/***Top Down Approach(Memoization)***/
// Time : O(N)
// Space : O(N)

int solve(vector<int>& nums1, vector<int>& nums2, int i, bool swapped, vector<vector<int>>& dp) {
    if(i == nums1.size())
        return 0;

    if(dp[i][swapped] != -1)
        return dp[i][swapped];

    int ans = INT_MAX;

    int prev1 = nums1[i-1];
    int prev2 = nums2[i-1];

    // catch
    if(swapped)
        swap(prev1, prev2);

    // no swap
    if(nums1[i] > prev1 && nums2[i] > prev2)
        ans = solve(nums1, nums2, i+1, 0, dp);

    // swap
    if (nums1[i] > prev2 && nums2[i] > prev1)
        ans = min(ans, 1 + solve(nums1, nums2, i+1, 1, dp));

    return dp[i][swapped] = ans;
}

int minSwap(vector<int>& nums1, vector<int>& nums2) {
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
        
    bool swapped = false;
    int n = nums1.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));

    return solve(nums1, nums2, 1, swapped, dp);
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N)
// Space : O(N)

int minSwap(vector<int>& nums1, vector<int>& nums2) {
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    int n = nums1.size();
    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    for(int i = n-1; i >= 1; i--){
        for(int swapped = 1; swapped >= 0; swapped--){
            int ans = INT_MAX;
            int prev1 = nums1[i-1];
            int prev2 = nums2[i-1];

            // catch
            if(swapped)
                swap(prev1, prev2);

            // no swap
            if(nums1[i] > prev1 && nums2[i] > prev2)
                ans = dp[i+1][0];

            // swap
            if (nums1[i] > prev2 && nums2[i] > prev1)
                ans = min(ans, 1 + dp[i+1][1]);

            dp[i][swapped] = ans;
        }
    }
    return dp[1][0];
}

/***Space Optimization***/
// Time : O(N)
// Space : O(1)

int minSwap(vector<int>& nums1, vector<int>& nums2) {
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    int n = nums1.size();

    vector<int> next(2, 0);
    vector<int> curr(2, 0);

    for(int i = n-1; i >= 1; i--){
        for(int swapped = 1; swapped >= 0; swapped--){
            int ans = INT_MAX;
            int prev1 = nums1[i-1];
            int prev2 = nums2[i-1];

            // catch
            if(swapped)
                swap(prev1, prev2);

            // no swap
            if(nums1[i] > prev1 && nums2[i] > prev2)
                ans = next[0];

            // swap
            if (nums1[i] > prev2 && nums2[i] > prev1)
                ans = min(ans, 1 + next[1]);

            curr[swapped] = ans;
        }
        next = curr;
    }
    return next[0];
}