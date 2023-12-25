#include<bits/stdc++.h>
using namespace std;

//Que.- Given a string str, find the length of the longest substring without
//      repeating characters.

//Time : O(L)
//Space : O(L)

int lengthOfLongestSubstring(string &s) {
    if(s.length() == 0)
        return 0;
        
    unordered_map<char, int> mp;
    int i = 0, j = 0;

    int currLen = 0;
    int maxLen = INT_MIN;
    while(j < s.length()) {
        char ch = s[j];

        //present in old window
        if(mp.count(ch) && mp[ch] >= i){
            i = mp[ch]+1;
            currLen = j-i;
        }

        mp[ch] = j;
        currLen++;
        j++;

        maxLen = max(maxLen, currLen);
    }

    return maxLen;
}