#include<bits/stdc++.h>
using namespace std;

//Que.- There is a one-dimensional garden on the x-axis. The garden starts at the point 0
//      and ends at the point n. (i.e., the length of the garden is n).
//      There are n + 1 taps located at points [0, 1, ..., n] in the garden.
//      Given an integer n and an integer array ranges of length n + 1 where ranges[i]
//      (0-indexed) means the i-th tap can water the area [i - ranges[i], i + ranges[i]]
//      if it was open.
//      Return the minimum number of taps that should be open to water the whole garden,
//      If the garden cannot be watered return -1.

/***Greedy Approach***/
// Time : O(N)
// Space : O(N)

int findMinFountains(vector<int> &arr, int n){
    vector<int> range(n+1, 0);
    for(int i = 0; i < arr.size(); i++){
        int left = max(0, i - arr[i]);
        int right = min(n, i + arr[i]);

        range[left] = max(range[left], right);
    }

    int taps = 0;
    int maxEnd = 0;
    int currEnd = 0;

    for(int i = 0; i <= n; i++){
        if(i > maxEnd)
            return -1;

        if(i > currEnd){
            taps++;
            currEnd = maxEnd;
        }

        maxEnd = max(maxEnd, range[i]);
    }

    return taps;
}

// This is also can be solved using sorting+dp.
// Time : O(N^2)
// Space : O(N)