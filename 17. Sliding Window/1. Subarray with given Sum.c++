#include<bits/stdc++.h>
using namespace std;

//Que.- Given an array A of size N that contains only non negative integers, find
//      a continuous sub-array that adds to a given number S and return the left
//      and right index(1-based indexing) of that subarray.
//      In case no such subarray exists return an array consisting of element -1.

//Time : O(N)
//Space : O(1)

vector<int> subarraySum(vector<int>arr, int n, long long sum){
    if(sum == 0){
        for(int i = 0; i < n; i++)
            if(arr[i] == 0)
                return {i+1,i+1};
        return {-1};
    }
        
    int i = 0, j = 0;
    long long currSum = arr[0];
        
    while(j < n) {
        if(currSum == sum)
            return {i+1, j+1};
            
        j++;
        currSum += arr[j];
            
        while(currSum > sum){
            currSum -= arr[i];
            i++;
        }
    }
        
    return {-1};
}