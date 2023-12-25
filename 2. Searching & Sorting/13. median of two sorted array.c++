#include<bits/stdc++.h>
using namespace std;

//Que.- Given two sorted arrays 'a' and 'b' of size 'n' and 'm' respectively.
//      Find the median of the two sorted array.

// ***Better Approach***
// Time : O(N + M)
// Space : O(1)

double median(vector<int> &a, vector<int> &b) {
    int n1 = a.size();
    int n2 = b.size();
    int n = n1+n2;
    
    int idx2 = n/2;
    int idx1 = idx2 - 1;
    int ele1 = -1, ele2 = -1;
    
    int i = 0, j = 0, count = 0;
    
    while(i < n1 && j < n2) {
        if(a[i] < b[j]) {
            if(count == idx1) ele1 = a[i];
            if(count == idx2) ele2 = a[i];
            count++;
            i++;
        }
        else {
            if(count == idx1) ele1 = b[j];
            if(count == idx2) ele2 = b[j];
            count++;
            j++;
        }
    }
    while(i < n1) {
        if(count == idx1) ele1 = a[i];
        if(count == idx2) ele2 = a[i];
        count++;
        i++;
    }
    while(j < n2){
        if(count == idx1) ele1 = b[j];
        if(count == idx2) ele2 = b[j];
        count++;
        j++;
    }

    if(n%2 == 1)
        return (double)ele2;
    
    return (double)((double)(ele1 + ele2))/2.0;
}

// ***Optimal Approach***
// Time : O(min(logN, logM))
// Space : O(1)

double median(vector<int>& a, vector<int>& b) {
    int n1 = a.size();
    int n2 = b.size();
    int n = n1 + n2;
    
    if(n1 > n2)
        return median(b, a); // as we require first array is always smaller array

    int lo = 0, hi = n1;
    int left = (n1 + n2 + 1)/2; // number of elements in hypothetical left part of merged array

    while(lo <= hi) {
        int mid1 = (lo + hi)/2;
        int mid2 = left - mid1;

        int l1 = (mid1 > 0) ? a[mid1-1] : INT_MIN;
        int l2 = (mid2 > 0) ? b[mid2-1] : INT_MIN;
        int r1 = (mid1 < n1) ? a[mid1] : INT_MAX;
        int r2 = (mid2 < n2) ? b[mid2] : INT_MAX;

        if(l1 <= r2 && l2 <= r1){ // we get our solution
            if(n%2 == 1)
                return max(l1,l2);
            else
                return ((double)(max(l1,l2) + min(r1,r2)))/2.0;
        }
        else if(l1 > r2){ //eleminating right half
            hi = mid1 - 1;
        }
        else if(l2 > r1) { // eleminating left half
            lo = mid1 + 1;
        }
    }
    return 0;
}