#include<bits/stdc++.h>
using namespace std;

//Que.- Given a 2D Array, the task is to find the Peak element.

// Time : O(N*logM)
// Space : O(1)

int find_maxIdx(vector<vector<int>> arr, int n, int m, int col) {
    int maxRow = -1;
    int maxValue = -1;
    for(int i = 0; i < n; i++) {
        if(arr[i][col] > maxValue) {
            maxValue = arr[i][col];
            maxRow = i; 
        }
    }
    return maxRow;
}

vector<int> findPeakGrid(vector<vector<int>> &arr){
    int n = arr.size();
    int m = arr[0].size();

    int lo = 0;
    int hi = m - 1;
    int mid;

    while(lo <= hi) {
        mid = (lo + hi)/2;
        int maxRowIdx = find_maxIdx(arr, n, m, mid);

        int left = mid-1 >= 0 ? arr[maxRowIdx][mid-1] : -1;
        int right = mid+1 < m ? arr[maxRowIdx][mid+1] : -1;

        if(left < arr[maxRowIdx][mid] && right < arr[maxRowIdx][mid])
            return {maxRowIdx, mid};

        if(left > arr[maxRowIdx][mid]) 
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return {-1, -1};
}