#include<bits/stdc++.h>
using namespace std;

//Que.- Given an integer array arr and an integer difference, return the length of 
//      the longest subsequence in arr which is an arithmetic sequence such that
//      the difference between adjacent elements in the subsequence equals difference.
//      A subsequence is a sequence that can be derived from arr by deleting some or
//      no elements without changing the order of the remaining elements.

//Note : This question is similar as "Longest Increasing Subsequence with Given
//       Difference D".

//Time : O(N*Time for dp.count())
//Space : O(N)

int longestSubsequence(vector<int>& arr, int diff) {
    unordered_map<int, int> dp;
    int ans = 0;

    for(int i = 0; i <  arr.size(); i++) {
        int target = arr[i]-diff;
        int tempAns = 0;
            
        if(dp.count(target))
            tempAns = dp[target];

        dp[arr[i]] = 1 + tempAns;
        ans = max(ans, dp[arr[i]]);
    }
    return ans;
}