#include<bits/stdc++.h>
using namespace std;

//Que.- Given a binary array 'ARR' of size 'N', your task is to find the longest sequence of
//      continuous 1’s that can be formed by replacing at-most 'K' zeroes by ones. Return
//      the length of this longest sequence of continuous 1’s.

/*Two Pointer Approach*/
//Time : O(N)
//Space : O(1)

int longestSubSeg(vector<int> &arr , int n, int k){
    int lo = 0;
    int zeroCount = 0;
    int ans = 0;

    for(int hi = 0; hi < n; hi++){
        if(arr[hi] == 0){
            zeroCount++;
            while(zeroCount > k){
                if(arr[lo] == 0)
                    zeroCount--;
                lo++;
            }
        }
        ans = max(ans, hi-lo+1);
    }

    return ans;
}