#include<bits/stdc++.h>
using namespace std;

// Weekly Conest 399 (Que.3)
// DATE : 26 May 2024

//Que.- You are given 2 integer arrays nums1 and nums2 of lengths n and m respectively. You
//      are also given a positive integer k.
//      A pair (i, j) is called good if nums1[i] is divisible by nums2[j] * k
//      (0 <= i <= n - 1, 0 <= j <= m - 1).
//      Return the total number of good pairs.

/*Constraints:
1 <= n, m <= 1e5
1 <= nums1[i], nums2[j] <= 1e6
1 <= k <= 1e3
*/


const int mx = 1e6;
int freq[mx+1];
int divisor[mx+1];

long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    for(int i = 0; i <= mx; i++) // O(mx)
        freq[i] = divisor[i] = 0;

    for(int x : nums2) // O(n2)
        if(x * k <= mx)
            freq[x * k]++;

    //O(mx * log(mx))
    for(int ele = 1; ele <= mx; ele++){
        int cnt = freq[ele];
        if(cnt == 0) continue;
        for(int j = ele; j <= mx; j += ele)
            divisor[j] += cnt;
    }

    /* This below code might takes O(N^2) when n2 = [1,1,1,1,1].
    //  That is why we take care of frequencies of every element.

    for(int i = 0; i < n2; i++){
        int ele = nums2[i];
        for(int j = ele; j <= mx; j += ele)
            divisor[j]++;
    } */

    // O(n1)
    long long ans = 0;
    for(int i = 0; i < n1; i++)
        ans += divisor[nums1[i]];

    return ans;
}

// Time -> O(n1 + n2 + MX*log(MX))
// Space -> O(MX)