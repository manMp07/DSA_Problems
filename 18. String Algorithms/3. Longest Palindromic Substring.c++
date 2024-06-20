#include<bits/stdc++.h>
using namespace std;

//Que.- Given a string str, return the longest palindromic substring in str.

/*
Brute Force : Check for each substring whether it is palindrmic or not.
Time : O(N^3)
Space : O(1)
*/

/*
DP Solution : Store the boolean value if the substr(i, j) is palindromic or not
Time : O(N^2)
Space : O(N^2)
*/

int dp[1001][1001];
bool solve(string s, int i, int j){
    if(i >= j)
        return true;
    
    if(dp[i][j] != -1)
        return dp[i][j];

    if(s[i] == s[j])
        return dp[i][j] = solve(s, i+1, j-1);
    
    return dp[i][j] = false;
}

string longestPalinSubstring(string str) {
    int n = str.length();
    memset(dp, -1, sizeof(dp));


    int maxLen = -1;
    int startingIndex;

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(j-i+1 > maxLen && solve(str, i, j)){
                maxLen = j-i+1;
                startingIndex = i;
            }
        }
    }

    return str.substr(startingIndex, maxLen);
}

/*
Instead of dcreasing length, here we're increasing(expanding) the length of palindromic
substring at every index

Time : O(N^2)
Space : O(1); Saved Space
*/

int expand_from_center(string str, int lo, int hi){
    while(lo >= 0 && hi < str.length() && str[lo] == str[hi]){
        lo--;
        hi++;
    }

    return hi-lo-1;
}

string longestPalinSubstring(string s) {
    int n = s.length();
    int maxlen = -1;
    int startingIndex;

    for(int i = 1; i < n; i++){
        int odd = expand_from_center(s, i, i);
        int even = expand_from_center(s, i-1, i);

        if(odd > maxlen){
            maxlen = odd;
            startingIndex = i - odd/2;
        }
        if(even > maxlen){
            maxlen = even;
            startingIndex = i - even/2;
        }
    }

    return s.substr(startingIndex, maxlen);
}

/*
This Can be solved in O(N) using Manacher's Algorithm
*/