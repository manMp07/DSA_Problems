#include<bits/stdc++.h>
using namespace std;

// Weekly Contest 404 (Que.3)
// DATE : 30 July 2024

//Que.- You are given an integer array nums and a positive integer k.
//      A subsequence sub of nums with length x is called valid if it satisfies:
//      (sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.
//      Return the length of the longest valid subsequence of nums.

/* Constraints:

2 <= nums.length <= 1e3
1 <= nums[i] <= 1e7
1 <= k <= 1e3 */

int maximumLength(vector<int>& a, int k) {
    int n = a.size();

    for(int& it : a) it = it % k;

    vector<vector<int>> dp(n, vector<int>(k, 0));
    vector<int> last(k, -1);

    // dp[i][y] : Longest Subsequence for subarray [0...i],
    //            If i'th index is selected and Y is the other alternate value

    int ans = 2;
    for(int i = 0; i < n; i++){
        for(int y = 0; y < k; y++){
            if(last[y] == -1)
                dp[i][y] = 1;
            else{
                int j = last[y];
                int x = a[i];
                dp[i][y] = dp[j][x] + 1;
            }

            ans = max(ans, dp[i][y]);
        }
        last[a[i]] = i;
    } // O(N*K)

    return ans;
}