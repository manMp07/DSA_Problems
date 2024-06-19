#include<bits/stdc++.h>
using namespace std;

//Que.- You are given a string 'Str' consisting of only characters 'a' and 'b'. You can
//      delete any number of characters in 'Str' to make 'Str' balanced.
//      A string is called balanced if there is no pair of indices (i, j) such that i < j,
//      Str[i] = 'b' and Str[j] = 'a'. You have to return the minimum number of deletions to
//      make the 'Str' balanced.

//Time : O(N)
//Space : O(1)

int minDeletions(string &str){
    int n = str.length();
    vector<int> aCount(n, 0);

    if(str[n-1] == 'a')
        aCount[n-1] = 1;

    for(int i = n-2; i >= 0; i--){
        if(str[i] == 'a')
            aCount[i] = 1 + aCount[i+1];
        else
            aCount[i] = aCount[i+1];
    }

    int bCount = 0;
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        if(str[i] == 'b'){
            ans = min(ans, bCount + aCount[i]);
            bCount++;
        }
    }

    return ans;
}

/* Can be solved using Recursion/DP */