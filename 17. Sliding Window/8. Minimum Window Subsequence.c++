#include<bits/stdc++.h>
using namespace std;

//Que.- You are given two strings ‘S’ and ‘T’. Your task is to find the minimum substring
//      ‘W’ of ‘S’, such that ‘T’ is a subsequence of ‘W’

// Time : O(N*N)
// Space : O(1)

string minWindow(string S, string T){
    int n = S.length();
    int m = T.length();

	int startIndex = -1;
    int minLen = 1e6;

    for(int i = 0; i < n; i++){
        int k = 0;
        for(int j = i; j < n; j++){
            if(S[j] == T[k])
                k++;

            if(k == m && j-i+1 < minLen){
                minLen = j-i+1;
                startIndex = i;
                break;
            }
        }
    }

    return startIndex == -1 ? "" : S.substr(startIndex, minLen);
}

//Optimized