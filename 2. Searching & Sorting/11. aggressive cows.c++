#include<bits/stdc++.h>
using namespace std;

//Que.- You are given an array consisting of n integers which denote the position of a
//      stall. You are also given an integer k which denotes the number of aggressive cows.
//      You are given the task of assigning stalls to k cows such that the minimum distance
//      between any two of them is the maximum possible.
//      Return the maximum possible minimum distance.

// Time : O(NlogN)
// Space : O(1)

bool isPossible(vector<int> arr, int k, int mid) {
    int cowCount = 1;
    int lastPos = arr[0];

    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] - lastPos >= mid) {
            cowCount++;
            lastPos = arr[i];
        }

        if(cowCount == k)
            return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k){
    sort(stalls.begin(), stalls.end());

    int n = stalls.size();
    int lo = 0;
    int hi = stalls[n-1] - stalls[0];

    while(lo <= hi) {
        int mid = lo + (hi-lo)/2;
        if(isPossible(stalls, k, mid))
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    // Because of opposite polarity concept
    return hi;
}