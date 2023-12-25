#include<bits/stdc++.h>
using namespace std;

//Que.- You are a professional robber planning to rob houses along a street. Each
//      house has a certain amount of money stashed. All houses at this place are
//      arranged in a circle. That means the first house is the neighbor of the last
//      one. Meanwhile, adjacent houses have a security system connected, and it
//      will automatically contact the police if two adjacent houses were broken
//      into on the same night.
//      Given an integer array nums representing the amount of money of each house,
//      return the maximum amount of money you can rob tonight without alerting the
//      police.

/***Space Optimization***/
// Time : O(N)
// Space : O(1)

long long int solve(vector<int> &num){
    long long int n = num.size();
    long long int prev1 = num[0];
    long long int prev2 = 0;

    for(long long int i = 1; i < n; i++) {
        long long int curr = max(prev2 + num[i], prev1);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse){
    int n = valueInHouse.size();

    if(n == 1)
        return valueInHouse[0];

    vector<int> first, last;
    for(int i = 0; i < n; i++){
        if(i != n-1)
            first.push_back(valueInHouse[i]);
        if(i != 0)
            last.push_back(valueInHouse[i]);
    }

    long long int ans1 = solve(first);
    long long int ans2 = solve(last);

    return max(ans1, ans2);
}