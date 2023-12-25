#include<bits/stdc++.h>
using namespace std;

//Que.- Koko loves to eat bananas. There are n piles of bananas; the ith pile has
//      piles[i] bananas. The guards have gone and will come back in h hours. Koko 
//      can decide her bananas-per-hour eating speed of k. Each hour, she chooses
//      some pile of bananas and eats k bananas from that pile. If the pile has
//      less than k bananas, she eats them instead and will not eat any more
//      bananas during this hour. Koko likes to eat slowly but still wants to
//      finish eating all the bananas before the guards return.

// Time : O(N*logN)
// Space : O(1)

bool isPossible(vector<int> piles, int H, int key) {
    int count = 0;
    for(int i = 0; i < piles.size(); i++) {
        if(piles[i] % key == 0)
            count += piles[i]/key;
        else
            count += piles[i]/key + 1;
                
        if(count > H)
            return false;
    }
    return true;
}

int Solve(int N, vector<int> &piles, int H) {
    int maxi = INT_MIN;
    for(int i = 0; i < N; i++) {
        if(piles[i] > maxi)
            maxi = piles[i];
    }
        
    int lo = 0;
    int hi = maxi;
    int ans = -1;
    int mid;
        
    while(lo <= hi) {
        mid = (lo+hi)/2;
        if(isPossible(piles, H, mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return ans;
}