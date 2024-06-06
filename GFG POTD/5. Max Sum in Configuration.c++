#include<bits/stdc++.h>
using namespace std;

// DATE : 06 June 2024

//Que.- Given an integer array(0-based indexing) a of size n. Your task is to return the
//      maximum value of the sum of i*a[i] for all 0<= i <=n-1, where a[i] is the element
//      at index i in the array. The only operation allowed is to rotate(clockwise or
//      counterclockwise) the array any number of times.

//Time : O(N)
//Space : O(1)

long long max_sum(int a[], int n) {
    long long sum = 0;
    long long prevValue = 0;
    
    for(int i = 0; i < n; i++){
        sum += a[i];
        prevValue += 1LL*i*a[i];
    }
    
    long long ans = prevValue;
    
    for(int i = 1; i < n; i++){
        // Try to find relation between two concecutive clockwise configurations.
        //  [8,3,1,2] & [3,1,2,8]
        long long currValue = prevValue + 1LL*n*a[i-1] - sum;
        ans = max(ans, currValue);
        
        prevValue = currValue;
    }
    
    return ans;
}