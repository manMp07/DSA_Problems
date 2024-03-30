#include<bits/stdc++.h>
using namespace std;

//Que.- You are given an array in which every element appears twice accept two. You need to
//      find the elements that appear only once.

//Time : O(N)
//Space : O(1)

vector<int> twoNonRepeatingElements(vector<int> arr, int n){
    long allXor = 0;
    for(int i = 0; i < n; i++)
        allXor = allXor ^ arr[i];

    long leftMost = (allXor & (allXor-1)) & allXor;

    int bucket1 = 0, bucket2 = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] & leftMost)
            bucket1 = bucket1 ^ arr[i];
        else
            bucket2 = bucket2 ^ arr[i];
    }

    return {bucket1, bucket2};
}