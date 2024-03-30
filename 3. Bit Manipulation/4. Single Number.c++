#include<bits/stdc++.h>
using namespace std;

//Que.- You are given an array in which every element appears twice accept one. You need to
//      find the element that appears only once.

//Time : O(N)
//Space : O(1)

int missingNumber(int n, vector<int> &arr){
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = ans ^ arr[i];

    return ans;
}