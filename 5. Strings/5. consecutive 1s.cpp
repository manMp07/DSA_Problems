#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

// Q.- Given a binary string & integer k, return the maximum number of consecutive 1s in
//     the string if you can flip at most k 0's. (Use sliding window tachnique)

// 000101101 2 -> 7
int main() {
    // Here we will find maximum sub_string which has k 0's.
    string str;
    int k;
    cin >> str >> k;

    int lo = 0;
    int hi = 0;
    int zeroCount = 0;
    int max_length = 0;

    while(hi < str.size()) {
        if(str[hi] == '0') {
            zeroCount++;
        }
        while(zeroCount > k) {
            if(str[lo] == '0') {
                zeroCount--;
            }
            lo++;
        }
        max_length = max(max_length, hi-lo+1);
        hi++;
    }

    cout << max_length;

    return 0;
}