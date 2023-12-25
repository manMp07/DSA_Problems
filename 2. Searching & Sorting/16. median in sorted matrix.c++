#include<bits/stdc++.h>
using namespace std;

//Que.- Given a row-wise sorted matrix of size N x M, where N is no. of rows and M
//      is no. of columns, find the median in the given matrix.
//      Note : M & N will always be odd.

// Time : O( log(10^9) * N * logM )
// Space : O(1)

int upper_bound(vector<int> arr, int x) {
    int lo = 0;
    int hi = arr.size()-1;

    while(lo <= hi) {
        int mid = (lo + hi)/2;
        if(arr[mid] <= x)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return lo;
}

int countSmallerEqual(vector<vector<int>> matrix, int x) {
    // Time : O(N*logM)
    int cnt = 0;
    for(int i = 0; i < matrix.size(); i++) {
        cnt += upper_bound(matrix[i], x);
    }
    return cnt;
}

int median(vector<vector<int>> &matrix, int n, int m) {
    int lo = INT_MAX;
    int hi = INT_MIN;
    for(int i = 0; i < n; i++) {
        lo = min(lo, matrix[i][0]);
        hi = max(lo, matrix[i][m-1]);
    }

    int required = (n*m)/2;
    while(lo <= hi) {
        int mid = (lo + hi)/2;
        int smallerEqual = countSmallerEqual(matrix, mid);
        if(smallerEqual <= required)
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    return lo;
}