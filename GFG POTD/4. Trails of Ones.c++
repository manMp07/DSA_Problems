#include<bits/stdc++.h>
using namespace std;

// DATE : 03 June 2024

//Que.- Given a number n, find the number of binary strings of length n that contain
//      consecutive 1's in them. Since the number can be very large, return the answer
//      after modulo with 1e9+7.

int numberOfConsecutiveOnes(int n) {
    int totalStrings = 1 << n;
    
    vector<int> a(n, 0);
    // a[i] = number of strings of length (i+1) ending at 0, without consecutive 1s.
    vector<int> b(n, 0);
    // a[i] = number of strings of length (i+1) ending at 1, without consecutive 1s.
    a[0] = b[0] = 1;
    
    for(int i = 1; i < n; i++){
        a[i] = a[i-1] + b[i-1];
        b[i] = a[i-1];
    }
    
    int without_conse_one = a[n-1] + b[n-1];
    
    return totalStrings - without_conse_one; // Didn't take of modulo.
}