#include<bits/stdc++.h>
using namespace std;

//Que.- Given two strings s and t of lengths m and n respectively, return the minimum
//      window substring of s such that every character in t (including duplicates) is
//      included in the window.
//      Testcases are generated such that a substring always exists and is unique.

/*** Brute Force : Traversing All substring ***/
// Time : O(N^2)
// Space : O(N)

string minSubstring(string &a, string &b){
    int n = a.size();
    int m = b.size();

    int minLen = 1e6, startIndex = -1;

    for(int i = 0; i < n; i++){
        unordered_map<char, int> mp;

        for(int j = 0; j < m; j++)
            mp[b[j]]++;

        int cnt = 0;
        for(int j = i; j < n; j++){
            if(mp[a[j]] > 0)
                cnt++;

            mp[a[j]]--;
            if(cnt == m){
                if(j-i+1 < minLen){
                    startIndex = i;
                    minLen = j-i+1;
                }
                break;
            }
        }
    }

    return a.substr(startIndex, minLen);
}

/*** Optimized ***/
// Time : O(2N)
// Space : O(N)

string minSubstring(string &a, string &b){
    int n = a.size();
    int m = b.size();

    int minLen = 1e6, startIndex = -1;

    unordered_map<char, int> mp;
    for(int j = 0; j < m; j++)
        mp[b[j]]++;

    int lo = 0;
    int cnt = 0;

    for(int hi = 0; hi < n; hi++){
        if(mp[a[hi]] > 0) cnt++;
        mp[a[hi]]--;

        while(cnt == m){
            if(hi-lo+1 < minLen){
                minLen = hi-lo+1;
                startIndex = lo;
            }

            mp[a[lo]]++;
            if(mp[a[lo]] > 0)
                cnt--;
                
            lo++;
        }
    }

    return a.substr(startIndex, minLen);
}