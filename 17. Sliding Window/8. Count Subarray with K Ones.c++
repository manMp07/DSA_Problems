#include<bits/stdc++.h>
using namespace std;

//Que.- You are given a binary array 'arr' of length 'N' and an integer 'k'. Return the
//      number of subarrays having the count of 1's equal to ‘k’.

// Time : O(4N)
// Space : O(1)

int func(vector<int> &arr, int goal) {
    if(goal < 0)
        return 0;

    int lo = 0;
    int sum = 0;
    int cnt = 0;

    for(int hi = 0; hi < arr.size(); hi++){
        sum += arr[hi];

        while(sum > goal)
            sum -= arr[lo++];

        cnt += hi-lo+1;
    }

    return cnt;
}

int subarrayWithSum(vector<int> &arr, int k) {
    return func(arr, k) - func(arr, k-1);
}