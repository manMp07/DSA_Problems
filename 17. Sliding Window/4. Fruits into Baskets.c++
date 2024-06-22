#include<bits/stdc++.h>
using namespace std;

//Que.- You are visiting a farm that has a single row of fruit trees arranged from left to
//      right. The trees are represented by an integer array fruits of size N, where
//      fruits[i]  is the type of fruit the ith tree produces.
//      You want to collect as much fruit as possible. However, the owner has some strict
//      rules that you must follow :
/*
        You only have two baskets, and each basket can only hold a single type of fruit.
        There is no limit on the amount of fruit each basket can hold.
        Starting from any tree of your choice, you must pick exactly one fruit from every
        tree (including the start tree) while moving to the right. The picked fruits must
        fit in one of the baskets.
        Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
        Given the integer array fruits, return the maximum number of fruits you can pick.
*/


int findMaxFruits(vector<int> &arr, int n) {
    unordered_map<int, int> mp;

    int maxLen = 0;
    int lo = 0;

    for(int hi = 0; hi < n; hi++){
        mp[arr[hi]]++;

        if(mp.size() > 2){
            mp[arr[lo]]--;
            if(mp[arr[lo]] == 0)
                mp.erase(arr[lo]);
            lo++;
        }

        if(mp.size() <= 2)
            maxLen = max(maxLen, hi-lo+1);
    }

    return maxLen;
}