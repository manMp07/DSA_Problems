#include<bits/stdc++.h>
using namespace std;

//Que.- You are given an array ‘ARR’ having ‘N’ integers. You are also given an integer
//      ‘K’. The task is to count the number of subarrays that have ‘K’ distinct values.

// Time : O(4N)
// Space : O(N)

int solve(vector<int>& arr, int goal){
    unordered_map<int, int> mp;
    int lo = 0;

    int count = 0;
    
    for(int hi = 0; hi < arr.size(); hi++){
        mp[arr[hi]]++;

        while(mp.size() > goal){
            mp[arr[lo]]--;
            if(mp[arr[lo]] == 0)
                mp.erase(arr[lo]);

            lo++;
        }

        count += (hi-lo+1);
    }

    return count;
}

int kDistinctSubarrays(vector<int> &arr, int n, int k){
    return solve(arr, k) - solve(arr, k-1);
}