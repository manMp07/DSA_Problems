#include<bits/stdc++.h>
using namespace std;

// Weekly Contest 402 (Que.3)
// DATE : 16 June 2024

//Que.- A magician has various spells.
//      You are given an array power, where each element represents the damage of a spell.
//      Multiple spells can have the same damage value.
//      It is a known fact that if a magician decides to cast a spell with a damage of
//      power[i], they cannot cast any spell with a damage of power[i] - 2, power[i] - 1,
//      power[i] + 1, or power[i] + 2.
//      Each spell can be cast only once.
//      Return the maximum possible total damage that a magician can cast.

/*
Constraints:
1 <= power.length <= 10^5 ---> N
1 <= power[i] <= 10^9
*/

// Time : O(N*logN)
// Space : O(N)

#define ll long long

long long maximumTotalDamage(vector<int>& power) {
    unordered_map<int, int> mp; // {element, freq}
    for(int it : power)
        mp[it]++;

    // If we're selecting any power[i] = x, then we would be selecting all occerences of x
    // That is why frequency is needed.
    vector<pair<int, ll>> freq;
    for(auto it : mp)
        freq.push_back(it);

    sort(freq.begin(), freq.end()); // sort : {element, freq} by element wise

    int n = freq.size();
    vector<ll> dp(n, 0); // we're applying DP on 'freq' array.

    // dp[i] : answer for subarray 0 to i.
    dp[0] = freq[0].first * freq[0].second;

    for(int i = 1; i < n; i++){
        int j = i-1; // find j such that (freq[i]-freq[j] > 2 && j < i)

        // this loop wil run at most 3 times
        while(j >= 0 && freq[i].first - freq[j].first <= 2)
            j--;

        ll noTake = dp[i-1];
        ll take = freq[i].first * freq[i].second; // all occerences of current element.

        if(j >= 0)
            take += dp[j];

        dp[i] = max(take, noTake);
    }

    return dp[n-1];
}