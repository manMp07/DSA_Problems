#include<bits/stdc++.h>
using namespace std;

//Que.- In the "Arcade" mall of Berland, Bob and his wife start at shop 0 and N-1 respectively.
//      Bob can jump from shop i to any shop between (i) and (i + Arr[i]). Determine the
//      minimum number of jumps Bob needs to make from shop 0 to reach his wife at shop N-1.
//      If it's not possible, return -1.

// Striver's Code
// Time : O(N)
// Space : O(1)

int minJumps(vector<int> &arr,int n) {
    int l = 0, r = 0;
    int jumps = 0;

    while(r < n-1){
        int farthest = 0;
        for(int i = l; i <= r; i++)
            farthest = max(farthest, i+arr[i]);
        l = r+1;
        r = farthest;
        jumps++;

        if(l > r)
            return -1;
    }

    return jumps;
}

// Same code as Minimum Taps Problem(Que.8)
// Time : O(N)
// Space : O(1)

int minJumps(vector<int> &arr, int n) {
    int jumps = 0;
    int currEnd = 0;
    int maxEnd = 0;

    for(int i = 0; i < n; i++){
        if(i > maxEnd)
            return -1;

        if(i > currEnd){
            currEnd = maxEnd;
            jumps++;
        }

        maxEnd = max(maxEnd, i + arr[i]);
    }

    return jumps;
}