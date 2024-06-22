#include<bits/stdc++.h>
using namespace std;

//Que.- You are given a string 'str' and an integer ‘K’. Your task is to find the length
//      of the largest substring with at most ‘K’ distinct characters.

// Time : O(N) + O(N)
// Space : O(256)

int kDistinctChars(int k, string &str){
    unordered_map<char, int> mp;

    int lo = 0;
    int maxLen = 0;
    for(int hi = 0; hi < str.length(); hi++){
        char ch = str[hi];
        mp[ch]++;

        // Does this while loop actually needed...??
        while(mp.size() > k){
            mp[str[lo]]--;
            if(mp[str[lo]] == 0)
                mp.erase(str[lo]);
            lo++;
        }

        if(mp.size() <= k)
            maxLen = max(maxLen, hi-lo+1);
    }

    return maxLen;
}

// Time : O(N)
// Space : O(256)

int kDistinctChars(int k, string &str){
    unordered_map<char, int> mp;

    int lo = 0;
    int maxLen = 0;
    for(int hi = 0; hi < str.length(); hi++){
        char ch = str[hi];
        mp[ch]++;

        if(mp.size() > k){
            mp[str[lo]]--;
            if(mp[str[lo]] == 0)
                mp.erase(str[lo]);
            lo++;
        }

        if(mp.size() <= k)
            maxLen = max(maxLen, hi-lo+1);
    }

    return maxLen;
}