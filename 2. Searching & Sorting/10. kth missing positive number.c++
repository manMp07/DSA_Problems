#include<iostream>
#include<vector>
using namespace std;

//Que.- You are given a strictly increasing array 'arr'and a positive integer 'K'.
//      Find the Kth positive integer missing from the 'arr'.

// Time : O(logN)
// Space : O(1)

int missingK(vector<int> arr, int n, int k) {
    int lo = 0;
    int hi = n-1;
    int mid;

    while(lo <= hi) {
        mid = (lo + hi)/2;
        int missing = arr[mid] - (mid + 1);
        if(missing < k)
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    return lo + k; // to understand this, watch striver's video
}