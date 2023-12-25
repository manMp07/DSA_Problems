#include<bits/stdc++.h>
using namespace std;

//Que.- Given two sorted arrays of size m and n respectively, you are tasked with finding
//      the element that would be at the k’th position of the final sorted array.

// Note : Already Done using recursion in "Resursion" section Que.-18.

// ***Optimal Approach***
// Time : O(min(logN, logM))
// Space : O(1)

int kthElement(vector<int> &a, vector<int> &b, int n1, int n2, int k){
    int n = n1 + n2;
    
    if(n1 > n2)
        return kthElement(b, a, n2, n1, k); // as we require first array is always smaller array

    int lo = max(0, k-n2), hi = min(n1, k); // do check this range

    int left = k; // number of elements in hypothetical left part of merged array

    while(lo <= hi) {
        int mid1 = (lo + hi)/2;
        int mid2 = left - mid1;

        int l1 = (mid1 > 0) ? a[mid1-1] : INT_MIN;
        int l2 = (mid2 > 0) ? b[mid2-1] : INT_MIN;
        int r1 = (mid1 < n1) ? a[mid1] : INT_MAX;
        int r2 = (mid2 < n2) ? b[mid2] : INT_MAX;

        if(l1 <= r2 && l2 <= r1){ // we get our solution
            return max(l1,l2);
        }
        else if(l1 > r2){ //eleminating right half
            hi = mid1 - 1;
        }
        else if(l2 > r1) { // eleminating left half
            lo = mid1 + 1;
        }
    }
}