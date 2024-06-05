#include<bits/stdc++.h>
using namespace std;

//Que.- Given an array of N elements(initially all 0s), preform Q queries on it and return
//      the final array after performing all queries.
//      Every query is of the form (L, R, X), which means you need to add X to all the
//      values of the array from index L to R.

// Time : O(Q + N)
// Space : O(1)

vector<int> querySum(int n, int q, vector<vector<int>> queries){
    vector<int> ans(n, 0);

    for(int i = 0; i < q; i++){
        int L = queries[i][0];
        int R = queries[i][1];
        int X = queries[i][2];

        ans[L] += X;
        if(R+1 < n)
            ans[R+1] -= X;
    }

    for(int i = 1; i < n; i++)
        ans[i] = ans[i] + ans[i-1];

    return ans;
}

/***XOR instead of Addition***/

vector<int> querySum(int n, int q, vector<vector<int>> queries){
    vector<int> ans(n, 0);

    for(int i = 0; i < q; i++){
        int L = queries[i][0];
        int R = queries[i][1];
        int X = queries[i][2];

        ans[L] ^= X;
        if(R+1 < n)
            ans[R+1] ^= X;
    }

    for(int i = 1; i < n; i++)
        ans[i] = ans[i] ^ ans[i-1];

    return ans;
}