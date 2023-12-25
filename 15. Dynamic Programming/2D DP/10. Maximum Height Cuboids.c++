#include<bits/stdc++.h>
using namespace std;

/*Que.- Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and place them on each other.

You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

Return the maximum height of the stacked cuboids.*/

bool check(vector<int> &base, vector<int> &newBox) {
    if(newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2])
        return true;
    else
        return false;
}

int solve(vector<vector<int>>& arr, int n){
    vector<int> currRow(n+1, 0);
    vector<int> nextRow(n+1, 0);
    
    for(int curr = n-1; curr >= 0; curr--){
        for(int prev = curr-1; prev >= -1; prev--){
            // take
            int include = 0;
            if(prev == -1 || check(arr[curr], arr[prev]))
                include = arr[curr][2] + nextRow[curr+1];

            // not take
            int exclude = nextRow[prev+1];

            currRow[prev+1] = max(include, exclude);
        }
        nextRow = currRow;
    }

    return nextRow[0];
}

int maxHeight(vector<vector<int>>& cuboids) {
    //step1 : sort all dimensions for every cuboid
    for(auto &a : cuboids)
        sort(a.begin(), a.end());

    //step2 : sort all cuboids, basis on W or L.
    sort(cuboids.begin(), cuboids.end());

    //step3 : Use LIS logic
    return solve(cuboids, cuboids.size());
}