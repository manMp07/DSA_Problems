#include<bits/stdc++.h>
using namespace std;

//Que.- Given a string str, find the length of the longest substring without
//      repeating characters.

//Time : O(L)
//Space : O(L)

int lengthOfLongestSubstring(string &s) {
    int n = s.length();
        
    unordered_map<char, int> mp;

    int maxLen = 0;
    int lo = 0;
    for(int hi = 0; hi < n; hi++){
        char ch = s[hi];

        // present in old window
        if(mp.count(ch) && mp[ch] >= lo)
            lo = mp[ch] + 1;
        
        mp[ch] = hi;

        maxLen = max(maxLen, hi-lo+1);
    }

    return maxLen;
}