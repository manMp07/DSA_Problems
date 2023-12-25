#include<bits/stdc++.h>
using namespace std;

//Que.- You are given a 2 array of integers 'height' & 'width' represents the height
//      and the width of an envelope.
//      One envelope can fit into another if and only if both the width and height
//      of one envelope are greater than the other envelope's width and height.
//      Return the maximum number of envelopes you can Russian doll (i.e., put one
//      inside the other).
//      You cannot rotate an envelope.

/***DP with Binary Search***/
//Time : O(N*logN)
//Space : O(N)

bool cmp(vector<int> &a, vector<int> &b){
    if(a[0] < b[0])
        return true;
    else if(a[0] > b[0])
        return false;
    else
        return (a[1] > b[1]);
}

int longestIncreasingSubsequence(vector<vector<int>>& arr, int n){
    vector<int> ans;
    ans.push_back(arr[0][1]);

    for(int i = 1; i < n; i++){
        if(arr[i][1] > ans.back())
            ans.push_back(arr[i][1]);
        else {
            int index = lower_bound(ans.begin(), ans.end(), arr[i][1]) - ans.begin();
            ans[index] = arr[i][1];
        }
    }

    return ans.size();
}

int findMaxEnvelopes(vector<int> &height, vector<int> &width, int n) {
    vector<vector<int>> envelopes(n, vector<int>(2));

    // envelopes[0] = height & envelopes[1] = width
    for(int i = 0; i < n; i++) {
        envelopes[i][0] = height[i];
        envelopes[i][1] = width[i];
    }

    //sorted on basis of increasing order of height(env[0]) and for same height place
    //in decreasing order of weight(env[1]), bcoz we can use Longest Increasing
    //Subsequence approach on weights.
    sort(envelopes.begin(), envelopes.end(), cmp);

    /*for(int i = 0; i < n; i++) 
        cout << envelopes[i][0] << " & " << envelopes[i][1] << endl;*/

    return longestIncreasingSubsequence(envelopes, n);
}